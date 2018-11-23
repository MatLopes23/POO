#include "CWindow.h"
#include <new>
#include<iostream>
#include<fstream>

CWindow::CWindow(const CWindow& h):x(h.x),y(h.y),cx(h.cx),cy(h.cy)
{
    my_canvas=new Canvas(h.Cget_tamanho(), h.Cget_tipo_fonte(), h.Cget_fonte(), h.Cget_pena(), h.Cget_pincel());
}

CWindow& CWindow::operator=(const CWindow& h)
{
    if (this==&h)
        return *this;

    x=h.x;
    y=h.y;
    cx=h.cx;
    cy=h.cy;

    delete my_canvas;

    my_canvas=new Canvas(h.Cget_tamanho(), h.Cget_tipo_fonte(), h.Cget_fonte(), h.Cget_pena(), h.Cget_pincel());

    return *this;
}

CWindow::CWindow(const int newx, const int newy, const int newcx, const int newcy, int tam_fonte, std::string tip_fonte, std::string font, std::string pen, std::string pince)
{
    x=newx;
    y=newy;
    cx=newcx;
    cy=newcy;
    if(newcx<=0)
        cx=10;
    if(newcy<=0)
        cy=10;
    my_canvas=new Canvas(tam_fonte, tip_fonte, font, pen, pince);
}

CWindow::~CWindow()
{
    delete my_canvas;
}

void CWindow :: move(const int newx,const int newy)
{
    x = newx;
    y = newy;
    show();
}

 void CWindow::resize(const int newcx,const int newcy)
{
    cx = newcx;
    cy = newcy;
    ///Restrição para valores de dimesoes negativas
    if(newcx<=0)
        cx=10;
    if(newcy<=0)
        cy=10;

    show();
}

void CWindow::show() const
{
    std::cout<<"Janela desenha na posicao ("<<x<<","<<y<<") com largura "<<cx<<" e altura "<<cy<<"."<<std::endl;
}

void CWindow::LeDeArquivo(const string nomeArquivo)
{
    ///Pegamos dado por dado e atribuimos aos seus respectivos atributos, considerando a existencia de todos
    std::ifstream arq(nomeArquivo.c_str());
    int aux;
    string aux2;
    arq>>aux;
    x=aux;
    arq>>aux;
    y=aux;
    arq>>aux;
    cx=aux;
    if(cx<=0)
        cx=10;
    arq>>aux;
    cy=aux;
    if(cy<=0)
        cy=10;
    arq>>aux;
    my_canvas->set_tamanho(aux);
    arq>>aux2;
    my_canvas->set_tipo_fonte(aux2);
    arq>>aux2;
    my_canvas->set_fonte(aux2);
    arq>>aux2;
    my_canvas->set_pena(aux2);
    arq>>aux2;
    my_canvas->set_pincel(aux2);
}

void CWindow::GravarArquivo(const string nomeArquivo)
{
    std::ofstream out(nomeArquivo);

    out<<x<<" "<<y<<std::endl;
    out<<cx<<" "<<cy<<std::endl;
    out<<my_canvas->get_tamanho()<<" "<<my_canvas->get_tipo_fonte()<<" "<<my_canvas->get_fonte()<<" "<<my_canvas->get_pena()<<" "<<my_canvas->get_pincel();

}

std::ostream& operator << (std::ostream& op, const CWindow& h)
{
    op<<"Janela desenha na posicao ("<<h.x<<","<<h.y<<") com largura "<<h.cx<<" e altura "<<h.cy<<"."<<std::endl;
    op<<"Fonte:\n"
                "\tTamanho: "<<h.my_canvas->get_tamanho()<<".\n"
                "\tTipo: "<<h.my_canvas->get_tipo_fonte()<<".\n"
                "\tCor: "<<h.my_canvas->get_fonte()<<".\n"
                "Pena: "<<h.my_canvas->get_pena()<<".\n"
                "Pincel: "<<h.my_canvas->get_pincel()<<".\n";

    return op;
}

std::istream& operator >> (std::istream& op, CWindow& h)
{
    std::cout<<"Posicao da janela: ";
    op>> h.x;
    op>> h.y;
    std::cout<<"Dimesao da janela: ";
    op>> h.cx;
    op>> h.cy;
    std::cout<<"Tamanho da fonte: ";
    int tam;
    std::string tipo,fonte,pena,pincel;
    op>>tam;
    h.my_canvas->set_tamanho(tam);
    std::cout<<"Tipo da fonte: ";
    op>>tipo;
    h.my_canvas->set_tipo_fonte(tipo);
    std::cout<<"Fonte(branco, azul, vermelhor, verde, amarelo, magenta, ciano, preto): ";
    op>>fonte;
    h.my_canvas->set_fonte(fonte);
    std::cout<<"Pena(branco, azul, vermelhor, verde, amarelo, magenta, ciano, preto): ";
    op>>pena;
    h.my_canvas->set_pena(pena);
    std::cout<<"Pincel(branco ,azul, vermelhor, verde, amarelo, magenta, ciano, preto): ";
    op>>pincel;
    h.my_canvas->set_pincel(pincel);

    return op;
}


///---------------Canvas------------------
CWindow::Canvas::Canvas(const int tam_fonte, const string tip_fonte, const string font, const string pen, const string pince)
{
    tamanho_fonte=tam_fonte;
    if(tam_fonte<0 || tam_fonte>60)///Restricao do tamanho da fonte
        tamanho_fonte=12;
    tipo_fonte=tip_fonte;
    fonte.set_Color(font);
    pena.set_Color(pen);
    pincel.set_Color(pince);

}

CWindow::Canvas::~Canvas(){}
