#include <iostream>
using namespace std;

void PrintSymbol(char symbol, int count) {    // funkcia PrintSymbol priimae symvol ta kilkist povtoren
    for (int i = 0; i < count; i++) {
        cout << symbol;
    }
    cout << endl;
}

int main() {
    char sym;
    int num;

    cout << "vvedit symbol: ";
    cin >> sym;

    cout << "vvedit kilkist povtoren: ";
    cin >> num;

   
    PrintSymbol(sym, num);       // vykluk funkcii PrintSymbol

    return 0;
}
