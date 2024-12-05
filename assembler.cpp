#include <iostream>
#include <fstream>
#include <string>
#include "dataStructs.h"
using namespace std;

int main() {
    dataStructs DS; // contains ELF format
    ofstream hex_dump("output/hex_dump.txt", ios::trunc);
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DS.ELFHeader.e_ident_CLASS[0] = "02";
    DS.ELFHeader.e_type[0] = "03";
    DS.ELFHeader.e_machine[0] = "3E";
    DS.ELFHeader.e_entry[2] = "40";
    DS.ELFHeader.e_shoff[0] = "78";
    DS.ELFHeader.e_ehsize[0] = "40";
    DS.ELFHeader.e_phentsize[0] = "38";
    DS.ELFHeader.e_phnum[0] = "01";
    DS.ELFHeader.e_shentsize[0] = "40";
    DS.ELFHeader.e_shnum[0] = "04";
    DS.ELFHeader.e_shstrndx[0] = "03";
    hex_dump << DS.buildELFHeader();


    dataStructs::PHt text;
    text.p_type[0] = "01";
    text.p_flags64[0] = "05";
    text.p_offset[0] = "A2";
    text.p_offset[1] = "01";
    text.p_vaddr[2] = "40";
    text.p_paddr[2] = "40";
    text.p_filesz[0] = "2A";
    text.p_memsz[0] = "2A";
    text.p_align[0] = "10";
    hex_dump << DS.buildPHt(text);


    dataStructs::SHt null;
    hex_dump << DS.buildSHt(null);

    dataStructs::SHt td;
    td.sh_name[0] = "0B";
    td.sh_type[0] = "01";
    td.sh_flags[0] = "06";
    td.sh_addr[2] = "40";
    td.sh_offset[0] = "78";
    td.sh_offset[1] = "01";
    td.sh_size[0] = "2A";
    td.sh_addralign[0] = "10";
    td.sh_entsize[0] = "2A";
    hex_dump << DS.buildSHt(td);

    dataStructs::SHt rodata;
    rodata.sh_name[0] = "11";
    rodata.sh_type[0] = "01";
    rodata.sh_flags[0] = "02";
    rodata.sh_addr[2] = "60";
    rodata.sh_offset[0] = "A2";
    rodata.sh_offset[1] = "01";
    rodata.sh_size[0] = "0D";
    rodata.sh_addralign[0] = "10";
    rodata.sh_entsize[0] = "0D";
    hex_dump << DS.buildSHt(rodata);

    dataStructs::SHt tab;
    tab.sh_name[0] = "01";
    tab.sh_type[0] = "03";
    tab.sh_flags[0] = "00";
    tab.sh_addr[0] = "00";
    tab.sh_offset[0] = "AF";
    tab.sh_offset[1] = "01";
    tab.sh_size[0] = "19";
    tab.sh_addralign[0] = "10";
    tab.sh_entsize[0] = "19";
    hex_dump << DS.buildSHt(tab);

    hex_dump << "48B80100000000000000 48BF0100000000000000 48BE0000600000000000 48BA0D00000000000000 0F05"; // code 42 
    hex_dump << "48656c6c6f2c20576f726c6421"; // hello world 13 
    hex_dump << "00 2E736873747274616200 2E7465787400 2E726F6461746100"; // section names 25 

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    hex_dump.close();
    return 0;
}
/* Notes
Element     Addr    size
-------------------------
ELFHeader   0x40    64
PHtHeader   0x78    56
S.null      0xB8    64
S.text      0xF8    64
S.rodata    0x138   64
S.tab       0x178   64
.text       0x1A2   42
.rodata     0x1AF   13
Names       0x1C8   25
------------------------


mov rax, 1          ; syscall number for sys_write
mov rdi, 1          ; file descriptor 1 (standard output)
mov rsi, message    ; pointer to the message to print
mov rdx, length     ; length of the message
syscall             ; invoke the syscall

B8: RAX
B9: RCX
BA: RDX
BB: RBX
BC: RSP
BD: RBP
BE: RSI
BF: RDI
0F05: syscall

*/