#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a = 0.0;         // Pochatkovi dani 
    double b = 15.0;
    double h = 1.5;
    // Zminni dlya dobutku
    double product = 1.0;
    bool foundProduct = false;
    // Zminni dlya poshuku maksymumu
    double maxX = a;
    double maxY = abs(pow(cos(a), 2) - 0.51) * abs(sin(3 * a - 4) - 4.44);
    bool firstPoint = true;

    cout << setw(10) << "x" << setw(15) << "y" << endl;
    cout << "----------------------------------------" << endl;
    // Tsykl tablyatsiyi funktsiyi
    for (double x = a; x <= b + 1e-9; x += h) {
        double y = abs(pow(cos(x), 2) - 0.51) * abs(sin(3 * x - 4) - 4.44); // Obchyslennya znachennya funktsiyi y
        // Vyvid potochnyh x ta y
        cout << setw(10) << fixed << setprecision(4) << x 
             << setw(15) << fixed << setprecision(4) << y << endl;
        // Perevirka umovy
        if (y > 1.0 && y < 3.1) {
            product *= y;
            foundProduct = true;
        }
        // Poshuk maksimalnogo y ta vidpovidnogo x
        if (firstPoint || y > maxY) {
            maxY = y;
            maxX = x;
            firstPoint = false;
        }
    }

    cout << "----------------------------------------" << endl;
    if (foundProduct) {
        cout << "Dobutok znachen (1 < y < 3.1): " << product << endl;
    } else {
        cout << "Net znachen, sho zadovolnyayut nerivnist." << endl;
    }
    cout << "Maksymalne znachennya y: " << maxY << " pry x = " << maxX << endl;

    return 0;
}
