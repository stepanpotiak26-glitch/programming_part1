#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function f_13(x) to compute 'a'
double f13(double x) {
    double sin_x = sin(x);
    double cos_x = cos(x);
    return pow(sin_x, 2) * pow(cos_x, 3) - sin_x + 5.2;
}

// Function f_14(x) to compute 'b'
double f14(double x) {
    return 2.0 * sin(x) * sin(2.0 * x - 1.5) * cos(2.0 * x + 1.5) - 6.0;
}

int main() {
    const int i = 8; // Option / Variant 8

    double a = 0.0;
    double b = 1.0;

    // Calculate sum 'a' (k from 8 to 13) using do-while
    int k_a = i;
    do {
        a += f13(k_a);
        k_a++;
    } while (k_a <= i + 5);

    // Calculate product 'b' (k from 8 to 16) using do-while
    int k_b = i;
    do {
        b *= f14(k_b);
        k_b++;
    } while (k_b <= i + 8);

    // Calculate z = a^2 + 3b
    double z = pow(a, 2) + 3.0 * b;

    // Output results
    cout << fixed << setprecision(6);
    cout << "Variant (i): " << i << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "z = " << z << endl;

    return 0;
}
