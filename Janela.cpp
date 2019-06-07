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
        window.clear();
       // window.draw(data->background);
        for(unsigned int i = 0; i < data->instancias.size(); i++)
        {
            //window.draw(data->spriteList[i]);
            //cout<<i<<endl;
            window.draw(data->instancias[i].sprite);
        }

        window.display();
}

void Janela::setAltura(int alt){
    altura = alt;
}
void Janela::setLargura(int larg){
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

