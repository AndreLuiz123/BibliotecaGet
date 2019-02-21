#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include "Base.h"
#include "Dados.h"
#include "Janela.h"

using namespace std;
//TESTE ANDRE
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
    //criarBackground("background.png");
}

void atualiza()
{
    int id = 1;
    int timer = 0;
    float speed = 0.5;
    if(verificaTeclaPressionada(SETA_CIMA))
    {
        moveSprite(id, 0, -speed);
    }
    if(verificaTeclaPressionada(SETA_ESQUERDA))
    {
        moveSprite(id, -speed, 0);
    }
    if(verificaTeclaPressionada(SETA_BAIXO))
    {
        moveSprite(id, 0, speed);
    }
    if(verificaTeclaPressionada(SETA_DIREITA))
    {
        moveSprite(id, speed, 0);
    }
    timer++;
    if(timer % 10000 == 0)
    {
        id = (id+1)%5;
        timer = 0;
    }
}

int main()
{
    //srand(time(NULL));
    ///FAZ A JANELA DO JOGO SURGIR
    inicializar();




    criarSpriteSheetIrregular("megamanJogoTeste.png");
    animationRun(0,14);
    ///COLOCA OS ELEMENTOS PRINCIPAIS DO JOGO
    setInitCallback(inicializa);
    ///ATUALIZA COSNTANTEMENTE OS ESTADOS DO JOGO
    setUpdateCallback(atualiza);
    rodar();

    //delete d;
    return 0;
}
