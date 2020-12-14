#include "balistica.h"

Balistica::Balistica(float x, float y,float xE,float yE,float d ,float fI, bool _lado)
    :xEnemy(xE),yEnemy(yE),d(d),factorImpacto(fI)
{
    simulador = new Movimiento(x,y,_lado);
    if(_lado) tInfiltrado = 1; //El aviso del infiltrado le cuesta 1sg;
    else tInfiltrado = 2;      //El aviso del infiltrado le cuesta 2sg;
    if(simulador->nParabolicos(xE,yE,d,fI)) lanzamientos = simulador->getParametros();
    else cout<<endl<<"*** ALERTA****\nNo hay Lanzamientos Efectivos. Estas en Peligro."<<endl<<endl;
}

Balistica::~Balistica()
{
    delete simulador;
}

void Balistica::alertaMisil(float xf, float yf, float angulo, float v0, float d, float factorImpacto)
{
    //Funcion Encargada de Calcular la posicion del enemigo para interceptarlo
}

void Balistica::defaultShots()
{
    int i = lanzamientos.size()/2;
    bestShots.clear();
    bestShots.insert(*lanzamientos.begin());
    bestShots.insert(pair<int,vector<float>>(1,lanzamientos.find(i)->second));
    bestShots.insert(*(--lanzamientos.end()));

}

void Balistica::fasterShots()
{
    int cont = 0;
    float faster = 0;
    bestShots.clear();
    for(it=lanzamientos.begin();it!=lanzamientos.end();it++,cont++){
        if(cont ==0 )faster = it->second.at(2);
        else if(it->second.at(2) < faster){
            faster = it->second.at(2);
            bestShots.insert(pair<int,vector<float>>(cont,it->second));
        }
    }
}

void Balistica::slowerShots()
{
    int cont = 0;
    float slower = 0;
    bestShots.clear();
    for(it=lanzamientos.begin();it!=lanzamientos.end();it++,cont++){
        if(cont ==0 )slower = it->second.at(2);
        else if(it->second.at(2) > slower){
            slower = it->second.at(2);
            bestShots.insert(pair<int,vector<float>>(cont,it->second));
        }
    }
}

void Balistica::printBest()
{
    for(it=bestShots.begin();it!=bestShots.end();it++){
        cout<<"Disparo "<<it->first<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"Posicion: "<<"("<<it->second.at(0)<<", "<<it->second.at(1)<<")"<<endl;
        cout<<"Tiempo: "<<it->second.at(2)<<endl;
        cout<<"Angulo: "<<it->second.at(3)<<endl;
        cout<<"Velocidad: "<<it->second.at(4)<<endl;
        cout<<"--------------------------------"<<endl;
    }
}
