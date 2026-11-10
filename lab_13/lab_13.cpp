#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f16(double x) {
    return 2.0 * sin(x) * sin(2.0 * x - 1.5) * cos(2.0 * x + 1.5) - 6.0;
}

int main() {
    const int i = 8;          // nomer variantu
    const double step = 0.8;  // krok h = 0.1 * i = 0.8
    const double x_start = 0.0;
    const double x_end = 8.0;

    int positive_count = 0;
    int negative_count = 0;

    // shapka tablytsi
    cout << "-------------------------" << endl;
    cout << setw(10) << "x" << " | " << setw(10) << "y" << endl;
    cout << "-------------------------" << endl;

    cout << fixed << setprecision(4);

    // tabulacia funkcii za dopomogoyu cykly for
    // oskilky x diysne chyslo, dodaemo step/2 dla tochnogo zavershennya cykly
    for (double x = x_start; x <= x_end + step / 2.0; x += step) {
        double y = f16(x);
        
        cout << setw(10) << x << " | " << setw(10) << y << endl;

        // pidrahunok kilkosti dodatnykh i vid'yemnykh znachen'
        if (y > 0) {
            positive_count++;
        } else if (y < 0) {
            negative_count++;
        }
    }

    cout << "-------------------------" << endl << endl;

    cout << "kilkist dodatnykh znachen': " << positive_count << endl;
    cout << "kilkist vid'yemnykh znachen': " << negative_count << endl;

    return 0;
}
