#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <string.h>
#include "Base.h"
#include "Dados.h"
#include "Janela.h"
#include "GerenciadorInput.h"
#include "Animacao.h"
#include "Instancia.h"
using namespace std;

enum Teclas
{
    SETA_CIMA = 1,
    SETA_ESQUERDA = 2,
    SETA_BAIXO = 3,
    SETA_DIREITA = 4
};

void inicializa()
{
    //int id = criarSprite("nave.png");
   // posicaoSprite(id, 300, 300);
 //   escalaSprite(1, 10);
   // criarBackground("background.png");
}

void atualiza1()
{
    float speed = 0.5;
    if(verificaTeclaPressionada(SETA_CIMA))
    {
//        moveSprite(0, 0, -speed);
    }
    if(verificaTeclaPressionada(SETA_ESQUERDA))
    {
 //       moveSprite(0, -speed, 0);
    }
    if(verificaTeclaPressionada(SETA_BAIXO))
    {
   //     moveSprite(0, 0, speed);
    }
    if(verificaTeclaPressionada(SETA_DIREITA))
    {
   //     moveSprite(0, speed, 0);

    }

//    rodarAnimacao(".png",0);

    if(verificaMousePressionado(BOTAO_ESQUERDO)){
        cout<<"funciona"<<endl;
    }
      if(verificaMousePressionado(BOTAO_DIREITO)){
        cout<<"funciona1"<<endl;
    }
      if(verificaMousePressionado(BOTAO_EXTRA_MOUSE_1)){
        cout<<"funciona2"<<endl;
    }
      if(verificaMousePressionado(BOTAO_EXTRA_MOUSE_2)){
        cout<<"funciona3"<<endl;
    }
}

int main()
{
    //srand(time(NULL));
   /* inicializar();
    criarSprite(".png");
   // escalaSprite(0,15);
    //escalaSprite(0,10);
    criarAnimacaoArquivoIrregular(".png",100);
   // criarSpriteSheetIrregular("spriteSheetCaveira.png");

    setInitCallback(inicializa);
    setUpdateCallback(atualiza);
    //rodar();

    inicializar();
    if(janelaAberta()){
        cout<<"aberta"<<endl;
    }
    rodar();*/

    inicializar();
    sf::RenderWindow window(sf::VideoMode(512,512), "SFML PROJECT", sf::Style::Close | sf::Style::Resize);

    Animation anim(0,100);
    anim.criarAnimacaoDeArquivoIrregular("SpriteSheetCaveira3.png");

    Instancia inst;

    sf::RectangleShape personagem(sf::Vector2f(30,30));
    personagem.setFillColor(sf::Color::Red);

    inst.adicionaAnimacao(anim);
    inst.sprite.setPosition(30,30);
    while(window.isOpen())
    {

        /*sf::Event event;
        while(window.pollEvent(event))
        {

        switch(event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        }
        }*/

        if(verificaPosicaoMouseEmIntervalo(500,700,0,1000))
            cout<<"TESTE0"<<endl;

        if(pressionarBotaoMouse(BOTAO_ESQUERDO)){
            cout<<"TESTE1"<<endl;
        }
        if(pressionarBotaoMouse(BOTAO_DIREITO)){
            cout<<"TESTE2"<<endl;
        }
      /*  if(pressionarTecla(TECLA_A)){
            cout<<"A";
        }*/

      //  window.setKeyRepeatEnabled(false);
      //  std::cout<<window.getKeyRepeatEnabled()<<std::endl;

        inst.rodarAnimacao(0,"SpriteSheetCaveira3.png");

        if(pressionarTecla(TECLA_A))
        {
           // inst.movePersonagem(2,2);
           inst.virarSpriteX();
        }
        if(pressionarTecla(TECLA_B))
        {
           // inst.movePersonagem(2,2);
           inst.virarSpriteY();
        }
        if(pressionarTecla(TECLA_DIREITA))
        {
            inst.movePersonagem(0.03,0);
        }
        if(pressionarTecla(TECLA_ESQUERDA))
        {
            inst.movePersonagem(-0.03,0);
        }
        if(pressionarTecla(TECLA_CIMA))
        {
            inst.movePersonagem(0,-0.03);
        }
        if(pressionarTecla(TECLA_BAIXO))
        {
            inst.movePersonagem(0,0.03);
        }
        if(pressionarTecla(TECLA_S))
        {
            inst.movePara(50,50);
        }
        if(pressionarTecla(TECLA_D))
        {
            inst.setEscala(10);
        }
        if(pressionarTecla(TECLA_F))
        {
            inst.setEscala(1);
        }
        if(pressionarTecla(TECLA_G))
        {
            inst.rotaciona(0.05);
        }
        if(pressionarTecla(TECLA_H))
        {
            inst.setOrientacao(90);
        }

        //pressionarTecla(TECLA_A);
        // cout<<"."<<endl;
        // atualiza();



        window.clear();
        window.draw(*inst.teste);
        window.draw(inst.sprite);
        window.display();

    }



    //delete d;
    return 0;
}
