#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // vidkryvae file myfile.dat.txt dla chytannia
    ifstream file("myfile.dat.txt");
    
    // perevirka chy vidkryvsya file
    if (!file.is_open()) {
        cerr << "pomylka: ne vdalosia vidkriti files myfile.dat.txt!" << endl;
        return 1;
    }

    int count = 0;
    string line;

    // poradkove chytannia faily
    while (getline(file, line)) {
        size_t pos = 0;
        // rahye vsi vhodzennia "!=" y riadkah
        while ((pos = line.find("!=", pos)) != string::npos) {
            count++;
            pos += 2; // perekydyemo pozyciu na 2 symvoly vpered , chcob chykatu znowy
        }
    }

    // zakryvaemo file
    file.close();

    cout << count << endl;

    return 0;
}
