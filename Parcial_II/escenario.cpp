#include "escenario.h"

Escenario::Escenario()
{

}

Escenario::Escenario(float xo, float yo, float xd, float yd)
    :xo(xo),yo(yo),xd(xd),yd(yd)
{
    d = abs(xo-xd); //Se inicializa la separacion

    //Se inicializan los Cañones
    cañonOfensivo = new Balistica(xo,yo,xd,yd,d,fIO,true);
    cañonDefensivo = new Balistica(xd,yd,xo,yo,d,fID,false);

}

Escenario::~Escenario()
{
    delete cañonOfensivo;
    delete cañonDefensivo;
    for(itO=proyectilesOf.begin();itO!=proyectilesOf.end();itO++){
        delete *itO;
    }
    for(itD=proyectilesDef.begin();itD!=proyectilesDef.end();itD++){
        delete *itD;
    }
}

void Escenario::cargarCañones(int opc)
{
    float angulo,v0;
    switch (opc) {
        case 1:
            cout<<endl<<"----------------------------"<<endl;
            cout<<"CASO 1 --> 3 DISPAROS OFENSIVOS HACIA CAÑON DEFENSIVO ."<<endl;
            cout<<"----------------------------"<<endl;
            cargarCoordenadasOfensivas(2); //Se cargan 3 disparos con coordenadas por defecto;
            itLO = lanzamientosOfensivos.begin();
            for(int i = 0;i<3;i++,itLO++){
                angulo = (*itLO).second.at(3);
                v0 = (*itLO).second.at(4);
                proyectilOfensivo = new Proyectil(xo,yo,angulo,v0,d,fIO,DT);
                proyectilesOf.push_back(proyectilOfensivo);
            }

            break;
        case 2:
            cout<<endl<<"----------------------------"<<endl;
            cout<<"CASO 2 --> 3 DISPAROS DEFENSIVOS HACIA CAÑON OFENSIVO."<<endl;
            cout<<"----------------------------"<<endl;
            cargarCoordenadasDefensivas(2); //Se cargan 3 disparos con coordenadas por defecto;
            itLD = lanzamientosDefensivos.begin();
            for(int i = 0;i<3;i++,itLD++){
                angulo = (*itLD).second.at(3);
                v0 = (*itLD).second.at(4);
                proyectilDefensivo = new Proyectil(xo,yo,angulo,v0,d,fIO,DT);
                proyectilesDef.push_back(proyectilDefensivo);
            }
            break;
        case 3:
            cout<<endl<<"----------------------------"<<endl;
            cout<<"CASO 3 --> 1 DISPARO OFENSIVO Y 3 DEFENSIVOS HACIA EL PROYECTIL LANZADO."<<endl;
            cout<<"           PDD: ESTA DEFENSA NO TIENE RESTRICCIONES."<<endl;
            cout<<"----------------------------"<<endl;
            cargarCoordenadasOfensivas(1); //Se cargan 3 disparos con coordenadas por defecto;
            itLO = lanzamientosOfensivos.begin();
            angulo = (*itLO).second.at(3);
            v0 = (*itLO).second.at(4);
            proyectilOfensivo = new Proyectil(xo,yo,angulo,v0,d,fIO,DT);
            proyectilesOf.push_back(proyectilOfensivo);
            cargarCoordenadasDefensivas(2); //Se cargan 3 disparos con coordenadas por defecto;
            itLD = lanzamientosDefensivos.begin();
            for(int i = 0;i<3;i++,itLD++){
                angulo = (*itLD).second.at(3);
                v0 = (*itLD).second.at(4);
                proyectilDefensivo = new Proyectil(xd,yd,angulo,v0,d,fIO,DT);
                proyectilesDef.push_back(proyectilDefensivo);
            }
            break;
        case 4:
            cout<<endl<<"----------------------------"<<endl;
            cout<<"CASO 4 --> 1 DISPARO OFENSIVO Y 3 DEFENSIVOS HACIA EL PROYECTIL LANZADO."<<endl;
            cout<<"           PDD: ESTA DEFENSA TIENE RESTRICCIONES."<<endl;
            cout<<"----------------------------"<<endl;
            cargarCoordenadasOfensivas(1); //Se cargan 3 disparos con coordenadas por defecto;
            itLO = lanzamientosOfensivos.begin();
            angulo = (*itLO).second.at(3);
            v0 = (*itLO).second.at(4);
            proyectilOfensivo = new Proyectil(xo,yo,angulo,v0,d,fIO,DT);
            proyectilesOf.push_back(proyectilOfensivo);
            cargarCoordenadasDefensivas(3); //Se cargan 3 disparos con coordenadas con resticcion de que no choquen al enemigo;
            itLD = lanzamientosDefensivos.end();
            itLD--;
            for(int i = 0;i<3;i++,--itLD){
                angulo = (*itLD).second.at(3);
                v0 = (*itLD).second.at(4);
                proyectilDefensivo = new Proyectil(xd,yd,angulo,v0,d,fIO,DT);
                proyectilesDef.push_back(proyectilDefensivo);
            }
            break;
            break;
        case 5:
            cout<<endl<<"----------------------------"<<endl;
            cout<<"CASO 5 --> 1 DISPARO OFENSIVO, 3 DEFNSIVOS HACIA EL OFENSIVO Y 3 OFENSIVOS HACIA LOS DEFENSIVOS."<<endl;
            cout<<"----------------------------"<<endl;
            cargarCoordenadasOfensivas(1); //Se cargan 3 disparos con coordenadas por defecto;
            itLO = lanzamientosOfensivos.begin();
            angulo = (*itLO).second.at(3);
            v0 = (*itLO).second.at(4);
            proyectilOfensivo = new Proyectil(xd,yd,angulo,v0,d,fIO,DT);
            proyectilesOf.push_back(proyectilOfensivo);
            cargarCoordenadasDefensivas(1); //Se cargan 3 disparos con coordenadas con resticcion de que no choquen al enemigo;
            itLD = lanzamientosDefensivos.begin();
            for(int i = 0;i<3;i++,itLD++){
                angulo = (*itLD).second.at(3);
                v0 = (*itLD).second.at(4);
                proyectilDefensivo = new Proyectil(xd,yd,angulo,v0,d,fIO,DT);
                proyectilesDef.push_back(proyectilDefensivo);
            }
            cargarCoordenadasOfensivas(2); //Se cargan 3 disparos con coordenadas por defecto;
            itLO = lanzamientosOfensivos.begin();
            for(int i = 0;i<3;i++,itLO++){
                angulo = (*itLO).second.at(3);
                v0 = (*itLO).second.at(4);
                proyectilOfensivo = new Proyectil(xo,yo,angulo,v0,d,fIO,DT);
                proyectilesOf.push_back(proyectilOfensivo);
            }
            break;
        default:
            cout<<"----------------------------"<<endl;
            cout<<"OPCIO NO VALIDA."<<endl;
            cout<<"----------------------------"<<endl;
            break;
        }
}

