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

/// Cria automaticamente o que há de mais básico para o jogo existir
///@param altura  altura da janela
///@param largura  largura da janela
void inicializar(int altura=600, int largura=800);
/// Verifica se a janela do jogo está aberta. Esta função é utilizada no loop principal das aplicações feitas com a GETGameLib
bool janelaAberta();
/// Atualiza automaticamente dados que o usuário da GETGameLib não possui acesso direto
///@param nivelAtual  Indica o nível em que se encontra o jogo. Por exemplo, no menu principal, nível 1, etc...
void atualiza(int nivelAtual=0);

/*
/// roda
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
/// Roda  animação  em intervalo de frames específico
///@param primeiroSprite  primeiro frame do vetor de frames a ser utilizado na animação
void animationRun(int primeiroSprite, int tamanhoAnimacao);
*/

///Fecha a janela do jogo
void finalizarJogo();

/// Verifica se uma tecla específica do teclado foi pressionada
///@param tecla  a tecla a ser verificada
bool pressionarTecla(int tecla);


/*/// Verifica se um botão específico do mouse foi pressionado
///@param botaoMouse  o botão do mouse a ser verificado
bool verificaMousePressionado(int botaoMouse);*/


/// Verifica se um botão específico do mouse foi pressionado
///@param botaoMouse  o botão do mouse a ser verificado
bool pressionarBotaoMouse(int botaoMouse);


/// Verifica se o cursor do mouse se encontra entre as coordenadas \a (x1,y1) \a e \a (x2,y2) \a da tela do computador
///@param x1  posição em \a X \a da coordenada \a (x1,y1) \a
///@param x2  posição em \a X \a da coordenada \a (x1,y1) \a
///@param y1  posição em \a Y \a da coordenada \a (x1,y1) \a
///@param y2  posição em \a Y \a da coordenada \a (x1,y1) \a
bool verificaPosicaoMouseEmIntervalo(int x1, int x2, int y1, int y2);
//sf::Vector2i retornaPosicaoMouse();


/// Cria background para o jogo baseado em um arquivo de imagem
///@param fileBackground  arquivo de imagem do background
///@param largura  largura aplicada ao arquivo de imagem no jogo
///@param altura  altura aplicada ao arquivo de imagem no jogo
///@param cam  câmera do vetor de câmeras a ser utilizada para visualizar o background
void criarCenario(std::string fileBackground, float largura, float altura, int cam);


/// Cria câmera e insere-a no vetor de câmeras da GETGameLib
///@param x  posição \a X \a na qual a câmera está centralizada
///@param y  posição \a Y \a na qual a câmera está centralizada
///@param width  largura da câmera. O tamanho colocado aqui tem sua primeira metade anterior ao parâmetro \a x \a e a segunda metade posterior ao mesmo parâmetro
///@param height  altura da câmera. O tamanho colocado aqui tem sua primeira metade anterior ao parâmetro \a y \a e a segunda metade posterior ao mesmo parâmetro
///@param tipoCamera  padrão de funcionamento da câmera
void criarCamera(float x=0, float y=0, float width=500, float height=400, TIPO_CAMERA tipoCamera=PADRAO_JOGADOR);


/// Destroi câmera de posição \a id \a do vetor de câmeras da GETGamesLib
///@param id  posição no vetor de câmeras da GETGameLib da câmera a ser destruída
void apagarCamera(int id);


///Movimenta a câmera de posição \a idCamera \a do vetor de câmeras da GETGamesLib com o vetor velocidade (dx,dy)
///@param idCamera  posição no vetor de câmeras da GETGameLib da câmera a ser movimentada
///@param dx  fator horizontal do vetor velocidade
///@param dy  fator vertical do vetor velocidade
void moverCamera(int idCamera, float dx, float dy);



///Reposiciona o centro da câmera de posição \a idCamera \a do vetor de câmeras da GETGamesLib para a coordenada (x,y)
///@param idCamera  posição no vetor de câmeras da GETGameLib da câmera a ser movimentada
///@param x  nova posição x da câmera
///@param y  nova posição y da câmera
void colocarCameraPosicao(int idCamera, float x, float y);


///Rotaciona a câmera de posição \a idCamera \a do vetor de câmeras da GETGamesLib na proporção determinada pela variável \a angulo \a do parâmetro
///@param idCamera  posição no vetor de câmeras da GETGameLib da câmera a ser movimentada
///@param angulo  fator de rotação da câmera
void rotacionarCamera(int idCamera, float angulo);


