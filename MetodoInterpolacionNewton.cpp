#include <iostream>
#include <cmath>

using namespace std;

double diferenciaDivFinita(int i0, int i1, double x[], double y[]) {

	if (i1 - i0 == 0) {
		return y[i0];
	}
	else {
		return (diferenciaDivFinita(i0 + 1, i1, x, y) - 
			diferenciaDivFinita(i0, i1 - 1, x, y)) / (x[i1] - x[i0]);
	}
}

void Newton(double x[], double y[], int tamano, double valor) {

	double aproximacion = 0;
	double *divisiones = new double[tamano];

	cout << "Coeficientes: " << endl;

	for (int i = 0; i < tamano; i++) {
		divisiones[i] = diferenciaDivFinita(0, i, x, y);
		cout << divisiones[i] << endl;
	}


	for (int i = 0; i < tamano; i++) {
		double aprox = divisiones[i];

		for (int j = 0; j < i; j++) {
			aprox *= (valor - x[j]);
		}

		aproximacion += aprox;
	}

	cout << "Valor aproximado: " << aproximacion << endl;
}

int main() {

	double x[] = {/*introduce aqui puntos en x*/}; //-----------puntos en x
	double y[] = {/*introduce aqui puntos en y*/}; //----------puntos en y

	Newton(x, y, sizeof(x)/sizeof(x[0]), /*x*/); //------valor de x a usar

}
