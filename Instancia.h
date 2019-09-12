#ifndef INSTANCIA_H_INCLUDED
#define INSTANCIA_H_INCLUDED

#include <vector>
#include <string>
#include "Animacao.h"

class Instancia
{
    private:

        float posX;
        float posY;
        bool ativo=true, flipedX=false,flipedY=false, rotacionando=false;
        int ordem;
        float anguloAtual;
        float velX, velY;
       //sf::Vector2f

    public:
        int animacaoAtual=0;
        float flpx=1, flpy=1;
        sf::RectangleShape *teste;//
        ///Construtor
        Instancia();
        ///Destrutor
        ~Instancia();
        std::vector<Animation> animacoes;
        sf::Sprite sprite;
        ///Retorna posição X da instância
        float getPosX();
        ///Retorna posição Y da instância
        float getPosY();
        ///Coloca novo valor no atributo \a posX
        /// @param posX Novo valor para o atributo \a posX \a
        void setPosX(float posX);
        ///Coloca novo valor no atributo \a posY \a
        ///@param posY  novo valor para o atributo \a posY \a
        void setPosY(float posY);
        ///Adiciona nova animação ao vetor de animações da instância
        /// @param anim nova animação a ser adicionada ao vetor de animações
        void adicionaAnimacao(Animation anim);
        ///Reposiciona a instância para a coordenada (x,y)
        /// @param x  : nova posição x da instância
        /// @param y : nova posição y da instância
        void movePara(int x, int y);
        ///Movimenta a instância com o vetor velocidade (dx,dy)
        ///@param dx  fator horizontal do vetor velocidade
        ///@param dy  fator vertical do vetor velocidade
        void movePersonagem(float dx, float dy);
        ///Modifica a posição da instância
        ///@param x  nova posição \a X \a
        ///@param y  nova posição \a Y \a
        void setPosicao(int x, int y);
        ///Modifica a escala da instância
        ///@param escala  escala a ser aplicada na instância
        void setEscala(float escala);
        //void rodarAnimacao(int animacao, std::string file);
        ///Espelha horizontalmente a instância
        void virarSpriteX();
        ///Deixa a instância obrigatoriamente olhando para a direita
        void virarSpriteXDireita();
        ///Deixa a instância obrigatoriamente olhando para a esquerda
        void virarSpriteXEsquerda();
        ///Espelha verticalmente a instância
        void virarSpriteY();
        ///Deixa a instância obrigatoriamente de cabeça para cima
        void virarSpriteYCima();
        ///Deixa a instância obrigatoriamente de cabeça para baixo
        void virarSpriteYBaixo();
        /// @brief Retorna a área que a instância ocupa
        float area();
        ///Rotaciona a instância na proporção determinada pela variável \a angulo \a do parâmetro
        ///@param angulo  fator de rotação da instância
        void rotaciona(float angulo);
        ///Modifica o ângulo da instância para o que é passado na variável \a angulo \a do parâmetro
        ///@param angulo  angulação que será aplicada à instância
        void setOrientacao(float angulo);
        ///Atribui textura à instância
        ///@param file  arquivo fonte da texture
        void atribuirTexturaPersonagem(std::string file);
        ///Faz a animação da posição 'id' do vetor de animações ser utilizada pela instância
        ///@param id  id da animação desejada
        void rodarAnimacao(int id);
        ///Faz a instância ficar ativa ou inativa, dependendo do que foi passado no parâmetro
        ///@param atv  Indica o novo estado de atividade da instância(se 'atv' for falso, a instância fica inativa, caso contrário, ela fica ativa. Uma instância inativa tem sua presença ignorada pela GETGameLib)
        void setAtivo(bool atv);
        ///Verifica se a instância está ativa ou não. Uma instância inativa tem sua presença ignorada pela GETGameLib
        bool getAtivo();
        ///Atribui textura à animação de índice 'anim' do vetor de animações da instância caso esta já não possua textura
        void adicionaAnimacaoDepois(int anim);
        ///Retorna a velocidade no eixo X da instância
        float getVelocidadeX();
        ///Retorna a velocidade no eixo Y da instância
        float getVelocidadeY();
        ///Retorna largura da instância
        float getWidth();
        ///Retorna a altura da instância
        float getHeight();
};

#endif // INSTANCIA_H_INCLUDED
