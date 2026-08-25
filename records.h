#pragma once

#include <vector>
#include <string>

using namespace std;

struct Record
{
    string date, time, type, objectName, direction;
};

void addRecords(vector<Record> &records, Record rc);

void getRecords(vector<Record> &records);

void printRecords(vector<Record> records, int &selected_option);

void rewriteRecord(vector<Record> &records);

void deleteRecord(vector<Record> &records);

void updateRecord(vector<Record> &records);
