#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Klas dlia zberihannia riadkiv u vidsortovanomu poriadku
class SortedStrings {
public:

    // Metod dodaie novyi riadok do spysku
    void AddString(const string& s) {
        strings.push_back(s);
    }

    // Metod povertaie vsi riadky u vidsortovanomu poriadku
    vector<string> GetSortedStrings() const {
        vector<string> result = strings;

        // Sortuvannia riadkiv za alfavitom
        sort(result.begin(), result.end());

        return result;
    }

private:
    // Pryvatnyi vektor dlia zberihannia riadkiv
    vector<string> strings;
};

// Funktsiia vyvodyt vidsortovani riadky
void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }

    cout << endl;
}

int main() {
    // Stvoriuiemo ob'iekt klasu
    SortedStrings strings;

    // Dodaiemo riadky
    strings.AddString("pershyi");
    strings.AddString("tretii");
    strings.AddString("druhyi");

    // Vyvodymo vidsortovani riadky
    PrintSortedStrings(strings);

    // Dodaiemo shche odyn riadok
    strings.AddString("druhyi");

    // Povtorno vyvodymo rezultat
    PrintSortedStrings(strings);

    return 0;
}
