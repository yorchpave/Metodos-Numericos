#include <iostream>
#include <cmath>

using namespace std;

//Variable que refleja el valor real la integral evaluada.
double real = 1;

//Método que evalúa la función en un valor d x.
double funcion(double x) {
 return  sin(pow(x, 2)); //------------------------------------------------definir funcion a resolver aqui-----------------
}

//Método que obtiene el error con base en el valor real.
double error(double res) {
 return abs((real - res) / real) * 100; //define tipo de error
}

//Sumas de Riemann por la derecha.
void RiemannDerecha(double a, double b, int n) {

 //Calcula el área, inicializa la variable de la respuesta.
 double h = (b - a) / n;
 double res = 0.0;
 
 //Empieza a sumar desde la esquina derecha del primer rectángulo.
 for (double i = a + h; i <= b; i+=h) {
 res += funcion(i)*h;
 }

 //Despliega resultados.
 cout << "Area aproximada: " << res << endl;
 //cout << "Error: " << error(res) << endl;
}

void RiemannIzquierda(double a, double b, int n) {

 //Calcula el área, inicializa la variable de la respuesta.
 double h = (b - a) / n;
 double res = 0.0;

 //Empieza a sumar desde la esquina izquierda del primer rectángulo.
 for (double i = a; i + h <= b; i += h) {
 res += funcion(i)*h;
 }

 //Despliega resultados.
 cout << "Area aproximada: " << res << endl;
 //cout << "Error: " << error(res) << endl;

}

void Trapecio(double a, double b, int n) { 
 
 //Calcula el área, inicializa la variable de la respuesta.
 double h = (b - a) / n;
 double res = 0;
 
 //Suma la primer área.
 res += funcion(a);

 //Sumas las áreas entre el segundo intervalo y el
 //penúltimo.
 for (double i = a + h; i < b; i += h) {
 res += 2 * funcion(i);
 }

 //Suma la última área y realiza la división.
 res += funcion(b);
 res = res* (h / 2);

 //Despliega los resultados.
 cout << "Area aproximada: " << res << endl;
 //cout << "Error: " << error(res) << endl;

}

int main() {

 //Los tres método se aplican de 1 a 9 y con
 //intención de predecir f(2).
 //RiemannDerecha(0, 1, 4);
 //RiemannIzquierda(0, 1, 4);
 Trapecio(0, 1, 1000); //----------------------------------------------limite inferior, limite superior, numero de segmentos---------------------------

 return 0;
}
