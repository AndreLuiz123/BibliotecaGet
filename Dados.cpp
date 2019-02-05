#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Dados.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sstream>
#include <cmath>
#include "Base.h"



using namespace std;

Dados* Dados::objt = 0;


Dados* Dados::getInstance()
{


    if(objt)
        return objt;
    else
    {
        objt = new Dados();
        return objt;
    }

}

Dados::~Dados()
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
    cout << "Deleted" << t << endl;
}

int Dados::criarSprite(string file)
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

int Dados::criarSpriteSheet(string file, int divX, int divY){

    int i,j, posicaoX, posicaoY;
    sf::Sprite sprit;
    sf::Texture *tex = new sf::Texture();
    std::cout << "Created " << tex << std::endl;
    tex->loadFromFile(file);

     sf::Vector2u textureSize;

     textureSize.x = tex->getSize().x/divX;
     textureSize.y = tex->getSize().y/divY;


    for(j=0; j<divY; j++){
        for(i=0; i<divX; i++){

            sprit.setTexture(*tex);

            posicaoX = (tex->getSize().x/divX)*i;
            posicaoY = (tex->getSize().x/divX)*j;
            sprit.setTextureRect(sf::IntRect(posicaoX ,posicaoY , textureSize.x, textureSize.y));
            spriteList.push_back(sprit);

            cout<<"separa sprite"<<posicaoX-textureSize.x<<" "<<posicaoY-textureSize.y<<endl;

            setaPosicaoSpr(spriteList.size()-1, 0, 0);

            //cout<<80*i<<" e "<<100*j<<endl;
        }
    }

   // cout<<"OLHA AQUI "<<i<<" AQUI TBM "<<j<<endl;


    return spriteList.size() - 1;
}

int Dados::criarSpriteSheetIrregular(string file, int divX, int divY){

    sf::Image *img = new sf::Image();
    int limites[2][2];
    int desenhaTelaX=0, desenhaTelaY=0;///só para visualização



    img->loadFromFile(file);

    bool **matrizFloodFill;

    matrizFloodFill = new bool*[img->getSize().x];
    for(int o=0; o<img->getSize().x; o++){
        matrizFloodFill[o] = new bool [img->getSize().y];
    }


    for(int i=0; i<img->getSize().y; i++){
        for(int j=0; j<img->getSize().x; j++){
            matrizFloodFill[j][i]=false;
        }
    }
    ///MatrizFloodFill indica quais pixels ja foram visitados

    for(int i=0; i<img->getSize().x; i++){
        for(int j=0; j<img->getSize().y; j++){

            if(matrizFloodFill[i][j]==false){
       // cout<<i<<" "<<j<<endl;
                if(img->getPixel(i,j).a > 100){
                    //cout<<limites[0][1]-limites[0][0]<<endl;
                    //cout<<limites[1][0]-limites[1][1]<<endl;
                    //cout<<i<<" "<<j<<endl;
                    //cout<<endl;
                    limites[0][0]=i;
                    limites[1][1]=j;
                    limites[0][1]=i;
                    limites[1][0]=j;
                    floodFillAux(matrizFloodFill,i,j,img,i,i,j,j,limites);
                    separarSprite(limites[0][0],limites[1][1], limites[0][1],limites[1][0], img, file);
                    setaPosicaoSpr(spriteList.size()-1, desenhaTelaX*50, desenhaTelaY*50);///só para visualização
                    //cout<<desenhaTelaX<<endl;
                    if(desenhaTelaX*50<450){///só para visualização
                    desenhaTelaX++;///só para visualização
                    }else{///só para visualização
                    desenhaTelaX=0;///só para visualização
                    desenhaTelaY++;///só para visualização
                    }///só para visualização


                //i+=limites[0][1];
                //j+=limites[1][0];
                }
            }
        }
    }


      cout<<img->getSize().x<<endl;
      cout<<img->getSize().y<<endl;


    return spriteList.size() - 1;
}


