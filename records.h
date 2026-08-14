#pragma once

#include <vector>
#include <string>

using namespace std;

struct Record
{
    string date, time, type, objectName, direction;
};

void addRecords(Record records);

vector<Record> getRecords();

void printRecords(vector<Record> records);
