#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include "Animacao.h"

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

AnimationFrame Animation::rodarAnimacaoDeArquivoRegular(std::string file, int divX, int divY){

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

Animation::~Animation()
{

}
