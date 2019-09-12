#include "Level.h"
#include <string>


Level::Level(std::string fileBackground, float largura, float altura, Camera *camera/*TIPO_CAMERA tipoCam, float posicaoInicialCamX, float posicaoInicialCamY*/)
{

    height = altura;
    width = largura;

    sf::Texture *t = new sf::Texture();
    t->loadFromFile(fileBackground);
    background.setTexture(*t);

    background.setScale(width/t->getSize().x, height/t->getSize().y);
    cam = camera;
    definirPosicaoInicialCamera(cam->camera.getCenter().x, cam->camera.getCenter().y);
    /*cam->tipoCam = tipoCam;

    cam->camera.setSize(300,200);*/
}

TIPO_CAMERA Level::padraoCamera(){
    return cam->tipoCam;
}

void Level::padraoCameraJogador(Instancia inst)
{

    float x, y;

    if(inst.sprite.getPosition().x - cam->camera.getSize().x/2 >= 0 && inst.sprite.getPosition().x + cam->camera.getSize().x/2 <= width)
    {
        x = inst.sprite.getPosition().x;
    }
    else
    {
        x = cam->camera.getCenter().x;
    }

    if(inst.sprite.getPosition().y - cam->camera.getSize().y/2 >= 0 && inst.sprite.getPosition().y + cam->camera.getSize().y/2 <= height)
    {

        y = inst.sprite.getPosition().y;
    }
    else
    {

        y = cam->camera.getCenter().y;
    }

    if(inst.sprite.getPosition().y > cam->camera.getCenter().y + cam->camera.getSize().y/2 || inst.sprite.getPosition().y < cam->camera.getCenter().y - cam->camera.getSize().y/2)
    {
      x = inst.sprite.getPosition().x;
      y = inst.sprite.getPosition().y;
    }

    cam->camera.setCenter(sf::Vector2f(x,y));
   // cam->camera.setCenter(sf::Vector2f(inst.sprite.getPosition().x,inst.sprite.getPosition().y));

}

void Level::padraoCameraHorizontal(Instancia inst)
{
    float x;
    if(inst.sprite.getPosition().x - cam->camera.getSize().x/2 >= 0 && inst.sprite.getPosition().x + cam->camera.getSize().x/2 <= width)
    {
        x = inst.sprite.getPosition().x;
    }
    else
    {
        x = cam->camera.getCenter().x;
    }
    cam->camera.setCenter(sf::Vector2f(x, cam->camera.getCenter().y));
    //cam->camera.setCenter(sf::Vector2f(inst.sprite.getPosition().x, cam->camera.getCenter().y));
}

void Level::padraoCameraVertical(Instancia inst)
{
    float y;
    if(inst.sprite.getPosition().y - cam->camera.getSize().y/2 >= 0 && inst.sprite.getPosition().y + cam->camera.getSize().y/2 <= height)
    {
        y = inst.sprite.getPosition().y;
    }
    else
    {
        y = cam->camera.getCenter().y;
    }
    cam->camera.setCenter(sf::Vector2f(cam->camera.getCenter().x, y));
    //cam->camera.setCenter(sf::Vector2f(cam->camera.getCenter().x, inst.sprite.getPosition().y));
}

void Level::padraoCameraSalas(Instancia inst)
{
    float x = cam->camera.getCenter().x ,y = cam->camera.getCenter().y;
    if(inst.sprite.getPosition().x>cam->camera.getCenter().x+cam->camera.getSize().x/2){
        x += cam->camera.getSize().x;
    }else{
        if(inst.sprite.getPosition().x<cam->camera.getCenter().x-cam->camera.getSize().x/2){
            x -= cam->camera.getSize().x;
    }
    }

    if(inst.sprite.getPosition().y>cam->camera.getCenter().y+cam->camera.getSize().y/2){
        y += cam->camera.getSize().y;
    }else{
        if(inst.sprite.getPosition().y<cam->camera.getCenter().y-cam->camera.getSize().y/2){
            y -= cam->camera.getSize().y;
        }
    }

    cam->camera.setCenter(sf::Vector2f(x,y));
}
void Level::definirPosicaoInicialCamera(float x, float y)
{

    if(x  - cam->camera.getSize().x/2 < 0)
    {
        x = cam->camera.getSize().x/2;
    }
    else
    {
        if(x+cam->camera.getSize().x/2 > width)
            x = width - cam->camera.getSize().x/2;
    }
    if(y  - cam->camera.getSize().y/2 < 0)
    {
        y = cam->camera.getSize().y/2;
    }
    else
    {
        if(y + cam->camera.getSize().y/2>height)
            y = height - cam->camera.getSize().y/2;
    }
    cam->camera.setCenter(x,y);
}

bool Level::limitesCenario(Instancia inst){

/*std::cout<<inst.sprite.getPosition().x<<std::endl;
std::cout<<inst.sprite.getPosition().y<<std::endl;
std::cout<<width<<std::endl;
std::cout<<height<<std::endl;*/
    if(inst.sprite.getPosition().x < 0 || inst.sprite.getPosition().y < 0 || inst.sprite.getPosition().x > width || inst.sprite.getPosition().y > height)
        return true;

    return false;
}
