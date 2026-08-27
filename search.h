#pragma once

#include <vector>
#include <string>
#include <functional>
#include "records.h"

using namespace std;

void searchPrintRecord(vector<Record> &records, function<bool(Record)> matches);

void searchRecord(vector<Record> &records);
