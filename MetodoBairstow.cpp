//Bairstow

#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
	return pow(x, 2);
}

int main() {
    // 1.25, -3.875, 2.125, 2.75, -3.5, 1
    double error, r, s, dr, ds;
    int degree;
    cout << "error: ";
    cin >> error;
    cout << "r: ";
    cin >> r;
    cout << "s: ";
    cin >> s;
    cout << "Degree of polynomial: ";
    cin >> degree;
    double coefficients[degree+1];
    for(int i = degree, j = 0; i >= 0; i--, j++){
        cout << "Coefficient of degree " << i << ": ";
        cin >> coefficients[j];
    }
    
    do {
        double bs[degree+1];
        for(int i = degree, j = 0; i >= 0; i--, j++){
            if(i == degree){
                bs[j] = coefficients[j];
            }
            else if(i == degree-1){
                bs[j] = coefficients[j] + bs[j-1]*r;
            }
            else {
                bs[j] = coefficients[j] + bs[j-1]*r + bs[j-2]*s;
            }
        }
        
        double cs[degree+1];
        for(int i = degree, j = 0; i >= 0; i--, j++){
            if(i == degree){
                cs[j] = bs[j];
            }
            else if(i == degree-1){
                cs[j] = bs[j] + cs[j-1]*r;
            }
            else {
                cs[j] = bs[j] + cs[j-1]*r + cs[j-2]*s;
            }
        }
        
        cout << "bs: ";
        for(int i = 0; i < degree+1; i++){
            cout << bs[i] << " ";
        }
        cout << endl;
        
        cout << "cs: ";
        for(int i = 0; i < degree+1; i++){
            cout << cs[i] << " ";
        }
        cout << endl;
        
        dr = ((-bs[degree-1])*cs[degree-2]-(-bs[degree])*(cs[degree-3]))/(cs[degree-2]*cs[degree-2]-cs[degree-1]*cs[degree-3]);
        ds = (cs[degree-2]*(-bs[degree])-cs[degree-1]*(-bs[degree-1]))/(cs[degree-2]*cs[degree-2]-cs[degree-1]*cs[degree-3]);
        
        cout << "dr: " << dr << endl;
        cout << "ds: " << ds << endl;
        
        r = r + dr;
        s = s + ds;
    } while(abs(dr/r) > error || abs(ds/s) > error);
    
    double x1 = (r + sqrt(pow(r,2)+4*s))/2;
    double x2 = (r - sqrt(pow(r,2)+4*s))/2;
    
    cout << endl << "x1: " << x1 << " x2: " << x2 << endl;
}
