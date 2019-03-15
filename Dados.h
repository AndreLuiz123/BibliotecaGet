#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string.h>
#include "Animacao.h"

using namespace std;

/// O "Dados.h" SERVE PARA GERENCIAR DADOS COMO SPRITES, BACKGROUNDS, AUDIOS, ETC...

class Dados{
private:
//    vector<sf::Sprite> spriteList;
    static Dados *objt;
    Dados() {}

public:

    int contador=0;
    //sf::Texture tex;
    sf::Sprite background; ///GUARDA O BACKGROUND DO JOGO
    vector<sf::Sprite> spriteList; ///GUARDA TODOS OS SPRITES DO SEU JOGO. � NESTE VETOR QUE TODAS AS IMAGENS DO SEU JOGO EST�O ARMAZENADAS
    vector<sf::RectangleShape> rectList; ///GUARDA TODAS AS FORMAS RETANGULARES DO JOGO
    vector<sf::CircleShape> circleList; ///GUARDA TODAS AS FORMAS CIRCULARES DO JOGO
    vector<Animation> animacoes; ///GUARDA ANIMA��ES APLICADAS AOS ELEMENTOS DA RECTLIST
    static Dados* getInstance(); ///PERMITE A CRIA��O DE UM OBJETO "DADOS" QUE, POR SUA VEZ, PODE SER USADO NA BASE
    int criarSprite(string file);///CRIA UM SPRITE A PARTIR DE UM ARQUIVO INSERIDO NO PAR�METRO E INSERE-O NA SPRITELIST
    int criarSpriteSheet(string file, int divX, int divY);///CRIA SPRITES QUE, EM SEQU�NCIA, FORMAM UMA ANIMA��O, E INSERE-OS NA SPRITELIST. ESTA FUN��O S� FUNCIONA COM SPRITESHEETS REGULARES
    int criarSpriteSheetIrregular(string file);///CRIA SPRITES QUE, EM SEQU�NCIA, FORMAM UMA ANIMA��O, E INSERE-OS NA SPRITELIST. ESTA FUN��O FUNCIONA COM QUALQUER SPRITESHEET COM FUNDO TRANSPARENTE, MAS � MAIS PESADA
    void setaPosicaoSpr(int id, float x, float y);///POSICIONA O SPRITE DA POSI��O "ID" DO SPRITELIST NA POSI��O (X,Y) DA TELA DO JOGO
    void moveSprite(int id, float dirX, float dirY);///MOVIMENTA O SPRITE DA POSI��O "ID" DO SPRITELIST NAS DIRE��ES DIRX E DIRY. PODE SER CONSIDERADA O VECTOR2 DESTA BIBLIOTECA
    void setaEscalaSpr(int id, float e);///REDIMENSIONA O SPRITE
    void criarRet();///CRIA UM RET�NGULO E INSERE-O NA RECTLIST
    void setaPosicaoRet(int id, float x, float y);///POSICIONA O RET�NGULO DA POSI��O "ID" DO RECTLIST NA POSI��O (X,Y) DA TELA DO JOGO
    void setaTamRet(int id, float l, float h);///REDIMENSIONA O RETANCULO
    void criarCir();///CRIA UM C�RCULO E INSERE-O NA CIRCLELIST
    void setaPosicaoCir(int id, float x, float y);///POSICIONA O C�RCULO DA POSI��O "ID" DO CIRCLELIST NA POSI��O (X,Y) DA TELA DO JOGO
    void setaRaioCir(int id, float r);///REDIMENSIONA O C�RCULO A PARTIR DE SEU RAIO
    void criarBackground(string file);///CRIA BACKGROUND PARA O JOGO E SALVA-O NO BACKGROUND
    void separarSprite(int x, int y, int w, int h, sf::Image * img,string file);///FUN��O AUXILIAR PARA O "criarSpriteSheetIrregular". BASICAMENTE CORTA O ARQUIVO DO PAR�METRO ENTRE AS COORDENADAS (X,Y) E (W,H)
    void floodFillAux(bool **matriz, int x, int y, sf::Image * img, int menorX, int maiorX, int menorY, int maiorY, int limites[2][2]);///FUN��O AUXILIAR PARA O "criarSpriteSheetIrregular". BASICAMENTE LOCALIZA AS COORDENADAS (X,Y) E (W,H) QUE SER�O USADAS NO "separaSprite"
    void criarAnimacao(string file,int divX, int divY);
    void rodarAnimacao(int id, string file);


    ~Dados();

};


#endif // DADOS_H_INCLUDED
