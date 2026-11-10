#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Funktsiya f_17(x) z tablytsi (dlya i = 8, 8 + 9 = 17)
double f17(double x) {
    return abs(pow(cos(2.0 * x), 3) + 2.0 * sin(x / 1.2 - 3.4)) + 10.51 * cos(abs(3.0 * x));
}

int main() {
    const int i = 8;
    const int start_year = 2000;
    const int end_year = 2010;
    const int n = end_year - start_year + 1; // 11 rokiv (2000-2010)

    // Dynamichni masyvy
    int* years = new int[n];
    double* y = new double[n];

    // Zapovnennya masyviv ta vyvedennya tablytsi
    cout << "----------------------------------------" << endl;
    cout << setw(10) << "Rik (k)" << " | " << setw(20) << "Prybutok (yk)" << endl;
    cout << "----------------------------------------" << endl;
    cout << fixed << setprecision(2);

    for (int k = 0; k < n; k++) {
        years[k] = start_year + k;
        y[k] = 100.0 * f17(years[k]);
        cout << setw(10) << years[k] << " | " << setw(20) << y[k] << endl;
    }
    cout << "----------------------------------------" << endl << endl;

    // Obchyslennya zavdannya 8
    double sum_losses = 0.0;
    bool has_losses = false;
    double max_loss_val = 0.0; // Naibilshyi zbytok (naimenshe vid'yemne znachennya)
    int max_loss_year = -1;

    for (int k = 0; k < n; k++) {
        if (y[k] < 0) { // Yakshcho y_k < 0 - tse zbytok
            sum_losses += y[k];

            if (!has_losses || y[k] < max_loss_val) {
                max_loss_val = y[k];
                max_loss_year = years[k];
                has_losses = true;
            }
        }
    }

    // Vyvedennya rezultativ
    if (has_losses) {
        cout << "Suma vsikh zbytkiv: " << sum_losses << " u.o." << endl;
        cout << "Naibilshyi zbytok buv u " << max_loss_year << " rotsi." << endl;
        cout << "Velichyna naibilshoho zbytku: " << max_loss_val << " u.o." << endl;
    } else {
        cout << "Povidomlennya: Zbytkiv protyahom 10 rokiv ne bulo!" << endl;
    }

    // Zvilnennya pam'yati
    delete[] years;
    delete[] y;

    return 0;
}
