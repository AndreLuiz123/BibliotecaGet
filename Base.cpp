#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cmath>
#include "Base.h"
#include "Janela.h"
#include "Dados.h"
using namespace std;

void inicializar()
{
    Janela *janela = Janela::getInstance();
    janela->abrir();
}

void finalizarJogo()
{
    Janela *janela = Janela::getInstance();
    janela->fechar();
}

int criarSprite(string file)
{
    Dados *data = Dados::getInstance();
    return data->criarSprite(file);
}

int criarSpriteSheet(string file, int divX, int divY)
{
    Dados *data = Dados::getInstance();
    return data->criarSpriteSheet(file, divX, divY);
}

int criarSpriteSheetIrregular(string file)
{
    Dados *data = Dados::getInstance();
    return data->criarSpriteSheetIrregular(file);
}

void posicaoSprite(int id, float x, float y)
{
    Dados *data = Dados::getInstance();
    data->setaPosicaoSpr(id, x, y);
}

void escalaSprite(int id, float e)
{
    Dados *data = Dados::getInstance();
    data->setaEscalaSpr(id, e);
}
void criarRetangulo()
{
    Dados *data = Dados::getInstance();
    data->criarRet();
}

void posicaoRetangulo(int id, float x, float y)
{
    Dados *data = Dados::getInstance();
    data->setaPosicaoRet(id, x, y);
}
void tamanhoRetangulo(int id, float l, float h)
{
    Dados *data = Dados::getInstance();
    data->setaTamRet(id, l, h);
}
void criarCirculo()
{
    Dados *data = Dados::getInstance();
    data->criarCir();
}
void posicaoCirculo(int id, float x, float y)
{
    Dados *data = Dados::getInstance();
    data->setaPosicaoCir(id, x, y);
}
void raioCirculo(int id, float r)
{
    Dados *data = Dados::getInstance();
    data->setaRaioCir(id, r);
}

void criarBackground(string file)
{
    Dados *data = Dados::getInstance();
    data->criarBackground(file);
}

void rodar()
{
    Janela *janela = Janela::getInstance();
    janela->rodar();

}

bool janelaAberta()
{
    Janela *janela = Janela::getInstance();
    return janela->estaAberta();
}

bool verificaTeclaPressionada(int id)
{
    switch (id){
    case 1:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            return true;
        }
        else{
            return false;
        }
        break;
    case 2:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            return true;
        }
        else{
            return false;
        }
        break;
    case 3:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            return true;
        }
        else{
            return false;
        }
        break;
    case 4:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            return true;
        }
        else{
            return false;
        }
        break;
    }

}
void moveSprite(int id, float dirX, float dirY)
{
    Dados *data = Dados::getInstance();
    data->moveSprite(id, dirX, dirY);
}

void setUpdateCallback(void (*pointer)(void))
{
    Janela *janela = Janela::getInstance();
    janela->setUpdateCallback(pointer);
}
void setInitCallback(void (*pointer)(void))
{
    Janela *janela = Janela::getInstance();
    janela->setInitCallback(pointer);
}
