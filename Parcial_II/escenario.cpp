#include "escenario.h"

Escenario::Escenario()
{

}

Escenario::Escenario(float xo, float yo, float xd, float yd)
    :xo(xo),yo(yo),xd(xd),yd(yd)
{
    d = (abs(xo)-abs(xd));
    p1 = new Proyectil(xo,yo,30,112,d,0.05,DT); proyectilesOf.push_back(p1);
    p2 = new Proyectil(xd,yd,70,-85,d,0.025,DT); proyectilesDef.push_back(p2);
    prueba1 = new Balistica(xo,yo,xd,yd,800,0.05,true);

    prueba1->fasterShots();
    prueba1->printBest();
}

Escenario::~Escenario()
{
    delete prueba1;
    for(itO=proyectilesOf.begin();itO!=proyectilesOf.end();itO++){
        delete *itO;
    }
    for(itD=proyectilesDef.begin();itD!=proyectilesDef.end();itD++){
        delete *itD;
    }
}

void Escenario::accion()
{
    float time = 0;
    for(int i=0;i<100;i++){
        time = time + DT;
        for(itO=proyectilesOf.begin();itO!=proyectilesOf.end();itO++){
            (*itO)->actualizar(DT);
        }
        for(itD=proyectilesDef.begin();itD!=proyectilesDef.end();itD++){
            (*itD)->actualizar(DT);
        }

        detectorColisiones();
        detectorCanonDefHerido();
        detectorCanonOfHerido();

    }
}

void Escenario::detectorColisiones()
{
    bool colisionOfensivaP,colisionDefensivaP;
    for(itO=proyectilesOf.begin();itO!=proyectilesOf.end();itO++){
        for(itD=proyectilesDef.begin();itD!=proyectilesDef.end();itD++){

            //Se guardan en variables todos los casos posibles de colision
            colisionOfensivaP = (sqrt(pow(((*itD)->x - (*itO)->x),2)+pow(((*itD)->y - (*itO)->y),2)) <= fIO*d);
            colisionDefensivaP = sqrt(pow(((*itO)->x - (*itD)->x),2)+pow(((*itO)->y - (*itD)->y),2)) <= fID*d;

            //Se pregunta quienes colisionaron y contra quien
            if(colisionOfensivaP){
                cout<<"------------------------------------------"<<endl;
                cout<<"************ELIMINADOS.********************"<<endl;
                cout<<"Proyectil Ofensivo Elimina al Proyectil Defensivo."<<endl;
                cout<<"------------------------------------------"<<endl;
                proyectilesOf.erase(itO); proyectilesDef.erase(itD);
                delete *itO; delete *itD;
            }
            else if(colisionDefensivaP){
                cout<<"------------------------------------------"<<endl;
                cout<<"************ELIMINADOS.********************"<<endl;
                cout<<"Proyectil Defensivo Elimina al Proyectil Ofensivo."<<endl;
                cout<<"------------------------------------------"<<endl;
                proyectilesOf.erase(itO); proyectilesDef.erase(itD);
                delete *itO; delete *itD;
            }
        }
    }
}

void Escenario::detectorCanonOfHerido()
{
    //Se analiza la posicion de cada Proyectil Defensivo
    for(itD=proyectilesDef.begin();itD!=proyectilesDef.end();itD++){
        if(!proyectilesDef.empty()){
            if(sqrt(pow((xo - (*itD)->x),2)+pow((yo - (*itD)->y),2)) <= fID*d){
            //El cañon ofensivo esta en el area de accion del proyectil defensivo
                proyectilesDef.erase(itD); delete *itD;
            }
            else if((*itD)->x < (xo-fID*d) || (*itD)->y < (yo-fID*d)){
            //El proyectil defensivo sobre paso el area de accion sobre el cañon ofensivo
                proyectilesDef.erase(itD); delete *itD;
                cout<<"------------------------------------------"<<endl;
                cout<<"************ELIMINADO.********************"<<endl;
                cout<<"Proyectil Defensivo No causo daños y es eliminado."<<endl;
                cout<<"------------------------------------------"<<endl;
            }
        }
        else break;
    }
}

void Escenario::detectorCanonDefHerido()
{
    int xx,yy,jj,kk;
    //Se analiza la posicion de cada Proyectil Defensivo
    for(itO=proyectilesOf.begin();itO!=proyectilesOf.end();itO++){
        if(!proyectilesOf.empty()){
            xx = (*itO)->x; yy = (*itO)->y;
            jj = (xd+fIO*d);
            if(sqrt(pow((xd - (*itO)->x),2)+pow((yd - (*itO)->y),2)) <= fIO*d){
            //El cañon ofensivo esta en el area de accion del proyectil defensivo
                proyectilesOf.erase(itO); delete *itO;
            }
            else if((*itO)->x > (xd+fIO*d) && (*itO)->y < (yd-fIO*d)){
            //El proyectil defensivo sobre paso el area de accion sobre el cañon ofensivo
                proyectilesOf.erase(itO); delete *itO;
                itO++;
                cout<<"------------------------------------------"<<endl;
                cout<<"************ELIMINADO.********************"<<endl;
                cout<<"Proyectil Ofensivo No causo daños y es eliminado."<<endl;
                cout<<"------------------------------------------"<<endl;
            }
        }
        else break;
    }
}
