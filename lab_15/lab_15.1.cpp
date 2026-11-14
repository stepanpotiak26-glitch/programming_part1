// Variant 8: y_k = f_18(k), k = 1..7, f_18(x) = |sin(x^2/1.5 - 2)| + 11.73*cos(1.6x - 1)
// Zavdannya 8: obchyslyty sumu drugogo dodatnogo ta tretogo elementiv (odnovymirnyj masyv).
#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return fabs(sin(x * x / 1.5 - 2)) + 11.73 * cos(1.6 * x - 1);
}

int main() {
    const int N = 7;
    double y[N];

    // utvorennya ta vyvedennya masyvu
    cout << "Masyv y:" << endl;
    for (int k = 1; k <= N; k++) {
        y[k - 1] = f(k);
        cout << "y[" << k << "] = " << y[k - 1] << endl;
    }

    // poshuk drugogo dodatnogo elementa
    int cnt = 0, idx = -1;
    for (int i = 0; i < N; i++) {
        if (y[i] > 0) {
            cnt++;
            if (cnt == 2) { idx = i; break; }
        }
    }

    if (idx == -1) {
        cout << "Drugogo dodatnogo elementa nemaye." << endl;
    } else {
        double sum = y[idx] + y[2]; // y[2] - tretij element
        cout << "Drugyj dodatnyj: y[" << idx + 1 << "] = " << y[idx] << endl;
        cout << "Tretij element: y[3] = " << y[2] << endl;
        cout << "Suma = " << sum << endl;
    }
    return 0;
}
