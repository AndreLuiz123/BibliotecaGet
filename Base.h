#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>

///A "Base.h" SERVE PARA A CHAMADA DAS FUN��ES DOS OUTROS TAD SEM QUE SEJA NECESS�RIO A CRIA��O DE UM OBJETO PRA ISSO

using namespace std;

///AS FUN��ES ABAIXO S�O AS QUE O USU�RIO DA BIBLIOTECA IR� UTILIZAR. EM RESUMO ELAS CHAMAM AS FUN��ES DOS OUTROS TAD.
///COMO DITO ANTERIORMENTE, SERVE PARA O USU�RIO DA BIBLIOTECA CHAMAR AS FUN��ES SEM A NECESSIDADE DE CRIAR UM OBJETO DO TIPO "Dados" OU "Janela"
///POR VIA DAS D�VIDAS, A DESCRI��O DAS FUN��ES DOS OUTROS TAD FORAM COPIADAS PARA SUAS CORRESPONDENTES NESTE TAD.
void inicializar();/// CRIA A JANELA DO JOGO
bool janelaAberta();///VERIFICA SE A JANELA ESTA OU N�O ABERTA
void rodar();/// FAZ A JANELA RODAR O JOGO. PARA ISTO, ESTA FUN��O UTILIZA TODAS AS OUTRAS FUN��ES DO TAD "Janela.h"
int criarSprite(string file);///CRIA UM SPRITE A PARTIR DE UM ARQUIVO INSERIDO NO PAR�METRO E INSERE-O NA SPRITELIST
int criarSpriteSheet(string file, int divX, int divY);///CRIA SPRITES QUE, EM SEQU�NCIA, FORMAM UMA ANIMA��O, E INSERE-OS NA SPRITELIST. ESTA FUN��O S� FUNCIONA COM SPRITESHEETS REGULARES
int criarSpriteSheetIrregular(string file);///CRIA SPRITES QUE, EM SEQU�NCIA, FORMAM UMA ANIMA��O, E INSERE-OS NA SPRITELIST. ESTA FUN��O FUNCIONA COM QUALQUER SPRITESHEET COM FUNDO TRANSPARENTE, MAS � MAIS PESADA
void separarSprite(int x, int y, int w, int h, string file);///SEPARA O SPRITE DE CERTO ARQUIVO ENTRE AS COORDENADAS (X,Y) E (W,H)
void finalizarJogo(); ///FECHA A JANELA DO JOGO
void posicaoSprite(int id, float x, float y);///POSICIONA O SPRITE DA POSI��O "ID" DO SPRITELIST NA POSI��O (X,Y) DA TELA DO JOGO
void escalaSprite(int id, float e);///REDIMENSIONA O SPRITE
void criarRetangulo();///CRIA UM RET�NGULO E INSERE-O NA RECTLIST
void posicaoRetangulo(int id, float x, float y);///POSICIONA O RET�NGULO DA POSI��O "ID" DO RECTLIST NA POSI��O (X,Y) DA TELA DO JOGO
void tamanhoRetangulo(int id, float l, float h);///REDIMENSIONA O RETANCULO
void criarCirculo();///CRIA UM C�RCULO E INSERE-O NA CIRCLELIST
void posicaoCirculo(int id, float x, float y);///POSICIONA O C�RCULO DA POSI��O "ID" DO CIRCLELIST NA POSI��O (X,Y) DA TELA DO JOGO
void raioCirculo(int id, float r);///REDIMENSIONA O C�RCULO A PARTIR DE SEU RAIO
void criarBackground(string file);///CRIA BACKGROUND PARA O JOGO E SALVA-O NO BACKGROUND
bool verificaTeclaPressionada(int id);///VERIFICA QUAL TECLA ESTA SENDO PRESSIONADA
void moveSprite(int id, float dirX, float dirY);///MOVIMENTA O SPRITE DA POSI��O "ID" DO SPRITELIST NAS DIRE��ES DIRX E DIRY. PODE SER CONSIDERADA O VECTOR2 DESTA BIBLIOTECA
void criarAnimacao(string file, int id);
void rodarAnimacao(string file, int id);
void setUpdateCallback(void (*pointer)(void));///RECEBE COMO PAR�METRO UMA FUN��O E EXECUTA-A. E USADA NO LOOPING INFINITO DO JOGO
void setInitCallback(void (*pointer)(void));///RECEBE COMO PAR�METRO UMA FUN��O E EXECUTA-A. E USADA NA INICIALIZA��O DO JOGO
void animationRun(int primeiroSprite, int tamanhoAnimacao);
#endif // BASE_H_INCLUDED
