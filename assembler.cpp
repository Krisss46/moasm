#include <iostream>
#include <fstream>
#include <string>
#include "dataStructs.h"
using namespace std;

int main() {
    dataStructs DS; // contains ELF format
    ofstream hex_dump("output/hex_dump.txt", ios::trunc);

    hex_dump << DS.buildELFHeader();

    

    hex_dump.close();
    return 0;
}