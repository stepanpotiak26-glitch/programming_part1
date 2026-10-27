#include <iostream>
#include <iomanip>
using namespace std;

// constants
const float PERSON_WT = 170.0;
const float LBS_PER_GAL = 6.7;
const float EMPTY_WEIGHT = 9887.0;
const float EMPTY_MOMENT = 3185853.0;

//  funkcia vyvedennia danuh (void)
void GetData(int &crew, int &passengers, float &closet, float &baggage, float &fuel) {
    cin >> crew >> passengers >> closet >> baggage >> fuel;
}

//  moment ekipazu екіпажу
float CrewMoment(int crew) {
    return crew * PERSON_WT * 143.0;
}

//  moment pasagyriw (vrahowyemo poriadok zapownennia ryadiw)
float PassengerMoment(int passengers) {
    float moment = 0;
    for (int i = 1; i <= passengers; i++) {
        if (i <= 2) moment += PERSON_WT * 265.0;       // 2-riad
        else if (i <= 4) moment += PERSON_WT * 219.0;  // 1- riad
        else if (i <= 6) moment += PERSON_WT * 295.0;  // 3- riad
        else if (i <= 8) moment += PERSON_WT * 341.0;  // 4- riad
    }
    return moment;
}

//  moment bagazy ta tualetu
float CargoMoment(float closet, float baggage) {
    return (closet * 182.0) + (baggage * 386.0);
}

//  moment palywa
float FuelMoment(float fuel) {
    float D = 0;
    if (fuel <= 59) {
        D = 314.6;
    } else if (fuel <= 360) {
        D = 305.8 + (-0.01233 * (fuel - 60));
    } else if (fuel <= 520) {
        D = 303.0 + (0.12500 * (fuel - 361));
    } else {
        D = 323.0 + (-0.04444 * (fuel - 521));
    }
    return (fuel * LBS_PER_GAL) * D;
}

//  poperedzennia (void)
void PrintWarning(float totalWt, float centerOfGravity) {

}
int main() {
    int crew, passengers;
    float closet, baggage, fuel;

    // vvedennia danyh
    GetData(crew, passengers, closet, baggage, fuel);

    // obchyslennia zagalnoi vagy
    float totalWt = EMPTY_WEIGHT + (passengers + crew) * PERSON_WT + closet + baggage + fuel * LBS_PER_GAL;

    // obchyslennia centru vagi
    float cg = (CrewMoment(crew) + PassengerMoment(passengers) + CargoMoment(closet, baggage) + FuelMoment(fuel) + EMPTY_MOMENT) / totalWt;

    cout << fixed << setprecision(2);
    cout << totalWt << endl;
    cout << cg << endl;

    PrintWarning(totalWt, cg);

    return 0;
}
