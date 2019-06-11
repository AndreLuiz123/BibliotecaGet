#ifndef JANELA_H_INCLUDED
#define JANELA_H_INCLUDED


#include <SFML/Window.hpp>
#include <string.h>
#include "Dados.h"
using namespace std;

/// A "Janela.h" SERVE PARA GERAR, APAGAR, COLORIR, ENTRE V�RIAS OUTRAS COISAS, A JANELA DO JOGO EM PRODU��O

class Janela{
private:

    sf::Event event;
    static Janela *obj; /// A PR�PRIA JANELA
  //  void (*updateCallback)(void); ///RECEBE UMA FUN��O
  //  void (*initCallback)(void); ///RECEBE UMA FUN��O
    int altura = 600;
    int largura = 800;
    Janela(){}

public:
    static Janela* getInstance();
    sf::RenderWindow window; /// DESENHA A JANELA
  //  void setUpdateCallback(void (*pointer)(void)) { updateCallback = pointer; } ///RECEBE COMO PAR�METRO UMA FUN��O E EXECUTA-A. � USADA NO LOOPING INFINITO DO JOGO
  //  void setInitCallback(void (*pointer)(void)) { initCallback = pointer; } ///RECEBE COMO PAR�METRO UMA FUN��O E EXECUTA-A. � USADA NA INICIALIZA��O DO JOGO
    bool janelaAberta(); ///VERIFICA SE A JANELA ESTA OU N�O ABERTA
    void atualiza(Dados *data);
    void abrir(); /// CRIA A JANELA DO JOGO
    void fechar(); ///FECHA A JANELA DO JOGO
    void setAltura(int alt);
    void setLargura(int larg);

   // void rodar(); /// FAZ A JANELA RODAR O JOGO. PARA ISTO, ESTA FUN��O UTILIZA TODAS AS ANTERIORES
};


#endif // JANELA_H_INCLUDED
