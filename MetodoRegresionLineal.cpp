// Regresión lineal

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>


using namespace std;

// Lista de las variables que se usarán.
double sum, sumx, sumx2, sumy, sumxy, promx, promy, a0, a1, sr, st, desvest, s, r, alfa, beta;

// Método que hace una sumatoria.
double sumatoria(double valores[], int modo, int n) {
    sum = 0;
    // Sumatoria normal de los valores del arreglo.
    if (modo == 0) {
        for (int i = 0; i < n; i++) {
            sum += valores[i];
        }
    }
    // Sumatoria de los cuadrados de los valores del arreglo.
    else if (modo == 1) {
        for (int i = 0; i < n; i++) {
            sum += pow(valores[i], 2);
        }
    }
    return sum;
}

// Método que efectúa la sumatoria de los productos de los valores
// de ambos arreglos.
double sumatoriaMult(double x[], double y[], int n) {
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (x[i]*y[i]);
    }
    return sum;
}

//
double getSt(double y[], double promy, int n) {
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow((y[i] - promy),2);
    }
    return sum;
}

double getSr(double x[], double y[], double a0, double a1, int n) {
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow((y[i] - a0 - a1*x[i]), 2);
    }
    return sum;
}

// Método de regresión lineal. Recibe dos arreglos que
// representan los valores de x y y, el número de
// datos.
void regresionLineal(double x[], double y[], int n) {

    // Se sacan los valores necesarios para la fórmula de
    // la regresión lineal.
    sumx = sumatoria(x, 0, n);
    sumy = sumatoria(y, 0, n);
    sumx2 = sumatoria(x, 1, n);
    sumxy = sumatoriaMult(x, y, n);
    promx = sumx / n;
    promy = sumy / n;

    // Se aplican las fórmulas de a1 y a0 con los datos
    // obtenidos previamente.
    a1 = ((n*sumxy) - (sumx*sumy)) / ((n*sumx2) - pow(sumx, 2));
    a0 = promy - a1*promx;

    // Imprime la ecuación de la recta ajustada.
    cout << "La recta es: y = " << a0 << " + " << a1 << "x" << endl;

    // Obtiene sr y st para la cuantificación del error.
    sr = getSr(x, y, a0, a1, n);
    st = getSt(y, promy, n);

    // Obtiene la desviación estándar y el error estándar de la
    // estimación.
    desvest = sqrt(st / (n - 1));
    s = sqrt(sr / (n - 2));

    // Determina si la desviación mejoro, y por tanto el ajuste
    // fue bueno.
    cout << "Desviacion estandar: " << desvest << endl;
    cout << "Error estandar de la estimacion: " << s << endl;
    if (desvest > s) {
        cout << "El ajuste fue adecuado." << endl;
    }
    else {
        cout << "No hubo un ajuste relevante." << endl;
    }

    // Obtiene el coeficiente de determinación y el coeficiente
    // de correlación.
    r = (st - sr) / st;
    cout << "Coeficiente de determinacion: " << r << endl;
    cout << "Coeficiente de correlacion: " << sqrt(r) << endl;


}

