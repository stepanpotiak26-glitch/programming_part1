//Z Yykorystanniam dwowymirnogo vektora

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Funktsiia f19(x)
double f19(double x) {
    return 13.4 * cos(abs(x)) * sin(x * x - 2.25);
}

// Funktsiia f20(x)
double f20(double x) {
    return abs(cos(x * x - 3.8)) / 4.5 - 9.7 * sin(x - 3.1);
}

int main() {
    const int ROWS = 4;
    const int COLS = 4;

    // Ogoloshennia dvovymirnoho vektora
    vector<vector<double>> a(ROWS, vector<double>(COLS));

    // 1. Zapovnennia ta vyvedennia vektora
    cout << "Dvovymirnyi vektor A [4x4]:" << endl;
    for (int k = 1; k <= ROWS; ++k) {
        for (int n = 1; n <= COLS; ++n) {
            a[k - 1][n - 1] = n * f19(k) + sin(k) * f20(n);
            cout << setw(10) << fixed << setprecision(3) << a[k - 1][n - 1] << " ";
        }
        cout << endl;
    }

    // 2. Poshuk vidiemnykh elementiv ta maksyma
    double negativeProduct = 1.0;
    bool hasNegative = false;

    double maxVal = a[0][0];
    int maxRow = 0;
    int maxCol = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (a[i][j] < 0) {
                negativeProduct *= a[i][j];
                hasNegative = true;
            }

            if (a[i][j] > maxVal) {
                maxVal = a[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // 3. Vyvedennia rezultativ
    cout << "\n=== Rezultaty ===" << endl;
    if (hasNegative) {
        cout << "Dobutok vidiemnykh elementiv: " << negativeProduct << endl;
    } else {
        cout << "Vidiemnykh elementiv u matrytsi nemaie." << endl;
    }

    cout << "Maksymalnyi element: " << maxVal << endl;
    cout << "Indeksi maksyma (riadok, kolonka): [" << maxRow << "][" << maxCol << "]" 
         << " (k=" << maxRow + 1 << ", n=" << maxCol + 1 << ")" << endl;

    return 0;
}
