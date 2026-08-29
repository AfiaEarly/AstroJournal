#include "streak.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

#define Streak_file "streakRecord.txt"

using namespace std;

Date seperateDate(string date)
{
    Date d;
    stringstream ss(date);
    string day, month, year;
    getline(ss, day, '-');

    getline(ss, month, '-');

    getline(ss, year, '-');

    d.day = stoi(day);
    d.month = stoi(month);
    d.year = stoi(year);

    return d;
}

void writeStreak(Streak streak)
{
    ofstream file(Streak_file);

    file << streak.date << "," << streak.streakCount << "," << endl;
}

Streak getStreak()
{
    ifstream file(Streak_file);

    string line;

    getline(file, line);

    string date = "", temp = "";
    int streakCount = 0;

    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == ',')
        {
            if (date.empty())
            {
                date = temp;
                temp = "";
            }
            else
            {
                streakCount = stoi(temp);
                temp = "";
            }
        }
        else
        {
            temp += line[i];
        }
    }

    return {date, streakCount};
}

void updateStreak(string newDate)
{
    auto streak = getStreak();

    if (streak.date.empty() || !streak.streakCount)
    {
        writeStreak({newDate, 1});

        return;
    }

    auto date = seperateDate(streak.date);
    auto currentDate = seperateDate(newDate);

    int dayDiff = currentDate.day - date.day;
    int monthDiff = currentDate.month - date.month;
    int yearDiff = currentDate.year - date.year;

    if (dayDiff == 1 && monthDiff == 0 && yearDiff == 0)
    {
        Streak newStreak = {newDate, streak.streakCount + 1};

        writeStreak(newStreak);

        return;
    }

    if (dayDiff == 0)
        return;

    if (dayDiff > 1)
    {
        Streak new_streak = {newDate, 1};
        writeStreak(new_streak);
    }
}

void printStreak()
{
    auto streak = getStreak();

    cout << endl;
    cout << "STREAK :" << endl;

    cout << "----------------------" << endl;
    cout << "Streak: " << streak.streakCount << endl;
    cout << "Last added: " << streak.date << endl;
    cout << "----------------------" << endl;
    cout << endl;
}
