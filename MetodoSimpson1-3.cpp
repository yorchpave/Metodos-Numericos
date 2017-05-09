//Simpson's 1/3rd Rule for Evaluation of Definite Integrals
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
    cout<<"\nIngresa numero de segmentos (DEBE SER PAR), \nn=";        //get the no. of subintervals
    cin>>n;
    double x[n+1],y[n+1];
    h=(b-a)/n;                        //get the width of the subintervals
    for (i=0;i<n+1;i++)
    {                        //loop to evaluate x0,...xn and y0,...yn
        x[i]=a+i*h;                //and store them in arrays
        y[i]=f(x[i]);
    }
    for (i=1;i<n;i+=2)
    {
        sum=sum+4.0*y[i];                //loop to evaluate 4*(y1+y3+y5+...+yn-1)
    }
    for (i=2;i<n-1;i+=2)
    {
        sum=sum+2.0*y[i];                /*loop to evaluate 4*(y1+y3+y5+...+yn-1)+
                                        2*(y2+y4+y6+...+yn-2)*/ 
    }
    integral=h/3.0*(y[0]+y[n]+sum);    //h/3*[y0+yn+4*(y1+y3+y5+...+yn-1)+2*(y2+y4+y6+...+yn-2)]
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
