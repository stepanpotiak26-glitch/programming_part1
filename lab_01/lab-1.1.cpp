#include <iostream>
using namespace std;

int main (){
    double width;
    double lenght;
    double floors;
    double non_residential_area;
    double price;
    double living_area;
   
   
     width =30.0;
     lenght = 40.0;
     floors = 2.5;
     non_residential_area = 825.0;
     price = 150000.0;
     living_area = width*lenght*floors-non_residential_area;
     cout <<"Cost per square meter: "<<price/living_area;
     
    return 0;
}