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

/*
    Esta função retorna um objeto do tipo "Dados". O primeiro if serve para retornar o objeto do tipo "Dados" caso ele já existe
    O else, por outro lado, cria um novo objeto do tipo dados caso não haja objeto deste tipo na chamada da função;
*/
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

/*
    Este é o destrutor do objeto do tipo "Dados". Esta função, em resumo, deleta todos os arquivos utilizados pela classe
    no jogo. O primeiro for apaga os sprites usados no jogo O ponteiro "t" apaga o background
*/
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
/*
    Esta função cria um sprite a partir de um arquivo. O sprite criado por esta função é único, e não um conjunto de sprites.
    Espera-se que esta função seja usada com arquivos de imagem com uma, e apenas uma, imagem.
    O algoritmo cria um novo sprite para ser usado no jogo e adiciona a este uma nova textura. Esta textura, por sua vez,
    tem como imagem a que esta presente no arquivo passado no parâmetro. Terminados os processos, o novo sprite é adicionado ao
    spriteList, lista que armazena todos os sprites do jogo.
*/
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

/*
    Esta função cria diversos sprites a partir de um único arquivo. Espera-se que o arquivo usado aqui seja uma spritesheet
    com os sprites divididos de forma simétrica. O que o algoritmo faz é cortar o arquivo em divX*divY partes menores que guardam os sprites
    do jogo. O algoritmo recebe como parâmetro o arquivo a ser dividido, o número de subdivisões em X é determinado com divX e subdivisões em
    Y é determinado com divY. Feito o processo de divisão, os sprites são colocados na spritelist
*/
int Dados::criarSpriteSheet(string file, int divX, int divY)
{

    int i,j, posicaoX, posicaoY;
    sf::Sprite sprit;
    sf::Texture *tex = new sf::Texture();
    std::cout << "Created " << tex << std::endl;
    tex->loadFromFile(file);

    sf::Vector2u textureSize;

    textureSize.x = tex->getSize().x/divX;
    textureSize.y = tex->getSize().y/divY;


    for(j=0; j<divY; j++)
    {
        for(i=0; i<divX; i++)
        {

            sprit.setTexture(*tex);

            posicaoX = (tex->getSize().x/divX)*i;
            posicaoY = (tex->getSize().x/divX)*j;
            sprit.setTextureRect(sf::IntRect(posicaoX,posicaoY, textureSize.x, textureSize.y));
            spriteList.push_back(sprit);

            cout<<"separa sprite"<<posicaoX-textureSize.x<<" "<<posicaoY-textureSize.y<<endl;

            setaPosicaoSpr(spriteList.size()-1, 0, 0);
        }
    }
    return spriteList.size() - 1;
}
///O criarSpriteSheetIrregular serve como ferramenta para separar os sprites de spritesheets com imagens desordenadas.
/*
  Primeiro o algoritmo salva em uma variável do tipo "Image" o arquivo do spritesheet.
  Depois o algoritmo cria a matrizFloodFill, com número de colunas e linhas iguais aos número de pixels
  O matrizFloodFill serve para indicar quais pixels já foram visitados pelo algoritmo ou não
  Como nenhum pixel foi visitado ainda, todas as coordenadas da matriz são falsas
  Ao mesmo tempo é criada a matriz limites, com 4 células e cujo objetivo será explicado mais adiante
  Continuando, o algoritmo percorre cada pixel da imagem analisando se o pixel é transparente ou não
  Quando não é transparente, o algoritmo chama a função matrizFloodFill, que define os limites da imagem do arquivo que será cortada pela função seguinte
  O matriz floodfill faz uma busca em profundidade que analisa todos os píxels que podem ser alcançados a partir de um píxel inicial
  A cada píxel analisado, o algoritmo ve se a coordenada x ouy é maior ou menor que alguma outra coordenada da imagem. Se for, a nova coordenada é salva na matriz "limite", citada anteriormente
  Por fim, o algoritmo pega as coordenadas encontradas no matriz flood fill e usa a função "separa sprite", cortando a imagem e colocando-a no spritelist
*/

