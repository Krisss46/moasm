#!/bin/bash

if [ "$#" -eq 1 ]; then
    if [ "$1" = "debug" ]; then
        g++ assembler.cpp -o assembler && ./assembler
        xxd -r -p output/hex_dump.txt output/executable.bin
        chmod +x output/executable.bin && ./output/executable.bin
    
    elif [ "$1" = "clear" ]; then
        rm assembler
        rm output/executable.bin
        rm output/hex_dump.txt

    elif [ "$1" = "dump" ]; then
        xxd output/executable.bin

    elif [ "$1" = "run" ]; then
        xxd -r -p output/hex_dump.txt output/executable.bin
        chmod +x output/executable.bin && ./output/executable.bin

    elif [ "$1" = "build" ]; then
        g++ assembler.cpp -o assembler && ./assembler

    elif [ "$1" = "help" ]; then
        echo debug - Compile, assemble and run executable
        echo run --- Assemble and run executable
        echo build - Compile assembler

    else
        echo invalid arguement, type help for more information
    fi

elif [ "$#" -eq 2 ]; then
    if [ false ]; then
        echo nothing1
    else
        echo invalid first arguement, type help for more information
    fi
fi