//Simpson's 3/8th Rule for Evaluation of Definite Integrals
#include<iostream>
#include<cmath>
using namespace std;
double f(double x)
{
    double a = sin(pow(x, 2));    //write the function whose definite integral is to be calcuated here
    return a;
}
int main()
{    cout.precision(6);        //set the precision
    cout.setf(ios::fixed);
    int n,i;            //n is for subintervals and i is for loop
    double a,b,c,h,sum=0,integral;
    cout<<"\nIngresa limites de integracion,\n\nLimite inicial, a= ";
    cin>>a;
    cout<<"\nLimite final, b=";                //get the limits of integration
    cin>>b;
    cout<<"\nIngresa numero de segmentos (DEBE SER MULTIPLO DE 3), \nn=";        //get the no. of subintervals
    cin>>n;
    double x[n+1],y[n+1];
    h=(b-a)/n;                        //get the width of the subintervals
    for (i=0;i<n+1;i++)
    {                        //loop to evaluate x0,...xn and y0,...yn
        x[i]=a+i*h;                //and store them in arrays
        y[i]=f(x[i]);
    }
    for (i=1;i<n;i++)
    {
        if (i%3==0)
        sum=sum+2*y[i];
        else
        sum=sum+3*y[i];
    }
    integral=3*h/8*(y[0]+y[n]+sum);    //3h/8*[y0+yn+3*(y1+y2+y4+...)+2*(y3+y6+y9+...+)]
    cout<<"\nLa integral definida es "<<integral<<"\n"<<endl;
    return 0;
}
/*
para 1/3, los puntos deben ser impares. Osea segmentos (n) pares
para 3/8, siempre deben de ser 4 puntos. Osea 3 segmentos (n)
puntos = segmentos + 1
segmentos = puntos - 1
rango entre valores de x se saca con (b - a) / n
*/
