#include <iostream>
#include <cmath>
using namespace std;

double fx(double y, double z) {
    
    return (7 + y - z)/2;
}

double fy(double x, double z) {
    
    return (6 - x + z)/2;
}

double fz(double x, double y) {
    
    return 12 - x - y;
}

int main() {
    
    double x, y, z;
    double error = pow(10, -12);
    int i;
    x = y = z = 0.0;
    
    do {
        
        x = fx(y, z);
        y = fy(x, z);
        z = fz(x, y);
        i++;
        cout << x << " | " << y << " | " << z << " | " << i << endl;
    }
    while(abs(x + y + z - 12)>error || abs(2*x - y + z - 7)>error || abs(x + 2*y - z - 6)>error);
    
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "i = " << i << endl;

}
