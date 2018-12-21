#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Dados2.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <cmath>

using namespace std;

Dados2* Dados2::objt = 0;


Dados2* Dados2::getInstance()
{


    if(objt)
        return objt;
    else
    {
        objt = new Dados2();
        return objt;
    }

}

Dados2::~Dados2()
{
    for(std::vector<sf::Sprite>::iterator it = spriteList.begin(); it != spriteList.end(); it++)
    {
        sf::Sprite spr = *it;
        const sf::Texture *tex = spr.getTexture();
        delete tex;
        cout << "Deleted " << tex << endl;
    }
    const sf::Texture *t = background.getTexture();
    delete t;
    cout << "Delected" << t << endl;
}

///tex->loadFromFile(file); esta dando erro de compilação. Mas não encontro nenhum erro nele :/
int Dados2::criarSprite(string file)
{
    sf::Sprite sprit;
    sf::Texture *tex = new sf::Texture();
    std::cout << "Created " << tex << std::endl;
    tex->loadFromFile(file);
    sprit.setTexture(*tex);
    cout << sprit.getPosition().x<<" "<< sprit.getPosition().y<<endl;
    spriteList.push_back(sprit);
    return spriteList.size()-1;
}

void Dados2::moveSprite(int id, float x, float y)
{
    spriteList[id].move(x, y);
}
void Dados2::setaPosicaoSpr(int id, float x, float y)
{
    spriteList[id].setPosition(x,y);
}
void Dados2::setaEscalaSpr(int id, float e)
{
    spriteList[id].setScale(e, e);
}

void Dados2::criarRet()
{
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Green);
    rectList.push_back(shape);
}

void Dados2::setaPosicaoRet(int id, float x, float y)
{
    rectList[id].setPosition(x,y);
}

void Dados2::setaTamRet(int id, float l, float h)
{
    rectList[id].setSize(sf::Vector2f(l, h));
}

void Dados2::criarCir()
{
    sf::CircleShape circl;
    circl.setFillColor(sf::Color::Black);
    circleList.push_back(circl);
}

void Dados2::setaPosicaoCir(int id, float x, float y)
{
    circleList[id].setPosition(x, y);
}

void Dados2::setaRaioCir(int id, float r)
{
    circleList[id].setRadius(r);
}

///t->loadFromFile(file); esta dando erro de compilação. Mas não encontro nenhum erro nele :/
void Dados2::criarBackground(string file)
{
    //sf::Sprite sprit;
    sf::Texture *t = new sf::Texture();
    std::cout << "Created " << t << std::endl;
    t->loadFromFile(file);
    background.setTexture(*t);
}

int Dados2::criaSpriteSheet(string file, int divX, int divY){

    sf::Sprite sprit;
    sf::Texture *tex = new sf::Texture();
    std::cout << "Created " << tex << std::endl;
    tex->loadFromFile(file);
    sprit.setTexture(*tex);

    sf::Vector2u textureSize = tex->getSize();
    textureSize.x/=divX;
    textureSize.y/=divY;
    sprit.setTextureRect(sf::IntRect(textureSize.x*0, textureSize.y*0, textureSize.x, textureSize.y));

    spriteList.push_back(sprit);

    return spriteList.size()-1;
}

