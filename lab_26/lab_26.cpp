#include "phone_number.h"
#include <stdexcept>

PhoneNumber::PhoneNumber(const string &international_number)
{
    if (international_number.empty() || international_number.front() != '+')
    {
        throw invalid_argument("Number must start with '+': " + international_number);
    }

    const size_t dash1 = international_number.find('-');
    const size_t dash2 = international_number.find('-', dash1 + 1);

    // Перевіряємо, чи є рівно два дефіси і вони не зливаються/відсутні
    if (dash1 == string::npos || dash2 == string::npos || international_number.find('-', dash2 + 1) != string::npos)
    {
        throw invalid_argument("Invalid format, expected 2 dashes: " + international_number);
    }

    country_ = international_number.substr(1, dash1 - 1);
    city_ = international_number.substr(dash1 + 1, dash2 - dash1 - 1);
    local_ = international_number.substr(dash2 + 1);

    if (country_.empty() || city_.empty() || local_.empty())
    {
        throw invalid_argument("Parts of the phone number cannot be empty: " + international_number);
    }
}

string PhoneNumber::GetCountryCode() const
{
    return country_;
}

string PhoneNumber::GetCityCode() const
{
    return city_;
}

string PhoneNumber::GetLocalNumber() const
{
    return local_;
}

string PhoneNumber::GetInternationalNumber() const
{
    return "+" + country_ + "-" + city_ + "-" + local_;
}
