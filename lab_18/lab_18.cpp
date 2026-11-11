#include <iostream>
#include <cstring>

using namespace std;

// Ogoloshennia struktury dlia avtomobilia (vykorystano odnovymirni masyvy char)
struct Car {
    char model[30];
    int year;
    double price;
    char color[20];
};

int main() {
    const int N = 6; // Kilkist elementiv u masyvi struktur

    // Ogoloshennia ta initsializatsiia odnovymirnoho masyvu struktur
    Car warehouse[N] = {
        {"Audi A4", 2001, 5500.0, "Red"},
        {"BMW X5", 2005, 8200.0, "Black"},
        {"Ford Focus", 2001, 3800.0, "Red"},
        {"Toyota Camry", 2010, 9500.0, "White"},
        {"Opel Astra", 2001, 3200.0, "Blue"},
        {"Honda Civic", 2001, 4100.0, "Red"}
    };

    // 1. Vyvedennia povnoho spysku avtomobiliv
    cout << "=== Spysok vsikh avtomobiliv na skladi ===" << endl;
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << ". Model: " << warehouse[i].model 
             << " | Rik: " << warehouse[i].year 
             << " | Tsina: $" << warehouse[i].price 
             << " | Kolir: " << warehouse[i].color << endl;
    }

    // 2. Poshuk ta vyvedennia chervonykh avtomobiliv 2001 roku
    cout << "\n=== Rezultat poshuku (Chervoni avto 2001 roku) ===" << endl;
    bool found = false;

    for (int i = 0; i < N; ++i) {
        // strcmp dlia porivniannia odnovymirnykh masyviv char
        if (warehouse[i].year == 2001 && strcmp(warehouse[i].color, "Red") == 0) {
            cout << "- Model: " << warehouse[i].model 
                 << " (Tsina: $" << warehouse[i].price << ")" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Avtomobiliv z takymy parametramy ne znaideno." << endl;
    }

    return 0;
}
