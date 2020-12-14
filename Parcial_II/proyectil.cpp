#include "proyectil.h"

Proyectil::Proyectil()
{

}

Proyectil::Proyectil(float x, float y, float angulo, float v0, float d, float fI,float dt)
    :x(x),y(y),d(d),factorImpacto(fI)
{
    ax = 0;
    ay = G;
    vx = v0*cos(angulo*pi/180);    //Velocidad inicial de x
    vy = abs(v0)*sin(angulo*pi/180) - ay*dt; //Velocidad inicial de y
    cout<<"Proyectil Cargado Con: "<<endl;
    cout<<"Angulo: "<<angulo<<"º"<<endl;
    cout<<"Velocidad Inicial: "<<v0<<"m/sg"<<endl;
}

void Proyectil::actualizar(float dt)
{
    cont++;
    if(cont==1) cout<<"\tEmpiezo trayectoria"<<endl;
    vy = vy - ay*dt;  //Velocidad en Componente y

    x = x + vx*dt; //Posicion x
    y = y + vy*dt-(0.5*ay*dt*dt); //Posicion y
    cout<<"\t"<<x<<" "<<y<<endl;
}

float Proyectil::getX() const
{
    return x;
}

float Proyectil::getY() const
{
    return y;
}