///Modifica o ângulo da câmera de posição \a idCamera \a do vetor de câmeras da GETGamesLib para o que é passado na variável \a angulo \a do parâmetro
///@param idCamera  posição no vetor de câmeras da GETGameLib da câmera a ser movimentada
///@param angulo  angulação que será aplicada à câmera
void colocarOrientacaoCamera(int idCamera, float angulo);


///Aproxima ou afasta a câmera de posição \a idCamera \a do vetor de câmeras da GETGamesLib do cenário de acordo com a proporção \a z \a passada no parâmetro
///@param idCamera  posição no vetor de câmeras da GETGameLib da câmera a ser movimentada
///@param aproximacao  proporção de aproximação da câmera. Quando negativo a câmera se afasta, quando positivo a câmera se aproxima
void zoomCamera(int idCamera, float aproximacao);


///Modifica o tamanho da câmera de posição \a idCamera \a do vetor de câmeras da GETGamesLib. O efeito é o mesmo da função zoom, só que absolutamente
///@param idCamera  posição no vetor de câmeras da GETGameLib da câmera a ser movimentada
///@param x  nova largura da câmera
///@param y  nova altura da câmera
void colocaTamanhoCamera(int idCamera, float x, float y);


/// Cria instância e insere-a no vetor de instâncias da GETGameLib
int criarInstancia();


/// Destroi instância de posição \a id \a do vetor de instâncias da GETGamesLib
///@param id  posição no vetor de instâncias da GETGameLib da instância a ser destruída
void apagarInstancia(int id);


/// Cria animação e associa-a a uma instância
///@param deltaTime  tempo de duração de cada frame da animação
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a receber a animação
///@param arquivoAnimacao  sprite sheet utilizada para criar a animação automaticamente. Caso não se deseje criar a animação automaticamente, não é necessário passar um valor para este parâmetro
void criarAnimacao(float deltaTime, int idInstancia, string arquivoAnimacao = " ");


/// Se esta função for utilizada, o usuário seleciona manualmente uma parte do arquivo fonte da animação para ser um novo frame da mesma
///@param instanciaId  posição no vetor de instâncias da GETGameLib da instância a receber a animação
///@param animacaoInstanciaId  id da animação do vetor de animações da instância de posição \a instanciaId \b do vetor de instâncias da GetGameLib
void criarFrameAnimacaoManualmente(int instanciaId, int animacaoInstanciaId, float x, float y, float dx, float dy);


/// Se esta função for utilizada, o usuário seleciona manualmente uma parte do arquivo fonte da animação para ser um novo frame da mesma
/// \b \a EM DESENVOLVIMENTO \a \b
void criarFramesAnimacaoAutomaticamente(int idInstancia, int idAnimacao, string arquivoAnimacao);

//void apagarAnimacao(int id);
//bool analisaColisaoPontoEspecificoInstancias(int id1, int id2);

/// Analisa se as instâncias id1 e id2 estão colidindo
/// \b id1  instância de posição \a id1 \a do vetor de instâncias da GETGamesLib
/// \b id2  instância de posição \a id2 \a do vetor de instâncias da GETGamesLib
bool analisaColisaoInstancias(int id1,int id2);


///Movimenta a instância de posição \a idInstancia \a do vetor de instâncias da GETGamesLib com o vetor velocidade (dx,dy)
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a ser movimentada
///@param dx  fator horizontal do vetor velocidade
///@param dy  fator vertical do vetor velocidade
void moverInstancia(int idInstancia, float dx, float dy);


///Modifica a posição da instância de posição \a idInstancia \a do vetor de instâncias da GETGamesLib
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a ser reposicionada
///@param x  nova posição \a X \a
///@param y  nova posição \a Y \a
void colocarInstanciaPosicao(int idInstancia, float x, float y);


///Rotaciona a instância de posição \a idInstancia \a do vetor de instâncias da GETGameLib na proporção determinada pela variável \a angulo \a do parâmetro
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a ser rotacionada
///@param angulo  fator de rotação da instância
void rotacionarInstancia(int idInstancia, float angulo);


///Modifica o ângulo da instância de posição \a idInstancia \a do vetor de instâncias da GETGameLib para o que é passado na variável \a angulo \a do parâmetro
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a ser reorientada
///@param angulo  angulação que será aplicada à instância
void colocarOrientacaoInstancia(int idInstancia, float angulo);


