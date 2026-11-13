#pragma once
#include <string>

using namespace std;

class PhoneNumber
{
public:
    explicit PhoneNumber(const string &international_number);

    string GetCountryCode() const;
    string GetCityCode() const;
    string GetLocalNumber() const;
    string GetInternationalNumber() const;

private:
    string country_;
    string city_;
    string local_;
};