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

    CDate IncreaseYear();
    CDate IncreaseMonth();
    CDate IncreaseDay();
    CDate DecreaseYear();
    CDate DecreaseMonth();
    CDate DecreaseDay();

    CDate IncreaseYear(int);
    CDate IncreaseMonth(int);
    CDate IncreaseDay(int);
    CDate DecreaseYear(int);
    CDate DecreaseMonth(int);
    CDate DecreaseDay(int);
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
    if (Year % 400 == 0)
        return true; // mod400 == 0
    if (Year % 100 == 0)
        return false; // mod100 == 0 && mod400 != 0
    if (Year % 4 == 0)
        return true;
    return false;
}

CDate CDate::IncreaseYear()
{
    Year++;
    while (CheckDate() == false)
        Day--;
    return *this;
}

CDate CDate::IncreaseMonth()
{
    Month++;
    if (Month > 12)
    {
        Year++;
        Month = 1;
    }
    while (CheckDate() == false)
        Day--;
    return *this;
}

CDate CDate::IncreaseDay()
{
    Day++;
    if (CheckDate() == false)
    {
        Month++;
        Day = 1;
    }
    if (CheckDate() == false)
    {
        Month = 1;
        Year++;
    }
    return *this;
}

CDate CDate::DecreaseYear()
{
    Year--;
    while (CheckDate() == false)
        Day--;
    return *this;
}

CDate CDate::DecreaseMonth()
{
    Month--;
    if (Month == 0)
    {
        Year--;
        Month = 12;
    }
    while (CheckDate() == false)
        Day--;
    return *this;
}

CDate CDate::DecreaseDay()
{
    Day--;
    if (Day == 0)
    {
        Month -= 1;
        if (Month == 0)
        {
            Year--;
            Month = 12;
        }
    }
    if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12)
        Day = 31;
    else if (Month == 2)
    {
        if (InspectLeapYear())
            Day = 29;
        else
            Day = 28;
    }
    else
        Day = 30;
    return *this;
}

CDate CDate::IncreaseYear(int a)
{
    CDate newDate = *this;
    while (a--)
        newDate = newDate.IncreaseYear();
    *this = newDate;
    return newDate;
}

CDate CDate::IncreaseMonth(int a)
{
    CDate newDate = *this;
    while (a--)
        newDate = newDate.IncreaseMonth();
    *this = newDate;
    return newDate;
}

CDate CDate::IncreaseDay(int a)
{
    CDate newDate = *this;
    while (a--)
        newDate = newDate.IncreaseDay();
    *this = newDate;
    return newDate;
}

CDate CDate::DecreaseYear(int a)
{
    CDate newDate = *this;
    while (a--)
        newDate = newDate.DecreaseYear();
    *this = newDate;
    return newDate;
}

CDate CDate::DecreaseMonth(int a)
{
    CDate newDate = *this;
    while (a--)
        newDate = newDate.DecreaseMonth();
    *this = newDate;
    return newDate;
}

CDate CDate::DecreaseDay(int a)
{
    CDate newDate = *this;
    while (a--)
        newDate = newDate.DecreaseDay();
    *this = newDate;
    return newDate;
}

int main()
{
    CDate day1;
    day1.InputDate();
    cout << (day1.CheckDate() ? "True\n" : "False\n");
    day1.IncreaseYear(5);
    day1.OutputDate();
    day1.IncreaseMonth(3);
    day1.OutputDate();
    day1.IncreaseDay(2);
    day1.OutputDate();
    return 0;
}