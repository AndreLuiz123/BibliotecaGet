#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>
#include "GerenciadorInput.h"
#include "Instancia.h"
#include "Camera.h"
#include "Level.h"

///A "Base.h" SERVE PARA A CHAMADA DAS FUNÇÕES DOS OUTROS TAD SEM QUE SEJA NECESSÁRIO A CRIAÇÃO DE UM OBJETO PRA ISSO

using namespace std;

///AS FUNÇÕES ABAIXO SÃO AS QUE O USUÁRIO DA BIBLIOTECA IRÁ UTILIZAR. EM RESUMO ELAS CHAMAM AS FUNÇÕES DOS OUTROS TAD.
///COMO DITO ANTERIORMENTE, SERVE PARA O USUÁRIO DA BIBLIOTECA CHAMAR AS FUNÇÕES SEM A NECESSIDADE DE CRIAR UM OBJETO DO TIPO "Dados" OU "Janela"
///POR VIA DAS DÚVIDAS, A DESCRIÇÃO DAS FUNÇÕES DOS OUTROS TAD FORAM COPIADAS PARA SUAS CORRESPONDENTES NESTE TAD.
void inicializar(int altura=600, int largura=800);/// CRIA A JANELA DO JOGO
bool janelaAberta();///VERIFICA SE A JANELA ESTA OU NÃO ABERTA
void atualiza(int nivelAtual=0);

/// @brief rodar
void rodar();

