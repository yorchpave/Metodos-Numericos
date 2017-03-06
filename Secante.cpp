//Metodo Secante

#include <iostream>
#include <cmath>
#include <string>

using namespace std;


void solveBySecante(double a, double b, double en);
double xm(double a, double b);

int main(){
    double a, b, en;
    a = 1;
    b = 2;

    en = 0.01;
    solveBySecante(a, b, en);
    return 0;
}


void solveBySecante(double a, double b, double en){

    //funcion = 2*sin(x)-x

    double c, fc, fa, fb, cOld, enCurrent;
    fa = 2. * sin(a) - a;
    fb = 2. * sin(b) - b;
    c = a - ((fa * (b - a)) / (fb - fa));

    if (fa * fb < 0){
        cOld = c;
        fc = 2. * sin(c) - c;
        enCurrent = fabs((c - cOld)/c)*1.;

        if (fc < en && fc > -en && enCurrent <= en) {
            cout << c << " es la raiz con un error normalizado de "<< en <<" % usando el metodo Secante" << endl;
        }
        else{

            solveBySecante(a, c, en); //acotamiento por la izqiuerda
            solveBySecante(c, b, en); //acotamiento por la derecha
        }
    }

}

