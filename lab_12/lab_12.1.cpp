#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char ch;
    
    // Vvedennya liter do-while zghidno z umovoyu
    do {
        cout << "Vvedit literu: ";
        cin >> ch;
        
        // Perevirka na tsyfru funktsiyeyu isdigit()
        if (isdigit(ch)) {
            cout << "Vvedenyy nepravylnyy symvol. Vvedit Q abo Z dlya vykhodu." << endl;
            continue;
        }
        
        // Perevirka na vykhid (Q abo Z)
        if (ch == 'Q' || ch == 'Z' || ch == 'q' || ch == 'z') {
            cout << "Vykhid." << endl;
            break;
        }
        
        // Perevirka chy ce litera
        if (!isalpha(ch)) {
            cout << "Vvedenyy nepravylnyy symvol. Vvedit Q abo Z dlya vykhodu." << endl;
            continue;
        }
        
        // Vyznachennya tsyfry na telefoni
        char upperCh = toupper(ch);
        if (upperCh >= 'A' && upperCh <= 'C') {
            cout << "Bukva " << ch << " vidpovidaye tsyfri 2 na telefoni." << endl;
        } else if (upperCh >= 'D' && upperCh <= 'F') {
            cout << "Bukva " << ch << " vidpovidaye tsyfri 3 na telefoni." << endl;
        } else if (upperCh >= 'G' && upperCh <= 'I') {
            cout << "Bukva " << ch << " vidpovidaye tsyfri 4 na telefoni." << endl;
        } else if (upperCh >= 'J' && upperCh <= 'L') {
            cout << "Bukva " << ch << " vidpovidaye tsyfri 5 na telefoni." << endl;
        } else if (upperCh >= 'M' && upperCh <= 'O') {
            cout << "Bukva " << ch << " vidpovidaye tsyfri 6 na telefoni." << endl;
        } else if (upperCh >= 'P' && upperCh <= 'S') {
            cout << "Bukva " << ch << " vidpovidaye tsyfri 7 na telefoni." << endl;
        } else if (upperCh >= 'T' && upperCh <= 'V') {
            cout << "Bukva " << ch << " vidpovidaye tsyfri 8 na telefoni." << endl;
        } else if (upperCh >= 'W' && upperCh <= 'Y') {
            cout << "Bukva " << ch << " vidpovidaye tsyfri 9 na telefoni." << endl;
        } else {
            cout << "Vvedenyy nepravylnyy symvol. Vvedit Q abo Z dlya vykhodu." << endl;
        }
        
    } while (true);

    return 0;
}