int Dados::intervaloPixels(int pontoInicialX, int pontoInicialY, bool sentidoHorizontal, sf::Image *img){
}


void Dados::floodFillAux(bool **matriz, int x, int y, sf::Image * img, int menorX, int maiorX, int menorY, int maiorY, int limites[2][2]){



    if(matriz[x][y]==false){
        if(img->getPixel(x,y).a > 100){
            if(x>maiorX){
                maiorX = x;
                limites[0][1]=x;
            }else{
                if(x<menorX){
                    menorX = x;
                    limites[0][0]=x;
                }
            }
            if(y>maiorY){
                maiorY = y;
                limites[1][0]=y;
            }else{
                if(y<menorY){
                    menorY = y;
                    limites[1][1]=y;
                }
            }
            matriz[x][y]=true;

            //img->setPixel(x,y,sf::Color(255,0,0,255));

            floodFillAux(matriz,x-1,y+1,img,menorX,maiorX,menorY,maiorY, limites);
            floodFillAux(matriz,x-1,y,img,menorX,maiorX,menorY,maiorY, limites);
            floodFillAux(matriz,x-1,y-1,img,menorX,maiorX,menorY,maiorY, limites);
            floodFillAux(matriz,x,y-1,img,menorX,maiorX,menorY,maiorY, limites);
            floodFillAux(matriz,x+1,y-1,img,menorX,maiorX,menorY,maiorY, limites);
            floodFillAux(matriz,x+1,y,img,menorX,maiorX,menorY,maiorY, limites);
            floodFillAux(matriz,x+1,y+1,img,menorX,maiorX,menorY,maiorY, limites);
            floodFillAux(matriz,x,y+1,img,menorX,maiorX,menorY,maiorY, limites);

        }
    }
}
///IDEIA: DEPOIS DE EXECUTAR ESTE ALGORITMO, UM SEGUNDO ALGORITMO É USADO: SUA FUNÇÃO É DETECTAR SE AINDA EXISTEM PIXELS NAS LINHAS SEGUINTES AOS LIMITES JÁ ESCONTRADOS


void Dados::separarSprite(int x, int y, int w, int h, sf::Image * img, string file){


        sf::Sprite sprite;
        sf::Texture *tex = new sf::Texture();

        tex->loadFromImage(*img);
        sprite.setTexture(*tex);

        sprite.setTextureRect(sf::IntRect(x,y,w-x,h-y));

        cout<<w-x<<" "<<h-y<<endl;

        spriteList.push_back(sprite);

        //   return spriteList.size() - 1;
}

void Dados::moveSprite(int id, float x, float y)
{
    spriteList[id].move(x, y);
}
void Dados::setaPosicaoSpr(int id, float x, float y)
{
    spriteList[id].setPosition(x,y);
}
void Dados::setaEscalaSpr(int id, float e)
{
    spriteList[id].setScale(e, e);
}

void Dados::criarRet()
{
    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Green);
    rectList.push_back(shape);
}

void Dados::setaPosicaoRet(int id, float x, float y)
{
    rectList[id].setPosition(x,y);
}

void Dados::setaTamRet(int id, float l, float h)
{
    rectList[id].setSize(sf::Vector2f(l, h));
}

void Dados::criarCir()
{
    sf::CircleShape circl;
    circl.setFillColor(sf::Color::Black);
    circleList.push_back(circl);
}

void Dados::setaPosicaoCir(int id, float x, float y)
{
    circleList[id].setPosition(x, y);
}

void Dados::setaRaioCir(int id, float r)
{
    circleList[id].setRadius(r);
}

void Dados::criarBackground(string file)
{
    //sf::Sprite sprit;
    sf::Texture *t = new sf::Texture();
    std::cout << "Created " << t << std::endl;
    t->loadFromFile(file);
    background.setTexture(*t);
}



