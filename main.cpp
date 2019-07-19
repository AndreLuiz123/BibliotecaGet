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

int main()
{

    inicializar();

    criarCamera(30,30,500,500,PADRAO_JOGADOR);
    criarCenario("background.png", 900, 500, 0);

    clock_t relogio = 0;

    int caveira = criarInstancia();
    criarAnimacao(100,caveira);
    criarAnimacao(100,caveira);
    criarAnimacao(100,caveira);

    associarArquivoAnimacao(0,0,"spriteSheetCaveira.png");

   ///Caveira parada
    criarFrameAnimacaoManualmente(caveira,0,17,75,30,52);

   ///Caveira andando
    criarFrameAnimacaoManualmente(caveira,1,17,75,30,52);
    criarFrameAnimacaoManualmente(caveira,1,82,75,30,52);
    criarFrameAnimacaoManualmente(caveira,1,17,75,30,52);

   ///Caveira pulando
     criarFrameAnimacaoManualmente(caveira,2,82,75,30,52);

    int chao[1000];
    bool virar = false;
    bool estaChao = false;
    bool andaDireita = true;
    bool andaEsquerda = true;
    float vel = 0;
    float ultimaVel;
    float ac = 0.001;
    int quadrados = 50;
    ///corrigir a velocidade do frame rate
    for(int i = 0; i<quadrados; i++)
    {
        chao[i] = criarInstancia();
        criarAnimacao(100,chao[i],"chao.png");
        colocarEscalaInstancia(chao[i], 0.2);
        ///Criar função que retorna escala
        colocarInstanciaPosicao(chao[i],getWidthInstancia(chao[i])*i,480);
    }

    for(int i = 50; i<53; i++)
    {
        chao[i] = criarInstancia();
        criarAnimacao(100,chao[i],"chao.png");
        colocarEscalaInstancia(chao[i], 0.2);
        ///Criar função que retorna escala
        colocarInstanciaPosicao(chao[i],getWidthInstancia(chao[i])*(i-42),480-getHeightInstancia(chao[i]));
    }
    for(int i = 53; i<55; i++)
    {
        chao[i] = criarInstancia();
        criarAnimacao(100,chao[i],"chao.png");
        colocarEscalaInstancia(chao[i], 0.2);
        colocarInstanciaPosicao(chao[i],getWidthInstancia(chao[i])*(i-44),480-2*getHeightInstancia(chao[i]));
    }

    ///ITENS

    int moedas[30];
    for(int i = 0; i<30; i++)
    {
        moedas[i] = criarInstancia();
        criarAnimacao(100,moedas[i],"lixo.png");
        colocarEscalaInstancia(moedas[i], 0.2);
        colocarInstanciaPosicao(moedas[i], getWidthInstancia(chao[0])*i,480-getHeightInstancia(chao[0]));
    }


   // virarSpriteXInstancia(caveira);



    while(janelaAberta())
    {
     instanciaUsaAnimacao(caveira, 0);
       if(andaDireita)
       {
        if(pressionarTeclaUmaVez(TECLA_DIREITA))
        {
            /*std::cout<<ultimaVel<<" deve ser menor que 0"<<std::endl;
            if(ultimaVel<0)
            virarSpriteXInstancia(caveira);*/
            virarSpriteXInstanciaEsquerda(caveira);
        }

        if(pressionarTecla(TECLA_DIREITA))
        {
            instanciaUsaAnimacao(caveira,1);
            moverInstancia(caveira,0.05,0);
            ultimaVel = 0.05;
        }

       }

       if(andaEsquerda)
       {
        if(pressionarTeclaUmaVez(TECLA_ESQUERDA))
        {
            instanciaUsaAnimacao(caveira,1);
            /*std::cout<<ultimaVel<<" deve ser maior que 0"<<std::endl;
            if(ultimaVel>0)
            virarSpriteXInstancia(caveira);*/
            virarSpriteXInstanciaDireita(caveira);///Neste exemplo a tecla esquerda faz ir pra direita e vice-versa pq o sprite é "problemático", e não a função
        }


        if(pressionarTecla(TECLA_ESQUERDA))
        {
            instanciaUsaAnimacao(caveira,1);
            moverInstancia(caveira,-0.05,0);
            ultimaVel = -0.05;
        }

       }


        if(!estaChao)
        {
            instanciaUsaAnimacao(caveira,2);
            moverInstancia(caveira,0,vel);
            vel+=ac;
        }

        estaChao = false;
        andaDireita = true;
        andaEsquerda = true;
        for(int i = 0; i<55; i++)
        {
             if(analisaColisaoInstancias(caveira, chao[i]))
             {
                estaChao = true;

                if(retornaPosicaoInstanciaY(caveira)<retornaPosicaoInstanciaY(chao[i])+getHeightInstancia(chao[i])&& retornaPosicaoInstanciaY(caveira)>retornaPosicaoInstanciaY(chao[i])-getHeightInstancia(chao[i]))
                {
                    if(retornaPosicaoInstanciaX(caveira)+getWidthInstancia(caveira)/2<=retornaPosicaoInstanciaX(chao[i])-getWidthInstancia(chao[i])/2)
                        andaDireita = false;

                    if(retornaPosicaoInstanciaX(caveira)+getWidthInstancia(caveira)/2>=retornaPosicaoInstanciaX(chao[i])+getWidthInstancia(chao[i])/2)
                        andaEsquerda = false;
                }

             }
        }



        if(pressionarTeclaUmaVez(TECLA_ESPACO) && estaChao)
        {
            estaChao = false;
            vel = - 0.4;
        }

        for(int i = 0; i<30; i++)
        if(analisaColisaoInstancias(caveira, moedas[i]))
        {
         desativaInstancia(moedas[i]);
        }


        atualiza();


    }

    return 0;
}




















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

