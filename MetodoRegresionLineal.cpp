#include <iostream>
#include <iomanip>
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;
//Linealizacion Modelo Lineal

//Para calcular Errores
double promy = 0.0;

double getSt(double* y, double promy, int n){
  double sum = 0;
  for(int i = 0; i < n; i++){
    sum += pow((y[i] - promy), 2);
  }
  return sum;
}

double getSr(double* x, double* y, double a0, double a1, int n){
  double sum = 0;
  for(int i = 0; i < n; i++){
    sum += pow((y[i] - a0 - (a1 * x[i])), 2);
  }
  return sum;
}

void MinimosCuadrados(int n, double* x, double* y){

  double sumXY = 0.0;
  for(int i = 0; i < n; i++){
    sumXY += x[i] * y[i];
  }

  double sumX = 0.0;
  for(int k = 0; k < n; k++){
    sumX += x[k];
  }

  double sumY = 0.0;
  for(int j = 0; j < n; j++){
    sumY += y[j];
  }

  double sumX2 = 0.0;
  for(int l = 0; l < n; l++){
    sumX2 += x[l] * x[l];
  }

  double a1 = ((n * sumXY) - (sumX * sumY)) / ((n * sumX2) - (sumX * sumX));
  double promedio = sumY / n;
  double a0 = promedio - (a1 * (sumX / n));

  cout << "y = " << a0 << " + " << a1 << "x\n\n";

  //calcular Errores
  double Sr = getSr(x, y, a0, a1, n);
  double St = getSt(y, promy, n);
  //Error Standard de la estimación.
  double Serr = sqrt(Sr / (n - 2));
  cout << "Error Standard = " << Serr << '\n';
  //Desviación Estandard
  double desvest = sqrt(St / (n - 1));
  cout << "Desviación Estandard = " << desvest << '\n';
  //Coefeficiente de Determinación
  double R2 = (St - Sr) / St;
  cout << "Coeficiente de Determinación = " << R2 << '\n';
  //Coeficiente de Correlación
  double R = sqrt(R2);
  cout << "Coeficiente de Correlación = " << R << '\n';
}


void Linealizacion(int n){
  //file has to be 2 numbers per Line
  //Separated by a blank space
  ifstream file("ejemploLinealizacion.txt",  std::ios_base::in); //Replace this line to read different File
  double x[n];
  double y[n];
  int i = 0;
  double a;
  double b;
  while(file >> a >> b){
    x[i] = a;
    y[i] = b;
    i++;
  }
  file.close();
  for(int i = 0; i < n; i++){
    promy += y[i];
  }
  promy = promy / n;

  MinimosCuadrados(n, x, y);

}

int main(int argc, char const *argv[]) {
  Linealizacion(5); //cambiar numero de puntos en archivo
  return 0;
}
