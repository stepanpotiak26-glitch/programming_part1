#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Відкриває файл myfile.dat.txt для читання
    ifstream file("myfile.dat.txt");
    
    // превірка чи відкрився файл
    if (!file.is_open()) {
        cerr << "pomylka: ne vdalosia vidkriti files myfile.dat.txt!" << endl;
        return 1;
    }

    int count = 0;
    string line;

    // Порядкове читання файлу
    while (getline(file, line)) {
        size_t pos = 0;
        // рахує всі входження "!=" у рядках
        while ((pos = line.find("!=", pos)) != string::npos) {
            count++;
            pos += 2; // перекидуємо позицію на 2 символи вперед , щоб не шукати знову
        }
    }

    // Закриваємо файл
    file.close();

    cout << count << endl;

    return 0;
}