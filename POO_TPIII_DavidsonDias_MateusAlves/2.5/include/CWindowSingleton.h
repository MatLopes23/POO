#ifndef CWINDOWSINGLETON_H
#define CWINDOWSINGLETON_H
#include<Color.h>
#include<iostream>

class CWindowSingleton
{
    class Canvas/// Classe alinhada para armazenar caracteristicas de uma janela
    {
            Color fonte,pena,pincel;
            int tamanho_fonte;
            string tipo_fonte;

        public:
            Canvas(const int tam_fonte, const string tip_fonte, const string font, const string pen, const string pince);
            ~Canvas();

            /**Metodos inline para setar os atributos da classe, os metodos para setar fonte, pena e pincel
            invocao metodos da classe Color pois esta tem seu atributos privados   */
            void set_fonte(const string font);
            void set_pena(const string pen);
            void set_pincel(const string pince);
            void set_tamanho(const int tamanho);
            void set_tipo_fonte(const string tipo_font);

            ///Metodos inline para retornar os atributos da classe
            string get_fonte()const ;
            string get_pena()const;
            string get_pincel()const;
            int get_tamanho()const;
            string get_tipo_fonte()const;
    };

    int x, y;
    int cx, cy ;
    Canvas* my_canvas;
    ///Atributo static equivalente a uma variavel global para fazer uma restricao de criação de janelas
    static CWindowSingleton *instaceptr;
    ///Construtor privado para execultar o padrão de projeto de Singleton
    CWindowSingleton(const int newx=0,const int newy=0,const int newcx=10,const int newcy=10, const int tam_fonte=12, const string tip_fonte="Arial", const string font="preto", const string pen="preto", const string pince="preto");

    CWindowSingleton(const CWindowSingleton& h);
    CWindowSingleton& operator= (const CWindowSingleton& h);

    public:
    friend std::ostream& operator << (std::ostream& op, const CWindowSingleton&);
    friend std::istream& operator >> (std::istream& op, CWindowSingleton&);
    static CWindowSingleton *Instace();///Metodo static para restricao de criação de janelas
    ~CWindowSingleton();
    void show() const;
    void move(const int newx,const int newy);
    void resize(const int newcx,const int newcy);

    /**Metodos inline para setar os atributos da classe, os metodos para setar fonte, pena e pincel
        invocao metodos da classe Canvas que tambem invocao outros metodos pois esta tem seu atributos privados   */
    void Cset_fonte(const string font);
    void Cset_pena(const string pen);
    void Cset_pincel(const string pince);
    void Cset_tamanho(const int tamanho);
    void Cset_tipo_fonte(const string tipo_font);

    ///Metodos inline para retornar os atributos da classe
    string Cget_fonte()const;
    string Cget_pena()const;
    string Cget_pincel()const;
    int Cget_tamanho()const;
    string Cget_tipo_fonte()const;

    void LeDeArquivo(const std::string nomeArquivo);
    void GravarArquivo(const std::string nomeArquivo);
};


inline void CWindowSingleton::Canvas::set_fonte(const string font){fonte.set_Color(font);}
inline void CWindowSingleton::Canvas::set_pena(const string pen){pena.set_Color(pen);}
inline void CWindowSingleton::Canvas::set_pincel(const string pince){pincel.set_Color(pince);}
inline void CWindowSingleton::Canvas::set_tamanho(const int tamanho){(tamanho>0&&tamanho<60)?tamanho_fonte=tamanho:tamanho_fonte=12;}
inline void CWindowSingleton::Canvas::set_tipo_fonte(const string tipo_font){tipo_fonte=tipo_font;}

inline string CWindowSingleton::Canvas::get_fonte()const {return fonte.Cor();}
inline string CWindowSingleton::Canvas::get_pena()const {return pena.Cor();}
inline string CWindowSingleton::Canvas::get_pincel()const {return pincel.Cor();}
inline int CWindowSingleton::Canvas::get_tamanho()const {return tamanho_fonte;}
inline string CWindowSingleton::Canvas::get_tipo_fonte()const {return tipo_fonte;}

inline void CWindowSingleton::Cset_fonte(const string font){my_canvas->set_fonte(font);}
inline void CWindowSingleton::Cset_pena(const string pen){my_canvas->set_pena(pen);}
inline void CWindowSingleton::Cset_pincel(const string pince){my_canvas->set_pincel(pince);}
inline void CWindowSingleton::Cset_tamanho(const int tamanho){my_canvas->set_tamanho(tamanho);}
inline void CWindowSingleton::Cset_tipo_fonte(const string tipo_font){my_canvas->set_tipo_fonte(tipo_font);}

inline string CWindowSingleton::Cget_fonte()const {return my_canvas->get_fonte();}
inline string CWindowSingleton::Cget_pena()const {return my_canvas->get_pena();}
inline string CWindowSingleton::Cget_pincel()const {return my_canvas->get_pincel();}
inline int CWindowSingleton::Cget_tamanho()const {return my_canvas->get_tamanho();}
inline string CWindowSingleton::Cget_tipo_fonte()const {return my_canvas->get_tipo_fonte();}


#endif // CWINDOWSINGLETON_H
