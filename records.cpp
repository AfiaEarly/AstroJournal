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

void printRecords(vector<Record> records, int &selected_option)
{
    int start = 0;
    int limit = 5;
    while (1)
    {

        for (int i = start; i < limit && i < records.size(); i++)
        {
            cout << "_______________________________________________" << endl;
            cout << i + 1 << ".";
            cout << "DATE:" << records[i].date << " ";
            cout << "TIME:" << records[i].time << " ";
            cout << "TYPE:" << records[i].type << endl;
            cout << "OBJECT NAME:" << records[i].objectName << " ";
            cout << "DIRECTION:" << records[i].direction << endl;
        }
        cout << endl;

        char choice;

        cout << "N. Next" << endl
             << "P. Previous" << endl
             << "0. Main Menu" << endl;

        cin >> choice;

        if (choice == '0')
        {
            selected_option = 0;
            break;
        }

        if (choice == 'N' || choice == 'n')
        {
            start = limit;
            limit += 5;
        }
        else if (choice == 'P' || choice == 'p')
        {
            if (start >= 5)
            {
                limit = start;
                start -= 5;
            }
        }
    }
}

void rewriteRecord(vector<Record> &records)
{
    ofstream file(filepath);

    for (int i = 0; i < records.size(); i++)
    {
        file << records[i].date << "," << records[i].time << ","
             << records[i].type << "," << records[i].objectName << ","
             << records[i].direction << "," << endl;
    }
}

void deleteRecord(vector<Record> &records)
{
    int index;

    cout << "Enter Record Index to delete: ";
    cin >> index;

    records.erase(records.begin() + index - 1);

    rewriteRecord(records);
    cout << "Succesfully deleted record!" << endl;
}

void updateRecord(vector<Record> &records)
{
    int index;

    index--;

    cout << "Enter Record Index to update: ";
    cin >> index;

    cout << "What do you want to change?" << endl;
    cout << "1.Date" << endl;
    cout << "2.Time" << endl;
    cout << "3.Type" << endl;
    cout << "4.Object name" << endl;
    cout << "5.Direction" << endl;

    int choice;
    cout << "Enter Choice:";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter new date:";
        cin >> records[index - 1].date;

        break;

    case 2:

        cout << "Enter new time:";
        cin >> records[index - 1].time;

        break;

    case 3:

        cout << "Enter new type:";
        cin >> records[index - 1].type;

        break;

    case 4:

        cout << "Enter new object name:";
        cin >> records[index - 1].objectName;

        break;

    case 5:

        cout << "Enter new direction:";
        cin >> records[index - 1].direction;

        break;

    default:
        break;
    }

    rewriteRecord(records);
    cout << endl;
    cout << "Succesfully updated record!" << endl;
}
