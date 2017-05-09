#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double f(double x) {

    return sin(pow(x, 2)); //funcion 
}

double trapezium(int n, double a, double b) {
    
    double h = (b-a)/n;
    double _a = a;
    double integral = f(a) + f(b);
    double integralSum = 0;
    for(double i = _a + h; i < b; i += h) {
        integralSum += f(i);
    }
    return (integral+ 2*integralSum)*h/2;
}


double rombergHelper(double* approximationsLvl1, int k, int me) {
    if(k == 1) {
        return approximationsLvl1[me];
    }
    else {
        return (pow(4, k-1)*rombergHelper(approximationsLvl1, k-1, me+1) - rombergHelper(approximationsLvl1, k-1, me))/(pow(4, k-1)-1);
    }
}

double romberg(double a, double b, int numberOfApprox) {
    
    double initialApprox[numberOfApprox];
    double h = (b-a)/numberOfApprox;
    double integral;

    for(int i = 0; i < numberOfApprox; i++) {
        double n;
        cout << "Number of trapeziums for approximation " << i << ": ";
        cin >> n;
        initialApprox[i] = trapezium(n, a, b);
    }

    integral = rombergHelper(initialApprox, numberOfApprox, 0);
    return integral;
}

int main() {
    double integral, a, b;
    int numberOfApprox;

    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Number of initial approximations = ";
    cin >> numberOfApprox;
    
    integral = romberg(a, b, numberOfApprox);
    
    cout << "Integral = " << integral << endl;
    
}
