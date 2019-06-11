#ifndef JANELA_H_INCLUDED
#define JANELA_H_INCLUDED


#include <SFML/Window.hpp>
#include <string.h>
#include "Dados.h"
using namespace std;

/// A "Janela.h" SERVE PARA GERAR, APAGAR, COLORIR, ENTRE VÁRIAS OUTRAS COISAS, A JANELA DO JOGO EM PRODUÇÃO

class Janela{
private:

    sf::Event event;
    static Janela *obj; /// A PRÓPRIA JANELA
  //  void (*updateCallback)(void); ///RECEBE UMA FUNÇÃO
  //  void (*initCallback)(void); ///RECEBE UMA FUNÇÃO
    int altura = 600;
    int largura = 800;
    Janela(){}

public:
    static Janela* getInstance();
    sf::RenderWindow window; /// DESENHA A JANELA
  //  void setUpdateCallback(void (*pointer)(void)) { updateCallback = pointer; } ///RECEBE COMO PARÂMETRO UMA FUNÇÃO E EXECUTA-A. É USADA NO LOOPING INFINITO DO JOGO
  //  void setInitCallback(void (*pointer)(void)) { initCallback = pointer; } ///RECEBE COMO PARÂMETRO UMA FUNÇÃO E EXECUTA-A. É USADA NA INICIALIZAÇÃO DO JOGO
    bool janelaAberta(); ///VERIFICA SE A JANELA ESTA OU NÃO ABERTA
    void atualiza(Dados *data);
    void abrir(); /// CRIA A JANELA DO JOGO
    void fechar(); ///FECHA A JANELA DO JOGO
    void setAltura(int alt);
    void setLargura(int larg);

   // void rodar(); /// FAZ A JANELA RODAR O JOGO. PARA ISTO, ESTA FUNÇÃO UTILIZA TODAS AS ANTERIORES
};


#endif // JANELA_H_INCLUDED
