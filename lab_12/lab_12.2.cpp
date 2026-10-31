#include <iostream>
#include <cmath>

using namespace std;
// Funktsiya  z tablytsi 
double f15(double x) {
    return fabs(cos(x) * cos(x) - 0.51) * sin(3.0 * x - 4.0) - 4.44;
}
int main() {
    int i = 15; 
    double a = 0.0;
    double b = 1.0; // Pochatkove znachennya dlya dobutku

    // Obchyslennya sumy a: vid k = i do i + 5
    for (int k = i; k <= i + 5; k++) {
        a += f15(static_cast<double>(k));
    }

    // Obchyslennya dobutku b: vid k = i do i + 8
    for (int k = i; k <= i + 8; k++) {
        b *= f15(static_cast<double>(k));
    }

    // Obchyslennya z = ctg(2a) - b (variant 15)
    // ctg(x) predstavleno yak cos(x) / sin(x)
    double angle = 2.0 * a;
    double ctg_2a = cos(angle) / sin(angle);
    double z = ctg_2a - b;

    cout << "Variant: " << i << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "z = " << z << endl;

    return 0;
}
