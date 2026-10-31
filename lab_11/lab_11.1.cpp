#include <iostream>
#include <string>

using namespace std;

int main() {
    string abbr;
    bool success = false;

    do {
        cout << "Vvedit abreviaturu shtatu: ";
        cin >> abbr;

        if (abbr.length() != 2) {
            cout << "Pomylka! Vvedit dvobukvenu abreviaturu znovu.\n";
            continue;
        }

        char first = toupper(abbr[0]);
        char second = toupper(abbr[1]);

        switch (first) {
            case 'A':
                switch (second) {
                    case 'L': cout << "Alabama\n"; success = true; break;
                    case 'K': cout << "Alaska\n"; success = true; break;
                    case 'Z': cout << "Arizona\n"; success = true; break;
                    case 'R': cout << "Arkansas\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'C':
                switch (second) {
                    case 'A': cout << "California\n"; success = true; break;
                    case 'O': cout << "Colorado\n"; success = true; break;
                    case 'T': cout << "Connecticut\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'D':
                switch (second) {
                    case 'E': cout << "Delaware\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'F':
                switch (second) {
                    case 'L': cout << "Florida\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'G':
                switch (second) {
                    case 'A': cout << "Georgia\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'H':
                switch (second) {
                    case 'I': cout << "Hawaii\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'I':
                switch (second) {
                    case 'D': cout << "Idaho\n"; success = true; break;
                    case 'L': cout << "Illinois\n"; success = true; break;
                    case 'N': cout << "Indiana\n"; success = true; break;
                    case 'A': cout << "Iowa\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'K':
                switch (second) {
                    case 'S': cout << "Kansas\n"; success = true; break;
                    case 'Y': cout << "Kentucky\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'L':
                switch (second) {
                    case 'A': cout << "Louisiana\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'M':
                switch (second) {
                    case 'E': cout << "Maine\n"; success = true; break;
                    case 'D': cout << "Maryland\n"; success = true; break;
                    case 'A': cout << "Massachusetts\n"; success = true; break;
                    case 'I': cout << "Michigan\n"; success = true; break;
                    case 'N': cout << "Minnesota\n"; success = true; break;
                    case 'S': cout << "Mississippi\n"; success = true; break;
                    case 'O': cout << "Missouri\n"; success = true; break;
                    case 'T': cout << "Montana\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'N':
                switch (second) {
                    case 'E': cout << "Nebraska\n"; success = true; break;
                    case 'V': cout << "Nevada\n"; success = true; break;
                    case 'H': cout << "New Hampshire\n"; success = true; break;
                    case 'J': cout << "New Jersey\n"; success = true; break;
                    case 'M': cout << "New Mexico\n"; success = true; break;
                    case 'Y': cout << "New York\n"; success = true; break;
                    case 'C': cout << "North Carolina\n"; success = true; break;
                    case 'D': cout << "North Dakota\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'O':
                switch (second) {
                    case 'H': cout << "Ohio\n"; success = true; break;
                    case 'K': cout << "Oklahoma\n"; success = true; break;
                    case 'R': cout << "Oregon\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'P':
                switch (second) {
                    case 'A': cout << "Pennsylvania\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'R':
                switch (second) {
                    case 'I': cout << "Rhode Island\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'S':
                switch (second) {
                    case 'C': cout << "South Carolina\n"; success = true; break;
                    case 'D': cout << "South Dakota\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'T':
                switch (second) {
                    case 'N': cout << "Tennessee\n"; success = true; break;
                    case 'X': cout << "Texas\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'U':
                switch (second) {
                    case 'T': cout << "Utah\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'V':
                switch (second) {
                    case 'T': cout << "Vermont\n"; success = true; break;
                    case 'A': cout << "Virginia\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            case 'W':
                switch (second) {
                    case 'A': cout << "Washington\n"; success = true; break;
                    case 'V': cout << "West Virginia\n"; success = true; break;
                    case 'I': cout << "Wisconsin\n"; success = true; break;
                    case 'Y': cout << "Wyoming\n"; success = true; break;
                    default: cout << "Pomylka! Vvedit abreviaturu znovu.\n"; break;
                }
                break;
            default:
                cout << "Pomylka! Vvedit abreviaturu znovu.\n";
                break;
        }
    } while (!success);

    return 0;
}
