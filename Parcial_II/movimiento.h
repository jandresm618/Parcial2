#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <iostream>
#include <math.h>

#define G 9.81
#define pi 3.141617

using namespace std;

class Movimiento
{
public:
    Movimiento(float x,float y,bool _lado);
    void actualizar(float dt);
    bool nParabolicos(float xf,float yf, float d, float factorImpacto);
    bool parabolico(float xf,float yf,float d, float factorImpacto);
    void imprimirValoresImpacto();

    bool lado; //Indicador de bando
                //false = Defensivo
                //true = Ofensivo
    float x = 0,y = 0;
    float px= 0,py= 0;
    float vx= 0,vy= 0;
    float ax= 0,ay= 0;
    float v0= 0;
    float v0x= 0,v0y= 0;
    float angulo= 0;
    float time= 0;
    float aux_v= 0,aux_sin= 0;
};

#endif // MOVIMIENTO_H
