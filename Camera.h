#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


///Os padrões enumerados abaixo ditam como a câmera do jogo funciona. A maioria deles poupa o trabalho do programador em
///descrever o funcionamento da câmera, mas ainda há um padrão que permite isso. O uso destes tipos depende da necessidade
///e interesse do desenvolvedor em ditar o padrão de suas câmeras
///@param PADRAO_JOGADOR  A câmera é centralizada na posição (x,y) do primeiro elemento da lista de instâncias carregada pela biblioteca
///@param PADRAO_HORIZONTAL   A câmera tem seu eixo \a x \a centralizado na posição \a x \a do primeiro elemento da lista de instâncias carregada pela biblioteca
///@param PADRAO_VERTICAL   A câmera tem seu eixo \a y \a centralizado na posição \a y \a do primeiro elemento da lista de instâncias carregada pela biblioteca
///@param PADRAO_SALAS  A câmera permanece estática até o primeiro elemento da lista de instâncias sair de seu campo de visão. Caso isso aconteça, a câmera se reposiciona para continuar enxergando a instância
///@param PADRAO_ORIGINAL  A câmera tem seu comportamento editado única e exclusivamente pelo desenvolvedor

enum TIPO_CAMERA {

    PADRAO_JOGADOR,
    PADRAO_HORIZONTAL,
    PADRAO_VERTICAL,
    PADRAO_SALAS,
    PADRAO_JOGADOR_ALT,
    PADRAO_ORIGINAL,

};

class Camera{

private:

public:
    sf::View camera;
    TIPO_CAMERA tipoCam;
    ///Construtor da função
    ///@param x  indica a posição no eixo X no mundo de jogo da  câmera
    ///@param y  indica a posição no eixo Y no mundo de jogo da  câmera
    ///@param width  indica a largura da câmera
    ///@param height  indica a altura da câmera
    ///@param tipoCamera  indica o padrão de funcionamento da câmera
    Camera(float x=0, float y=0, float width=300, float height=200, TIPO_CAMERA tipoCamera=PADRAO_JOGADOR);
    //Camera();
    ///Movimenta a câmera com o vetor velocidade (dx,dy)
    ///@param dx  fator horizontal do vetor velocidade
    ///@param dy  fator vertical do vetor velocidade
    void moveCamera(float dx, float dy);
    ///Reposiciona o centro da câmera para a coordenada (x,y)
    ///@param x  nova posição x da câmera
    ///@param y  nova posição y da câmera
    void movePara(float x, float y);
    ///Rotaciona a câmera na proporção determinada pela variável \a angulo \a do parâmetro
    ///@param angulo  fator de rotação da câmera
    void rotacionaCamera(float angulo);
    ///Modifica o ângulo da câmera para o que é passado na variável \a angulo \a do parâmetro
    ///@param angulo  angulação que será aplicada à câmera
    void setOrientacao(float angulo);
    ///Aproxima ou afasta a câmera do cenário de acordo com a proporção \a z \a passada no parâmetro
    ///@param z  proporção de aproximação da câmera. Quando negativo a câmera se afasta, quando positivo a câmera se aproxima
    void zoom(float z);
    ///Modifica o tamanho da câmera. O efeito é o mesmo da função zoom, só que absolutamente
    ///@param x  nova largura da câmera
    ///@param y  nova altura da câmera
    void colocaTamanhoCamera(float x, float y);
    ///Modifica o padrão da câmera
    ///@param padrao  novo padrão da câmera
    void mudarPadraoCamera(TIPO_CAMERA padrao);
};


#endif // CAMERA_H_INCLUDED
