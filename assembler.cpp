#include <iostream>
#include <fstream>
#include <string>
#include "dataStructs.h"
using namespace std;

int main() {
    dataStructs DS; // contains ELF format
    ofstream hex_dump("output/hex_dump.txt", ios::trunc);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DS.ELFHeader.e_ident_CLASS[0] = "02"; //set to 64bit mode
    DS.ELFHeader.e_type[0] = "02"; // set to executable
    DS.ELFHeader.e_machine[0] = "3E"; // AMD processor
    DS.ELFHeader.e_entry[0] = "78"; // entry point
    DS.ELFHeader.e_entry[1] = "01";
    DS.ELFHeader.e_entry[3] = "08";
    DS.ELFHeader.e_shoff[0] = "78"; // section header offset
    DS.ELFHeader.e_ehsize[0] = "40"; // ELF header size
    DS.ELFHeader.e_phentsize[0] = "38"; // Program header size
    DS.ELFHeader.e_phnum[0] = "01"; // Number of program entries
    DS.ELFHeader.e_shentsize[0] = "40"; // Section header size
    DS.ELFHeader.e_shnum[0] = "04"; // Number of section entries
    DS.ELFHeader.e_shstrndx[0] = "03"; // Index of section header table entry that contains section names
    hex_dump << DS.buildELFHeader(); // 0x40

    dataStructs::PHt text;
    text.p_type[0] = "01"; // .text is loadable
    text.p_flags64[0] = "07"; // readable and executable
    text.p_offset[0] = "78"; // program offset
    text.p_offset[1] = "01";
    text.p_vaddr[3] = "08"; // Virtual address of the segment in memory
    text.p_paddr[3] = "08"; // On systems where physical address is relevant, reserved for segment's physical address
    text.p_filesz[0] = "43"; // Size in bytes of the segment in the file image 
    text.p_memsz[0] = "43"; // Size in bytes of the segment in memory
    hex_dump << DS.buildPHt(text); // 0x78

    dataStructs::SHt null;
    hex_dump << DS.buildSHt(null); // 0xB8

    dataStructs::SHt stext;
    stext.sh_name[0] = "0B"; // An offset to a string in .shstrtab section that represents the name of this section
    stext.sh_type[0] = "01"; // program data
    stext.sh_flags[0] = "06"; // takes memory and executable
    stext.sh_addr[0] = "78"; // Virtual address of section in memory
    stext.sh_addr[1] = "01"; // Virtual address of section in memory
    stext.sh_addr[3] = "08"; // Virtual address of section in memory
    stext.sh_offset[0] = "78"; // offset of section names table
    stext.sh_offset[1] = "01";
    stext.sh_size[0] = "1D"; // size of section names table
    hex_dump << DS.buildSHt(stext); // 0xF8

    dataStructs::SHt rodata;
    rodata.sh_name[0] = "11"; // An offset to a string in .shstrtab section that represents the name of this section
    rodata.sh_type[0] = "01"; // program data
    rodata.sh_flags[0] = "02"; // takes memory and executable
    rodata.sh_addr[0] = "95"; // Virtual address of section in memory
    rodata.sh_addr[1] = "01"; // Virtual address of section in memory
    rodata.sh_addr[3] = "08"; // Virtual address of section in memory
    rodata.sh_offset[0] = "95"; // offset of section names table
    rodata.sh_offset[1] = "01"; // offset of section names table
    rodata.sh_size[0] = "0D"; // size of section names table
    hex_dump << DS.buildSHt(rodata); // 0x138

    dataStructs::SHt shstrtab;
    shstrtab.sh_name[0] = "01"; // An offset to a string in .shstrtab section that represents the name of this section
    shstrtab.sh_type[0] = "03"; // string table 
    shstrtab.sh_offset[0] = "A2"; // offset of section names table
    shstrtab.sh_offset[1] = "01";
    shstrtab.sh_size[0] = "19"; // size of section names table
    hex_dump << DS.buildSHt(shstrtab); // 0x178

    hex_dump << "b801000000 bf01000000 4889f6  ba0d000000 0f05 b860000000 31ff 0f05"; // print hello world code 0x195  29
    hex_dump << "48 65 6c 6c 6f 2c 20 57 6f 72 6c 64 21"; // hello world 0x1A2  13
    hex_dump << "00 2E736873747274616200 2E7465787400 2E726F6461746100"; // section names 0x1BB  25

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    hex_dump.close();
    return 0;
}