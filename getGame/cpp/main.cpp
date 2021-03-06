#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include "Base.h"
#include "Dados.h"
#include "Janela.h"

using namespace std;

enum Teclas
{
    SETA_CIMA = 1,
    SETA_ESQUERDA = 2,
    SETA_BAIXO = 3,
    SETA_DIREITA = 4
};

void inicializa()
{
    int id = criarSprite("nave.png");
    posicaoSprite(id, 300, 300);
    escalaSprite(id, 0.1);
    criarBackground("background.png");
}

void atualiza()
{
    float speed = 0.5;
    if(verificaTeclaPressionada(SETA_CIMA))
    {
        moveSprite(0, 0, -speed);
    }
    if(verificaTeclaPressionada(SETA_ESQUERDA))
    {
        moveSprite(0, -speed, 0);
    }
    if(verificaTeclaPressionada(SETA_BAIXO))
    {
        moveSprite(0, 0, speed);
    }
    if(verificaTeclaPressionada(SETA_DIREITA))
    {
        moveSprite(0, speed, 0);
    }
}

int main()
{
    //srand(time(NULL));
    inicializar();
    setInitCallback(inicializa);
    setUpdateCallback(atualiza);
    rodar();

    //delete d;
    return 0;
}
