#include <stdio.h>
#include <syscalls.h>
#include <standardIO.h>

#define CHAR_COLOR 0xFFFFFF

void println(char *toPrint){
    printcFrom(toPrint,-1,-1,CHAR_COLOR);
    print("\n");
}

void print(char *toPrint){
    printcFrom(toPrint,-1,-1,CHAR_COLOR);
}

void printc(char* toPrint, int color){
    printcFrom(toPrint,-1,-1,color);
}

void printcFrom(char* toPrint, int row, int col, int color){
    write(toPrint,row,col,color);
}

void printFrom(char* toPrint, int row, int col){
    printcFrom(toPrint,row,col,CHAR_COLOR);
}

void removeChar(){
    print("\b");
}

char getChar(){
    char c;
    read(&c, 1);    
    return c;
}

void putChar(char c) {
    char buffer [2] = {0};
    *buffer=c;
    print(buffer);
}