#include <iostream>
using namespace std;

    int main() {
        int ocinka1 , ocinka2 , ocinka3 ;
        double vaga1 , vaga2 , vaga3;
        double result;

        cout << "yvedit ocinku 1 :";
        cin >> ocinka1 >> vaga1 ;
        cout << "yvedit ocinku 2 :" ;
        cin >> ocinka2 >> vaga2 ;
        cout << "yvedit ocinku 3 :" ;
        cin >> ocinka3 >> vaga3 ;


        result = ocinka1 * vaga1 + ocinka2 * vaga2 + ocinka3 * vaga3;
        cout <<"serednozvazhne znachennia :" << result ;

    return 0;
}
   