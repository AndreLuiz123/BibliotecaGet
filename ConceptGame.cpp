#include <iostream>
#include <GETGameLib.h>

using namespace std;

enum PadraoCamera
{
    MOVIMENTO_LATERAL,
    SEGUE_PERSONAGEM,
    MOVER_POR_SALAS,
    MANUAL;
};

int main()
{
    iniciaJogo();

    int jogadorId = criaJogador(1, "sprite.png");
    int inimigoId = criaInimigo("spriteEnemy.png", COMPORTAMENTO_PADRAO);
    criaCenario("background.png");
    setaPadraoCamera(TIPO_CAMERA); // mover com o personagem, mover por salas, mover só na horizontal etc.

    while(jogoEmExecucao())
    {
        float dx, dy = 0;
        if(teclaPressionada(TECLA_SETA_DIREITA))
            dx = 1;
        if(teclaPressionada(TECLA_SETA_ESQUERDA))
            dx = -1;
        moveJogador(1, dx, dy);

        moveInimigo(id, dx, dy);

        trataColisao(jogadorId, inimigoId, TIPO_COLISAO);

        atualizaTela();
    }

    return 0;
}