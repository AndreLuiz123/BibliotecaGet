#include "Instancia.h"

Instancia::Instancia()
{

    sprite.setOrigin(sf::Vector2f(25,25)/**/);

}
Instancia::~Instancia()
{
   // delete teste;
}

float Instancia::getPosX(){
    return sprite.getPosition().x;
}
float Instancia::getPosY(){
    return sprite.getPosition().y;
}
void Instancia::setPosX(float posiX){
    posX = posiX;
}
void Instancia::setPosY(float posiY){
    posY = posiY;
}

void Instancia::adicionaAnimacao(Animation anim)
{
    animacoes.push_back(anim);
    // teste->setTexture(anim.arquivoDaAnimacao);
    if(anim.arquivoDaAnimacao!=" ")
    {
    sf::Texture *t = new sf::Texture();
    //std::cout << "Created " << t << std::endl;
    t->loadFromFile(anim.arquivoDaAnimacao);
    sprite.setTexture(*t);
    }
}

void Instancia::adicionaAnimacaoDepois(int anim)
{
    // teste->setTexture(anim.arquivoDaAnimacao);
    sf::Texture *t = new sf::Texture();
    //std::cout << "Created " << t << std::endl;
    t->loadFromFile(animacoes[anim].arquivoDaAnimacao);
    sprite.setTexture(*t);

}

void Instancia::movePara(int x, int y)
{
    sprite.setPosition(x,y);
    //movePersonagem()
}

void Instancia::movePersonagem(float dx, float dy)
{
    //setPosicao(posX + dx, posY + dy);
    sprite.move(dx,dy);
    sprite.move(dx,dy);
    velX = dx;
    velY = dy;
}

void Instancia::setPosicao(int x, int y)
{
    posX = x;
    posY = y;
    sprite.setPosition(x,y);
}

void Instancia::setEscala(float escala)
{

    if(escala<0)
        escala*=-1;

    if(flpx>=0)
    {
        flpx = escala;
    }
    else
    {
        flpx = -escala;
    }

    if(flpy>=0)
    {
        flpy = escala;
    }
    else
    {
        flpy = -escala;
    }

    sprite.setScale(flpx,flpy);
}

void Instancia::virarSpriteX()
{
    flpx *= -1;
    sprite.setScale(flpx,flpy);
}

void Instancia::virarSpriteXDireita()
{
    flpx = 1;
    sprite.setScale(flpx,flpy);
}

void Instancia::virarSpriteXEsquerda()
{
    flpx = -1;
    sprite.setScale(flpx,flpy);
}

void Instancia::virarSpriteY()
{
    flpy *= -1;
    sprite.setScale(flpx,flpy);
}

void Instancia::virarSpriteYCima()
{
    flpy = 1;
    sprite.setScale(flpx,flpy);
}

void Instancia::virarSpriteYBaixo()
{
    flpy = -1;
    sprite.setScale(flpx,flpy);
}

float Instancia::area()
{
    return sprite.getScale().x*sprite.getScale().y;
}
void Instancia::rotaciona(float angulo)
{
    sprite.rotate(angulo);
    anguloAtual = angulo;
}
void Instancia::setOrientacao(float angulo)
{
    sprite.setRotation(angulo);
}
void Instancia::rodarAnimacao(int id)
{
    //std::string arq;

    //arq = ;
    animacaoAtual = id;

    //std::cout<<animacoes[id].arquivoDaAnimacao<<std::endl;
   /**/sprite.setTextureRect(sf::IntRect(animacoes[id].rodarAnimacaoDeArquivoRegular(animacoes[id].arquivoDaAnimacao).x,
                                               animacoes[id].rodarAnimacaoDeArquivoRegular(animacoes[id].arquivoDaAnimacao).y,
                                               animacoes[id].rodarAnimacaoDeArquivoRegular(animacoes[id].arquivoDaAnimacao).dx,
                                               animacoes[id].rodarAnimacaoDeArquivoRegular(animacoes[id].arquivoDaAnimacao).dy));
    /**//*sprite.setTextureRect(sf::IntRect(animacoes[id].frames[N].x,
                                      animacoes[id].frames[N].y,
                                      animacoes[id].frames[N].dx,
                                      animacoes[id].frames[N].dy));*/
     sprite.setOrigin(sprite.getTextureRect().width/2,sprite.getTextureRect().height/2);
    //std::cout<<animacoes[id].rodarAnimacaoDeArquivoRegular(file).x<<std::endl;
}

void Instancia::setAtivo(bool atv){
    ativo = atv;
}
bool Instancia::getAtivo(){
    return ativo;
}
float Instancia::getVelocidadeX(){
    return velX;
}
float Instancia::getVelocidadeY(){
    return velY;
}
float Instancia::getWidth(){
    return sprite.getTextureRect().width*flpx;
}
float Instancia::getHeight(){
    return sprite.getTextureRect().height*flpy;
}

