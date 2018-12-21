#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <vector>

using namespace std;

void inicializar();
bool janelaAberta();
void rodar();
int criarSprite(string file);
int criarSpriteSheet(string file, int divX, int divY);
int criarSpriteSheetIrregular(string file, int divX, int divY);
void separarSprite(int x, int y, int w, int h, string file);
void finalizarJogo(); //Fechar janela
void posicaoSprite(int id, float x, float y);
void escalaSprite(int id, float e);
void criarRetangulo();
void posicaoRetangulo(int id, float x, float y);
void tamanhoRetangulo(int id, float l, float h);
void criarCirculo();
void posicaoCirculo(int id, float x, float y);
void raioCirculo(int id, float r);
void criarBackground(string file);
bool verificaTeclaPressionada(int id);
void moveSprite(int id, float dirX, float dirY);
void setUpdateCallback(void (*pointer)(void));
void setInitCallback(void (*pointer)(void));
#endif // BASE_H_INCLUDED
