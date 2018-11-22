#ifndef COLOR_H
#define COLOR_H
#include<string>

using std::string;

class Color
{
    struct rgb///struct para representer uma cor no formato RGB
    {
        int x,y,z;
        string nome_cor;
    };
    struct rgb RGB;
    void colorir(const string c);///Método axiliar
    public:
        Color(const string c="branco");
        void set_Color(const string c);
        string Cor() const;
        virtual ~Color();

};

#endif // COLOR_H
