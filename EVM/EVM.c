/*
 * EVM.c
 *
 * Created: 11/3/2023 8:35:00 PM
 *  Author: DELL
 */ 


#include <avr/io.h>
#include "button.h"
#include "LCD 8BIT.h"
#include "keybad.h"
#include "menu.h"
#include "EEPROM.h"
#define F_CPU 8000000UL
#include <util/delay.h>
unsigned char counter1=0;
unsigned char counter2=0;
unsigned char counter3=0;
unsigned char counter4=0;
 //unsigned char counter6= 0;
int main(void)
{
// 	 keypad_vinit();
// 	 LCD_INIT();
// 	 unsigned char keypressd=notpassed;
	
	 keypad_vinit();
	 LCD_INIT();
	 unsigned char keypressd=notpassed;
	 while(1)
	 {
		 LCD_SEND_CMD(0X0C);
	     
	     unsigned char user[card_size]={NOT_SELECTED,NOT_SELECTED,NOT_SELECTED,NOT_SELECTED};
	     unsigned char STORED_card[card_size] ={0XFF,0XFF,0XFF,0XFF};
			  LCD_MOVE_CURSOR(1,5);
			  LCD_SEND_STRING("welcome");
			  LCD_MOVE_CURSOR(2,2);
			  LCD_SEND_STRING("voting machine");
			  _delay_ms(700);
			  LCD_clear_screen();
			  LCD_SEND_STRING("last four digits ");
			  LCD_MOVE_CURSOR(2,3);
			  LCD_SEND_STRING("of ID card");
			  _delay_ms(1000);
			  LCD_clear_screen();
			  LCD_SEND_STRING("Enter ID:");
			  LCD_MOVE_CURSOR(2,6);
			  LCD_SEND_STRING("____");
			  LCD_MOVE_CURSOR(2,6);
			  //_delay_ms(100);
		 unsigned char counter6 = 0;
// 		 while(counter6 < card_size)
// 		 {
// 			//_delay_ms(30);
// 			 keypressd = notpassed;
// 			 while(keypressd == notpassed)
// 			 {
// 				keypressd = keybad_u8read_press();
// 			 }
// 			 user [counter6] = keypressd;
// 			 LCD_SEND_CHAR(keypressd);
// 			_delay_ms(1000);
// 			 LCD_MOVE_CURSOR(2,6+(counter6++));
// 			_delay_ms(100);
// 			 /*counter6++;*/	
// 			// keypressd = notpassed;
// 		 }
        for(counter6=0;counter6<=3;counter6++)
        {
	        do
	        {
		        keypressd=keybad_u8read_press();
	        }while(keypressd==notpassed);
	        LCD_MOVE_CURSOR(2,counter6+6);
	        LCD_SEND_CHAR(keypressd);
	        _delay_ms(300);
	        LCD_MOVE_CURSOR(2,counter1+6);
	        
        }
		 LCD_clear_screen();
		 eeprom_writeblock_from_address(location_user2,user,card_size);
		 eeprom_writebyte_to_address (status_location_user1,card_set);
         
		 eeprom_readblock_from_address(location_user2,STORED_card,card_size);
		 if(compare_pass(user,STORED_card,card_size) == 1)
		 {
			 LCD_clear_screen();
			 LCD_MOVE_CURSOR(1,2);
			 LCD_SEND_STRING("press once on ");
			 LCD_MOVE_CURSOR(2,3);
			 LCD_SEND_STRING("any button");
			 _delay_ms(400);
		 }
		 else
		 {
			 
			 LCD_clear_screen();
			 LCD_SEND_STRING("wrong ID");
			 _delay_ms(700);
			 LCD_clear_screen();
			
		 }
		 LCD_clear_screen();
		 LCD_SEND_CMD(0X0C);
		 u8Button_read('C',0);
		 u8Button_read('C',1);
		 u8Button_read('C',2);
		 u8Button_read('C',3);
		 u8Button_read('C',4);
		 LCD_MOVE_CURSOR(1,3);
		 LCD_SEND_STRING("Please Vote");
		 _delay_ms(500);
		 LCD_clear_screen();
		 LCD_SEND_STRING("A=");
		 LCD_MOVE_CURSOR(1,3);
		 LCD_SEND_CHAR(counter1+48);
		 LCD_MOVE_CURSOR(1,12);
		 LCD_SEND_STRING("B=0");
		 LCD_MOVE_CURSOR(1,14);
		 LCD_SEND_CHAR(counter2+48);
		 LCD_MOVE_CURSOR(2,1);
		 LCD_SEND_STRING("C=0");
		 LCD_MOVE_CURSOR(2,3);
		 LCD_SEND_CHAR(counter3+48);
		 LCD_MOVE_CURSOR(2,12);
		 LCD_SEND_STRING("D=0");
		 LCD_MOVE_CURSOR(2,14);
		 LCD_SEND_CHAR(counter4+48);
		 
		while(1)
		{
			
			if(u8Button_read('C',0)==1)
			{
			counter1++;
			LCD_MOVE_CURSOR(1,3);
			    if(counter1<10)
				 {
				   LCD_SEND_CHAR(counter1+48);
				 }
				else
				 {
				   LCD_SEND_CHAR(counter1/10+48);
				   LCD_SEND_CHAR(counter1%10+48);  
				 }
				 while(u8Button_read('C',0)==1);
				  LCD_clear_screen();
				 break;
			}		
		   else if(u8Button_read('C',1)==1)
			 {
				counter2++;
				LCD_MOVE_CURSOR(1,14);
				if(counter2<10)
				{
					LCD_SEND_CHAR(counter2+48);	
				}
				else
				{
					LCD_SEND_CHAR(counter2/10+48);
					LCD_SEND_CHAR(counter2%10+48);	
				}
				while(u8Button_read('C',1)==1);
				 LCD_clear_screen();
				 break;
			}
			else if (u8Button_read('C',2)==1)
			{
				counter3++;
				LCD_MOVE_CURSOR(2,3);
				if(counter3<10)
				{
					LCD_SEND_CHAR(counter3+48);	
				}
				else
				{
					LCD_SEND_CHAR(counter3/10+48);
					LCD_SEND_CHAR(counter3%10+48);
				}
				 while(u8Button_read('C',2)==1);
				LCD_clear_screen();
				break;
			}
		
			else if(u8Button_read('C',3)==1)
			{
				_delay_ms(50);
				counter4++;
				LCD_MOVE_CURSOR(2,14);
				if(counter4<10)
				{
					LCD_SEND_CHAR(counter4+48);
				}					
				else
				{
					LCD_SEND_CHAR(counter4/10+48);
					LCD_SEND_CHAR(counter4%10+48);	
				}
				 while(u8Button_read('C',3)==1);
				LCD_clear_screen();
				break;
			}
			else if(u8Button_read('C',4)==1)
			{
				counter1=counter2=counter3=counter4=0;
			
			
				 LCD_MOVE_CURSOR(1,1);
				 LCD_SEND_STRING("A=0 ");
				 LCD_MOVE_CURSOR(1,12);
				 LCD_SEND_STRING("B=0 ");
				 LCD_MOVE_CURSOR(2,1);
				 LCD_SEND_STRING("C=0 ");
				 LCD_MOVE_CURSOR(2,12);
				 LCD_SEND_STRING("D=0 ");
				 LCD_MOVE_CURSOR(1,1);
				 LCD_clear_screen();
				 break;
			}
			while(u8Button_read('C',4)==1);
			_delay_ms(200);
		}
	  
	  }
	
	}