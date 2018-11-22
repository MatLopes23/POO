#include "CWindowSingleton.h"
#include <new>
#include<iostream>
#include<fstream>

CWindowSingleton::CWindowSingleton(const int newx, const int newy, const int newcx, const int newcy, int tam_fonte, std::string tip_fonte, std::string font, std::string pen, std::string pince)
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

CWindowSingleton::~CWindowSingleton()
{
    delete my_canvas;
}

void CWindowSingleton :: move(const int newx,const int newy)
{
    x = newx;
    y = newy;
    show();
}

 void CWindowSingleton::resize(const int newcx,const int newcy)
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

void CWindowSingleton::show() const
{
    std::cout<<"Janela desenha na posicao ("<<x<<","<<y<<") com largura "<<cx<<" e altura "<<cy<<"."<<std::endl;
}

void CWindowSingleton::LeDeArquivo(const string nomeArquivo)
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

void CWindowSingleton::GravarArquivo(const string nomeArquivo)
{
    std::ofstream out(nomeArquivo);

    out<<x<<" "<<y<<std::endl;
    out<<cx<<" "<<cy<<std::endl;
    out<<my_canvas->get_tamanho()<<" "<<my_canvas->get_tipo_fonte()<<" "<<my_canvas->get_fonte()<<" "<<my_canvas->get_pena()<<" "<<my_canvas->get_pincel();

}

CWindowSingleton *CWindowSingleton::instaceptr=0; ///Atribui '0' para instaceptr no inicio do programa e depois recebe o endereço do objeto criado

CWindowSingleton *CWindowSingleton::Instace()///O metodo restringe a criação de janelas e retorna a janela ja existente caso tente criar outra
{
    if(instaceptr==0)
        instaceptr = new CWindowSingleton;
    return(instaceptr);
}

///---------------Canvas------------------
CWindowSingleton::Canvas::Canvas(const int tam_fonte, const string tip_fonte, const string font, const string pen, const string pince)
{


    tamanho_fonte=tam_fonte;
    if(tam_fonte<0 || tam_fonte>60)///Restricao do tamanho da fonte
        tamanho_fonte=12;

    tipo_fonte=tip_fonte;
    fonte.set_Color(font);
    pena.set_Color(pen);
    pincel.set_Color(pince);

}

CWindowSingleton::Canvas::~Canvas(){}
