#include "movimiento.h"

Movimiento::Movimiento(float x,float y,bool _lado): px(x),py(y),lado(_lado)
{

}

void Movimiento::actualizar(float dt)
{
    ax = 0;  //Aceleracion en Componente x
    ay = G; //Aceleracion en Componente y

    vx = vx;    //Velocidad en Componente x
    vy = vy - ay*dt;  //Velocidad en Componente y

    x = x + vx*dt; //Posicion x
    y = y + vy*dt-(0.5*ay*dt*dt); //Posicion y
    //cout<<x<<" "<<y<<endl;
}

bool Movimiento::nParabolicos(float xf, float yf, float d, float factorImpacto)
{
    bool impacto = false; //Bandera que indica si hubo impacto o no
    bool aux=false;       //Variable auxiliar
    float dt = 0.1;       //Delta de tiempo
    int v0_,angle,cont=0; //Variables Temporales para cada iterador

    for(v0_=0;;){
        //Iteracion para diferentes valores de Velocidad
        for( angle= 30; angle< 90; angle++){
            //Iteracion para diferentes valores de Angulo
            x = px; y = py; angulo = angle, v0 = v0_; //Inicializacion de Variables para cada valor de angulo y velocidad
            vx = v0_*cos(angle*pi/180);    //Velocidad inicial de x
            vy = abs(v0_)*sin(angle*pi/180) - ay*dt; //Velocidad inicial de y
            aux = parabolico(xf,yf,d,factorImpacto); //Retorna true si la parabola es efectiva
            if(aux){
                // Se ejecuta si y solo si hubo impacto
                cout<<endl<<"Impacto numero: "<<cont+1<<endl;
                imprimirValoresImpacto(); impacto = true; cont++; break;
            }
        }
        //Condicion Relativa De Fin de la Funcion
        if(lado){ //Si la Simulacion es Ofensiva
            v0_+=5;
            if(x >= 2*(xf+(factorImpacto*d))) break; // Si la Posicion Excede la Posicion Enemiga en X
        }
        else{ //Si la Simulacion es Defensiva¨
            v0_-=5;
            if(x < 2*(xf-(factorImpacto*d))) break; // Si la Posicion Excede la Posicion Enemiga en X
        }
    }
    return impacto;
}

bool Movimiento::parabolico(float xf, float yf, float d, float factorImpacto)
{
    bool impacto = false;
    float dt = 0.1;
    time = 0;
    while((y >= 0) ){
        actualizar(dt);
        if(sqrt(pow((xf - x),2)+pow((yf - y),2)) <= factorImpacto*d){
            impacto=true; break;
        }
        time = time + dt;
    }

    return impacto;
}

void Movimiento::imprimirValoresImpacto()
{
    cout<<"--------------------------"<<endl;
    cout<<"Impacto: "<<endl;
    cout<<"Tiempo: "<<time<<" sg\n";
    cout<<"Angulo: "<<angulo<<"º\n";
    cout<<"Velocidad: "<<v0<<" m/sg\n";
    cout<<"Posicion Final ("<<x<<","<<y<<")\n";
    cout<<"--------------------------"<<endl;
}