/*  inicializar();
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
 /*int naruto = criarInstancia();
 int caveira = criarInstancia();
  criarAnimacao(100,naruto,"Naruto.png");
  criarAnimacao(100,caveira);
  criarAnimacao(100,caveira, "spriteSheetCaveira.png");

  associarArquivoAnimacao(caveira,0,"spriteSheetCaveira.png");
  criarFrameAnimacaoManualmente(caveira,0,17,15,29,45);
  criarFrameAnimacaoManualmente(caveira,0,17,30,29,45);
  /*criarFrameAnimacaoManualmente(1,0,23,79,19,46);
  criarFrameAnimacaoManualmente(1,0,17,143,29,46);*/


/*    int caveira = criarInstancia();
    criarAnimacao(100,caveira);

    associarArquivoAnimacao(0,0,"spriteSheetCaveira.png");

    ///Resolver problema do frame a mais
    criarFrameAnimacaoManualmente(0,0,17,75,30,52);
    criarFrameAnimacaoManualmente(0,0,82,75,30,52);
    criarFrameAnimacaoManualmente(0,0,17,75,30,52);

    //inst.adicionaAnimacao(anim);
    //inst.sprite.setPosition(30,30);
    while(/*window.isOpen()*//*janelaAberta()/**///)
/* {
     if(largarTecla(TECLA_0))
     {
           std::cout<<"teste0"<<std::endl;
     }
     if(largarTecla(TECLA_1))
     {
           std::cout<<"teste1"<<std::endl;
     }
     if(largarTecla(TECLA_2))
     {
           std::cout<<"teste2"<<std::endl;
     }
     if(largarTecla(TECLA_A))
     {
           std::cout<<"teste2"<<std::endl;
     }
     if(pressionarTeclaUmaVez(TECLA_B))
     {
           std::cout<<"testeB"<<std::endl;
     }
     /*if(largarTecla(TECLA_0))
     {
        // std::cout<<"FUNCIONOU"<<std::endl;
     }*/

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

/*
if(verificaPosicaoMouseEmIntervalo(500,700,0,1000))
    cout<<"TESTE0"<<endl;

if(pressionarBotaoMouse(BOTAO_ESQUERDO)){
    cout<<"TESTE1"<<endl;
    instanciaUsaAnimacao(1,0);
}
if(pressionarBotaoMouse(BOTAO_DIREITO)){
    cout<<"TESTE2"<<endl;
    instanciaUsaAnimacao(1,1);
}*/
/*if(pressionarTecla(TECLA_A)){
    cout<<"A";
}*/

//  window.setKeyRepeatEnabled(false);
//  std::cout<<window.getKeyRepeatEnabled()<<std::endl;

//inst.rodarAnimacao(0,"Pokemon.png");

/*   if(pressionarTecla(TECLA_A))
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
       moverInstancia(0, 0.5,0);
   }
   if(pressionarTecla(TECLA_ESQUERDA))
   {
       //v.move(-0.5f,0.0);
       //inst.movePersonagem(-0.03,0);
       moverInstancia(0,-0.5,0);
   }
   if(pressionarTecla(TECLA_CIMA))
   {
       //v.move(0.0,-0.5f);
       //inst.movePersonagem(0,-0.03);
       moverInstancia(0,0,-0.05);
   }
   if(pressionarTecla(TECLA_BAIXO))
   {
       //v.move(0.0,0.5f);
       //inst.movePersonagem(0,0.03);
       moverInstancia(0,0,0.05);
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

   //if(analisaColisaoInstancias(0,1))
       //cout<<"encostou"<<endl;
   //    else
         //  cout<<"Nao encostou"<<endl;
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

// }



//delete d;
/*    return 0;
*/
