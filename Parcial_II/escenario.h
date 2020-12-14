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

    void cargarCañones(int opc);
    void accion(int timeTotal);
    void cargarCoordenadasOfensivas(int opc);
    void cargarCoordenadasDefensivas(int opc);

    void detectorColisiones();
    void detectorCanonOfHerido();
    void detectorCanonDefHerido();


    Proyectil *proyectilOfensivo, *proyectilDefensivo;
    Balistica *cañonOfensivo;
    Balistica *cañonDefensivo;
    vector<Proyectil*> proyectilesOf;
    vector<Proyectil*> proyectilesDef;
    vector<Proyectil*>::iterator itO;
    vector<Proyectil*>::iterator itD;

    map<int,vector<float>> lanzamientosOfensivos;
    map<int,vector<float>>::iterator itLO;
    map<int,vector<float>> lanzamientosDefensivos;
    map<int,vector<float>>::iterator itLD;

    float xo,yo;
    float xd,yd;
    float d;
    float fIO = 0.05,fID = 0.025;
};

#endif // ESCENARIO_H
