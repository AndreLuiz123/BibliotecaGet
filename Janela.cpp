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

void Janela::atualiza(Dados *data)
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
        if(data->niveis[0].cam.tipoCam!=PADRAO_ORIGINAL)
            switch(data->niveis[0].cam.tipoCam)
            {
            case PADRAO_JOGADOR:
                data->niveis[0].padraoCameraJogador(data->instancias[0]);
                break;
            case PADRAO_HORIZONTAL:
                data->niveis[0].padraoCameraHorizontal(data->instancias[0]);
                break;
            case PADRAO_VERTICAL:
                data->niveis[0].padraoCameraVertical(data->instancias[0]);
                break;
            case PADRAO_SALAS:
                data->niveis[0].padraoCameraSalas(data->instancias[0]);
                break;
            }
    //  data->niveis[0].padraoCameraVertical(data->instancias[0]);
    window.clear();
    ///window.setView(data->cameras[0].camera);
    if(data->niveis.size()>0)
    {
        window.setView(data->niveis[0].cam.camera);
        // window.draw(data->background);
        window.draw(data->niveis[0].background);
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

