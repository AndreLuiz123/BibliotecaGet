#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include "Animacao.h"
#include <stack>

Animation::Animation(clock_t timer, clock_t framesDuration)
{
    this->timer = timer;
//    this->frames = &frames;
    this->deltaTime = framesDuration;
    this->frameId = 0;

}

clock_t Animation::getTimer()
{
    return timer;
}

void Animation::setTimer(clock_t timer)
{
    this->timer = timer;
}

std::vector<sf::Texture*> &Animation::getFrames()
{
//    return *frames;
}

void Animation::setFrames()
{
//    this->frames = &frames;
}

clock_t Animation::getDeltaTime()
{
    return deltaTime;
}

void Animation::setDeltaTime(clock_t deltaTime)
{
    this->deltaTime = deltaTime;
}


void Animation::animationRun()
{

    if(frameId==frames.size())
    {
        frameId=0;
    }

    if(clock() - timer > deltaTime)
    {
        timer=clock();
        frameId++;
    }

    //return frames[frameId];
}


void Animation::criarAnimacaoDeArquivoRegular(std::string file,int divX, int divY)
{

    sf::Texture *tex = new sf::Texture();
    std::cout << "Created " << tex << std::endl;
    tex->loadFromFile(file);

    for(int i=0; i<divY; i++)
    {
        for(int j=0; j<divX; j++)
        {
            AnimationFrame frame;
            frame.dx = tex->getSize().x/divX;
            frame.dy = tex->getSize().y/divY;

            frame.x = j*frame.dx;
            frame.y = i*frame.dy;

            frames.push_back(frame);

        }
    }

    std::cout<<frames.size()<<std::endl;

}

void Animation::criarAnimacaoDeArquivoIrregular(std::string file)
{

    sf::Image *img = new sf::Image();
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
std::cout<<"arquivo irregular"<<std::endl;
    for(int j=0; j<img->getSize().y; j++)
    {
        for(int i=0; i<img->getSize().x; i++)
        {

            if(matrizFloodFill[i][j]==false)
            {
                if(img->getPixel(i,j).a > 100)
                {
                    AnimationFrame frame;
                    frame = squareGrowing(i,j,1,1,img,matrizFloodFill);
                    frames.push_back(frame);
                    //  std::cout<<i<<" "<<j<<std::endl;
                }else{
                    matrizFloodFill[i][j]=true;
                }
            }
        }
    }

}

/*AnimationFrame buscaEmProfundidade(AnimationFrame frame, bool **matriz, sf::Image img)
{
    stack<sf::Color> pilhaBusca;

    if(img.getPixel(i,j).a>100 && !matriz[i][j])///Se o pixel visitado não ser transparente e não foi visitado ainda
    {
        pilhaBusca.push(img.getPixel(i,j));///Coloca o pixel na pilha
        matriz[i][j]=true;///Marca o pixel como visitado

        if(i>frame.x + frame.dx)///Se o pixel em questão é maior que o limite superior do sprite, então o pixel é o novo limite superior em x
        {
            frame.dx = frame.x - i;
        }else
        {
            if(i<frame.x)///Se o pixel em questão é menor que o limite inferior do sprite, então o pixel é o novo limite inferior em x
            {
             frame.x = i;
            }
        }

        if(j>frame.y + frame.dy)///Se o pixel em questão é maior que o limite superior do sprite, então o pixel é o novo limite superior em y
        {
            frame.dy = frame.y - j;
        }else
        {
            if(j<frame.y)///Se o pixel em questão é menor que o limite inferior do sprite, então o pixel é o novo limite inferior em y
            {
             frame.y = j;
            }
        }
    }else///Se o pixel for transparente ou ja foi visitado, volta um nivel da pilha
    {
        pilhaBusca.pop();
    }


}*/


AnimationFrame Animation::squareGrowing(int pixelX, int pixelY, int pixelDX, int pixelDY, sf::Image *img, bool **matriz)
{
     AnimationFrame newFrame;
     bool borda = true;
     int i;

     while(borda){

        borda = false;

        for(i=pixelX; i<pixelX+pixelDX; i++)
        {
           if(img->getPixel(i, pixelY).a>100 && pixelY>2)
           {
                pixelY--;
                borda=true;
           }
        }

        for(i=pixelX; i<pixelX+pixelDX; i++)
        {
           if(img->getPixel(i, pixelY+pixelDY).a>100 && pixelY+pixelDY<img->getSize().y-2)
           {
                pixelDY++;
                borda=true;
           }
        }

        for(i=pixelY; i<pixelY+pixelDY; i++)
        {
            if(img->getPixel(pixelX,i).a>100 && pixelX>2)
           {
                pixelX--;
                borda=true;
           }
        }

        for( i=pixelY; i<pixelY+pixelDY; i++)
        {
           if(img->getPixel(pixelX+pixelDX,i).a>100 && pixelX + pixelDX<img->getSize().x-2)
           {
                pixelDX++;
                borda=true;
           }
        }

     }

    for(int u=pixelX; u<pixelX+pixelDX; u++)
    {
        for(int t=pixelY; t<pixelY+pixelDY; t++)
        {
            matriz[u][t]=true;
        }
    }


    std::cout<<pixelDX<<std::endl;

    newFrame.x  = pixelX;
    newFrame.y  = pixelY;
    newFrame.dx = pixelDX;
    newFrame.dy = pixelDY;

    return newFrame;
}


AnimationFrame Animation::rodarAnimacaoDeArquivoRegular(std::string file){

    //criarAnimacaoDeArquivoRegular(file,divX,divY);

    if(frameId==frames.size())
    {
        frameId=0;
    }

    if(clock() - timer > deltaTime)
    {
        timer=clock();
        frameId++;
    }

    return frames[frameId];

}

void Animation::criarAnimacaoComParteDeArquivo(std::string file, int divX, int divY, int linha1, int linha2){

    sf::Texture *tex = new sf::Texture();
    std::cout << "Created " << tex << std::endl;
    tex->loadFromFile(file);

     for(int i=linha1; i<linha2; i++)
    {
        for(int j=0; j<divX; j++)
        {
            AnimationFrame frame;
            frame.dx = tex->getSize().x/divX;
            frame.dy = tex->getSize().y/divY;

            frame.x = j*frame.dx;
            frame.y = i*frame.dy;

            frames.push_back(frame);

        }
    }


}

Animation::~Animation()
{

}