/// FAZ A JANELA RODAR O JOGO. PARA ISTO, ESTA FUNÇÃO UTILIZA TODAS AS OUTRAS FUNÇÕES DO TAD "Janela.h"
int criarSprite(string file);///CRIA UM SPRITE A PARTIR DE UM ARQUIVO INSERIDO NO PARÂMETRO E INSERE-O NA SPRITELIST
int criarSpriteSheet(string file, int divX, int divY);///CRIA SPRITES QUE, EM SEQUÊNCIA, FORMAM UMA ANIMAÇÃO, E INSERE-OS NA SPRITELIST. ESTA FUNÇÃO SÓ FUNCIONA COM SPRITESHEETS REGULARES
int criarSpriteSheetIrregular(string file);///CRIA SPRITES QUE, EM SEQUÊNCIA, FORMAM UMA ANIMAÇÃO, E INSERE-OS NA SPRITELIST. ESTA FUNÇÃO FUNCIONA COM QUALQUER SPRITESHEET COM FUNDO TRANSPARENTE, MAS É MAIS PESADA
void separarSprite(int x, int y, int w, int h, string file);///SEPARA O SPRITE DE CERTO ARQUIVO ENTRE AS COORDENADAS (X,Y) E (W,H)
void finalizarJogo(); ///FECHA A JANELA DO JOGO
void posicaoSprite(int id, float x, float y);///POSICIONA O SPRITE DA POSIÇÃO "ID" DO SPRITELIST NA POSIÇÃO (X,Y) DA TELA DO JOGO
void escalaSprite(int id, float e);///REDIMENSIONA O SPRITE
void criarRetangulo();///CRIA UM RETÂNGULO E INSERE-O NA RECTLIST
void posicaoRetangulo(int id, float x, float y);///POSICIONA O RETÂNGULO DA POSIÇÃO "ID" DO RECTLIST NA POSIÇÃO (X,Y) DA TELA DO JOGO
void tamanhoRetangulo(int id, float l, float h);///REDIMENSIONA O RETANCULO
void criarCirculo();///CRIA UM CÍRCULO E INSERE-O NA CIRCLELIST
void posicaoCirculo(int id, float x, float y);///POSICIONA O CÍRCULO DA POSIÇÃO "ID" DO CIRCLELIST NA POSIÇÃO (X,Y) DA TELA DO JOGO
void raioCirculo(int id, float r);///REDIMENSIONA O CÍRCULO A PARTIR DE SEU RAIO
void criarBackground(string file);///CRIA BACKGROUND PARA O JOGO E SALVA-O NO BACKGROUND
bool verificaTeclaPressionada(int id);///VERIFICA QUAL TECLA ESTA SENDO PRESSIONADA
void moveSprite(int id, float dirX, float dirY);///MOVIMENTA O SPRITE DA POSIÇÃO "ID" DO SPRITELIST NAS DIREÇÕES DIRX E DIRY. PODE SER CONSIDERADA O VECTOR2 DESTA BIBLIOTECA
void criarAnimacaoArquivoRegular(string file, int divX, int divY, int fps);
void criarAnimacaoArquivoIrregular(string file, int fps);
void rodarAnimacao(string file, int id);
void setUpdateCallback(void (*pointer)(void));///RECEBE COMO PARÂMETRO UMA FUNÇÃO E EXECUTA-A. E USADA NO LOOPING INFINITO DO JOGO
void setInitCallback(void (*pointer)(void));///RECEBE COMO PARÂMETRO UMA FUNÇÃO E EXECUTA-A. E USADA NA INICIALIZAÇÃO DO JOGO
void animationRun(int primeiroSprite, int tamanhoAnimacao);
bool pressionarTecla(int tecla);
bool verificaMousePressionado(int botaoMouse);
bool pressionarBotaoMouse(int botaoMouse);
bool verificaPosicaoMouseEmIntervalo(int x1, int x2, int y1, int y2);
sf::Vector2i retornaPosicaoMouse();
void criarCenario(std::string fileBackground, float largura, float altura, int cam);
void criarCamera(float x=0, float y=0, float width=500, float height=400, TIPO_CAMERA tipoCamera=PADRAO_JOGADOR);
void apagarCamera(int id);
void moverCamera(int idCamera, float dx, float dy);
void colocarCameraPosicao(int idCamera, float x, float y);
void rotacionarCamera(int idCamera, float angulo);
void colocarOrientacaoCamera(int idCamera, float angulo);
void zoomCamera(int idCamera, float aproximacao);
void colocaTamanhoCamera(int idCamera, float x, float y);
int criarInstancia();
void apagarInstancia(int id);
void criarAnimacao(float deltaTime, int idInstancia, string arquivoAnimacao = " ");
void apagarAnimacao(int id);
bool analisaColisaoPontoEspecificoInstancias(int id1, int id2);
bool analisaColisaoInstancias(int id1,int id2);
void moverInstancia(int idInstancia, float dx, float dy);
void colocarInstanciaPosicao(int idInstancia, float x, float y);
void rotacionarInstancia(int idInstancia, float angulo);
void colocarOrientacaoInstancia(int idInstancia, float angulo);
void colocarEscalaInstancia(int idInstancia, float escala);
void virarSpriteXInstancia(int idInstancia);
void virarSpriteXInstanciaDireita(int idInstancia);
void virarSpriteXInstanciaEsquerda(int idInstancia);
void virarSpriteYInstancia(int idInstancia);
void virarSpriteYInstanciaCima(int idInstancia);
void virarSpriteYInstanciaBaixo(int idInstancia);
bool limitesCenario(int cenario, int instancia);
void mudarPadraoCamera(int idCamera, TIPO_CAMERA padrao);
float retornaPosicaoInstanciaX(int id);
float retornaPosicaoInstanciaY(int id);
void criarFrameAnimacaoManualmente(int instanciaId, int animacaoInstanciaId, float x, float y, float dx, float dy);
void associarArquivoAnimacao(int instanciaId, int animacaoInstanciaId, std::string arquivoAnimacao);
void instanciaUsaAnimacao(int instanciaId, int animacaoId);
bool largarTecla(int tecla);
bool pressionarTeclaUmaVez(int tecla);
float getVelocidadeXInstancia(int idInstancia);
float getVelocidadeYInstancia(int idInstancia);
float getWidthInstancia(int idInstancia);
float getHeightInstancia(int idInstancia);
void ativaInstancia(int idInstancia);
void desativaInstancia(int idInstancia);
#endif // BASE_H_INCLUDED
