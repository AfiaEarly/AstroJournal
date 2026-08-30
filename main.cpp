#include "records.h"
#include "search.h"
#include "stats.h"
#include "streak.h"
#include <iostream>

using namespace std;

void options()
{
    cout << "---OPTIONS---" << endl;
    cout << endl;
    cout << "1.New Record" << endl;
    cout << "2.View Record" << endl;
    cout << "3.Delete Record" << endl;
    cout << "4.Update Record" << endl;
    cout << "5.Search Record" << endl;
    cout << "6.Statistics" << endl;
}

int main()
{
    vector<Record> records;
    getRecords(records);

    int selected_option = 0;

    cout << endl;
    cout << "-----------------" << endl;
    cout << "|  ASTROJOURNAL  |" << endl;
    cout << "-----------------" << endl;
    cout << endl;

    while (1)
    {

        switch (selected_option)
        {
        case 1:
        {
            Record rc;
            string date, time, type, objectName, direction;

            cout << endl;

            cout << "Date: ";
            cin >> rc.date;

            cout << "Time: ";
            cin >> rc.time;

            cout << "Type: ";
            cin >> rc.type;

            cout << "Objectname: ";
            getline(cin >> ws, rc.objectName);

            cout << "Direction: ";
            cin >> rc.direction;

            addRecords(records, rc);

            cout << endl;

            cout << "Succesfully added record!" << endl;

            selected_option = 0;

            break;
        }

        case 2:
        {
            printRecords(records, selected_option);

            break;
        }

        case 3:
        {
            deleteRecord(records);

            selected_option = 0;

            break;
        }

        case 4:
        {
            updateRecord(records);

            cout << endl;

            selected_option = 0;

            break;
        }

        case 5:
        {
            searchRecord(records);

            cout << endl;

            selected_option = 0;

            break;
        }

        case 6:
        {
            statistics(records);

            cout << endl;

            selected_option = 0;
        }

        case 0:
        {
            printStreak();

            options();

            cout << "Choose option: ";

            cin >> selected_option;

            break;
        }

        default:

            cout << "Invalid Option" << endl;

            break;
        }
    }
}