void linealizacion(double x[], double y[], int n, int modo) {

    double *logx = new double[n];
    double *logy = new double[n];

    if (modo == 0) {
        for (int i = 0; i < n; i++) {
            logy[i] = log(y[i]);
        }

        beta = (logy[1] - logy[0]) / (x[1] - x[0]);
        alfa = beta*(-x[0]) + logy[0];

        cout << "La linealizacion es: ln(y) = " << alfa << " + " << beta << "x" << endl;
        cout << "La curva ajustada es: y = " << exp(alfa) << "e ^ " << beta << "x" << endl;

        // Se sacan los valores necesarios para la fórmula de
        // la regresión lineal.
        sumx = sumatoria(x, 0, n);
        sumy = sumatoria(logy, 0, n);
        sumx2 = sumatoria(x, 1, n);
        sumxy = sumatoriaMult(x, logy, n);
        promx = sumx / n;
        promy = sumy / n;

        // Se aplican las fórmulas de a1 y a0 con los datos
        // obtenidos previamente.
        a1 = ((n*sumxy) - (sumx*sumy)) / ((n*sumx2) - pow(sumx, 2));
        a0 = promy - a1*promx;

        // Obtiene sr y st para la cuantificación del error.
        sr = getSr(x, logy, a0, a1, n);
        st = getSt(logy, promy, n);

        // Obtiene la desviación estándar y el error estándar de la
        // estimación.
        desvest = sqrt(st / (n - 1));
        s = sqrt(sr / (n - 2));

        // Determina si la desviación mejoro, y por tanto el ajuste
        // fue bueno.
        cout << "Desviacion estandar: " << desvest << endl;
        cout << "Error estandar de la estimacion: " << s << endl;
        if (desvest > s) {
            cout << "El ajuste fue adecuado." << endl;
        }
        else {
            cout << "No hubo un ajuste relevante." << endl;
        }

        // Obtiene el coeficiente de determinación y el coeficiente
        // de correlación.
        r = (st - sr) / st;
        cout << "Coeficiente de determinacion: " << r << endl;
        cout << "Coeficiente de correlacion: " << sqrt(r) << endl;



    }else if (modo == 1){
        for (int i = 0; i < n; i++) {
            logx[i] = log10(x[i]);
            logy[i] = log10(y[i]);
        }
        beta = (logy[1] - logy[0]) / (logx[1] - logx[0]);
        alfa = beta*(-logx[0]) + logy[0];

        cout << "La linealizacion es: log(y) = " << beta << "log(x) + " << alfa << endl;
        cout << "La curva ajustada es: y = " << pow(10, alfa) << "x ^ " << beta << endl;

        // Se sacan los valores necesarios para la fórmula de
        // la regresión lineal.
        sumx = sumatoria(logx, 0, n);
        sumy = sumatoria(logy, 0, n);
        sumx2 = sumatoria(logx, 1, n);
        sumxy = sumatoriaMult(logx, logy, n);
        promx = sumx / n;
        promy = sumy / n;

        // Se aplican las fórmulas de a1 y a0 con los datos
        // obtenidos previamente.
        a1 = ((n*sumxy) - (sumx*sumy)) / ((n*sumx2) - pow(sumx, 2));
        a0 = promy - a1*promx;

        // Obtiene sr y st para la cuantificación del error.
        sr = getSr(logx, logy, a0, a1, n);
        st = getSt(logy, promy, n);

        // Obtiene la desviación estándar y el error estándar de la
        // estimación.
        desvest = sqrt(st / (n - 1));
        s = sqrt(sr / (n - 2));


        // Determina si la desviación mejoro, y por tanto el ajuste
        // fue bueno.
        cout << "Desviacion estandar: " << desvest << endl;
        cout << "Error estandar de la estimacion: " << s << endl;
        if (desvest > s) {
            cout << "El ajuste fue adecuado." << endl;
        }
        else {
            cout << "No hubo un ajuste relevante." << endl;
        }

        // Obtiene el coeficiente de determinación y el coeficiente
        // de correlación.
        r = (st - sr) / st;
        cout << "Coeficiente de determinacion: " << r << endl;
        cout << "Coeficiente de correlacion: " << sqrt(r) << endl;

    }
}

int main() {
    // Arreglos de valores de x y y.

    double x[] = { 1,2,3,4,5,6,7 };
    double y[] = { 0.5, 2.5, 2, 4, 3.5, 6, 5.5 };

    //double x2[] = {0.75, 2, 3, 4, 6, 8, 8.5};
    //double y2[] = {1.2, 1.95, 2, 2.4, 2.4, 2.7, 2.6};

    // Llamada al método.
    regresionLineal(x, y, (sizeof(x)/sizeof(x[0])));//------------REGRESION LINEAL---------

    //cout << endl

    //double x2[] = { 1,2,3,4,5 };
    //double y2[] = { 0.5, 1.7, 3.4, 5.7, 8.4 };

   // double x2[] = { 2.5, 3.5, 5, 6, 7.5, 10, 12.5, 15, 17.5, 20 };
    //double y2[] = { 13, 11, 8.5, 8.2, 7, 6.2, 5.2, 4.8, 4.6, 4.3 };

    //double x2[] = { 0.4, 0.8, 1.2, 1.6, 2, 2.3 };
    //double y2[] = { 800, 975, 1500, 1950, 2900, 3600 };
    //linealizacion(x2, y2, (sizeof(x2) / sizeof(x2[0])), 0);//--------LINEALIZACION-----------POTENCIAL(1) Y EXPONENCIAL(0)--------------

    return 0;
}
