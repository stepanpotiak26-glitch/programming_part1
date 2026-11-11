#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Klas dlia roboty z riadkamy, yaki mozhna perevertaty
class ReversibleString {
private:
    string value; // Pryvatne pole dlia zberihannia riadka

public:
    // Konstruktor za zamovchuvanniam — stvoriuie porozhnii riadok
    ReversibleString() {
        value = "";
    }

    // Parametryzovanyi konstruktor — pryimaie pochatkovyi riadok
    ReversibleString(const string& str) {
        value = str;
    }

    // Metod perevertaie riadok u zvorotnomu poriadku
    void Reverse() {
        reverse(value.begin(), value.end());
    }

    // Metod povertaie riadok
    // const oznachaie, shcho metod ne zminiuie ob'iekt
    string ToString() const {
        return value;
    }
};

int main() {
    // Stvoriuiemo ob'iekt zi slovom live
    ReversibleString s("live");

    // Perevertaiemo slovo
    s.Reverse();

    // Vyvodymo rezultat
    cout << s.ToString() << endl;

    // Povertaiemo slovo do pochatkovoho vyhliadu
    s.Reverse();

    // Stvoriuiemo konstantne posylannia na ob'iekt
    const ReversibleString& s_ref = s;

    // Otrymuiemo riadok cherez konstantne posylannia
    string tmp = s_ref.ToString();

    cout << tmp << endl;

    // Stvoriuiemo porozhnii riadok za zamovchuvanniam
    ReversibleString empty;

    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}
