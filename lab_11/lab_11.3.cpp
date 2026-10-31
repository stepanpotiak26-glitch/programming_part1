#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char type;
    double x;
    cout << "Enter work type (A, B, C): ";
    cin >> type;
    cout << "Enter x: ";
    cin >> x;

    double f = abs(pow(cos(x), 2) - 0.51) * sin(3 * x - 4) - 4.44;
    double y = 0;
    double taxRate = 0;

    if (type == 'A' || type == 'a' ) goto case_a;
    if (type == 'B' || type == 'b' ) goto case_b;
    if (type == 'C' || type == 'c' ) goto case_c;
    goto default_case;

case_a:
    y = 100 * abs(f) + 50;
    taxRate = 0.10;
    goto end_block;

case_b:
    y = 150 * abs(f) + 100;
    taxRate = 0.15;
    goto end_block;

case_c:
    y = 200 * abs(f) + 135;
    taxRate = 0.20;
    goto end_block;

default_case:
    cout << "Invalid work type!" << endl;
    return 1;

end_block:
    double tax = y * taxRate;
    double total = y - tax;

    cout << "Accrued amount (y): " << y << endl;
    cout << "Tax amount: " << tax << endl;
    cout << "Net amount: " << total << endl;

    return 0;
} 
