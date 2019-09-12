#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "Janela.h"
#include "Dados.h"
#include "Base.h"
using namespace std;

Janela* Janela::obj = 0;

Janela* Janela::getInstance()
{
    if(obj)
        return obj;
    else
    {
        obj = new Janela();
        return obj;
    }

}

void Janela::abrir()
{
    window.create(sf::VideoMode(largura, altura), "Janela Padrao");
}

void Janela::fechar()
{
    window.close();
}

bool Janela::janelaAberta()
{
    return window.isOpen();
}

void Janela::atualiza(Dados *data, int nivelAtual, bool *keyPressed)
{

    window.setFramerateLimit(60);
    /*while(window.pollEvent(event))
    {
        //if(event.type == sf::Event::Closed)
          //  window.close();
       /* if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }
    }*/
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }

    if(event.type == sf::Event::KeyReleased)
    {
        switch(event.key.code)
        {
            case TECLA_0:
                keyPressed[TECLA_0] = false;
            break;
            case TECLA_1:
                 keyPressed[TECLA_1] = false;
            break;
            case TECLA_2:
                keyPressed[TECLA_2] = false;
            break;
            case TECLA_3:
                keyPressed[TECLA_3] = false;
            break;
            case TECLA_4:
                 keyPressed[TECLA_4] = false;
            break;
            case TECLA_5:
                 keyPressed[TECLA_5] = false;
            break;
            case TECLA_6:
                 keyPressed[TECLA_6] = false;
            break;
            case TECLA_7:
                 keyPressed[TECLA_7] = false;
            break;
            case TECLA_8:
                 keyPressed[TECLA_8] = false;
            break;
            case TECLA_9:
                 keyPressed[TECLA_9] = false;
            break;
            case TECLA_A:
                 keyPressed[TECLA_A] = false;
            break;
            case TECLA_B:
                 keyPressed[TECLA_B] = false;
            break;
            case TECLA_BACKSPACE:
                 keyPressed[TECLA_BACKSPACE] = false;
            break;
            case TECLA_BAIXO:
                  keyPressed[TECLA_BAIXO] = false;
            break;
            case TECLA_C:
                   keyPressed[TECLA_C] = false;
            break;
            case TECLA_CIMA:
                   keyPressed[TECLA_CIMA] = false;
            break;
            case TECLA_COLCHETE_ABERTO:
                   keyPressed[TECLA_COLCHETE_ABERTO] = false;
            break;
            case TECLA_COLCHETE_FECHADO:
                   keyPressed[TECLA_COLCHETE_FECHADO] = false;
            break;
            case TECLA_D:
                  keyPressed[TECLA_D] = false;
            break;
            case TECLA_Delete:
                  keyPressed[TECLA_Delete] = false;
            break;
            case TECLA_DIREITA:
                  keyPressed[TECLA_DIREITA] = false;
            break;
            case TECLA_DIVISAO:
                   keyPressed[TECLA_DIVISAO] = false;
            break;
            case TECLA_E:
                   keyPressed[TECLA_E] = false;
            break;
            case TECLA_End:
                   keyPressed[TECLA_End] = false;
            break;
            case TECLA_ENTER:
                   keyPressed[TECLA_ENTER] = false;
            break;
            case TECLA_Escape:
                    keyPressed[TECLA_Escape] = false;
            break;
            case TECLA_ESPACO:
                    keyPressed[TECLA_ESPACO] = false;
            break;
            case TECLA_ESQUERDA:
                    keyPressed[TECLA_ESQUERDA] = false;
            break;
            case TECLA_F:
                    keyPressed[TECLA_F] = false;
            break;
            case TECLA_F1:
                    keyPressed[TECLA_F1] = false;
            break;
            case TECLA_F2:
                    keyPressed[TECLA_F2] = false;
            break;
            case TECLA_F3:
                    keyPressed[TECLA_F3] = false;
            break;
            case TECLA_F4:
                    keyPressed[TECLA_F4] = false;
            break;
            case TECLA_F5:
                   keyPressed[TECLA_F5] = false;
            break;
            case TECLA_F6:
                   keyPressed[TECLA_F6] = false;
            break;
            case TECLA_F7:
                    keyPressed[TECLA_F7] = false;
            break;
            case TECLA_F8:
                   keyPressed[TECLA_F8] = false;
            break;
            case TECLA_F9:
                   keyPressed[TECLA_F9] = false;
            break;
            case TECLA_F10:
                   keyPressed[TECLA_F10] = false;
            break;
            case TECLA_F11:
                  keyPressed[TECLA_F11] = false;
            break;
            case TECLA_F12:
                   keyPressed[TECLA_F12] = false;
            break;
            case TECLA_F13:
                   keyPressed[TECLA_F13] = false;
            break;
            case TECLA_F14:
                   keyPressed[TECLA_F14] = false;
            break;
            case TECLA_F15:
                   keyPressed[TECLA_F15] = false;
            break;
            case TECLA_G:
                   keyPressed[TECLA_G] = false;
            break;
            case TECLA_H:
                   keyPressed[TECLA_H] = false;
            break;
            case TECLA_HIFEN:
                   keyPressed[TECLA_HIFEN] = false;
            break;
            case TECLA_Home:
                   keyPressed[TECLA_Home] = false;
            break;
            case TECLA_I:
                   keyPressed[TECLA_I] = false;
            break;
            case TECLA_IGUAL:
                  keyPressed[TECLA_IGUAL] = false;
            break;
            case TECLA_Insert:
                  keyPressed[TECLA_Insert] = false;
            break;
            case TECLA_J:
                   keyPressed[TECLA_J] = false;
            break;
            case TECLA_K:
                    keyPressed[TECLA_K] = false;
            break;
            case TECLA_L:
                   keyPressed[TECLA_L] = false;
            break;
            case TECLA_LAlt:
                   keyPressed[TECLA_LAlt] = false;
            break;
            case TECLA_LControl:
                    keyPressed[TECLA_LControl] = false;
            break;
            case TECLA_LShift:
                   keyPressed[TECLA_LShift] = false;
            break;
            case TECLA_LSystem:
                    keyPressed[TECLA_LSystem] = false;
            break;
            case TECLA_M:
                   keyPressed[TECLA_M] = false;
            break;
            case TECLA_Menu:
                    keyPressed[TECLA_Menu] = false;
            break;
            case TECLA_MULTIPLICACAO:
                    keyPressed[TECLA_MULTIPLICACAO] = false;
            break;
            case TECLA_N:
                  keyPressed[TECLA_N] = false;
            break;
            case TECLA_O:
                    keyPressed[TECLA_O] = false;
            break;
            case TECLA_P:
                   keyPressed[TECLA_P] = false;
            break;
            case TECLA_PageDown:
                   keyPressed[TECLA_PageDown] = false;
            break;
            case TECLA_PageUp:
                    keyPressed[TECLA_PageUp] = false;
            break;
            case TECLA_PONTO:
                   keyPressed[TECLA_PONTO] = false;
            break;
            case TECLA_PONTO_E_VIRGULAR:
                   keyPressed[TECLA_PONTO_E_VIRGULAR] = false;
            break;
            case TECLA_Q:
                    keyPressed[TECLA_Q] = false;
            break;
            case TECLA_R:
                   keyPressed[TECLA_R] = false;
            break;
            case TECLA_RAlt:
                   keyPressed[TECLA_RAlt] = false;
            break;
            case TECLA_RControl:
                   keyPressed[TECLA_RControl] = false;
            break;
            case TECLA_RShift:
                   keyPressed[TECLA_RShift] = false;
            break;
            case TECLA_RSystem:
                  keyPressed[TECLA_RSystem] = false;
            break;
            case TECLA_S:
                   keyPressed[TECLA_S] = false;
            break;
            case TECLA_SOMA:
                   keyPressed[TECLA_SOMA] = false;
            break;
            case TECLA_SUBTRACAO:
                   keyPressed[TECLA_SUBTRACAO] = false;
            break;
            case TECLA_T:
                  keyPressed[TECLA_T] = false;
            break;
            case TECLA_TAB:
                 keyPressed[TECLA_TAB] = false;
            break;
            case TECLA_TIL:
                   keyPressed[TECLA_TIL] = false;
            break;
            case TECLA_U:
                   keyPressed[TECLA_U] = false;
            break;
            case TECLA_V:
                 keyPressed[TECLA_V] = false;
            break;
            case TECLA_VIRGULA:
                  keyPressed[TECLA_VIRGULA] = false;
            break;
            case TECLA_W:
                   keyPressed[TECLA_W] = false;
            break;
            case TECLA_X:
                   keyPressed[TECLA_X] = false;
            break;
            case TECLA_Y:
                   keyPressed[TECLA_Y] = false;
            break;
            case TECLA_Z:
                   keyPressed[TECLA_Z] = false;
            break;
        }

    }



        //window.setKeyRepeatEnabled(false);
        //if(event.type == sf::Event::KeyPressed)

    }

    for(unsigned int i = 0; i < data->instancias.size(); i++)
    {
//            for()
        if(data->instancias[i].getAtivo())
        data->instancias[i].rodarAnimacao(data->instancias[i].animacaoAtual);
    }

    // cout<<data->instancias.size()<<endl;
    if(data->niveis.size()>0)
        if(data->niveis[nivelAtual].cam->tipoCam!=PADRAO_ORIGINAL)
            switch(data->niveis[nivelAtual].cam->tipoCam)
            {
            case PADRAO_JOGADOR:
                data->niveis[nivelAtual].padraoCameraJogador(data->instancias[0]);
                break;
            case PADRAO_HORIZONTAL:
                data->niveis[nivelAtual].padraoCameraHorizontal(data->instancias[0]);
                break;
            case PADRAO_VERTICAL:
                data->niveis[nivelAtual].padraoCameraVertical(data->instancias[0]);
                break;
            case PADRAO_SALAS:
                data->niveis[nivelAtual].padraoCameraSalas(data->instancias[0]);
                break;
            }
    //  data->niveis[nivelAtual].padraoCameraVertical(data->instancias[0]);
    window.clear();
    ///window.setView(data->cameras[0].camera);
    if(data->niveis.size()>0)
    {
        window.setView(data->niveis[nivelAtual].cam->camera);
        // window.draw(data->background);
        window.draw(data->niveis[nivelAtual].background);
    }



    for(unsigned int i = 0; i < data->instancias.size(); i++)
    {
        //window.draw(data->spriteList[i]);
        //cout<<i<<endl;
        if(data->instancias[i].getAtivo())
        window.draw(data->instancias[i].sprite);
    }

    window.display();
}

void Janela::setAltura(int alt)
{
    altura = alt;
}
void Janela::setLargura(int larg)
{
    largura = larg;
}

float Janela::getAltura()
{
    return altura;
}

float Janela::getLargura()
{
    return largura;
}

/*void Janela::rodar()
{
    Dados *data = Dados::getInstance();
    initCallback();
    while(window.isOpen())
    {
        updateCallback();
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
        }
        //updateCallback();
        window.clear(sf::Color::Green);

        window.draw(data->background);
        for(unsigned int i = 0; i < data->spriteList.size(); i++)
        {
            window.draw(data->spriteList[i]);
        }

        window.display();
    }
}*/

