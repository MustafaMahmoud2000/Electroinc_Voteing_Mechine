/*
 * menu.c
 *
 * Created: 1/17/2024 12:10:02 AM
 *  Author: DELL
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "menu.h"
extern volatile uint16 counter_timer;
extern uint8 timeout;
uint8 compare_pass(const uint8* pass1,const uint8* pass2,const uint8 size)
{
	uint8 counter1 = 0;
	uint8 returnval = 1;
	
	while(counter1 < size)
	{
		if(*(pass1+counter1) == *(pass2+counter1))
		{
		  returnval = 0;
		  break;	
		}
		counter1++;
	}
	return returnval;
	
}
