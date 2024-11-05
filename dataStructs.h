/*

*/

#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H
#include <string>

using namespace std;

class dataStructs{
    public://////////////////////////////////////////////////////////////////////////////////
        struct {
            string e_ident_MAG[4] = {"7F", "45", "4C", "46"};
            string e_ident_CLASS[1] = {"00"}; //
            string e_ident_DATA[1] = {"01"}; 
            string e_ident_VERSION[1] = {"01"};
            string e_ident_OSABI[1] = {"03"};
            string e_ident_ABIVERSION[1] = {"00"};
            string e_ident_PAD[7] = {"00", "00", "00", "00", "00", "00", "00"}; 
            string e_type[2] = {"00", "00"}; //
            string e_machine[2] = {"00", "00"}; //
            string e_version[4] = {"01", "00", "00", "00"};
            string e_entry[8] = {"00", "00", "00", "00", "00", "00", "00", "00"}; //
            string e_phoff[8] = {"40", "00", "00", "00", "00", "00", "00", "00"};
            string e_shoff[8] = {"00", "00", "00", "00", "00", "00", "00", "00"}; //
            string e_flags[4] = {"00", "00", "00", "00"};
            string e_ehsize[2] = {"00", "00"}; //
            string e_phentsize[2] = {"00", "00"}; //
            string e_phnum[2] = {"00", "00"}; //
            string e_shentsize[2] = {"00", "00"}; //
            string e_shnum[2] = {"00", "00"}; //
            string e_shstrndx[2] = {"00", "00"}; //
        } ELFHeader;

