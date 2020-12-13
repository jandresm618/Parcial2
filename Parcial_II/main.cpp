#include "movimiento.h"

int main()
{
    float xo = 0, yo=0;
    float xf = 800,yf = 100;

    Movimiento move1 = Movimiento(xo,yo,true);
    Movimiento move2 = Movimiento(xf,yf,false);

    cout<<endl<<"Simulacion Ofensiva."<<endl;
    move1.nParabolicos(xf,yf,800,0.05);

    cout<<endl<<"Simulacion Defensiva."<<endl;
    move2.nParabolicos(xo,yo,800,0.025);

    cout << "Hello World!" << endl;
    return 0;
}
