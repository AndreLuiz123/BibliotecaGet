#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include "Instancia.h"
#include "Camera.h"
#include <vector>

class Level{

private:
    float width, height;
public:
    Camera *cam;
    sf::Sprite background;
    ///Construtor
    ///@param fileBackground  Arquivo que define o background da fase
    ///@param largura  Largura da fase no mundo de jogo
    ///@param altura  Altura da fase no mundo de jogo
    ///@param camera  Câmera associada à fase
    Level(std::string fileBackground, float largura, float altura, Camera *camera);
    ///Retorna o padrão da câmera associada à fase
    TIPO_CAMERA padraoCamera();
    ///Descreve o funcionamento da câmera para o PADRAO_JOGADOR
    ///@param inst  Instância seguida pela câmera
    void padraoCameraJogador(Instancia inst);
    ///Descreve o funcionamento da câmera para o PADRAO_HORIZONTAL
    ///@param inst  Instância seguida pela câmera
    void padraoCameraHorizontal(Instancia inst);
    ///Descreve o funcionamento da câmera para o PADRAO_VERTICAL
    ///@param inst  Instância seguida pela câmera
    void padraoCameraVertical(Instancia inst);
    ///Descreve o funcionamento da câmera para o PADRAO_SALAS
    ///@param inst  Instância seguida pela câmera
    void padraoCameraSalas(Instancia inst);
    ///Define a coordenada (x,y) do mundo do jogo na qual a câmera se encontra no início da fase
    ///@param x  coordenada em X
    ///@param y  coordenada em Y
    void definirPosicaoInicialCamera(float x, float y);
    ///Verifica se a instância passada no parâmetro esta ou não nos limites do cenário
    ///@param inst  Instância a ser verificada se esta ou não nos limites do cenário
    bool limitesCenario(Instancia inst);
};

#endif // LEVEL_H_INCLUDED