        struct PHt{
            string p_type[4] = {"00", "00", "00", "00"};
            string p_flags64[4] = {"00", "00", "00", "00"}; // 64bit position
            string p_offset[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
            string p_vaddr[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
            string p_paddr[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
            string p_filesz[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
            string p_memsz[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
            string p_flags32[4] = {"00", "00", "00", "00"}; // 32bit position
            string p_align[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
        };

        struct SHt{
            string sh_name[4] = {"00", "00", "00", "00"};
            string sh_type[4] = {"00", "00", "00", "00"};
            string sh_flags[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
            string sh_addr[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
            string sh_offset[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
            string sh_size[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
            string sh_link[4] = {"00", "00", "00", "00"};
            string sh_info[4] = {"00", "00", "00", "00"};
            string sh_addralign[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
            string sh_entsize[8] = {"00", "00", "00", "00", "00", "00", "00", "00"};
        };
        ///////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////
        string buildELFHeader() { // constructs ELFHeader
            string ans = "";

            if (ELFHeader.e_ident_CLASS[0] == "02") {
                for (string item : ELFHeader.e_ident_MAG) ans += item;
                for (string item : ELFHeader.e_ident_CLASS) ans += item;
                for (string item : ELFHeader.e_ident_DATA) ans += item;
                for (string item : ELFHeader.e_ident_VERSION) ans += item;
                for (string item : ELFHeader.e_ident_OSABI) ans += item;
                for (string item : ELFHeader.e_ident_ABIVERSION) ans += item;
                for (string item : ELFHeader.e_ident_PAD) ans += item;
                for (string item : ELFHeader.e_type) ans += item;
                for (string item : ELFHeader.e_machine) ans += item;
                for (string item : ELFHeader.e_version) ans += item;
                for (string item : ELFHeader.e_entry) ans += item;
                for (string item : ELFHeader.e_phoff) ans += item;
                for (string item : ELFHeader.e_shoff) ans += item;
                for (string item : ELFHeader.e_flags) ans += item;
                for (string item : ELFHeader.e_ehsize) ans += item;
                for (string item : ELFHeader.e_phentsize) ans += item;
                for (string item : ELFHeader.e_phnum) ans += item;
                for (string item : ELFHeader.e_shentsize) ans += item;
                for (string item : ELFHeader.e_shnum) ans += item;
                for (string item : ELFHeader.e_shstrndx) ans += item; // 0x40 ending
            } else {
                // add 32bit construct here
                // 0x34 ending
            }
            return ans;
        }

        string buildPHt(PHt item) {
                string ans = "";

                if (ELFHeader.e_ident_CLASS[0] == "02") {
                    for (string item : item.p_type) ans += item;
                    for (string item : item.p_flags64) ans += item;
                    for (string item : item.p_offset) ans += item;
                    for (string item : item.p_vaddr) ans += item;
                    for (string item : item.p_paddr) ans += item;
                    for (string item : item.p_filesz) ans += item;
                    for (string item : item.p_memsz) ans += item;
                    for (string item : item.p_align) ans += item; // 0x38 ending
                } else {
                    // add 32bit construct here
                    // 0x20 ending
                }
                return ans;
            }

        string buildSHt(SHt item) { //later huh
            string ans = "";

            if (ELFHeader.e_ident_CLASS[0] == "02") {
                for (string item : item.sh_name) ans += item;
                for (string item : item.sh_type) ans += item;
                for (string item : item.sh_flags) ans += item;
                for (string item : item.sh_addr) ans += item;
                for (string item : item.sh_offset) ans += item;
                for (string item : item.sh_size) ans += item;
                for (string item : item.sh_link) ans += item;
                for (string item : item.sh_info) ans += item;
                for (string item : item.sh_addralign) ans += item;
                for (string item : item.sh_entsize) ans += item; // 0x40
            } else {
                // add 32bit construct here
                // 0x28 ending
            }
            return ans;
        }
        /////////////////////////////////////////////////////////////////////////////////////
};
#endif 

/*  <<<STRUCTS EXPLAINED>>>
<<ELFHeader>>
<e_ident[EI_MAG0] / e_ident[EI_MAG3]>
magic number 7F 45 4C 46 must always come and shall not be changed

<e_ident_CLASS>
01 and 02 represent 32bit and 64bit respectively

<e_ident_DATA>
01 and 02 represent little and big endian respectively, takes in effect at e_type[]

<e_ident_VERSION>
ELF header version, at the moment its fixed at 01

<e_ident_OSABI>
identifies the target operating system ABI

Value 	ABI
00 	    System V
01 	    HP-UX
02   	NetBSD
03 	    Linux
04 	    GNU Hurd
06 	    Solaris
07 	    AIX (Monterey)
08 	    IRIX
09 	    FreeBSD
0A 	    Tru64
0B 	    Novell Modesto
0C 	    OpenBSD
0D 	    OpenVMS
0E 	    NonStop Kernel
0F 	    AROS
10 	    FenixOS
11 	    Nuxi CloudABI
12  	Stratus Technologies OpenVOS

<e_ident_ABIVERSION>
specifies the ABI version

<e_ident_PAD>
pure padding, all 00s, does nothing at the moment

<e_type>
object file type

Value   Type        Description
00   	ET_NONE 	Unknown
01   	ET_REL  	Relocatable file
02   	ET_EXEC 	Executable file
03   	ET_DYN 	    Shared object
04   	ET_CORE 	Core file
FE00 	ET_LOOS 	Reserved inclusive range. Operating system specific
FEFF 	ET_HIOS
FF00 	ET_LOPROC 	Reserved inclusive range. Processor specific
FFFF 	ET_HIPROC

<e_machine>
specifies ISA

Value 	ISA
00  	No specific instruction set
01  	AT&T WE 32100
02  	SPARC
03  	x86
04  	Motorola 68000 (M68k)
05  	Motorola 88000 (M88k)
06  	Intel MCU
07  	Intel 80860
08  	MIPS
09  	IBM System/370
0A  	MIPS RS3000 Little-endian
0B      Reserved for future use
0E
0F   	Hewlett-Packard PA-RISC
13   	Intel 80960
14   	PowerPC
15   	PowerPC (64-bit)
16   	S390, including S390x
17   	IBM SPU/SPC
18      Reserved for future use
23
24   	NEC V800
25   	Fujitsu FR20
26   	TRW RH-32
27   	Motorola RCE
28   	Arm (up to Armv7/AArch32)
29   	Digital Alpha
2A   	SuperH
2B   	SPARC Version 9
2C   	Siemens TriCore embedded processor
2D   	Argonaut RISC Core
2E   	Hitachi H8/300
2F   	Hitachi H8/300H
30   	Hitachi H8S
31   	Hitachi H8/500
32   	IA-64
33   	Stanford MIPS-X
34   	Motorola ColdFire
35   	Motorola M68HC12
36   	Fujitsu MMA Multimedia Accelerator
37   	Siemens PCP
38   	Sony nCPU embedded RISC processor
39   	Denso NDR1 microprocessor
3A   	Motorola Star*Core processor
3B   	Toyota ME16 processor
3C   	STMicroelectronics ST100 processor
3D   	Advanced Logic Corp. TinyJ embedded processor family
3E   	AMD x86-64
3F   	Sony DSP Processor
40   	Digital Equipment Corp. PDP-10
41   	Digital Equipment Corp. PDP-11
42   	Siemens FX66 microcontroller
43   	STMicroelectronics ST9+ 8/16 bit microcontroller
44   	STMicroelectronics ST7 8-bit microcontroller
45   	Motorola MC68HC16 Microcontroller
46   	Motorola MC68HC11 Microcontroller
47   	Motorola MC68HC08 Microcontroller
48   	Motorola MC68HC05 Microcontroller
49   	Silicon Graphics SVx
4A   	STMicroelectronics ST19 8-bit microcontroller
4B   	Digital VAX
4C   	Axis Communications 32-bit embedded processor
4D   	Infineon Technologies 32-bit embedded processor
4E   	Element 14 64-bit DSP Processor
4F   	LSI Logic 16-bit DSP Processor
8C   	TMS320C6000 Family
AF   	MCST Elbrus e2k
B7   	Arm 64-bits (Armv8/AArch64)
DC   	Zilog Z80
F3   	RISC-V
F7   	Berkeley Packet Filter
101 	WDC 65C816
102 	LoongArch

<e_version>
original ELF version, fiexd at 01

<e_entry>
memory address of programs entry point, only first 4 bytes used if e_ident_CLASS is 01 (32bit)

<e_phoff>
memory address of where program header starts, only first 4 bytes used if e_ident_CLASS is 01 (32bit)

<e_shoff>
memory of of where section header starts, only first 4 bytes used if e_ident_CLASS is 01 (32bit)

<e_flags>
Processor specific flags, ? would be great to get more info on this

<e_ehsize>
ELF header size

<e_phentsize>
program header size

<e_phnum>
number of entries in program header

<e_shentsize>
section header size

<e_shnum>
number of entries in section header

<e_shstrndx>
index of section header entry that contains section names


<<program header>>
<p_type>
identifies type of segment

Value 	    Name     	Meaning
00000000 	PT_NULL 	Program header table entry unused.
00000001 	PT_LOAD 	Loadable segment.
00000002 	PT_DYNAMIC 	Dynamic linking information.
00000003 	PT_INTERP 	Interpreter information.
00000004 	PT_NOTE 	Auxiliary information.
00000005 	PT_SHLIB 	Reserved.
00000006 	PT_PHDR 	Segment containing program header table itself.
00000007 	PT_TLS   	Thread-Local Storage template.
60000000 	PT_LOOS 	Reserved inclusive range. Operating system specific.
6FFFFFFF 	PT_HIOS
70000000 	PT_LOPROC 	Reserved inclusive range. Processor specific.
7FFFFFFF 	PT_HIPROC

<p_flags64> (64bit position)
segment-dependent flags

Value 	Name 	Meaning
0x1 	PF_X 	Executable segment
0x2 	PF_W 	Writeable segment
0x4 	PF_R 	Readable segment

<p_offset>
need some testing on defenition for this

<p_vaddr>
virtual address of segment in memory

<p_paddr>
on systems where physical address is relevant, reserved for segment's physical address

<p_filesz>
segment size in file image, can be 0

<p_memsz>
segment size in memory, can be 0.

<p_flags32> (32bit position)
Segment-dependent flags (position for 32-bit structure). See above p_flags field for flag definitions.   need more info on this...

<p_align>
0 and 1 specify no alignment. Otherwise should be a positive, integral power of 2, with p_vaddr equating p_offset modulus p_align.


<<section header>>
<sh_name>
offset to a string in .shstrtab section that represents the name of this section

<sh_type>
identifies the type of this header

Value 	    ame 	            Meaning
0 	        SHT_NULL 	        Section header table entry unused
1 	        SHT_PROGBITS 	    Program data
2 	        SHT_SYMTAB 	        Symbol table
3 	        SHT_STRTAB 	        String table
4 	        SHT_RELA 	        Relocation entries with addends
5 	        SHT_HASH 	        Symbol hash table
6 	        SHT_DYNAMIC 	    Dynamic linking information
7 	        SHT_NOTE 	        Notes
8 	        SHT_NOBITS 	        Program space with no data (bss)
9 	        SHT_REL 	        Relocation entries, no addends
0A 	        SHT_SHLIB 	        Reserved
0B 	        SHT_DYNSYM 	        Dynamic linker symbol table
0E 	        SHT_INIT_ARRAY 	    Array of constructors
0F 	        SHT_FINI_ARRAY 	    Array of destructors
10 	        SHT_PREINIT_ARRAY 	Array of pre-constructors
11 	        SHT_GROUP 	        Section group
12 	        SHT_SYMTAB_SHNDX 	Extended section indices
13 	        SHT_NUM 	        Number of defined types.
60000000 	SHT_LOOS 	        Start OS-specific.

<sh_flags>
identifies attributes of the section

Value    	Name 	                Meaning
1 	        SHF_WRITE 	            Writable
2 	        SHF_ALLOC 	            Occupies memory during execution
4 	        SHF_EXECINSTR 	        Executable
10 	        SHF_MERGE 	            Might be merged
20 	        SHF_STRINGS 	        Contains null-terminated strings
40 	        SHF_INFO_LINK 	        'sh_info' contains SHT index
80 	        SHF_LINK_ORDER 	        Preserve order after combining
100 	    SHF_OS_NONCONFORMING 	Non-standard OS specific handling required
200 	    SHF_GROUP 	            Section is member of a group
400 	    SHF_TLS 	            Section hold thread-local data
0FF00000 	SHF_MASKOS 	            OS-specific
F0000000 	SHF_MASKPROC 	        Processor-specific
4000000 	SHF_ORDERED 	        Special ordering requirement (Solaris)
8000000 	SHF_EXCLUDE 	        Section is excluded unless referenced or allocated (Solaris)

<sh_addr>
virtual address of the section in memory, for sections that are loaded

<sh_offset> 
offset the section in the file image

<sh_size>
section size, can be 0

<sh_link>
contains the section index of an associated section. This field is used for several purposes, depending on the type of section.   need more info

<sh_info>
contains extra information about the section. This field is used for several purposes, depending on the type of section.   need more info

<sh_addralign>
contains required alignment of the section. This field must be a power of two

<sh_entsize>
contains the size, in bytes, of each entry, for sections that contain fixed-size entries. Otherwise, this field contains zero
*/