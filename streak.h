#pragma once

#include <vector>
#include <string>
#include "records.h"

using namespace std;

struct Date
{
    int day, month, year;
};

Date seperateDate(string date);

struct Streak
{
    string date;
    int streakCount;
};

void writeStreak(Streak streak);

Streak getStreak();

void updateStreak(string newDate);

void printStreak();
