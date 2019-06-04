#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cmath>
#include "Base.h"
#include "Janela.h"
#include "Dados.h"
#include "Animacao.h"
#include "GerenciadorInput.h"
using namespace std;

GerenciadorInput gerInp;

void inicializar(int altura, int largura)
{
    Janela *janela = Janela::getInstance();
    janela->setAltura(altura);
    janela->setLargura(largura);
    janela->abrir();
}

void finalizarJogo()
{
    Janela *janela = Janela::getInstance();
    janela->fechar();
}

/*int criarSprite(string file)
{
    Dados *data = Dados::getInstance();
    return data->criarSprite(file);
}

int criarSpriteSheet(string file, int divX, int divY)
{
    Dados *data = Dados::getInstance();
    return data->criarSpriteSheet(file, divX, divY);
}

int criarSpriteSheetIrregular(string file)
{
    Dados *data = Dados::getInstance();
    return data->criarSpriteSheetIrregular(file);
}

void posicaoSprite(int id, float x, float y)
{
    Dados *data = Dados::getInstance();
    data->setaPosicaoSpr(id, x, y);
}

void escalaSprite(int id, float e)
{
    Dados *data = Dados::getInstance();
    data->setaEscalaSpr(id, e);
}

void criarRetangulo()
{
    Dados *data = Dados::getInstance();
    data->criarRet();
}

void posicaoRetangulo(int id, float x, float y)
{
    Dados *data = Dados::getInstance();
    data->setaPosicaoRet(id, x, y);
}

void tamanhoRetangulo(int id, float l, float h)
{
    Dados *data = Dados::getInstance();
    data->setaTamRet(id, l, h);
}

void criarCirculo()
{
    Dados *data = Dados::getInstance();
    data->criarCir();
}

void posicaoCirculo(int id, float x, float y)
{
    Dados *data = Dados::getInstance();
    data->setaPosicaoCir(id, x, y);
}

void raioCirculo(int id, float r)
{
    Dados *data = Dados::getInstance();
    data->setaRaioCir(id, r);
}

void criarBackground(string file)
{
    Dados *data = Dados::getInstance();
    data->criarBackground(file);
}
*/
/*void rodar()
{
    Janela *janela = Janela::getInstance();
    janela->rodar();

}*/

bool janelaAberta()
{
    Janela *janela = Janela::getInstance();
    return janela->janelaAberta();
}

void atualiza()
{
    Janela *janela = Janela::getInstance();
    janela->atualiza();
}

bool verificaTeclaPressionada(int id)
{
    switch (id){
    case 1:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            return true;
        }
        else{
            return false;
        }
        break;
    case 2:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            return true;
        }
        else{
            return false;
        }
        break;
    case 3:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            return true;
        }
        else{
            return false;
        }
        break;
    case 4:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            return true;
        }
        else{
            return false;
        }
        break;
    }

}
/*void moveSprite(int id, float dirX, float dirY)
{
    Dados *data = Dados::getInstance();
    data->moveSprite(id, dirX, dirY);
}

void criarAnimacaoArquivoRegular(string file, int divX, int divY, int fps){

    Dados *dados = Dados::getInstance();
    dados->criarAnimacaoArquivoRegular(file, divX, divY, fps);
}

void criarAnimacaoArquivoIrregular(string file, int fps){

    Dados *dados = Dados::getInstance();
    dados->criarAnimacaoArquivoIrregular(file, fps);
}

void rodarAnimacao(string file, int id){

    Dados *dados = Dados::getInstance();
    dados->rodarAnimacao(id,file);
}
*/
/*void setUpdateCallback(void (*pointer)(void))
{
    Janela *janela = Janela::getInstance();
    janela->setUpdateCallback(pointer);
}*/

/*void setInitCallback(void (*pointer)(void))
{
    Janela *janela = Janela::getInstance();
    janela->setInitCallback(pointer);
}*/
void animationRun(int primeiroSprite, int tamanhoAnimacao)
{

}
bool pressionarTecla(int tecla){
   // Janela *janela = Janela::getInstance();
   /* janela->window.setKeyRepeatEnabled(false);*/
   GerenciadorInput *gerInp = GerenciadorInput::getInstance();
   return gerInp->teclaPressionada(tecla);
}

bool segurarTecla(int tecla){
    GerenciadorInput *gerInp = GerenciadorInput::getInstance();
    return gerInp->teclaPressionada(tecla);
}
void verificaTeclaLargada(int tecla){

}
bool verificaMousePressionado(int botaoMouse){
    GerenciadorInput *gerInp = GerenciadorInput::getInstance();
    return gerInp->mousePressionado(botaoMouse);
}
bool pressionarBotaoMouse(int botaoMouse){
    GerenciadorInput *gerInp = GerenciadorInput::getInstance();
    return gerInp->mousePressionado(botaoMouse);
}
/*
posicaoMouse verificaPosicaoMouse(){
return gerInp.verificaPosicaoMouse();
}
*/
bool verificaPosicaoMouseEmIntervalo(int x1, int x2, int y1, int y2){
    GerenciadorInput *gerInp = GerenciadorInput::getInstance();
    gerInp->intervaloPosicaoMouse(x1,x2,y1,y2);
}
sf::Vector2i retornaPosicaoMouse(){
    GerenciadorInput *gerInp = GerenciadorInput::getInstance();
    gerInp->retornaPosicaoMouse();
}
void criarInstancia(){
    Dados *data = Dados::getInstance();
    Instancia inst;
    data->recebeInstancia(inst);
}
void apagarInstancia(int id){
    Dados *data = Dados::getInstance();
    data->apagarInstancia(id);
}
void criarAnimacao(string arquivoAnimacao, float deltaTime){
    Dados *data = Dados::getInstance();
    Animation anim(0,deltaTime);
    anim.criarAnimacaoDeArquivoIrregular(arquivoAnimacao);
    data->recebeAnimacao(anim);
}
void apagarAnimacao(int id){
    Dados *data = Dados::getInstance();
    data->apagarAnimacao(id);
}
bool analisaColisaoPontoEspecificoInstancias(int id1, int id2){
    //Dados *data = Dados::getInstance();
    //data->analisaColisaoInstancias(id1, id2);
}
bool analisaColisaoInstancias(int id1,int id2){
    Dados *data = Dados::getInstance();
    data->analisaColisaoInstancias(id1,id2);
}
