#include "Camera.h"
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <string.h>

Camera::Camera(float x, float y, float width, float height, TIPO_CAMERA tipoCamera){
    camera.setCenter(sf::Vector2f(x,y));
    camera.setSize(sf::Vector2f(width, height));
    tipoCam = tipoCamera;
    std::cout<<camera.getViewport().width<<std::endl;
}
void Camera::moveCamera(float dx, float dy){
    camera.move(dx, dy);
}
void Camera::movePara(float x, float y){
    camera.setCenter(x,y);
}
void Camera::rotacionaCamera(float angulo){
    camera.rotate(angulo);
}
void Camera::setOrientacao(float angulo){
    camera.setRotation(angulo);
}
void Camera::zoom(float z){
    camera.zoom(z);
   // std::cout<<camera.getViewport().width<<std::endl;
}
void Camera::colocaTamanhoCamera(float x, float y){
    camera.setSize(sf::Vector2f(x,y));
   // std::cout<<camera.getViewport().width<<std::endl;
}
void Camera::mudarPadraoCamera(TIPO_CAMERA padrao){
    tipoCam = padrao;
}
