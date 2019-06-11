#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

enum TIPO_CAMERA {

    PADRAO_JOGADOR,
    PADRAO_HORIZONTAL,
    PADRAO_VERTICAL,
    PADRAO_SALAS,
    PADRAO_JOGADOR_ALT,
    PADRAO_ORIGINAL,

};

class Camera{

private:

public:
    sf::View camera;
    TIPO_CAMERA tipoCam;
    Camera(float x=0, float y=0, float width=300, float height=200, TIPO_CAMERA tipoCamera=PADRAO_JOGADOR);
    //Camera();
    void moveCamera(float dx, float dy);
    void movePara(float x, float y);
    void rotacionaCamera(float angulo);
    void setOrientacao(float angulo);
    void zoom(float z);
    void colocaDistancia(float x, float y);
};


#endif // CAMERA_H_INCLUDED
