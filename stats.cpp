#include "stats.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void statistics(vector<Record> &records)
{
    map<string, int> typecount;
    map<string, int> objNameCount;

    for (int i = 0; i < records.size(); i++)
    {
        typecount[records[i].type]++;
        objNameCount[records[i].objectName]++;
    }

    cout << "----STATISTICS----" << endl;
    cout << endl;

    cout << "*Type Stats:" << endl;
    cout << "_________________" << endl;

    for (auto ty : typecount)
    {
        cout << ty.first << ":" << ty.second << endl;
    }
    cout << "_________________" << endl;

    cout << endl
         << endl;

    cout << "*Object Name Stats:" << endl;
    cout << "____________" << endl;

    for (auto ob : objNameCount)
    {
        cout << ob.first << ":" << ob.second << endl;
    }
    cout << "____________" << endl;
}
