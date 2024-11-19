#include <iostream>
#include <fstream>
#include <string>
#include "dataStructs.h"
using namespace std;

int main() {
    dataStructs DS; // contains ELF format
    ofstream hex_dump("output/hex_dump.txt", ios::trunc);

    hex_dump << DS.buildELFHeader();

    DS.PHt ass = new DS.PHt;

    ass.p_type[3] = "";
    

    hex_dump.close();
    return 0;
}