int Dados::criarSpriteSheetIrregular(string file)
{

    sf::Image *img = new sf::Image();
    int limites[2][2];
    int desenhaTelaX=0, desenhaTelaY=0;///só para visualização

    img->loadFromFile(file);

    bool **matrizFloodFill;

    matrizFloodFill = new bool*[img->getSize().x];
    for(int o=0; o<img->getSize().x; o++)
    {
        matrizFloodFill[o] = new bool [img->getSize().y];
    }

    for(int i=0; i<img->getSize().y; i++)
    {
        for(int j=0; j<img->getSize().x; j++)
        {
            matrizFloodFill[j][i]=false;
        }
    }
    ///MatrizFloodFill indica quais pixels ja foram visitados

    for(int j=0; j<img->getSize().y; j++)
    {
        for(int i=0; i<img->getSize().x; i++)
        {

            if(matrizFloodFill[i][j]==false)
            {
                if(img->getPixel(i,j).a > 100)
                {
                    limites[0][0]=i;
                    limites[1][1]=j;
                    limites[0][1]=i;
                    limites[1][0]=j;
                    floodFillAux(matrizFloodFill,i,j,img,i,i,j,j,limites);
                    separarSprite(limites[0][0],limites[1][1], limites[0][1],limites[1][0], img, file);
                     setaPosicaoSpr(spriteList.size()-1, desenhaTelaX*50, desenhaTelaY*50);///só para visualização
                    if(desenhaTelaX*50<450) ///só para visualização
                    {
                        desenhaTelaX++;///só para visualização
                    }
                    else  ///só para visualização
                    {
                        desenhaTelaX=0;///só para visualização
                        desenhaTelaY++;///só para visualização
                    }///só para visualização
                }
            }
        }
    }

    return spriteList.size() - 1;
}
/*
    Esta função auxilia a função "criarSpriteSheetIrregular". Ela basicamente pega um píxel não transparente e pega todos os píxels não transparentes
    que podem ser acessados a partir dela. Este processo é feito a partir de uma busca em profundidade.
*/
void Dados::floodFillAux(bool **matriz, int x, int y, sf::Image * img, int menorX, int maiorX, int menorY, int maiorY, int limites[2][2])
{
    if(matriz[x][y]==false)
    {
        if(img->getPixel(x,y).a > 100)
        {
            if(x>maiorX)
            {
                maiorX = x;
                limites[0][1]=x;
            }
            else
            {
                if(x<menorX)
                {
                    menorX = x;
                    limites[0][0]=x;
                }
            }
            if(y>maiorY)
            {
                maiorY = y;
                limites[1][0]=y;
            }
            else
            {
                if(y<menorY)
                {
                    menorY = y;
                    limites[1][1]=y;
                }
            }
            matriz[x][y]=true;

            //img->setPixel(x,y,sf::Color(255,0,0,255));
            if(x>0)
            {
                if(y<img->getSize().y)
                    floodFillAux(matriz,x-1,y+1,img,menorX,maiorX,menorY,maiorY, limites);

                floodFillAux(matriz,x-1,y,img,menorX,maiorX,menorY,maiorY, limites);

                if(y>0)
                    floodFillAux(matriz,x-1,y-1,img,menorX,maiorX,menorY,maiorY, limites);
            }
            if(y>0)
                floodFillAux(matriz,x,y-1,img,menorX,maiorX,menorY,maiorY, limites);
            if(x+1<img->getSize().x)
            {
                if(y>0)
                    floodFillAux(matriz,x+1,y-1,img,menorX,maiorX,menorY,maiorY, limites);
                floodFillAux(matriz,x+1,y,img,menorX,maiorX,menorY,maiorY, limites);
                if(y<img->getSize().y)
                    floodFillAux(matriz,x+1,y+1,img,menorX,maiorX,menorY,maiorY, limites);
            }
            if(y<img->getSize().y)
                floodFillAux(matriz,x,y+1,img,menorX,maiorX,menorY,maiorY, limites);
        }
    }
}
/*
    So separa o sprite entre os pontos x,y,w e h do arquivo file. Função auxiliar do "criarSpriteSheetIrregular"
*/
void Dados::separarSprite(int x, int y, int w, int h, sf::Image * img, string file)
{
    sf::Sprite sprite;
    sf::Texture *tex = new sf::Texture();

    tex->loadFromImage(*img);
    sprite.setTexture(*tex);

    sprite.setTextureRect(sf::IntRect(x,y,w-x,h-y));

    spriteList.push_back(sprite);
}
/*
    Movimenta o sprite cuja posição na spriteList é igual a "id" oom as velocidades x para o eixo horizontal e y para o eixo vertical
    Utiliza a função "move" da sfml.
*/
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



