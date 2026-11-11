#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    srand(time(NULL));

    const int TOWNS = 6;
    const int CANDIDATES = 5;
    const int VARIANT = 8;

    // Dvovymirnyi vektor dlia tablytsi holosiv
    vector<vector<int>> votes(TOWNS, vector<int>(CANDIDATES));

    // 1. Zapovnennia ta vyvedennia
    cout << "=== Tablytsia rezul'tativ holosuvannia (Vektor) ===" << endl;
    cout << setw(10) << "Misto/Kand";
    for (int j = 1; j <= CANDIDATES; ++j) {
        cout << setw(12) << "Kand " + to_string(j);
    }
    cout << endl;

    for (int i = 0; i < TOWNS; ++i) {
        cout << setw(10) << "Punkt " + to_string(i + 1);
        for (int j = 0; j < CANDIDATES; ++j) {
            votes[i][j] = rand() % 500 + 50 * VARIANT;
            cout << setw(12) << votes[i][j];
        }
        cout << endl;
    }

    // 2. Vvedennia n
    int n;
    cout << "\nVvedit chislo n (poroh kilkosti opytanykh): ";
    cin >> n;

    // 3. Obchyslennia sumy po riadkakh ta zapys u vektor
    vector<int> resultTowns; // Odnovymirnyi vektor dlia nomeriv punktiv

    cout << "\n=== Rezul'taty dlia Varianta 8 ===" << endl;
    for (int i = 0; i < TOWNS; ++i) {
        int totalTownVotes = 0;
        for (int j = 0; j < CANDIDATES; ++j) {
            totalTownVotes += votes[i][j];
        }

        cout << "Punkt " << (i + 1) << ": vsyoho opytano = " << totalTownVotes << endl;

        if (totalTownVotes > n) {
            resultTowns.push_back(i + 1);
        }
    }

    // 4. Vyvedennia rezultativ
    if (!resultTowns.empty()) {
        cout << "\nNaseleni punkty, de kilkist opytanykh bilsha za " << n << ":" << endl;
        cout << "Odnovymirnyi vektor nomeriv: [ ";
        for (int townNum : resultTowns) {
            cout << townNum << " ";
        }
        cout << "]" << endl;
    } else {
        cout << "\nNemaie naselenykh punktiv z kilkistiu opytanykh bilshoie za " << n << "." << endl;
    }

    return 0;
}
