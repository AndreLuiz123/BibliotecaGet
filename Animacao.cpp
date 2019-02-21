#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include "Animacao.h"

Animation::Animation(clock_t timer, std::vector<sf::Texture> frames, clock_t framesDuration)
{

    this->timer = timer;
    this->frames = frames;
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

std::vector<sf::Texture> Animation::getFrames()
{
    return frames;
}

void Animation::setFrames(std::vector<sf::Texture> frames)
{
    this->frames = frames;
}

clock_t Animation::getDeltaTime()
{
    return deltaTime;
}

void Animation::setDeltaTime(clock_t deltaTime)
{
    this->deltaTime = deltaTime;
}

sf::Texture* Animation::animationRun()
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

    return &frames[frameId];
}

Animation::~Animation()
{
}
