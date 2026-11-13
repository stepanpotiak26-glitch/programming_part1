#include <iostream>
#include <string>

using namespace std;

void SendSms(const string &number, const string &message)
{
    cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string &email, const string &message)
{
    cout << "Send '" << message << "' to e-mail " << email << endl;
}

class INotifier
{
public:
    virtual void Notify(const string &message) = 0;
    virtual ~INotifier() = default;
};

class SmsNotifier : public INotifier
{
private:
    string number;

public:
    SmsNotifier(const string &phone_number) : number(phone_number) {}

    void Notify(const string &message) override
    {
        SendSms(number, message);
    }
};

class EmailNotifier : public INotifier
{
private:
    string email_address;

public:
    EmailNotifier(const string &email) : email_address(email) {}

    void Notify(const string &message) override
    {
        SendEmail(email_address, message);
    }
};

void Notify(INotifier &notifier, const string &message)
{
    notifier.Notify(message);
}

int main()
{
    SmsNotifier sms{"+38-067-777-77-77"};
    EmailNotifier email{"lab28-final@pnu.edu.ua"};
    Notify(sms, "I am learning C++");
    Notify(email, "and I want to be successful");

    return 0;
}
