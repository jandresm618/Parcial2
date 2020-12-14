#ifndef ESCENARIO_H
#define ESCENARIO_H
#include "proyectil.h"
#define DT 0.1

class Escenario
{
public:
    Escenario();
    Escenario(float xo,float yo,float xd,float yd);
    ~Escenario();

    void accion();
    void detectorColisiones();
    void detectorCanonOfHerido();
    void detectorCanonDefHerido();


    Proyectil *p1, *p2;
    Balistica *prueba1;
    vector<Proyectil*> proyectilesOf;
    vector<Proyectil*> proyectilesDef;
    vector<Proyectil*>::iterator itO;
    vector<Proyectil*>::iterator itD;

    float xo,yo;
    float xd,yd;
    float d;
    float fIO = 0.05,fID = 0.025;
};

#endif // ESCENARIO_H
