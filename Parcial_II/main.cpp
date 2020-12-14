#include "escenario.h"


int main()
{
    int vOpc = 0;
    float xo = 0, yo=0;
    float xf = 800,yf = 100;

    Escenario escena;

    cout<<"-----------------------------------------------------"<<endl;
    cout<<"BIENVENIDO A LA GUERRA ENTRE TURQUIA Y RUSIA"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"*********************MENU*********************"<<endl<<endl;
    cout<<"ELIJA UNA OPCION:"<<endl;
    cout<<"1. Asignar valores por defecto."<<endl;
    cout<<"2. Asignar valores personalizados."<<endl;
    cin>>vOpc;

    switch (vOpc) {
    case 1:
        escena= Escenario(xo,yo,xf,yf);
        while (vOpc != 0){
            cout<<"SELECCIONE EL CASO A CALIFICAR"<<endl;
            cout<<"1."<<endl;
            cout<<"2."<<endl;
            cout<<"3."<<endl;
            cout<<"4."<<endl;
            cout<<"5."<<endl;
            cout<<"0. Salir"<<endl;
            cin>>vOpc;
            switch (vOpc) {
            case 1:
                escena.cargarCañones(1);
                escena.accion(480);
            break;
            case 2:
                escena.cargarCañones(2);
                escena.accion(480);
            break;
            case 3:
                escena.cargarCañones(3);
                escena.accion(480);
            break;
            case 4:
                escena.cargarCañones(4);
                escena.accion(480);
            break;
            case 5:
                escena.cargarCañones(5);
                escena.accion(480);
            break;
            default:
                cout<<"SALIENDOOO..."<<endl;
                break;
            }
        }


    break;
    case 2:
        cout<<"Ingrese la posicion en x ofensiva: "<<endl;
        cin>>xo;
        cout<<"Ingrese la posicion en y ofensiva: "<<endl;
        cin>>yo;
        cout<<"Ingrese la posicion en x defensiva: "<<endl;
        cin>>xf;
        cout<<"Ingrese la posicion en y ofensiva: "<<endl;
        cin>>yf;
        escena= Escenario(xo,yo,xf,yf);
        cout<<"-----------------------------------------------------"<<endl;
        cout<<"CAÑONES CARGADOS Y LISTOS PARA ATACAR"<<endl;
        cout<<"-----------------------------------------------------"<<endl;
        while (vOpc != 0){
            cout<<"SELECCIONE EL CASO A CALIFICAR"<<endl;
            cout<<"1."<<endl;
            cout<<"2."<<endl;
            cout<<"3."<<endl;
            cout<<"4."<<endl;
            cout<<"5."<<endl;
            cout<<"0. Salir"<<endl;
            cin>>vOpc;
            switch (vOpc) {
            case 1:
                escena.cargarCañones(1);
                escena.accion(480);
            break;
            case 2:
                escena.cargarCañones(2);
                escena.accion(480);
            break;
            case 3:
                escena.cargarCañones(3);
                escena.accion(480);
            break;
            case 4:
                escena.cargarCañones(4);
                escena.accion(480);
            break;
            case 5:
                escena.cargarCañones(5);
                escena.accion(480);
            break;
            default:
                cout<<"SALIENDOOO..."<<endl;
                break;
            }
        }
    break;
    default:
        cout<<"OPCION NO VALIDA."<<endl;
        break;
    }


    cout << "Hello World!" << endl;
    return 0;
}
