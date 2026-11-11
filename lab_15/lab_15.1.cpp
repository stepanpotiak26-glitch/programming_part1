#include <iostream>
#include <cmath>

using namespace std;

// Funktsiia 8-ho variantu
double f18(double x) {
    return abs(sin(x * x / 1.5 - 2.0)) + 11.73 * cos(1.6 * x - 1.0);
}

int main() {
    const int n = 7;
    double* y = new double[n]; // Dynamichnyi masiv

    // Zapovnennia ta vyvedennia masyvu
    cout << "Masyv y:" << endl;
    for (int k = 1; k <= n; ++k) {
        y[k - 1] = f18(k);
        cout << "y[" << k << "] = " << y[k - 1] << endl;
    }

    // Poshuk druhoho dodatnoho elementa
    int positiveCount = 0;
    double secondPositive = 0;
    bool foundSecondPositive = false;

    for (int i = 0; i < n; ++i) {
        if (y[i] > 0) {
            positiveCount++;
            if (positiveCount == 2) {
                secondPositive = y[i];
                foundSecondPositive = true;
                break;
            }
        }
    }

    // Tretii element masyvu indeks 2
    double thirdElement = y[2];

    // Obchyslennia ta vyvedennia rezultatu
    if (foundSecondPositive) {
        double sum = secondPositive + thirdElement;
        cout << "\nDrugii dodatnii element: " << secondPositive << endl;
        cout << "Tretii element masyvu: " << thirdElement << endl;
        cout << "Suma druhoho dodatnoho ta tretoho elementiv: " << sum << endl;
    } else {
        cout << "\nU masyvi nemaie druhoho dodatnoho elementa!" << endl;
    }

    // Zvilnennia pamiati
    delete[] y;

    return 0;
}
