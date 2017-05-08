#include<iostream>
//#include<conio>

using namespace std;
int main()
{
    int n,i,j;
    float mult,sum=0,x[10],f[10],a;

    cout<<"Ingresa numero de puntos:" << endl;
    cin>>n;
    cout<<"Ingresa valores para \"x\" y \"y\" en el siguiente orden: " << endl;
    cout << "x1" << endl;
    cout << "y1" << endl;
    cout << "x2" << endl;
    cout << "y2" << endl;
    cout << "y así sucesivamente..." << endl;
    
    for(i=0;i<n;i++)
	cin>> x[i] >> f[i];
        
    cout<<"\nIngresa tu \"x\" para el cálculo: " << endl;
    cin>>a;

    for(i=0;i<=n-1;i++)
    {
    mult=1;
        for(j=0;j<=n-1;j++)
        {
            if(j!=i)
            mult*=(a-x[j])/(x[i]-x[j]);
        }
        sum+=mult*f[i];
    }
    cout<<"\nValor estimado de f(x) = " << sum << endl;
    
    return 0;
}
