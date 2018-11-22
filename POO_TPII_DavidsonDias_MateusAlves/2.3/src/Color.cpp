#include "Color.h"

void Color::colorir(const string c)/// Metodo para converter o nome da cor em formato RGB
{
    if(c=="branco")
    {
        RGB.nome_cor=c;
        RGB.x=255;
        RGB.y=255;
        RGB.z=255;
    }
    else if(c=="azul")
    {
        RGB.nome_cor=c;
        RGB.x=0;
        RGB.y=0;
        RGB.z=255;
    }
    else if(c=="vermelho")
    {
        RGB.nome_cor=c;
        RGB.x=255;
        RGB.y=0;
        RGB.z=0;
    }
    else if(c=="verde")
    {
        RGB.nome_cor=c;
        RGB.x=0;
        RGB.y=255;
        RGB.z=0;
    }
    else if(c=="amarelo")
    {
        RGB.nome_cor=c;
        RGB.x=255;
        RGB.y=255;
        RGB.z=0;
    }
    else if(c=="magenta")
    {
        RGB.nome_cor=c;
        RGB.x=255;
        RGB.y=0;
        RGB.z=255;
    }
    else if(c=="ciano")
    {
        RGB.nome_cor=c;
        RGB.x=0;
        RGB.y=255;
        RGB.z=255;
    }
    else
    {
        RGB.nome_cor="preto";
        RGB.x=0;
        RGB.y=0;
        RGB.z=0;
    }
}

Color::Color(const string c)
{
    colorir(c);
}

Color::~Color()
{
    //dtor
}

void Color::set_Color(const string c)
{
    colorir(c);
}

string Color::Cor() const
{
    return RGB.nome_cor;
}
