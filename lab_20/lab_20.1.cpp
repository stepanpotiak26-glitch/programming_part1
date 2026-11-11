#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    srand(time(NULL));

    const int TOWNS = 6;      // k = 1..6
    const int CANDIDATES = 5; // n = 1..5
    const int VARIANT = 8;    // i = 8

    int votes[TOWNS][CANDIDATES];

    // 1. Zapovnennia ta vyvedennia tablytsi holosuvannia
    cout << "=== Tablytsia rezul'tativ holosuvannia ===" << endl;
    cout << setw(10) << "Misto/Kand";
    for (int j = 1; j <= CANDIDATES; ++j) {
        cout << setw(12) << "Kand " + to_string(j);
    }
    cout << endl;

    for (int i = 0; i < TOWNS; ++i) {
        cout << setw(10) << "Punkt " + to_string(i + 1);
        for (int j = 0; j < CANDIDATES; ++j) {
            // Formula: rand() % 500 + 50 * i (dlia i = 8 -> rand() % 500 + 400)
            votes[i][j] = rand() % 500 + 50 * VARIANT;
            cout << setw(12) << votes[i][j];
        }
        cout << endl;
    }

    // 2. Vvedennia porohovoho znachennia n
    int n;
    cout << "\nVvedit chislo n (poroh kilkosti opytanykh): ";
    cin >> n;

    // 3. Obchyslennia opytanykh u kozhnomu misti та poshuk tykh, de sum > n
    int resultTowns[TOWNS]; // Odnovymirnyi masyv dlia nomeriv mist
    int count = 0;

    cout << "\n=== Rezul'taty dlia Varianta 8 ===" << endl;
    for (int i = 0; i < TOWNS; ++i) {
        int totalTownVotes = 0;
        for (int j = 0; j < CANDIDATES; ++j) {
            totalTownVotes += votes[i][j];
        }

        cout << "Punkt " << (i + 1) << ": vsyoho opytano = " << totalTownVotes << endl;

        if (totalTownVotes > n) {
            resultTowns[count] = i + 1; // Zberihaiemo nomer punktu (1..6)
            count++;
        }
    }

    // 4. Vyvedennia odnovymirnoho masyvu z rezul'tatamy
    if (count > 0) {
        cout << "\nNaseleni punkty, de kilkist opytanykh bilsha za " << n << ":" << endl;
        cout << "Odnovymirnyi masyv nomeriv: [ ";
        for (int i = 0; i < count; ++i) {
            cout << resultTowns[i] << " ";
        }
        cout << "]" << endl;
    } else {
        cout << "\nNemaie naselenykh punktiv z kilkistiu opytanykh bilshoie za " << n << "." << endl;
    }

    return 0;
}
