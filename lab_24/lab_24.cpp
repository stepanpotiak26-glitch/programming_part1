#include <iostream>
#include <sstream>

using namespace std;

// Znakhodyt naibilshyi spilnyi dilnyk
int GreatestCommonDivisor(int a, int b) {
    if (b == 0) {
        return a < 0 ? -a : a;
    }

    return GreatestCommonDivisor(b, a % b);
}

// Klas dlia predstavlennia ratsionalnykh chysel
class Rational {
private:
    int numerator;   // Chysenyk
    int denominator; // Znamennyk

public:
    // Konstruktor za zamovchuvanniam
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    // Konstruktor z dvoma parametramy
    Rational(int numerator, int denominator) {
        // Zakhyst vid nulovoho znamennyka
        if (denominator == 0) {
            this->numerator = 0;
            this->denominator = 1;
            return;
        }

        // Yakshcho znamennyk vid'iemnyi, perenosymo znak u chysenyk
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        // Znakhodymo NSD dlia skorochennia drobu
        int gcd = GreatestCommonDivisor(numerator, denominator);

        // Yakshcho chysenyk dorivniuie nulu, drib dorivniuie 0/1
        if (numerator == 0) {
            this->numerator = 0;
            this->denominator = 1;
        }
        else {
            this->numerator = numerator / gcd;
            this->denominator = denominator / gcd;
        }
    }

    // Povertaie chysenyk
    int Numerator() const {
        return numerator;
    }

    // Povertaie znamennyk
    int Denominator() const {
        return denominator;
    }
};

// Perevirziaie rivnist dvokh drobiv
bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() &&
        lhs.Denominator() == rhs.Denominator();
}

// Dodavannia dvokh drobiv
Rational operator+(const Rational& lhs, const Rational& rhs) {
    int numerator =
        lhs.Numerator() * rhs.Denominator() +
        rhs.Numerator() * lhs.Denominator();

    int denominator =
        lhs.Denominator() * rhs.Denominator();

    return Rational(numerator, denominator);
}

// Vidnimannia dvokh drobiv
Rational operator-(const Rational& lhs, const Rational& rhs) {
    int numerator =
        lhs.Numerator() * rhs.Denominator() -
        rhs.Numerator() * lhs.Denominator();

    int denominator =
        lhs.Denominator() * rhs.Denominator();

    return Rational(numerator, denominator);
}

// Mnozhennia dvokh drobiv
Rational operator*(const Rational& lhs, const Rational& rhs) {
    int numerator =
        lhs.Numerator() * rhs.Numerator();

    int denominator =
        lhs.Denominator() * rhs.Denominator();

    return Rational(numerator, denominator);
}

// Dilennia dvokh drobiv
Rational operator/(const Rational& lhs, const Rational& rhs) {
    // Perevirziaiemo, chy ne dilymo na nul
    if (rhs.Numerator() == 0) {
        return Rational();
    }

    int numerator =
        lhs.Numerator() * rhs.Denominator();

    int denominator =
        lhs.Denominator() * rhs.Numerator();

    return Rational(numerator, denominator);
}

// Operator vyvedennia drobu
ostream& operator<<(ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << '/'
        << rational.Denominator();

    return stream;
}

// Operator vvedennia drobu
istream& operator>>(istream& stream, Rational& rational) {
    int numerator;
    int denominator;
    char slash;

    // Spochatku zchytuiemo dani v tymchasovi zminni
    if (stream >> numerator >> slash >> denominator) {

        // Perevirziaiemo pravylnist formatu
        if (slash == '/' && denominator != 0) {
            rational = Rational(numerator, denominator);
        }
        else {
            stream.setstate(ios::failbit);
        }
    }

    return stream;
}

int main() {
    // Perevirka konstruktoriv
    {
        const Rational r(3, 10);

        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);

        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);

        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);

        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    // Perevirka aryfmetychnykh operatoriv
    {
        Rational a(2, 3);
        Rational b(4, 3);

        if (!(a + b == Rational(2, 1))) {
            cout << "Pomylka dodavannia" << endl;
            return 5;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);

        if (!(a - b == Rational(31, 63))) {
            cout << "Pomylka vidnimannia" << endl;
            return 6;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);

        if (!(a * b == Rational(8, 9))) {
            cout << "Pomylka mnozhennia" << endl;
            return 7;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);

        if (!(a / b == Rational(2, 3))) {
            cout << "Pomylka dilennia" << endl;
            return 8;
        }
    }

    // Perevirka vvedennia ta vyvedennia
    {
        ostringstream output;
        output << Rational(-6, 8);

        if (output.str() != "-3/4") {
            cout << "Pomylka vyvedennia" << endl;
            return 9;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;

        if (!(r == Rational(5, 7))) {
            cout << "Pomylka vvedennia" << endl;
            return 10;
        }
    }

    cout << "OK" << endl;

    return 0;
}
