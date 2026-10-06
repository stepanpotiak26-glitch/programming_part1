#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double i = 15;

    double ax = 0, ay = 0;
    double bx = i, by = i - 1;
    double cx = -i, cy = i + 1;

    double a, b, c;
    double p;
    double ma, Wc;

    a = sqrt(pow(bx - cx, 2) + pow(by - cy, 2));
    b = sqrt(pow(cx - ax, 2) + pow(cy - ay, 2));
    c = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));

    p = (a + b + c) / 2;

    ma = 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);

    Wc = (2 / (a + b)) * sqrt(a * b * p * (p - c));

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "p = " << p << endl;

    cout << "ma = " << ma << endl;
    cout << "Wc = " << Wc << endl;

    return 0;
}
