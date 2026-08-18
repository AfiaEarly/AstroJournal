#include "records.h"
#include <iostream>

using namespace std;

void options()
{
    cout << "---OPTIONS---" << endl;
    cout << "1.New Record" << endl;
    cout << "2.View Record" << endl;
}

int main()
{
    vector<Record> records;
    getRecords(records);
    options();

    while (1)
    {
        int option;
        cout << "Choose option:";
        cin >> option;
        cout << endl;
        switch (option)
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

            options();

            break;
        }
        case 2:

        {
            printRecords(records);
            options();

            break;
        }
        default:

            cout << "Invalid Option" << endl;

            break;
        }
    }
}