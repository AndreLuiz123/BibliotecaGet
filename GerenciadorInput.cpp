#include <iostream>
#include "GerenciadorInput.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

GerenciadorInput* GerenciadorInput::objt = 0;

GerenciadorInput::GerenciadorInput(){
    for(int i = 0; i<86; i++)
    justPressedKeys[i] = false;
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

bool GerenciadorInput::teclaJustPressed(int tecla)
{

 if(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(tecla))){
    if(justPressedKeys[tecla] == false)
    {
        justPressedKeys[tecla] = true;
        return teclaPressionada(tecla);
    }
    return false;
 }
    return false;
}

/*bool GerenciadorInput::teclaLargada(int tecla, sf::Event event, sf::RenderWindow &window){

    if(event.type == sf::Event::KeyReleased)
    {
    switch(tecla)
    {
    case TECLA_0:
           return true;
    break;
    case TECLA_1:
           return true;

    return true;
    break;
    case TECLA_2:
           return true;

    break;
    case TECLA_3:

           return true;
    break;
    case TECLA_4:

           return true;
    break;
    case TECLA_5:

           return true;
    break;
    case TECLA_6:

           return true;
    break;
    case TECLA_7:

    {

           return true;
    }
    break;
    case TECLA_8:

    {

           return true;
    }
    break;
    case TECLA_9:

    {

           return true;
    }
    break;
    case TECLA_A:
 if(tecla == event.key.code)
    {

           return true;
    }
    break;
    case TECLA_B:

    {

           return true;
    }
    break;
    case TECLA_BACKSPACE:

    {

           return true;
    }
    break;
    case TECLA_BAIXO:

    {

           return true;
    }
    break;
    case TECLA_C:

    {

           return true;
    }
    break;
    case TECLA_CIMA:

    {

           return true;
    }
    break;
    case TECLA_COLCHETE_ABERTO:

    {

           return true;
    }
    break;
    case TECLA_COLCHETE_FECHADO:

    {

           return true;
    }
    break;
    case TECLA_D:

    {

           return true;
    }
    break;
    case TECLA_Delete:

    {

           return true;
    }
    break;
    case TECLA_DIREITA:

    {

           return true;
    }
    break;
    case TECLA_DIVISAO:

    {

           return true;
    }
    break;
    case TECLA_E:

    {

           return true;
    }
    break;
    case TECLA_End:

    {

           return true;
    }
    break;
    case TECLA_ENTER:

    {

           return true;
    }
    break;
    case TECLA_Escape:

    {

           return true;
    }
    break;
    case TECLA_ESPACO:

    {

           return true;
    }
    break;
    case TECLA_ESQUERDA:

    {

           return true;
    }
    break;
    case TECLA_F:

    {

           return true;
    }
    break;
    case TECLA_F1:

    {

           return true;
    }
    break;
    case TECLA_F2:

    {

           return true;
    }
    break;
    case TECLA_F3:

    {

           return true;
    }
    break;
    case TECLA_F4:

    {

           return true;
    }
    break;
    case TECLA_F5:

    {

           return true;
    }
    break;
    case TECLA_F6:

    {

           return true;
    }
    break;
    case TECLA_F7:

    {

           return true;
    }
    break;
    case TECLA_F8:

    {

           return true;
    }
    break;
    case TECLA_F9:

    {

           return true;
    }
    break;
    case TECLA_F10:

    {

           return true;
    }
    break;
    case TECLA_F11:

    {

           return true;
    }
    break;
    case TECLA_F12:

    {

           return true;
    }
    break;
    case TECLA_F13:

    {

           return true;
    }
    break;
    case TECLA_F14:

    {

           return true;
    }
    break;
    case TECLA_F15:

    {

           return true;
    }
    break;
    case TECLA_G:

    {

           return true;
    }
    break;
    case TECLA_H:

    {

           return true;
    }
    break;
    case TECLA_HIFEN:

    {

           return true;
    }
    break;
    case TECLA_Home:

    {

           return true;
    }
    break;
    case TECLA_I:

    {

           return true;
    }
    break;
    case TECLA_IGUAL:

    {

           return true;
    }
    break;
    case TECLA_Insert:

    {

           return true;
    }
    break;
    case TECLA_J:

    {

           return true;
    }
    break;
    case TECLA_K:

    {

           return true;
    }
    break;
    case TECLA_L:

    {

           return true;
    }
    break;
    case TECLA_LAlt:

    {

           return true;
    }
    break;
    case TECLA_LControl:

    {

           return true;
    }
    break;
    case TECLA_LShift:

    {

           return true;
    }
    break;
    case TECLA_LSystem:

    {

           return true;
    }
    break;
    case TECLA_M:

    {

           return true;
    }
    break;
    case TECLA_Menu:

    {

           return true;
    }
    break;
    case TECLA_MULTIPLICACAO:

    {

           return true;
    }
    break;
    case TECLA_N:

    {

           return true;
    }
    break;
    case TECLA_O:

    {

           return true;
    }
    break;
    case TECLA_P:

    {

           return true;
    }
    break;
    case TECLA_PageDown:

    {

           return true;
    }
    break;
    case TECLA_PageUp:

    {

           return true;
    }
    break;
    case TECLA_PONTO:

    {

           return true;
    }
    break;
    case TECLA_PONTO_E_VIRGULAR:

    {

           return true;
    }
    break;
    case TECLA_Q:

    {

           return true;
    }
    break;
    case TECLA_R:

    {

           return true;
    }
    break;
    case TECLA_RAlt:

    {

           return true;
    }
    break;
    case TECLA_RControl:

    {

           return true;
    }
    break;
    case TECLA_RShift:

    {

           return true;
    }
    break;
    case TECLA_RSystem:

    {

           return true;
    }
    break;
    case TECLA_S:

    {

           return true;
    }
    break;
    case TECLA_SOMA:

    {

           return true;
    }
    break;
    case TECLA_SUBTRACAO:

    {

           return true;
    }
    break;
    case TECLA_T:

    {

           return true;
    }
    break;
    case TECLA_TAB:

    {

           return true;
    }
    break;
    case TECLA_TIL:

    {

           return true;
    }
    break;
    case TECLA_U:

    {

           return true;
    }
    break;
    case TECLA_V:

    {

           return true;
    }
    break;
    case TECLA_VIRGULA:

    {

           return true;
    }
    break;
    case TECLA_W:

    {

           return true;
    }
    break;
    case TECLA_X:

    {

           return true;
    }
    break;
    case TECLA_Y:

    {

           return true;
    }
    break;
    case TECLA_Z:

    {

           return true;
    }
    break;
    default:
    return false;
    break;
    }
    }

    return false;
}

bool GerenciadorInput::pressionarTeclaUmaVez(int tecla, sf::Event event, sf::RenderWindow &window){

   // window.setKeyRepeatEnabled(false);
    if(event.type == sf::Event::KeyPressed)
    {
    switch(event.key.code)
    {
    case TECLA_0:

    {

           return true;
    }
    break;
    case TECLA_1:

    {

           return true;
    }
    return true;
    break;
    case TECLA_2:

    {

           return true;
    }
    break;
    case TECLA_3:

    {

           return true;
    }
    break;
    case TECLA_4:

    {

           return true;
    }
    break;
    case TECLA_5:

    {

           return true;
    }
    break;
    case TECLA_6:

    {

           return true;
    }
    break;
    case TECLA_7:

    {

           return true;
    }
    break;
    case TECLA_8:

    {

           return true;
    }
    break;
    case TECLA_9:

    {

           return true;
    }
    break;
    case TECLA_A:
 if(tecla == event.key.code)
    {

           return true;
    }
    break;
    case TECLA_B:

    {

           return true;
    }
    break;
    case TECLA_BACKSPACE:

    {

           return true;
    }
    break;
    case TECLA_BAIXO:

    {

           return true;
    }
    break;
    case TECLA_C:

    {

           return true;
    }
    break;
    case TECLA_CIMA:

    {

           return true;
    }
    break;
    case TECLA_COLCHETE_ABERTO:

    {

           return true;
    }
    break;
    case TECLA_COLCHETE_FECHADO:

    {

           return true;
    }
    break;
    case TECLA_D:

    {

           return true;
    }
    break;
    case TECLA_Delete:

    {

           return true;
    }
    break;
    case TECLA_DIREITA:

    {

           return true;
    }
    break;
    case TECLA_DIVISAO:

    {

           return true;
    }
    break;
    case TECLA_E:

    {

           return true;
    }
    break;
    case TECLA_End:

    {

           return true;
    }
    break;
    case TECLA_ENTER:

    {

           return true;
    }
    break;
    case TECLA_Escape:

    {

           return true;
    }
    break;
    case TECLA_ESPACO:

    {

           return true;
    }
    break;
    case TECLA_ESQUERDA:

    {

           return true;
    }
    break;
    case TECLA_F:

    {

           return true;
    }
    break;
    case TECLA_F1:

    {

           return true;
    }
    break;
    case TECLA_F2:

    {

           return true;
    }
    break;
    case TECLA_F3:

    {

           return true;
    }
    break;
    case TECLA_F4:

    {

           return true;
    }
    break;
    case TECLA_F5:

    {

           return true;
    }
    break;
    case TECLA_F6:

    {

           return true;
    }
    break;
    case TECLA_F7:

    {

           return true;
    }
    break;
    case TECLA_F8:

    {

           return true;
    }
    break;
    case TECLA_F9:

    {

           return true;
    }
    break;
    case TECLA_F10:

    {

           return true;
    }
    break;
    case TECLA_F11:

    {

           return true;
    }
    break;
    case TECLA_F12:

    {

           return true;
    }
    break;
    case TECLA_F13:

    {

           return true;
    }
    break;
    case TECLA_F14:

    {

           return true;
    }
    break;
    case TECLA_F15:

    {

           return true;
    }
    break;
    case TECLA_G:

    {

           return true;
    }
    break;
    case TECLA_H:

    {

           return true;
    }
    break;
    case TECLA_HIFEN:

    {

           return true;
    }
    break;
    case TECLA_Home:

    {

           return true;
    }
    break;
    case TECLA_I:

    {

           return true;
    }
    break;
    case TECLA_IGUAL:

    {

           return true;
    }
    break;
    case TECLA_Insert:

    {

           return true;
    }
    break;
    case TECLA_J:

    {

           return true;
    }
    break;
    case TECLA_K:

    {

           return true;
    }
    break;
    case TECLA_L:

    {

           return true;
    }
    break;
    case TECLA_LAlt:

    {

           return true;
    }
    break;
    case TECLA_LControl:

    {

           return true;
    }
    break;
    case TECLA_LShift:

    {

           return true;
    }
    break;
    case TECLA_LSystem:

    {

           return true;
    }
    break;
    case TECLA_M:

    {

           return true;
    }
    break;
    case TECLA_Menu:

    {

           return true;
    }
    break;
    case TECLA_MULTIPLICACAO:

    {

           return true;
    }
    break;
    case TECLA_N:

    {

           return true;
    }
    break;
    case TECLA_O:

    {

           return true;
    }
    break;
    case TECLA_P:

    {

           return true;
    }
    break;
    case TECLA_PageDown:

    {

           return true;
    }
    break;
    case TECLA_PageUp:

    {

           return true;
    }
    break;
    case TECLA_PONTO:

    {

           return true;
    }
    break;
    case TECLA_PONTO_E_VIRGULAR:

    {

           return true;
    }
    break;
    case TECLA_Q:

    {

           return true;
    }
    break;
    case TECLA_R:

    {

           return true;
    }
    break;
    case TECLA_RAlt:

    {

           return true;
    }
    break;
    case TECLA_RControl:

    {

           return true;
    }
    break;
    case TECLA_RShift:

    {

           return true;
    }
    break;
    case TECLA_RSystem:

    {

           return true;
    }
    break;
    case TECLA_S:

    {

           return true;
    }
    break;
    case TECLA_SOMA:

    {

           return true;
    }
    break;
    case TECLA_SUBTRACAO:

    {

           return true;
    }
    break;
    case TECLA_T:

    {

           return true;
    }
    break;
    case TECLA_TAB:

    {

           return true;
    }
    break;
    case TECLA_TIL:

    {

           return true;
    }
    break;
    case TECLA_U:

    {

           return true;
    }
    break;
    case TECLA_V:

    {

           return true;
    }
    break;
    case TECLA_VIRGULA:

    {

           return true;
    }
    break;
    case TECLA_W:

    {

           return true;
    }
    break;
    case TECLA_X:

    {

           return true;
    }
    break;
    case TECLA_Y:

    {

           return true;
    }
    break;
    case TECLA_Z:

    {

           return true;
    }
    break;
    default:
    return false;
    break;
    }
    }

    return false;
}*/

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
