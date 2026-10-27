#include <iostream>

using namespace std;

// funkcia obchuslennia serednogo harmoninogo dwoh chysel
double PrintGarm(double x, double y) {
    return (2.0 * x * y) / (x + y);
}

int main() {
    double a, b;

    while (true) {
        cout << "\n Enter two numbers (or 0 to stop):" << endl;
        cout << "First number: ";
        cin >> a;
        cout << "Second number: ";
        cin >> b;

        // perewirka ymowy zypinki: yaksho hoch odne z chysel doriwnue 0
        if (a == 0 || b == 0) {
            cout << "Entered 0. Program stopped." << endl;
            break;
        }

        // obchyslennia ta vyvid rezultatu
        double harmonic_mean = PrintGarm(a, b);
        cout << "Harmonic mean of " << a << " and " << b 
             << " is: " << harmonic_mean << endl;
    }

    return 0;
}
