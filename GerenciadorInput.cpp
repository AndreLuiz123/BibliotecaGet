#include <iostream>
#include "GerenciadorInput.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

GerenciadorInput* GerenciadorInput::objt = 0;

GerenciadorInput::GerenciadorInput(){
}

GerenciadorInput* GerenciadorInput::getInstance()
{
    if(objt)
        return objt;
    else
    {
        objt = new GerenciadorInput();
        return objt;
    }

}

bool GerenciadorInput::teclaPressionada(int tecla){

    if(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(tecla))){
//        cout<<"tecla "<<static_cast<TECLADO>(tecla)<<" pressionada"<<endl;
        return true;
    }else{
        return false;
    }
}

bool GerenciadorInput::mousePressionado(int botaoMouse){


    if(sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(botaoMouse))){
//        cout<<"tecla "<<static_cast<TECLADO>(tecla)<<" pressionada"<<endl;
        return true;
    }else{
        return false;
    }
}

bool GerenciadorInput::intervaloPosicaoMouse(int x1, int x2, int y1, int y2){///mouseNoIntervalo() <- NOVO NOME

    posMouse.posX = sf::Mouse::getPosition().x;
    posMouse.posY = sf::Mouse::getPosition().y;

    if(posMouse.posX>x1&&posMouse.posX<x2&&posMouse.posY<y2&&posMouse.posY<y2)
        return true;
    else
        return false;

}

sf::Vector2i GerenciadorInput::retornaPosicaoMouse(){
    return sf::Mouse::getPosition();
}
