#include "records.h"
#include <iostream>
#include <fstream>
#include <vector>

#define filepath "records.txt"
using namespace std;

void addRecords(vector<Record> &records, Record rc)
{
    ofstream file(filepath, ios::app);
    file << rc.date << "," << rc.time << "," << rc.type << "," << rc.objectName << "," << rc.direction << "," << "\n";
    records.push_back(rc);
}

void getRecords(vector<Record> &records)
{
    if (!records.empty())
    {
        return;
    }
    ifstream file(filepath);
    string line;

    while (getline(file, line))
    {
        string date, time, type, objectName, direction, temp;
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == ',')
            {
                if (date.empty())
                {
                    date = temp;
                    temp = "";
                }
                else if (time.empty())
                {
                    time = temp;
                    temp = "";
                }
                else if (type.empty())
                {
                    type = temp;
                    temp = "";
                }
                else if (objectName.empty())
                {
                    objectName = temp;
                    temp = "";
                }
                else if (direction.empty())
                {
                    direction = temp;
                    temp = "";
                }
            }
            else
            {
                temp += line[i];
            }
        }
        Record rc;
        rc.date = date;
        rc.time = time;
        rc.type = type;
        rc.objectName = objectName;
        rc.direction = direction;
        records.push_back(rc);
    }
}

void printRecords(vector<Record> records)
{
    for (int i = 0; i < records.size(); i++)
    {
        cout << "_______________________________________________" << endl;
        cout << i + 1 << ".";
        cout << "DATE:" << records[i].date << " ";
        cout << "TIME:" << records[i].time << " ";
        cout << "TYPE:" << records[i].type << endl;
        cout << "OBJECT NAME:" << records[i].objectName << " ";
        cout << "DIRECTION:" << records[i].direction << endl;
    }
}
