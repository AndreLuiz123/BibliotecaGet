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
        Instancia();
        ~Instancia();
        std::vector<Animation> animacoes;
        sf::Sprite sprite;
        float getPosX();
        float getPosY();
        void setPosX(float posX);
        void setPosY(float posY);
        void adicionaAnimacao(Animation anim);
        void movePara(int x, int y);
        void movePersonagem(float dx, float dy);
        void setPosicao(int x, int y);
        void setEscala(float escala);
        //void rodarAnimacao(int animacao, std::string file);
        void virarSpriteX();
        void virarSpriteXDireita();
        void virarSpriteXEsquerda();
        void virarSpriteY();
        void virarSpriteYCima();
        void virarSpriteYBaixo();
        float area();
        void rotaciona(float angulo);
        void setOrientacao(float angulo);
        void atribuirTexturaPersonagem(std::string file);
        void rodarAnimacao(int id);
        void setAtivo(bool atv);
        bool getAtivo();
        void adicionaAnimacaoDepois(int anim);
        float getVelocidadeX();
        float getVelocidadeY();
        float getWidth();
        float getHeight();
};

#endif // INSTANCIA_H_INCLUDED
