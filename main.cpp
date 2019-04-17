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
    //int id = criarSprite("nave.png");
   // posicaoSprite(id, 300, 300);
 //   escalaSprite(1, 10);
   // criarBackground("background.png");
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

    rodarAnimacao("Pokemon.png",0);
}

int main()
{
    //srand(time(NULL));
    inicializar();
    criarSprite("Pokemon.png");
   // escalaSprite(0,15);
    //escalaSprite(0,10);
    criarAnimacaoArquivoIrregular("Pokemon.png",100);
   // criarSpriteSheetIrregular("spriteSheetCaveira.png");

    setInitCallback(inicializa);
    setUpdateCallback(atualiza);
    rodar();

    //delete d;
    return 0;
}
