#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string.h>

using namespace std;

class Dados{
private:
//    vector<sf::Sprite> spriteList;
    static Dados *objt;
    Dados() {}

public:

    //sf::Texture tex;
    sf::Sprite background;
    vector<sf::Sprite> spriteList;
    vector<sf::RectangleShape> rectList;
    vector<sf::CircleShape> circleList;
    static Dados* getInstance();
    int criarSprite(string file);
    int criarSpriteSheet(string file, int divX, int divY);
    int criarSpriteSheetIrregular(string file, int divX, int divY);
    void setaPosicaoSpr(int id, float x, float y);
    void moveSprite(int id, float dirX, float dirY);
    void setaEscalaSpr(int id, float e);
    void criarRet();
    void setaPosicaoRet(int id, float x, float y);
    void setaTamRet(int id, float l, float h);
    void criarCir();
    void setaPosicaoCir(int id, float x, float y);
    void setaRaioCir(int id, float r);
    void criarBackground(string file);
    int intervaloPixels(int pontoInicialX, int pontoInicialY, bool sentidoHorizontal, sf::Image *img);
    void separarSprite(int x, int y, int w, int h, sf::Image * img,string file);
    void floodFillAux(bool **matriz, int x, int y, sf::Image * img, int menorX, int maiorX, int menorY, int maiorY, int limites[2][2]);


    ~Dados();

};


#endif // DADOS_H_INCLUDED
