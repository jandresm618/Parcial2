#ifndef PROYECTIL_H
#define PROYECTIL_H
#include "balistica.h"
#define G 9.81

class Proyectil
{
public:
    Proyectil();
    Proyectil(float x,float y,float angulo,float v0,float d,float fI,float dt);
    void actualizar(float dt);

    float getX() const;
    float getY() const;

    float x,y;
private:
    float vx,vy;
    float ax,ay;
    float d,factorImpacto;
};

#endif // PROYECTIL_H
