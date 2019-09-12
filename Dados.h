#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string.h>
#include "Animacao.h"
#include "Instancia.h"
#include "Level.h"
#include "Camera.h"
using namespace std;

/// O "Dados.h" SERVE PARA GERENCIAR DADOS COMO SPRITES, BACKGROUNDS, AUDIOS, ETC...

class Dados{
private:
//    vector<sf::Sprite> spriteList;
    static Dados *objt;
    ///Construtor
    Dados() {}

public:

    int contador=0;
    //sf::Texture tex;
    sf::Sprite background;
    vector<sf::Sprite> spriteList;
    vector<sf::RectangleShape> rectList;
    vector<sf::CircleShape> circleList;

    vector<Instancia> instancias;
    vector<Animation> animacoes;
    vector<Level> niveis;
    vector<Camera> cameras;
    ///Não deve ser usada pelo desenvolvedor. O objetivo deste método é garantir que a GETGameLib só use um gerenciador de dados em sua aplicação.
    static Dados* getInstance();

    /// Adiciona nova instância ao vetor de instâncias
    ///@param inst  instância nova a ser adicionada
    void recebeInstancia(Instancia inst);
    /// Destrói a instância na posição 'id', passada no parâmetro da função, do vetor de instâncias
    ///@param id  Posição na qual se encontra a instância a ser apagada
    void apagarInstancia(int id);
    /// Adiciona nova animação ao vetor de animações
    void recebeAnimacao(Animation anim);
    /// Destrói a animação na posição 'id', passada no parâmetro da função, do vetor de animações
    void apagarAnimacao(int id);
    /// Adiciona nova câmera ao vetor de câmeras
    ///@param camera  câmera nova a ser adicionada
    void recebeCamera(Camera camera);
    /// Destrói a câmera na posição 'id', passada no parâmetro da função, do vetor de câmeras
    ///@param id  Posição na qual se encontra a câmera a ser apagada
    void apagarCamera(int id);

    //Talvwz eu retire esta função
    // bool analisaColisaoPontoEspecificoInstancias(int id1, int id2);

    ///Analisa se há colisão entre as instâncias passadas no parâmetro
    /// @param id1  instância de posição \a id1 \a do vetor de instâncias
    /// @param id2  instância de posição \a id2 \a do vetor de instâncias
    bool analisaColisaoInstancias(int id1,int id2);

   /* int criarSprite(string file);///CRIA UM SPRITE A PARTIR DE UM ARQUIVO INSERIDO NO PARÂMETRO E INSERE-O NA SPRITELIST
    int criarSpriteSheet(string file, int divX, int divY);///CRIA SPRITES QUE, EM SEQUÊNCIA, FORMAM UMA ANIMAÇÃO, E INSERE-OS NA SPRITELIST. ESTA FUNÇÃO SÓ FUNCIONA COM SPRITESHEETS REGULARES
    int criarSpriteSheetIrregular(string file);///CRIA SPRITES QUE, EM SEQUÊNCIA, FORMAM UMA ANIMAÇÃO, E INSERE-OS NA SPRITELIST. ESTA FUNÇÃO FUNCIONA COM QUALQUER SPRITESHEET COM FUNDO TRANSPARENTE, MAS É MAIS PESADA
    void setaPosicaoSpr(int id, float x, float y);///POSICIONA O SPRITE DA POSIÇÃO "ID" DO SPRITELIST NA POSIÇÃO (X,Y) DA TELA DO JOGO
    void moveSprite(int id, float dirX, float dirY);///MOVIMENTA O SPRITE DA POSIÇÃO "ID" DO SPRITELIST NAS DIREÇÕES DIRX E DIRY. PODE SER CONSIDERADA O VECTOR2 DESTA BIBLIOTECA
    void setaEscalaSpr(int id, float e);///REDIMENSIONA O SPRITE
    void criarRet();///CRIA UM RETÂNGULO E INSERE-O NA RECTLIST
    void setaPosicaoRet(int id, float x, float y);///POSICIONA O RETÂNGULO DA POSIÇÃO "ID" DO RECTLIST NA POSIÇÃO (X,Y) DA TELA DO JOGO
    void setaTamRet(int id, float l, float h);///REDIMENSIONA O RETANCULO
    void criarCir();///CRIA UM CÍRCULO E INSERE-O NA CIRCLELIST
    void setaPosicaoCir(int id, float x, float y);///POSICIONA O CÍRCULO DA POSIÇÃO "ID" DO CIRCLELIST NA POSIÇÃO (X,Y) DA TELA DO JOGO
    void setaRaioCir(int id, float r);///REDIMENSIONA O CÍRCULO A PARTIR DE SEU RAIO
    void criarBackground(string file);///CRIA BACKGROUND PARA O JOGO E SALVA-O NO BACKGROUND
    void separarSprite(int x, int y, int w, int h, sf::Image * img,string file);///FUNÇÃO AUXILIAR PARA O "criarSpriteSheetIrregular". BASICAMENTE CORTA O ARQUIVO DO PARÂMETRO ENTRE AS COORDENADAS (X,Y) E (W,H)
    void floodFillAux(bool **matriz, int x, int y, sf::Image * img, int menorX, int maiorX, int menorY, int maiorY, int limites[2][2]);///FUNÇÃO AUXILIAR PARA O "criarSpriteSheetIrregular". BASICAMENTE LOCALIZA AS COORDENADAS (X,Y) E (W,H) QUE SERÃO USADAS NO "separaSprite"
    void criarAnimacaoArquivoRegular(string file,int divX, int divY, int fps);
    void criarAnimacaoArquivoIrregular(string file, int fps);
    void rodarAnimacao(int id, string file);
    void criarSpriteFrames();*/

    ~Dados();

};

#endif // DADOS_H_INCLUDED