void Escenario::accion(int timeTotal)
{
    float time = 0,cont = 0;
    for(int i=0;i<timeTotal;i++){
        time = time + DT;

        cout<<"Tiempo Recorrido: "<<time<<endl;
        if(proyectilesDef.empty() && proyectilesOf.empty()) break;
        for(itO=proyectilesOf.begin(),cont = 0;itO!=proyectilesOf.end();itO++,cont++){
            if(time >= cont) (*itO)->actualizar(DT);
        }
        for(itD=proyectilesDef.begin(),cont = 0;itD!=proyectilesDef.end();itD++,cont++){
            if(time >= cont) (*itD)->actualizar(DT);
        }

        detectorColisiones();
        detectorCanonDefHerido();
        detectorCanonOfHerido();

    }
}

void Escenario::cargarCoordenadasOfensivas(int opc)
{
    switch (opc) {
    case 1:
        //Aqui se cargan disparos por defecto
        cañonOfensivo->defaultShots();
        break;
    case 2:
        //Aqui se cargan los disparos mas rapidos
        cañonOfensivo->fasterShots();
        break;
    case 3:
        //Aqui se cargan los disparos mas lentos o que toman mas tiempo
        cañonOfensivo->slowerShots();
        break;
    }
    lanzamientosOfensivos = cañonOfensivo->getBestShots();
}

