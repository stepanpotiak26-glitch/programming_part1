//Yykoristannia dwowymirnogo masyvu

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Funktsiia f19(x) dlia i = 8 (8 + 11 = 19)
double f19(double x) {
    return 13.4 * cos(abs(x)) * sin(x * x - 2.25);
}

// Funktsiia f20(x) dlia i = 8 (8 + 12 = 20)
double f20(double x) {
    return abs(cos(x * x - 3.8)) / 4.5 - 9.7 * sin(x - 3.1);
}

int main() {
    const int ROWS = 4;
    const int COLS = 4;
    double a[ROWS][COLS];

    // 1. Zapovnennia та vyvedennia matritsi (k, n = 1..4)
    cout << "Matrytsia A [4x4]:" << endl;
    for (int k = 1; k <= ROWS; ++k) {
        for (int n = 1; n <= COLS; ++n) {
            a[k - 1][n - 1] = n * f19(k) + sin(k) * f20(n);
            cout << setw(10) << fixed << setprecision(3) << a[k - 1][n - 1] << " ";
        }
        cout << endl;
    }

    // 2. Obchyslennia dobutku vidiemnykh elementiv
    double negativeProduct = 1.0;
    bool hasNegative = false;

    // 3. Poshuk maksimelnoho elementa ta ioho indeksiv
    double maxVal = a[0][0];
    int maxRow = 0;
    int maxCol = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Perevirka na vidiemnyst
            if (a[i][j] < 0) {
                negativeProduct *= a[i][j];
                hasNegative = true;
            }

            // Poshuk maksymuma
            if (a[i][j] > maxVal) {
                maxVal = a[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // 4. Vyvedennia rezultativ
    cout << "\n=== Rezultaty ===" << endl;
    if (hasNegative) {
        cout << "Dobutok vidiemnykh elementiv: " << negativeProduct << endl;
    } else {
        cout << "Vidiemnykh elementiv u matrytsi nemaie." << endl;
    }

    cout << "Maksymalnyi element: " << maxVal << endl;
    cout << "Indeksi maksyma (riadok, kolonka): [" << maxRow << "][" << maxCol << "]" 
         << " (abo k=" << maxRow + 1 << ", n=" << maxCol + 1 << " u matematychnykh indeksakh)" << endl;

    return 0;
}
