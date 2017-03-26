//Metodo Secante

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void solveBySecante(double a, double b, double en);
double xm(double a, double b);
int iter = 0;

int main(){
    double a, b, en;
    
    //Define intervalos
    a = 1;
    b = 3;
    
    //Define error
    en = 0.001;
    solveBySecante(a, b, en);
    return 0;
}

void solveBySecante(double a, double b, double en){
    //Escribe funcion
    //funcion = 2*sin(x)-x
    
    double c, fc, fa, fb, cOld, enCurrent;
    fa = 2. * sin(a) - a;
    fb = 2. * sin(b) - b;
    c = a - ((fa * (b - a)) / (fb - fa));
    
    if (fa * fb < 0){
        cOld = c;
        fc = 2. * sin(c) - c;
        //Escoge tipo de error
        //enCurrent = fabs((c - cOld)/c)*1.; // <- porcentual 
        //enCurrent = fabs((c - cOld));  // <-absoluto  (real - obtenido)
        //enCurrent = fabs((c - cOld)/c); //<- relativo (real - obtenido/ real) 
        if (fc < en && fc > -en && enCurrent <= en) {
            cout << c << " Es la raíz con un error relativo de "<< en << endl;
            cout << "El numero de iteraciones fue: " << iter<<endl;
        }
        else{
            iter ++;
            solveBySecante(a, c, en); //acotamiento por la izquierda
            solveBySecante(c, b, en); //acotamiento por la derecha
        }
    }
    
}
