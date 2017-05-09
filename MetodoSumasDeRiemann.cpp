#include <iostream>
#include <cmath>
#include <math.h>
#include <stdio.h>

double f(double x){
  return  sin(pow(x, 2)); //funcion a integrar
}

double Riemann(double a, double b, int n){
  double sum = 0.0;
  double i = a;
  double base = (b - a) / n;
  for(; i <= b; i = i + base){
    sum += f(i) * base;
    //std::cout << "i: " << i << " sum: " << sum << '\n';
  }
  return sum;
}
int main(int argc, char const *argv[]) {
  double ans = Riemann(0, 1, 1000); //se pasan limites inferior y superior respectivamente y el numero de rectangulos para realizar calculo
  std::cout << "Integral: " << ans << '\n';
  return 0;
}
