#include "search.h"
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void searchPrintRecord(vector<Record> &records, function<bool(Record)> matches)
{
    for (int i = 0; i < records.size(); i++)
    {
        if (matches(records[i]))
        {
            printRecord(records[i], i);
        }
    }
}

void searchRecord(vector<Record> &records)
{
    string key;

    cout << "Search by:" << endl;
    cout << "1.Date" << endl;
    cout << "2.Time" << endl;
    cout << "3.Type" << endl;
    cout << "4.Object name" << endl;
    cout << "5.Direction" << endl;

    int choice;
    cout << "Enter Choice:";
    cin >> choice;

    cout << "Enter key:";
    cin >> key;

    switch (choice)
    {
    case 1:
        searchPrintRecord(records, [key](auto rec)
                          { return key == rec.date; });

        break;

    case 2:
        searchPrintRecord(records, [key](auto rec)
                          { return key == rec.time; });

        break;

    case 3:
        searchPrintRecord(records, [key](auto rec)
                          { return key == rec.type; });

        break;

    case 4:
        searchPrintRecord(records, [key](auto rec)
                          { return key == rec.objectName; });

        break;

    case 5:

        searchPrintRecord(records, [key](auto rec)
                          { return key == rec.direction; });

        break;

    default:
        break;
    }
}