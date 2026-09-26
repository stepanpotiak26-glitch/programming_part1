#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double i;

    cout << "Vvedit nomer variantu: ";
    cin >> i;

    double a = sqrt(4 * i * i + 4);
    double b = sqrt(2 * i * i + 2 * i + 1);
    double c = sqrt(2 * i * i - 2 * i + 1);

    double Ma = i;

    double p = (a + b + c) / 2;

    double Wc = (2 * sqrt(a * b * p * (p - c))) / (a + b);

    cout << "Ma (Mediana) = " << Ma << endl;
    cout << "Wc (Bisektrysa) = " << Wc << endl;

    return 0;
}
