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
    //sf::RenderWindow window(sf::VideoMode(512,512), "SFML PROJECT", sf::Style::Close | sf::Style::Resize);

    //Animation anim(0,100);
    //anim.criarAnimacaoDeArquivoIrregular("Pokemon.png");

    //Instancia inst;

    //Level nv("background.png",1000,900, PADRAO_HORIZONTAL);

    //sf::RectangleShape personagem(sf::Vector2f(30,30));
    //personagem.setFillColor(sf::Color::Red);

    //sf::View v(sf::FloatRect(300.f, 200.f, 300.f, 200.f));
    criarCamera(0.f, 0.f, 300.f, 200.f, PADRAO_JOGADOR);
    criarCenario("background.png",1000,900, 0);
    criarInstancia();
    criarInstancia();
    criarAnimacao("Pokemon.png",100,0);
    criarAnimacao("spriteSheetCaveira.png",100,1);

    //inst.adicionaAnimacao(anim);
    //inst.sprite.setPosition(30,30);
    while(/*window.isOpen()*//**/janelaAberta()/**/)
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
        /*if(pressionarTecla(TECLA_A)){
            cout<<"A";
        }*/

      //  window.setKeyRepeatEnabled(false);
      //  std::cout<<window.getKeyRepeatEnabled()<<std::endl;

        //inst.rodarAnimacao(0,"Pokemon.png");

        if(pressionarTecla(TECLA_A))
        {
           // inst.movePersonagem(2,2);
           virarSpriteXInstancia(0);
        }
        if(pressionarTecla(TECLA_B))
        {
           //inst.movePersonagem(2,2);
           // inst.virarSpriteY();
           virarSpriteYInstancia(0);
        }
        if(pressionarTecla(TECLA_DIREITA))
        {
            //v.move(0.5f,0.0);
            //inst.movePersonagem(-0.03,0);
            moverInstancia(0, 2.0,0);
        }
        if(pressionarTecla(TECLA_ESQUERDA))
        {
            //v.move(-0.5f,0.0);
            //inst.movePersonagem(-0.03,0);
            moverInstancia(0,-2.0,0);
        }
        if(pressionarTecla(TECLA_CIMA))
        {
            //v.move(0.0,-0.5f);
            //inst.movePersonagem(0,-0.03);
            moverInstancia(0,0,-2.0);
        }
        if(pressionarTecla(TECLA_BAIXO))
        {
            //v.move(0.0,0.5f);
            //inst.movePersonagem(0,0.03);
            moverInstancia(0,0,2.0);
        }
        if(pressionarTecla(TECLA_Z))
        {
            //inst.movePara(50,50);
            colocarInstanciaPosicao(0,50,50);
        }
        if(pressionarTecla(TECLA_D))
        {
            //inst.setEscala(10);
            colocarEscalaInstancia(0,10);
        }
        if(pressionarTecla(TECLA_F))
        {
           //inst.setEscala(1);
           colocarEscalaInstancia(0,1);
        }
        if(pressionarTecla(TECLA_G))
        {
           // inst.rotaciona(0.05);
           rotacionarInstancia(0,0.05);
        }
        if(pressionarTecla(TECLA_H))
        {
           // inst.setOrientacao(90);
           colocarOrientacaoInstancia(0,90);
        }

        if(pressionarTecla(TECLA_Q))
        {
           // inst.setOrientacao(90);
           moverCamera(0,-0.5,0.0);
        }
        if(pressionarTecla(TECLA_E))
        {
           // inst.setOrientacao(90);
           moverCamera(0,0.5,0.0);
        }
        if(pressionarTecla(TECLA_W))
        {
           // inst.setOrientacao(90);
           moverCamera(0,0.0,-0.5);
        }
        if(pressionarTecla(TECLA_R))
        {
           // inst.setOrientacao(90);
           moverCamera(0,0.0,0.5);
        }
        if(pressionarTecla(TECLA_T))
        {
           // inst.setOrientacao(90);
           zoomCamera(0,0.97);
        }
        if(pressionarTecla(TECLA_Y))
        {
           // inst.setOrientacao(90);
           zoomCamera(0,1.01);
        }
        if(pressionarTecla(TECLA_P))
        {
           // inst.setOrientacao(90);
           colocaTamanhoCamera(0, 2000, 2000);
        }
        if(pressionarTecla(TECLA_U))
        {
            //inst.setOrientacao(90);
           rotacionarCamera(0,-0.005);
        }
        if(pressionarTecla(TECLA_I))
        {
            //inst.setOrientacao(90);
           colocarOrientacaoCamera(0,90);
        }
        if(pressionarTecla(TECLA_B))
        {
            //inst.setOrientacao(90);
           mudarPadraoCamera(0, PADRAO_JOGADOR);
        }
        if(pressionarTecla(TECLA_X))
        {
            //inst.setOrientacao(90);
           mudarPadraoCamera(0,PADRAO_SALAS);
        }
        if(pressionarTecla(TECLA_C))
        {
            //inst.setOrientacao(90);
           mudarPadraoCamera(0,PADRAO_HORIZONTAL);
        }
        if(pressionarTecla(TECLA_V))
        {
            //inst.setOrientacao(90);
           mudarPadraoCamera(0,PADRAO_VERTICAL);
        }
        if(limitesCenario(0,0)){
            cout<<"LIMITES CENARIO"<<endl;
        }
       // cout<<limitesCenario(0,0)<<endl;

        //nv.padraoCameraHorizontal(0);
        //pressionarTecla(TECLA_A);
        // cout<<"."<<endl;
        atualiza();
       /* window.clear();
       // window.setView(v);
        window.draw(nv.background);
        window.draw(inst.sprite);
        window.display();*/

    }



    //delete d;
    return 0;
}