///Modifica a escala da instância de posição \a idInstancia \a do vetor de instâncias da GETGameLib
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a ter sua escala modificada
///@param escala  escala a ser aplicada na instância
void colocarEscalaInstancia(int idInstancia, float escala);


///Espelha horizontalmente a instância de posição \a idInstancia \a do vetor de instâncias da GETGameLib
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a ser virada
void virarSpriteXInstancia(int idInstancia);


///Deixa a instância de posição \a idInstancia \a do vetor de instâncias da GETGameLib obrigatoriamente olhando para a direita
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a ser virada
void virarSpriteXInstanciaDireita(int idInstancia);

///Deixa a instância de posição \a idInstancia \a do vetor de instâncias da GETGameLib obrigatoriamente olhando para a esquerda
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a ser virada
void virarSpriteXInstanciaEsquerda(int idInstancia);


///Espelha verticalmente a instância de posição \a idInstancia \a do vetor de instâncias da GETGameLib
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a ser virada
void virarSpriteYInstancia(int idInstancia);


/// Faz sprite ficar forçadamente em sentido para cima
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a ser virada
void virarSpriteYInstanciaCima(int idInstancia);


/// Faz sprite ficar forçadamente em sentido para baixo
///@param idInstancia  posição no vetor de instâncias da GETGameLib da instância a ser virada
void virarSpriteYInstanciaBaixo(int idInstancia);


/// Verifica se uma dada instância está ou não dentro dos limites do cenário indicado no parâmetro
///@param cenario  posição do cenário no vetor de cenarios da GETGameLib
///@param instancia  posição da instância do vetor de instância da GETGameLib
bool limitesCenario(int cenario, int instancia);


/// Modifica o padrão da câmera
///@param idCamera  posição da câmera no vetor de câmeras da GETGameLib
///@param padrao  novo padrão de câmera a ser aplicado
void mudarPadraoCamera(int idCamera, TIPO_CAMERA padrao);


/// Retorna posição X da instância
///@param id  posição no vetor de instâncias da GETGameLib da instância
float retornaPosicaoInstanciaX(int id);


/// Retorna posição Y da instância
///@param id  posição no vetor de instâncias da GETGameLib da instância
float retornaPosicaoInstanciaY(int id);


/// Faz animação de uma dada instância ter como fonte de seus frames o arquivo passado no parâmetro
///@param instanciaId  posição no vetor de instâncias da GETGameLib da instância
///@param animacaoInstanciaId  posição da animação no vetor de animações da instância passada no parâmetro
///@param arquivoAnimacao  arquivo que será fonte de frames da animação
void associarArquivoAnimacao(int instanciaId, int animacaoInstanciaId, std::string arquivoAnimacao);


/// Decide qual animação da lista de animações da instância será utilizada com a chamada da função
///@param instanciaId  posição no vetor de instâncias da GETGameLib da instância
///@param animacaoId  posição da animação no vetor de animações da instância passada no parâmetro
void instanciaUsaAnimacao(int instanciaId, int animacaoId);


/*/// Verifica se a tecla acabou de ser largada
bool largarTecla(int tecla);*/


/// Verifica se a tecla passada no parâmetro foi pressionada. Caso tenha sido, a ação atribuída a esta condição é realizada uma, e apenas uma, vez
///@param tecla  tecla a ser analisada
bool pressionarTeclaUmaVez(int tecla);


/// Retorna o deslocamento em x que a instância sofre no momento que a função é chamada
///@param instanciaId  posição no vetor de instâncias da GETGameLib da instância
float getVelocidadeXInstancia(int idInstancia);


/// Retorna o deslocamento em y que a instância sofre no momento que a função é chamada
///@param instanciaId  posição no vetor de instâncias da GETGameLib da instância
float getVelocidadeYInstancia(int idInstancia);


/// Retorna a largura da TextureRect que representa a instância no momento
///@param instanciaId  posição no vetor de instâncias da GETGameLib da instância
float getWidthInstancia(int idInstancia);


/// Retorna a altura da TextureRect que representa a instância no momento
///@param instanciaId  posição no vetor de instâncias da GETGameLib da instância
float getHeightInstancia(int idInstancia);


/// Faz o atributo 'ativo' ter valor verdadeiro
///@param instanciaId  posição no vetor de instâncias da GETGameLib da instância
void ativaInstancia(int idInstancia);


/// Faz o atributo 'ativo' ter valor falso
///@param instanciaId  posição no vetor de instâncias da GETGameLib da instância
void desativaInstancia(int idInstancia);
#endif // BASE_H_INCLUDED
