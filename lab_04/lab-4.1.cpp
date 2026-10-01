#include <iostream>
#include <cmath>
using namespace std;
int main() {

 double a, b, d;
 const double Xc = 5 , Yc = 5 , R = 40;
 
    cout << "Vvedit kordinatu X: ";
    cin >> a;
    cout << "Vvedit kordinatu Y: ";
    cin >> b;

    d = sqrt((a - Xc) * (a - Xc) + (b - Yc) * (b - Yc));

    if (d == 0) {
      cout << "Tochka nahoditsya v centri kruga" << endl;
    } 
    else if (d == R) {
      cout << "Tochka nahoditsya na obodi kola " << endl;
    } 
    else if (d < R) {
      cout << "Tochka nahoditsya vseredyni kruga" << endl;
    } 
    else {
      cout << "Tochka nahoditsya za mezhami kruga" << endl;
    }
  return 0;
} 
