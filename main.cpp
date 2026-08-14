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

            string date, time, type, objectName, direction;

            cout << "Enter date:";
            cin >> date;

            cout << "Enter time:";
            cin >> time;

            cout << "Enter type:";
            cin >> type;

            cout << "Enter objectname:";
            getline(cin >> ws, objectName);

            cout << "Enter direction:";
            cin >> direction;

            addRecords({date, time, type, objectName, direction});

            cout << endl;

            cout << "Succesfully added record!" << endl;

            options();

            break;
        }
        case 2:

        {
            auto rec = getRecords();
            cout << "Current Records:" << endl;
            printRecords(rec);
            cout << endl;
            options();

            break;
        }
        default:

            cout << "Invalid Option" << endl;

            break;
        }
    }
}