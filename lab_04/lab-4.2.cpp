#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double R, x, y, d;

    cout << "Vvedit radius : ";
    cin >> R;

    cout << "Vvedit koordinatu X: ";
    cin >> x;
    cout << "Vvedit koordinatu Y: ";
    cin >> y;

    d = sqrt(x * x + y * y);

    if (d == R) {
        cout << "Tochka znakhodytsya na koli" << endl;
    } 
    else if (d < R) {
        cout << "Tochka znakhodytsya v seredyni kola" << endl;
    } 
    else {
        cout << "Tochka znakhodytsya za mezhamy kola" << endl;
    }

    return 0;
}
