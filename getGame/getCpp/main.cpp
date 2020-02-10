#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Base.h"
#include "Dados.h"
#include "Janela.h"
#include "Animacao.h"
#include "Instancia.h"
#include "GerenciadorInput.h"

using namespace std;

int main()
{

    inicializar();
    clock_t timer = 0;
    clock_t deltaTime = 1;

    while(janelaAberta())
    {
       if(clock() - timer > deltaTime)
        {

            timer=clock();





        atualiza();
        
        }
    }

    return 0;
}
