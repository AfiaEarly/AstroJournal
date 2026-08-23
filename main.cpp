#include "records.h"
#include <iostream>
#include "stats.h"
using namespace std;

void options()
{
    cout << "---OPTIONS---" << endl;
    cout << "1.New Record" << endl;
    cout << "2.View Record" << endl;
    cout << "3.Delete Record" << endl;
    cout << "4.Statistics" << endl;
}

int main()
{
    vector<Record> records;
    getRecords(records);

    int selected_option = 0;

    while (1)
    {

        switch (selected_option)
        {
        case 1:
        {
            Record rc;
            string date, time, type, objectName, direction;

            cout << "Enter date:";
            cin >> rc.date;

            cout << "Enter time:";
            cin >> rc.time;

            cout << "Enter type:";
            cin >> rc.type;

            cout << "Enter objectname:";
            getline(cin >> ws, rc.objectName);

            cout << "Enter direction:";
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
            statistics(records);
            cout << endl;
            selected_option = 0;
        }

        case 0:
        {
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