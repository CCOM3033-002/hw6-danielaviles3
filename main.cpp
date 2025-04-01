/*  HW 6: Figuras en 3D
   Nombre: Daniel Aviles
   Num Est. 801-24-5453
   tutor: Lillian Gonzales
   web link: https://animated-memory-q74xr9g6jp9rh6r4.github.dev/

*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

//Prototipo de Funciones
//Este programa usa overloading
double volumen(double, double);
double volumen(double);
double volumen(double, double, double);

double area(double);
double area(double, double);
double area(double, double, double);

int main() {
    //Las variables que se van a uasr
    char x, y;
    string figura; 
    double radio, altura, largo, ancho;
    double resultado;
    
    cout << "Este programa calcula el volumen y el área de la superficie de tres figuras.\n\n";
    
    cout << "Escoja una figura:\n"
         << "a. Cilindro\n" << "b. Esfera\n"
         << "c. Prisma Rectangular\n\n"
         << "Selección: ";
    cin >> x;
    
    cout << "\nEscoja entre las siguientes opciones:\n"
         << "a. Volumen\n" << "b. Área de la superficie\n\n"
         << "Selección: ";
    cin >> y;
    
    //Usando switch para que cuando el usario seleccione sus opciones
    switch(x) {
        case 'a': 
            figura = "cilindro";
            cout << "\nEntre el radio y altura del Cilindro separados por espacio: ";
            cin >> radio >> altura;
            break;
         
        case 'b':
            figura = "esfera";
            cout << "\nEntre el radio de la esfera: ";
            cin >> radio;
            
            break;
         
        case 'c': 
            figura = "prisma rectangular";
            cout << "\nEntre el largo, ancho y altura del Prisma Rectangular separados por espacios ";
            cin >> largo >> ancho >> altura;
            
            
            break;
        //Cuando el opcion que entro no es valido
        default:
            cout << "\nOpción no válida!\n";
            return 1;
    }
    
    //Cuando el usario seleccione su letra usa la funcion de los que esxogio para dar el resultado
    switch(y) {
        case 'a':
            if(x == 'a')
                //Estos ifs son para validar lo que puso el usario y asegurar que caiga en el programa
                if(radio < 0 && altura < 0)
            {
                cout << "Opcion no es valido" << endl;
            }
                else {
                    resultado = volumen(radio, altura);
                    cout << "El volumen del " << figura << " es " << fixed << setprecision(2) << resultado << endl;
                }
            else if(x == 'b')
                 if(radio < 0)
            {
                cout << "Opcion no es valido" << endl;
            }
                else {
                resultado = volumen(radio);
                cout << "El volumen del " << figura << " es " << fixed << setprecision(2) << resultado << endl;
            }
            
            else if(x == 'c')
                 if(largo < 0 && altura < 0 && ancho < 0)
            {
                cout << "Opcion no es valido" << endl;
            }
                else
            {
                resultado = volumen(largo, ancho, altura);
                cout << "El volumen del " << figura << " es " << fixed << setprecision(2) << resultado << endl;
            }
            break;
        
        case 'b':
            if(x == 'a')
                if(radio < 0 && altura < 0)
            {
                cout << "Opcion no es valido" << endl;
            }
                else
                {
                resultado = area(radio, altura);
                cout << "El área del" << figura << " es " << fixed << setprecision(2) << resultado << endl;
                }
            else if(x == 'b')
                  if(radio < 0)
            {
                cout << "Opcion no es valido" << endl;
            }
                else {
                resultado = area(radio);
                cout << "El área del" << figura << " es " << fixed << setprecision(2) << resultado << endl;
                }
            else if(x == 'c')
                  if(largo < 0 && altura < 0 && ancho < 0)
            {
                cout << "Opcion no es valido" << endl;
            }
                else 
                {
                resultado = area(largo, ancho, altura);
                cout << "El área del" << figura << " es " << fixed << setprecision(2) << resultado << endl;
                
                }
            break;
    }
    return 0;
}

// Funciones de Volume
double volumen(double radio, double altura) {
    // Cilindro volumen: πr²h
    return M_PI * pow(radio, 2) * altura;
}

double volumen(double radio) {
    // Esfera volumen: (4/3)πr³
    return (4.0/3.0) * M_PI * pow(radio, 3);
}

double volumen(double largo, double ancho, double altura) {
    // Prisma Rectangular volumen: lwh
    return largo * ancho * altura;
}

// Area functions
double area(double radio) {
    // Esfera area: 4πr²
    return 4 * M_PI * pow(radio, 2);
}

double area(double radio, double altura) {
    // Cilindro area: 2πr² + 2πrh
    return 2 * M_PI * pow(radio, 2) + 2 * M_PI * radio * altura;
}

double area(double largo, double ancho, double altura) {
    // Prisma Rectangular area: 2(lw + lh + wh)
    return 2 * (largo * ancho + largo * altura + ancho * altura);
}
