/*
 * STD_message.h
 *
 * Created: 1/17/2024 12:11:45 AM
 *  Author: MUSTAFA
 */ 


#ifndef STD_MESSAGE_H_
#define STD_MESSAGE_H_


#define room1status 0x11
#define room2status 0x12
#define room3status 0x13
#define room4status 0x14
#define TVstatus 0x15
#define AIRCONDITIONstatus  0x16


#define room1turn_on 0x21
#define room2turn_on 0x22
#define room3tunn_on 0x23
#define room4turn_on 0x24
#define TVturn_on 0x25
#define AIRCONDITIONturn_on 0x26


#define room1turn_off 0x31
#define room2turn_off 0x32
#define room3tunn_off 0x33
#define room4turn_off 0x34
#define TVturn_off 0x35
#define AIRCONDITIONturn_off 0x36



#define set_temp 0x40
#define ack 0xff
#define demand_response 0xff
#define on_status 0x01
#define off_status 0x00

#endif /* STD_MESSAGE_H_ */