#include <iostream>
using namespace std;

// funkcia Calc ne povertae znachennia (tip void)
void Calc(double a, char op, double b) {
    if (op == '+') {
        cout << "resultat dorivnue : " << a + b << endl;
    } 
    else if (op == '-') {
        cout << "resultat dorivnue : " << a - b << endl;
    } 
    else if (op == '*') {
        cout << "resultat dorivnue : " << a * b << endl;
    } 
    else if (op == '/') {
        cout << "resultat dorivnue : " << a / b << endl;
    }
}

int main() {
    double operand1, operand2;
    char operation;
    char again;

    do {
        cout << "vvedit pershiy operand, operaciu i drugiy operanb: ";
        cin >> operand1 >> operation >> operand2;

        Calc(operand1, operation, operand2);    // vyklyk funkcii Calc

        cout << "Vykonaty she odny operaciu (y/n)? ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
