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
#include "andewSay.h"
struct AnimationFrame
{
    int x, y;
    int dx, dy;
};

class Animation{

private:
    clock_t deltaTime;
    clock_t timer;

    int frameId;

public:
    std::string arquivoDaAnimacao;
    sf::Texture arquivoAnimacao;
    Animation(clock_t timer, clock_t framesDuration);

    clock_t getTimer();
    void setTimer(clock_t timer);
    std::vector<sf::Texture*> &getFrames();
    std::vector<AnimationFrame> frames;
    void setFrames();
    clock_t getDeltaTime();
    void setDeltaTime(clock_t deltaTime);
    void animationRun();
    void criarAnimacaoDeArquivoRegular(std::string file,int divX, int divY);
    void criarAnimacaoDeArquivoIrregular(std::string file);
    AnimationFrame squareGrowing(int pixelX, int pixelY, int pixelDX, int pixelDY, sf::Image *img, bool ** matriz);
    void criarAnimacaoComParteDeArquivo(std::string file, int divX, int divY, int linha1, int linha2);
    AnimationFrame rodarAnimacaoDeArquivoRegular(std::string file);
    void trocarPosicaoFrames(int frame1, int frame2);
    void apagarFrame(int frame);
    static bool compara(AnimationFrame &a1, AnimationFrame &a2);
    static bool comparaY(AnimationFrame &a1, AnimationFrame &a2);
    void definirFrameManualmente(int x, int y, int dx, int dy);
    void criarFrameManualmente(int x, int y, int dx, int dy);
    void associarArquivoAnimacao(std::string arquivo);

     ~Animation();
};


#endif // ANIMACAO_H_INCLUDED
