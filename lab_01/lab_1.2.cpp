#include <iostream> 

using namespace std;

int main() {
    double museum = 1.5; 
    double gallery = 2.3;
    double book_store = 5.9;
    double concert = 4.0;

    double scale = 0.25;

    double cm1 = museum + gallery;
    double cm2 = gallery + book_store;
    double cm3 = book_store + concert;
    double cm4 = museum + gallery + book_store + concert;

    double distance1 = cm1 * scale ;
    double distance2 = cm2 * scale;
    double distance3 = cm3 * scale;
    double distance4 = cm4 * scale;

    float scaleDistance = (int(distance4 * 10.0 + 0.5)) / 10.0; // то все заокруглення 

    cout << "Distance point to point" << endl;
    cout << "Distance between museum and gallery: " << distance1 << " km" << endl;
    cout << "Distance between gallery and book store: " << distance2 << " km" << endl;
    cout << "Distance between book store and concert: " << distance3 << " km" << endl;
    cout << "Total distance: " << scaleDistance << " km" << endl;

    return 0;
}