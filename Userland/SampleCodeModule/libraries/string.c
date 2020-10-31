#include <string.h>
#include <types.h>
#include <syscalls.h>

void itoa(int value, char* buffer, int length){
    for (int i = 0; i < length; i++){
        buffer[length - i - 1] = value % 10 + '0';
        value /= 10;
    } 
}

void dateToString(date myDate, char * buffer, char separator, int length) {
    
    itoa(myDate->day, buffer, 2);
	buffer[2] = separator;
	itoa(myDate->month, buffer + 3, 2);
	buffer[5] = separator;
    itoa(myDate->year, buffer + 6, 2);
    buffer[8] = ' ';
    itoa(myDate->hour, buffer + 9, 2);
	buffer[11] = ':';
    itoa(myDate->minutes, buffer + 12, 2);
	buffer[14] = ':';
    itoa(myDate->seconds, buffer + 15, 2);
    buffer[18] = '\0';
}

char* strcpy(char *destination, char *source){
    char *start = destination;

    while(*source != '\0'){
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
    return start;
}

int strlen(char* string){
    int count = 0;
    while(string[count]!='\0'){
        count++;
    }
    return count;
}

void println(char *toPrint){
    print(toPrint);
    print("\n");
}