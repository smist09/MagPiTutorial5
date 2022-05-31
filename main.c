//
// C program to call our Assembly Language
// toupper routine.
//

#include <stdio.h>
#include "pico/stdlib.h"

extern void initTempSensor();
extern int readTemp();

#define MAX_BUFFSIZE 255
void main()
{
	char *str = "This is a test.";
	char outBuf[MAX_BUFFSIZE];
	int adctemp;
	int temp;
	
	stdio_init_all();

	initTempSensor();
	
	while( 1 )
	{
		adctemp = readTemp();
		temp = 437 - (100 *adctemp) / 215;		
		printf("Temerpature = %d\n", temp);
		sleep_ms(1000);
	}	
}
