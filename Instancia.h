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
        bool ativo, flipedX=false,flipedY=false, rotacionando=false;
        int ordem, flpx=1, flpy=1;
        float anguloAtual;
       //sf::Vector2f

    public:
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
        void setEscala(int escala);
        //void rodarAnimacao(int animacao, std::string file);
        void virarSpriteX();
        void virarSpriteY();
        float area();
        void rotaciona(float angulo);
        void setOrientacao(float angulo);
        void atribuirTexturaPersonagem(std::string file);
        void rodarAnimacao(int id);
};

#endif // INSTANCIA_H_INCLUDED
