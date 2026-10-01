#include <iostream>
#include <iomanip>
using namespace std;
int main () {
 
    double poch_znach, krok_zminu, kilkist_radkiv;
    setw(10);

    cout << "vvedit pochatkove znachennia miru :";
    cin >> poch_znach ;
    cout << "vvedit krok zminu : ";
    cin >> krok_zminu ;
    cout << "vvedit kilkist radkiv (10-15): ";
    cin >> kilkist_radkiv ;
    cout << fixed << setprecision(2);


cout << "\n=======================================================\n";
    cout << " | " << left << setw(12) << "unicu" ;
    cout << " | " << setw(15) << "grams" ;
    cout << " | " << setw(15) << "karat" << " |\n";
    cout << "=======================================================\n";

    double current_val = poch_znach;
    for (int i = 0; i < kilkist_radkiv; ++i) {
       
        double grams = current_val * 28.353495;
        double carats = current_val * 142.0;

        cout << " | " << left << setw(12) << current_val ;
        cout << " | " << setw(15) << grams ;
        cout << " | " << setw(15) << carats << " |\n";

        current_val += krok_zminu;

    }

    cout << "=======================================================\n";

    return 0;
}
