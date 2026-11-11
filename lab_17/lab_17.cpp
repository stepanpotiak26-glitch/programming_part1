#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;

    cout << "Vvedit riadok iz symvolamy ':' :" << endl;
    getline(cin, str);

    // Poshuk pershoho dvoikrapky
    size_t firstColon = str.find(':');

    if (firstColon == string::npos) {
        cout << "Error: Symvol ':' ne znaideno v riadku!" << endl;
        return 0;
    }

    // 1. Oborot pidriadka do pershoho ':'
    string beforeColon = str.substr(0, firstColon);
    reverse(beforeColon.begin(), beforeColon.end());

    cout << "\nSimvoly do pershoho ':' u zvorotnomu poriadku: " << beforeColon << endl;

    // 2. Poshuk nastupnykh dvoikrapok ta pidrakhunok symvoliv mizh nymy
    size_t currentPos = firstColon;
    size_t nextColon = str.find(':', currentPos + 1);
    int intervalCount = 0;

    while (nextColon != string::npos) {
        intervalCount++;
        size_t countBetween = nextColon - currentPos - 1;
        cout << "Kilkist symvoliv mizh " << intervalCount << "-iu ta " 
             << (intervalCount + 1) << "-iu dvoikrapkoiu: " << countBetween << endl;

        currentPos = nextColon;
        nextColon = str.find(':', currentPos + 1);
    }

    if (intervalCount == 0) {
        cout << "U riadku tilky odyn symvol ':', tomu intervaliv nemaie." << endl;
    }

    return 0;
}
