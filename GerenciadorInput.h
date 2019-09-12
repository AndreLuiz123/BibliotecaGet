#ifndef GERENCIADORINPUT_H_INCLUDED
#define GERENCIADORINPUT_H_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

struct posicaoMouse{

    float posX, posY;


};

enum TECLADO
{
    Unknown = -1,       ///< Unhandled key
    TECLA_A = 0,        ///< The A key
    TECLA_B,            ///< The B key
    TECLA_C,            ///< The C key
    TECLA_D,            ///< The D key
    TECLA_E,            ///< The E key
    TECLA_F,            ///< The F key
    TECLA_G,            ///< The G key
    TECLA_H,            ///< The H key
    TECLA_I,            ///< The I key
    TECLA_J,            ///< The J key
    TECLA_K,            ///< The K key
    TECLA_L,            ///< The L key
    TECLA_M,            ///< The M key
    TECLA_N,            ///< The N key
    TECLA_O,            ///< The O key
    TECLA_P,            ///< The P key
    TECLA_Q,            ///< The Q key
    TECLA_R,            ///< The R key
    TECLA_S,            ///< The S key
    TECLA_T,            ///< The T key
    TECLA_U,            ///< The U key
    TECLA_V,            ///< The V key
    TECLA_W,            ///< The W key
    TECLA_X,            ///< The X key
    TECLA_Y,            ///< The Y key
    TECLA_Z,            ///< The Z key
    TECLA_0,         ///< The 0 key
    TECLA_1,         ///< The 1 key
    TECLA_2,         ///< The 2 key
    TECLA_3,         ///< The 3 key
    TECLA_4,         ///< The 4 key
    TECLA_5,         ///< The 5 key
    TECLA_6,         ///< The 6 key
    TECLA_7,         ///< The 7 key
    TECLA_8,         ///< The 8 key
    TECLA_9,         ///< The 9 key
    TECLA_Escape,       ///< The Escape key
    TECLA_LControl,     ///< The left Control key
    TECLA_LShift,       ///< The left Shift key
    TECLA_LAlt,         ///< The left Alt key
    TECLA_LSystem,      ///< The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
    TECLA_RControl,     ///< The right Control key
    TECLA_RShift,       ///< The right Shift key
    TECLA_RAlt,         ///< The right Alt key
    TECLA_RSystem,      ///< The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
    TECLA_Menu,         ///< The Menu key
    TECLA_COLCHETE_ABERTO,     ///< The [ key
    TECLA_COLCHETE_FECHADO,     ///< The ] key
    TECLA_PONTO_E_VIRGULAR,    ///< The ; key
    TECLA_VIRGULA,        ///< The , key
    TECLA_PONTO,       ///< The . key
    Quote,        ///< The ' key
    Slash,        ///< The / key
    Backslash,    ///< The \ key
    TECLA_TIL,        ///< The ~ key
    TECLA_IGUAL,        ///< The = key
    TECLA_HIFEN,       ///< The - key (hyphen)
    TECLA_ESPACO,        ///< The Space key
    TECLA_ENTER,        ///< The Enter/Return keys
    TECLA_BACKSPACE,    ///< The Backspace key
    TECLA_TAB,          ///< The Tabulation key
    TECLA_PageUp,       ///< The Page up key
    TECLA_PageDown,     ///< The Page down key
    TECLA_End,          ///< The End key
    TECLA_Home,         ///< The Home key
    TECLA_Insert,       ///< The Insert key
    TECLA_Delete,       ///< The Delete key
    TECLA_SOMA,          ///< The + key
    TECLA_SUBTRACAO,     ///< The - key (minus, usually from numpad)
    TECLA_MULTIPLICACAO,     ///< The * key
    TECLA_DIVISAO,       ///< The / key
    TECLA_ESQUERDA,         ///< Left arrow
    TECLA_DIREITA,        ///< Right arrow
    TECLA_CIMA,           ///< Up arrow
    TECLA_BAIXO,         ///< Down arrow
    Numpad0,      ///< The numpad 0 key
    Numpad1,      ///< The numpad 1 key
    Numpad2,      ///< The numpad 2 key
    Numpad3,      ///< The numpad 3 key
    Numpad4,      ///< The numpad 4 key
    Numpad5,      ///< The numpad 5 key
    Numpad6,      ///< The numpad 6 key
    Numpad7,      ///< The numpad 7 key
    Numpad8,      ///< The numpad 8 key
    Numpad9,      ///< The numpad 9 key
    TECLA_F1,           ///< The F1 key
    TECLA_F2,           ///< The F2 key
    TECLA_F3,           ///< The F3 key
    TECLA_F4,           ///< The F4 key
    TECLA_F5,           ///< The F5 key
    TECLA_F6,           ///< The F6 key
    TECLA_F7,           ///< The F7 key
    TECLA_F8,           ///< The F8 key
    TECLA_F9,           ///< The F9 key
    TECLA_F10,          ///< The F10 key
    TECLA_F11,          ///< The F11 key
    TECLA_F12,          ///< The F12 key
    TECLA_F13,          ///< The F13 key
    TECLA_F14,          ///< The F14 key
    TECLA_F15,          ///< The F15 key
    Pause,        ///< The Pause key

