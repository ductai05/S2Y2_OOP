#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class CDate
{
private:
    int Year;
    int Month;
    int Day;

public:
    void InputDate();
    void OutputDate();
    bool CheckDate();
    bool InspectLeapYear();
};

void CDate::InputDate()
{
    string in;
    cin >> in;
    stringstream ss(in);
    char delimiter;
    ss >> Day >> delimiter >> Month >> delimiter >> Year;
    return;
}

void CDate::OutputDate()
{
    cout << Day << "/" << Month << "/" << Year << "\n";
    return;
}

bool CDate::CheckDate()
{
    if (Year < 0)
        return false;
    if (Month > 12 || Month < 0)
        return false;
    if (Day < 0 || Day > 31)
        return false;
    if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
    {
        if (Day > 31)
            return false;
    }
    else if (Month == 2)
    {
        if (this->InspectLeapYear() && Day > 29)
            return false;
        if (!this->InspectLeapYear() && Day > 28)
            return false;
    }
    else
    {
        if (Day > 30)
            return false;
    }
    return true;
}

bool CDate::InspectLeapYear()
{
    return false;
}

int main()
{
    CDate day1;
    day1.InputDate();
    day1.OutputDate();
    cout << (day1.CheckDate() ? "True" : "False");
}