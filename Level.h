#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "Instancia.h"
#include "Camera.h"
#include <vector>

class Level{

private:
    float width, height;
public:
    Camera cam;
    sf::Sprite background;
    Level(std::string fileBackground, float largura, float altura, Camera camera);
    TIPO_CAMERA padraoCamera();
    void padraoCameraJogador(Instancia inst);
    void padraoCameraHorizontal(Instancia inst);
    void padraoCameraVertical(Instancia inst);
    void padraoCameraSalas(Instancia insto);
    void definirPosicaoInicialCamera(float x, float y);
};

#endif // LEVEL_H_INCLUDED