void Escenario::cargarCoordenadasDefensivas(int opc)
{
    switch (opc) {
    case 1:
        //Aqui se cargan disparos por defecto
        cañonDefensivo->defaultShots();
        break;
    case 2:
        //Aqui se cargan los disparos mas rapidos
        cañonDefensivo->fasterShots();
        break;
    case 3:
        //Aqui se cargan los disparos mas lentos o que toman mas tiempo
        cañonDefensivo->slowerShots();
        break;
    }
    lanzamientosDefensivos = cañonDefensivo->getBestShots();
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
                delete *itO;
                proyectilesOf.erase(itO);
                delete *itD;
                proyectilesDef.erase(itD);break;
            }
            else if(colisionDefensivaP){
                cout<<"------------------------------------------"<<endl;
                cout<<"************ELIMINADOS.********************"<<endl;
                cout<<"Proyectil Defensivo Elimina al Proyectil Ofensivo."<<endl;
                cout<<"------------------------------------------"<<endl;
                delete *itO;
                proyectilesOf.erase(itO);
                delete *itD;
                proyectilesDef.erase(itD);break;
            }            
        }
        if(proyectilesOf.empty())break;
    }
}

void Escenario::detectorCanonOfHerido()
{
    int rx,ry,r;
    int limit_x,limit_y;
    //Se analiza la posicion de cada Proyectil Defensivo
    for(itD=proyectilesDef.begin();itD!=proyectilesDef.end();itD++){
        if(!proyectilesDef.empty()){
            rx = (xo - (*itD)->x);ry = (yo - (*itD)->y);
            r = sqrt(pow((xo - (*itD)->x),2)+pow((yo - (*itD)->y),2));
            limit_x = (xo-fID*d); limit_y = (yo-fID*d);

            if(sqrt(pow((xo - (*itD)->x),2)+pow((yo - (*itD)->y),2)) <= fID*d){
            //El cañon ofensivo esta en el area de accion del proyectil defensivo
                cout<<"------------------------------------------"<<endl;
                cout<<"************ELIMINADO.********************"<<endl;
                cout<<"Proyectil Defensivo causo daños en cañon Ofensivo eliminado."<<endl;
                cout<<"------------------------------------------"<<endl;
                delete *itD; proyectilesDef.erase(itD);  break;
                cout<<"Ojooo"<<endl;
            }
            else if( r>d  && (*itD)->x < (xo-fID*d)/*(*itD)->y < (yo-fID*d)*/ ){
            //El proyectil defensivo sobre paso el area de accion sobre el cañon ofensivo                
                cout<<"------------------------------------------"<<endl;
                cout<<"************ELIMINADO.********************"<<endl;
                cout<<"Proyectil Defensivo No causo daños y es eliminado."<<endl;
                cout<<"------------------------------------------"<<endl;
                delete *itD;proyectilesDef.erase(itD); break;
                cout<<"Ojooo"<<endl;

            }
        }
        else break;
    }
}

void Escenario::detectorCanonDefHerido()
{
    float rx,ry,r,limit_x,limit_y,impactDits;
    //Se analiza la posicion de cada Proyectil Defensivo
    for(itO=proyectilesOf.begin();itO!=proyectilesOf.end();itO++){
        if(!proyectilesOf.empty()){
            rx = xd - (*itO)->x;ry = yd - (*itO)->y;
            r = sqrt(pow((xd - (*itO)->x),2)+pow((yd - (*itO)->y),2));
            limit_x = (xd+fIO*d); limit_y = (yd-fIO*d);
            impactDits = fIO*d;
            if(sqrt(pow((xd - (*itO)->x),2)+pow((yd - (*itO)->y),2)) <= fIO*d){
            //El cañon ofensivo esta en el area de accion del proyectil defensivo
                cout<<"------------------------------------------"<<endl;
                cout<<"************ELIMINADO.********************"<<endl;
                cout<<"Proyectil Ofensivo causo daños en cañon defensivo y es eliminado."<<endl;
                cout<<"------------------------------------------"<<endl;
                delete *itO; proyectilesOf.erase(itO);  break;
                cout<<"Ojooo"<<endl;
            }
            else if(r>1.5*d  && (*itO)->x > (xd+fIO*d) /* (*itO)->y < (yd-fIO*d)*/){
            //El proyectil defensivo sobre paso el area de accion sobre el cañon ofensivo
                cout<<"------------------------------------------"<<endl;
                cout<<"************ELIMINADO.********************"<<endl;
                cout<<"Proyectil Ofensivo No causo daños y es eliminado."<<endl;
                cout<<"------------------------------------------"<<endl;
                delete *itO; proyectilesOf.erase(itO);  break;
                cout<<"Ojooo"<<endl;
            }
        }
        else break;
    }
}
