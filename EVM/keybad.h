/*
 * keybad.h
 *
 * Created: 11/3/2023 11:26:27 AM
 *  Author: DELL
 */ 


#ifndef KEYBAD_H_
#define KEYBAD_H_
#define keybad_port 'D'
#include "DIO.h"
#define card_size   (unsigned char)5
#define NOT_SELECTED 0xFF
#define notpassed 0xFF
void keypad_vinit(void);
#define card_set  (unsigned char) 0x01
char keybad_u8read_press();
#define  status_location_user1  (unsigned short) 0x101
#define  location_user2  (unsigned short) 0x100




#endif /* KEYBAD_H_ */