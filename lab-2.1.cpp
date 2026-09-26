#include <iostream>
using namespace std;

int main() {
    double gas1;
    double gas2; 
    double gas3;
    double gas4;
    double km1 = 67308.0;
    double km2 = 68750.5;

    cout <<  "Enter the amount of gas in liters 1: ";
    cin >> gas1;
    cout << "Enter the amount of gas in liters 2: ";
    cin >> gas2;
    cout << "Enter the amount of gas in liters 3: ";
    cin >> gas3;
    cout << "Enter the amount of gas in liters 4: ";
    cin >> gas4;
    
    cout << "distance covered: \n" << km2 - km1 << endl;

    cout << "fuel consumed \n" <<  (km2 - km1) / (gas1 + gas2 + gas3 + gas4) << (" km/l ")  << endl;

    return 0;
}