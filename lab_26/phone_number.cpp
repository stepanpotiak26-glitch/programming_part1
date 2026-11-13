#include <iostream>
#include <string>
#include <exception>
#include "phone_number.h"

using namespace std;

int main()
{
    auto test = [](const string &s)
    {
        try
        {
            PhoneNumber num(s);
            cout << num.GetInternationalNumber() << endl;
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    };

    test("+38-029-07168");
    test("+380-29-aaaaa");
    test("+3-9-aaaaa");
    test("380-29-aaaaa");
    test("+380-29-");

    return 0;
}
