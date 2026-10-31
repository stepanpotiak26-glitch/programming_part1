#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char type;
    double x;
    cout << "Enter work type (A, B, C): ";
    cin >> type;
    cout << "Enter x: ";
    cin >> x;
    // Obchyslennia znachennia funktsii
    double f = abs(pow(cos(x), 2) - 0.51) * sin(3 * x - 4) - 4.44;
    double y = 0;
    double taxRate = 0;
    // Vybir typu robit za dopomohoiu switch
    switch (type) {
        case 'A':
        case 'a':
            y = 100 * abs(f) + 50;
            taxRate = 0.10;
            break;
        case 'B':
        case 'b':
            y = 150 * abs(f) + 100;
            taxRate = 0.15;
            break;
        case 'C':
        case 'c':
            y = 200 * abs(f) + 135;
            taxRate = 0.20;
            break;
        default:
            cout << "Invalid work type!" << endl;
            return 1;
    }
        // Rozrakhunok podatku ta kincevoi sumy
    double tax = y * taxRate;
    double total = y - tax;

    cout << "Accrued amount (y): " << y << endl;       //Accrued amount- narahovana suma 
    cout << "Tax amount: " << tax << endl;            // Tax amount- suma podatku 
    cout << "Net amount: " << total << endl;         // Net amount- kintseva suma

    return 0;
}
