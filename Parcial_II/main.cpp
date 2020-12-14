#include "escenario.h"


int main()
{
    float xo = 0, yo=0;
    float xf = 800,yf = 100;
    Escenario escena= Escenario(xo,yo,xf,yf);

    escena.accion();


    cout << "Hello World!" << endl;
    return 0;
}