    KeyCount,     ///< Keep last -- the total number of keyboard keys
};

enum MOUSE {

    BOTAO_ESQUERDO,
    BOTAO_DIREITO,
    BOTAO_MEIO,
    BOTAO_EXTRA_MOUSE_1,
    BOTAO_EXTRA_MOUSE_2,

    mouseCount,
};

class GerenciadorInput
{

private:
    static GerenciadorInput *objt;
    posicaoMouse posMouse;
    int mousePosX, mousePosY;

public:

    bool justPressedKeys[86];
    bool releasedKeys[86];

    ///Construtor
    GerenciadorInput();
    ///Não deve ser usada pelo desenvolvedor. O objetivo deste método é garantir que a GETGameLib só use um Gerenciador de Inputs em sua aplicação
    static GerenciadorInput* getInstance();
    /// Verifica se a tecla passada no parâmetro está sendo pressionada ou não
    ///@param tecla  tecla a ser analisada
    bool teclaPressionada(int tecla);
    /// Verifica se o botão do mouse passado no parâmetro está sendo pressionado ou não
    ///@param botaoMouse  botão do mouse a ser analisado
    bool mousePressionado(int botaoMouse);
    /// Verifica se o cursor do mouse se encontra entre as coordenadas \a (x1,y1) \a e \a (x2,y2) \a da tela do computador
    ///@param x1  posição em \a X \a da coordenada \a (x1,y1) \a
    ///@param x2  posição em \a X \a da coordenada \a (x1,y1) \a
    ///@param y1  posição em \a Y \a da coordenada \a (x1,y1) \a
    ///@param y2  posição em \a Y \a da coordenada \a (x1,y1) \a
    bool intervaloPosicaoMouse(int x1, int x2, int y1, int y2);
    /// Retorna a posição do cursor do mouse
    sf::Vector2i retornaPosicaoMouse();
    //bool teclaLargada(int tecla, sf::Event event,sf::RenderWindow &window);
    /*/// Verifica se a tecla passada no parâmetro foi pressionada. Caso tenha sido, a ação atribuída a esta condição é realizada uma, e apenas uma, vez
    ///@param tecla  tecla a ser analisada
    ///
    bool pressionarTeclaUmaVez(int tecla, sf::Event event, sf::RenderWindow &window);
   */
    /// Verifica se a tecla passada no parâmetro foi pressionada. Caso tenha sido, a ação atribuída a esta condição é realizada uma, e apenas uma, vez
    ///@param tecla  tecla a ser analisada
    bool teclaJustPressed(int tecla);

};

#endif // GERENCIADORINPUT_H_INCLUDED
