#ifndef GETGAME_H_INCLUDED
#define GETGAME_H_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string.h>

using namespace std;
///esta função não deveria ter sido criada. Ignore-a
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


    ~Dados();


};


#endif // GETGAME_H_INCLUDED
