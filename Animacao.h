#ifndef ANIMACAO_H_INCLUDED
#define ANIMACAO_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <string>

struct AnimationFrame
{
    int x, y;
    int dx, dy;
};

class Animation{

private:
    clock_t deltaTime;
    clock_t timer;
    std::vector<AnimationFrame> frames;
    int frameId;

public:
    Animation(clock_t timer, clock_t framesDuration);

    clock_t getTimer();
    void setTimer(clock_t timer);
    std::vector<sf::Texture*> &getFrames();
    void setFrames();
    clock_t getDeltaTime();
    void setDeltaTime(clock_t deltaTime);
    void animationRun();
    void criarAnimacaoDeArquivoRegular(std::string file,int divX, int divY);
    AnimationFrame rodarAnimacaoDeArquivoRegular(std::string file, int divX, int divY);

     ~Animation();
};


#endif // ANIMACAO_H_INCLUDED