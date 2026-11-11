#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    // Vidkryttia failu dlia zapysu
    ofstream outfile("multiplication_table.txt");

    // Perevirka, chy vdalosia vidkryty fail
    if (!outfile.is_open()) {
        cout << "Pomylka vidkryttia failu!" << endl;
        return 1;
    }

    // Formuvannia та zapys tablytsi mnozhennia 9x9 у fail
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            // setw(4) vyrivniuie chysla dlia krasyvoho matrichnoho vyhliadu
            outfile << setw(4) << i * j;
        }
        outfile << endl; // Perekhod na novyi riadok matritsi
    }

    // Zakryttia failu
    outfile.close();

    cout << "Tablytsia mnozhennia uspishno zapysana u fail 'multiplication_table.txt'!" << endl;

    return 0;
}
