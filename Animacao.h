#ifndef ANIMACAO_H_INCLUDED
#define ANIMACAO_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <string>
#include "andewSay.h"
struct AnimationFrame
{
    int x, y;
    int dx, dy;
};

class Animation{

private:
    clock_t deltaTime;
    clock_t timer;

    int frameId;

public:
    std::string arquivoDaAnimacao;
    sf::Texture arquivoAnimacao;
    ///Construtor
    ///@param timer  Variável auxiliar para contagem do tempo
    ///@param framesDuration  Tempo de duração de cada frame da animação em milissegundos(unidade ainda não confirmada)
    Animation(clock_t timer, clock_t framesDuration);

    ///Retorna valor do \a timer \a
    clock_t getTimer();
    ///Atribui novo valor ao atributo \a timer \a
    ///@param timer  novo valor a ser atribuído
    void setTimer(clock_t timer);
    //std::vector<sf::Texture*> &getFrames();
    std::vector<AnimationFrame> frames;
    //void setFrames();
    ///Retorna valor do \a deltaTime \a
    clock_t getDeltaTime();
    ///Atribui novo valor ao atributo \a deltaTime \a
    void setDeltaTime(clock_t deltaTime);
    ///Troca os frames da animação. Faz a animação de fato rodar
    void animationRun();
    ///Cria animação automaticamente a partir de um arquivo cujos sprites se encontram bem posicionados
    ///@param file  arquivo fonte do qual será criada a nova animação
    ///@param divX  número de subdivisões em X que o arquivo passado no parâmetro será dividido
    ///@param divY  número de subdivisões em Y que o arquivo passado no parâmetro será dividido
    void criarAnimacaoDeArquivoRegular(std::string file,int divX, int divY);
    ///Cria animação automaticamente a partir de qualquer arquivo. As animações nem sempre têm os frames posicionados no vetor de frames corretamente, problema que pode ser resolvido com os métodos auxiliares \a criarAnimacaoComParteDeArquivo() \a , \a trocarPosicaoFrames() \a e \a apagarFrames() \a
    ///@param file  arquivo fonte do qual será criada a nova animação
    void criarAnimacaoDeArquivoIrregular(std::string file);
    ///Não deve ser utilizada pelo desenvolvedor. Método auxiliar do \a criarAnimacaoDeArquivoIrregular() \a . É este método que de fato separa os frames automaticamente
    ///@param pixelX  eixo X do píxel da parte da imagem passada no \a criarAnimacaoDeArquivoIrregular() \a
    ///@param pixelY  eixo Y do píxel da parte da imagem passada no \a criarAnimacaoDeArquivoIrregular() \a
    ///@param pixelDX  quanto, a partir de \a pixelX \a , que a imagem será cortada em X
    ///@param pixelDY  quanto, a partir de \a pixelY \a , que a imagem será cortada em Y
    ///@param img  imagem fonte
    ///@param matriz  retorna os valores de pixelX, pixelY, pixelDX e pixelDY para o \a criarAnimacaoDeArquivoIrregular() \a
    AnimationFrame squareGrowing(int pixelX, int pixelY, int pixelDX, int pixelDY, sf::Image *img, bool ** matriz);
    ///EM DESENVOLVIMENTO
    void criarAnimacaoComParteDeArquivo(std::string file, int divX, int divY, int linha1, int linha2);
   ///Troca os frames da animação. Faz a animação de fato rodar
    AnimationFrame rodarAnimacaoDeArquivoRegular(std::string file);
    ///Troca a posição, no vetor de frames, entre os frames passados no parâmetro
    ///@param frame1  índice do primeiro frame
    ///@param frame2  índice do segundo frame
    void trocarPosicaoFrames(int frame1, int frame2);
    ///Apaga, do vetor de frames, o frame passado no parâmetro
    ///@param frame  índice do frame a ser apagado
    void apagarFrame(int frame);

    static bool compara(AnimationFrame &a1, AnimationFrame &a2);
    static bool comparaY(AnimationFrame &a1, AnimationFrame &a2);

    ///Permite criar um frame manualmente, partindo a imagem associada à animação de acordo com os parâmetros do método
    ///@param x  localização X da imagem
    ///@param y  localização Y da imagem
    ///@param dx  largura do corte
    ///@param dy  altura do corte
    void criarFrameManualmente(int x, int y, int dx, int dy);
    ///Associa um arquivo de imagem para a animação criar seus frames a partir dele
    ///@param arquivo  arquivo fonte a ser associado à animação
    void associarArquivoAnimacao(std::string arquivo);

// void definirFrameManualmente(int x, int y, int dx, int dy);
     ~Animation();
};


#endif // ANIMACAO_H_INCLUDED
