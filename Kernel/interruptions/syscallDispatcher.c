#include <stdint.h>
#include <videoDriver.h>
#include <keyboardDriver.h>
#include <timerDriver.h>

static int readHandler();
static int writeHandler();
static void getDate();


void syscallDispatcher(uint64_t call, uint64_t first_parameter, uint64_t second_parameter) {
	switch (call) {
		case 0:
			readHandler((int)first_parameter, (char*) second_parameter); //0 read
			break;
		case 1:
			writeHandler((int)first_parameter, (char*) second_parameter); //1 write
			break;
		case 10: 
			getTime((date) first_parameter);
			break;
	}
	return;
}

int readHandler(int length, char* toRead){
    readBuffer(toRead);
    return 0;
}


static int j = 0;
int writeHandler(int length, char* toWrite){
	for(int i = 0; i < length; i++) {
    	draw_char(toWrite[i], 15, 15 + (j++) * 8, 0x1FFFFF);

	}
    return 0;
}

void getTime(date myDate){
	getLocalDate(myDate);
}
