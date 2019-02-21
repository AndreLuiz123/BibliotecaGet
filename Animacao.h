#ifndef ANIMACAO_H_INCLUDED
#define ANIMACAO_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>

class Animation{

private:
    clock_t deltaTime;
    clock_t timer;
    std::vector<sf::Texture> frames;
    int frameId;

public:
    Animation(clock_t timer, std::vector<sf::Texture> frames, clock_t framesDuration);

    clock_t getTimer();
    void setTimer(clock_t timer);
    std::vector<sf::Texture> getFrames();
    void setFrames(std::vector<sf::Texture> frames);
    clock_t getDeltaTime();
    void setDeltaTime(clock_t deltaTime);
    sf::Texture* animationRun();

     ~Animation();
};

#endif // ANIMACAO_H_INCLUDED
