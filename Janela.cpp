#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "Janela.h"
#include "Dados.h"
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

void Janela::atualiza(Dados *data, int nivelAtual)
{

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
    }

    for(unsigned int i = 0; i < data->instancias.size(); i++)
    {
//            for()
        data->instancias[i].rodarAnimacao(0);
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

