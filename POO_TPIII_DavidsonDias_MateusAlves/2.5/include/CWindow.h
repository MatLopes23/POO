#ifndef CWINDOW_H
#define CWINDOW_H
#include<Color.h>

class CWindow
{
    class Canvas/// Classe alinhada para armazenar caracteristicas de uma janela
    {
            Color fonte,pena,pincel;
            int tamanho_fonte;
            string tipo_fonte;

        public:
            Canvas( const int tam_fonte, const string tip_fonte, const string font, const string pen, const string pince);
            ~Canvas();

            /**Metodos inline para setar os atributos da classe, os metodos para setar fonte, pena e pincel
            invocao metodos da classe Color pois esta tem seu atributos privados   */
            void set_fonte(const string font);
            void set_pena(const string pen);
            void set_pincel(const string pince);
            void set_tamanho(const int tamanho);
            void set_tipo_fonte(const string tipo_font);

            ///Metodos inline para retornar os atributos da classe
            string get_fonte()const;
            string get_pena()const;
            string get_pincel()const;
            int get_tamanho()const;
            string get_tipo_fonte()const ;
    };

    int x, y;
    int cx, cy ;
    Canvas* my_canvas;

    public:

    CWindow(const CWindow& h);
    CWindow& operator= (const CWindow& h);
    friend std::ostream& operator << (std::ostream& op, const CWindow&);
    friend std::istream& operator >> (std::istream& op, CWindow&);
    CWindow(const int newx=0,const int newy=0,const int newcx=10,const int newcy=10, const int tam_fonte=12, const string tip_fonte="Arial", const string font="preto", const string pen="preto", const string pince="preto");
    ~CWindow();
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

inline void CWindow::Canvas::set_fonte(const string font){fonte.set_Color(font);}
inline void CWindow::Canvas::set_pena(const string pen){pena.set_Color(pen);}
inline void CWindow::Canvas::set_pincel(const string pince){pincel.set_Color(pince);}
inline void CWindow::Canvas::set_tamanho(const int tamanho){(tamanho>0&&tamanho<60)?tamanho_fonte=tamanho:tamanho_fonte=12;}
inline void CWindow::Canvas::set_tipo_fonte(const string tipo_font){tipo_fonte=tipo_font;}

inline string CWindow::Canvas::get_fonte()const {return fonte.Cor();}
inline string CWindow::Canvas::get_pena()const {return pena.Cor();}
inline string CWindow::Canvas::get_pincel()const {return pincel.Cor();}
inline int CWindow::Canvas::get_tamanho()const {return tamanho_fonte;}
inline string CWindow::Canvas::get_tipo_fonte()const {return tipo_fonte;}

inline void CWindow::Cset_fonte(const string font){my_canvas->set_fonte(font);}
inline void CWindow::Cset_pena(const string pen){my_canvas->set_pena(pen);}
inline void CWindow::Cset_pincel(const string pince){my_canvas->set_pincel(pince);}
inline void CWindow::Cset_tamanho(const int tamanho){my_canvas->set_tamanho(tamanho);}
inline void CWindow::Cset_tipo_fonte(const string tipo_font){my_canvas->set_tipo_fonte(tipo_font);}

inline string CWindow::Cget_fonte()const {return my_canvas->get_fonte();}
inline string CWindow::Cget_pena()const {return my_canvas->get_pena();}
inline string CWindow::Cget_pincel()const {return my_canvas->get_pincel();}
inline int CWindow::Cget_tamanho()const {return my_canvas->get_tamanho();}
inline string CWindow::Cget_tipo_fonte()const {return my_canvas->get_tipo_fonte();}

#endif // CWINDOW_H
