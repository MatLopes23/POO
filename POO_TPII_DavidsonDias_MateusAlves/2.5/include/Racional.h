#ifndef RACIONAL_H
#define RACIONAL_H


class Racional
{
    private:
    int numerador,denominador;
    void simplificar(int n,int d);

    public:
        Racional(int n=0,int d=1);
        virtual ~Racional();
        void add(const int n, int d=1);///O denominador por default recebe 1 para caso ele não seja especificado
        void subtrair(const Racional a ,const Racional b);
        void multiplicar(const Racional a,const Racional b);
        void dividir(const Racional a, const Racional b);
        void printflutuante()const ;
        void print()const;


};

#endif // RACIONAL_H
