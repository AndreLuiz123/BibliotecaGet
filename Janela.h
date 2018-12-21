#ifndef JANELA_H_INCLUDED
#define JANELA_H_INCLUDED


#include <SFML/Window.hpp>
#include <string.h>

using namespace std;
class Janela{
private:
    sf::RenderWindow window;
    static Janela *obj;
    void (*updateCallback)(void);
    void (*initCallback)(void);

    Janela() {}

public:
    static Janela* getInstance();

    void setUpdateCallback(void (*pointer)(void)) { updateCallback = pointer; }
    void setInitCallback(void (*pointer)(void)) { initCallback = pointer; }
    bool estaAberta();
    void abrir();
    void fechar();
    void rodar();
};


#endif // JANELA_H_INCLUDED
