#include <iostream>
#include<CWindow.h>
#include<CWindowSingleton.h>
#include<stdlib.h>

void teste_CWindow(CWindow h)
{
    h.move(10,10);
    std::cout<<"Dentro da funçao por copia\n"<<h;

}

void teste2_CWindow(CWindow& h)
{
    h.move(10,10);
    std::cout<<"Dentro da funçao por referencia\n"<<h;
}
void teste_CWindowSingleton(CWindowSingleton h)
{
    h.move(10,10);
    std::cout<<"Dentro da funçao por copia\n"<<h;
}

void teste2_CWindowSingleton(CWindowSingleton& h)
{
    h.move(10,10);
    std::cout<<"Dentro da funçao por referencia\n"<<h;
}
