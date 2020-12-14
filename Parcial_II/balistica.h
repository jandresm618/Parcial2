#ifndef BALISTICA_H
#define BALISTICA_H
#include "movimiento.h"


class Balistica
{
public:
    Balistica(float x,float y,float xE,float yE,float d ,float fI,bool _lado);
    ~Balistica();


    void alertaMisil(float xf,float yf,float angulo,float v0,float d, float factorImpacto);

    void defaultShots();
    void fasterShots();
    void slowerShots();

    void printBest();


private:
    Movimiento *simulador;
    int tInfiltrado;
    float xEnemy,yEnemy;
    float d, factorImpacto,factorImpactoEnemy;

    map<int,vector<float>> lanzamientos;
    map<int,vector<float>> bestShots;
    map<int,vector<float>>::iterator it;
};

#endif // BALISTICA_H
