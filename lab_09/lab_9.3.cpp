#include <iostream>

using namespace std;

// funkcia obchuslennia faktorialu
long long PrintFactorial( int n ) {
    if (n < 0) {
        return -1; // faktorial minusowyh chysel ne isnue
    }
    
    long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    int num;

    while (true) {
        cout << "\n Enter a number to calculate factorial (or negative number to stop): ";
        cin >> num;

        // perewirka ymowy zypinki
        if (num < 0) {
            cout << "Negative number entered. Program stopped." << endl;
            break;
        }

        // obchyslennia ta vyvid rezultatu
        long long result = PrintFactorial(num);
        cout << num << "! = " << result << endl;
    }

    return 0;
}
