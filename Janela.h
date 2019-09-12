#ifndef JANELA_H_INCLUDED
#define JANELA_H_INCLUDED


#include <SFML/Window.hpp>
#include <string.h>
#include "Dados.h"
using namespace std;

/// A "Janela.h" SERVE PARA GERAR, APAGAR, COLORIR, ENTRE VÁRIAS OUTRAS COISAS, A JANELA DO JOGO EM PRODUÇÃO

class Janela{
private:

    static Janela *obj; /// A PRÓPRIA JANELA
  //  void (*updateCallback)(void); ///RECEBE UMA FUNÇÃO
  //  void (*initCallback)(void); ///RECEBE UMA FUNÇÃO
    int altura = 600;
    int largura = 800;
    ///Construtor
    Janela(){}

public:
       sf::Event event;

    ///Não deve ser usada pelo desenvolvedor. O objetivo deste método é garantir que a GETGameLib só use uma janela em sua aplicação
    ///\li \a \b observação \b \a : Talvez o desenvolvedor pense em uma aplicação que use mais de uma janela, mas a GETGameLib tem como objetivo fornecer o básico para criar \b jogos \b \b simples \b . Sendo assim, ideias muito "inovadoras" como utilizar mais de uma janela em sua aplicação podem não ser possíveis com esta ferramenta
    static Janela* getInstance();
    sf::RenderWindow window;
  //  void setUpdateCallback(void (*pointer)(void)) { updateCallback = pointer; } ///RECEBE COMO PARÂMETRO UMA FUNÇÃO E EXECUTA-A. É USADA NO LOOPING INFINITO DO JOGO
  //  void setInitCallback(void (*pointer)(void)) { initCallback = pointer; } ///RECEBE COMO PARÂMETRO UMA FUNÇÃO E EXECUTA-A. É USADA NA INICIALIZAÇÃO DO JOGO

    /// Verifica se a janela do jogo está aberta. Esta função é utilizada no loop principal das aplicações feitas com a GETGameLib
    bool janelaAberta();

    /// Não deve ser usada pelo desenvolvedor. Atualiza automaticamente dados que o usuário da GETGameLib não possui acesso direto
    ///@param data  gerenciador de dados da GETGameLib
    ///@param nivelAtual  indica o nível em que se encontra o jogo. Por exemplo, no menu principal, nível 1, etc...
    ///@param keyPressed  vetor que gerencia as teclas que estão sendo pressionadas ou não
    void atualiza(Dados *data,int nivelAtual, bool *keyPressed);
    ///Cria a janela
    void abrir();
    ///Destrói a janela
    void fechar();
    ///Define altura da janela
    ///@param alt  altura a ser aplicada na janela
    void setAltura(int alt);
    ///Define largura da janela
    ///@param larg  largura a ser aplicada na janela
    void setLargura(int larg);
    ///Retorna a altura da janela
    float getAltura();
    ///Retorna a largura da janela
    float getLargura();

   // void rodar(); /// FAZ A JANELA RODAR O JOGO. PARA ISTO, ESTA FUNÇÃO UTILIZA TODAS AS ANTERIORES
};


#endif // JANELA_H_INCLUDED
