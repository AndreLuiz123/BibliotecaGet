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
    window.create(sf::VideoMode(800, 600), "Janela Padrao");
}
void Janela::fechar()
{
    window.close();
}
bool Janela::estaAberta()
{
    return window.isOpen();
}
void Janela::rodar()
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
}
