//============================================================================
// Name        : ConfigCom.h
// Author      : Amr Tarek
// Version     : 1.0
// Description : Configuration file for COM port communication
//============================================================================

#ifndef CONFIGCOM_H_
#define CONFIGCOM_H_

/*********************/
/* Windows COM ports */
/*********************/
#define COM1 0
#define COM2 1
#define COM3 2
#define COM4 3
#define COM5 4
#define COM6 5
#define COM7 6
#define COM8 7
#define COM9 8
#define COM10 9
/*********************/

/***********************/
/* Supported Baud rate */
/***********************/
#define BAUDRATE_110 110
#define BAUDRATE_300 300
#define BAUDRATE_600 600
#define BAUDRATE_1200 1200
#define BAUDRATE_2400 2400
#define BAUDRATE_4800 4800
#define BAUDRATE_9600 9600
#define BAUDRATE_19200 19200
#define BAUDRATE_38400 38400
#define BAUDRATE_57600 57600
#define BAUDRATE_115200 115200
#define BAUDRATE_128000 128000
#define BAUDRATE_256000 256000
#define BAUDRATE_500000 500000
/***********************/

/************************/
/* Supported Frame Data */
/************************/
#define DATA_5 '5'
#define DATA_6 '6'
#define DATA_7 '7'
#define DATA_8 '8'
/************************/

/*************************/
/* Supported Parity Bits */
/*************************/
#define PARITY_N 'N'	/*No Parity bit*/
#define PARITY_E 'E'	/*Even Parity bit*/
#define PARITY_O 'O'  	/*Odd Parity bit*/
/*************************/

/***********************/
/* Supported Stop Bits */
/***********************/
#define STOP_1 '1'		/*1 stop bit*/
#define STOP_2 '2'		/*1 stop bit*/
/***********************/

typedef struct ConfigComStruct{
	int comPortNr;      			  	/* /dev/ttyS0 (COM1 on windows) */
	int baudRate;       				/* 9600 baud */
	char mode[4];						//  Mode {Data, Parity bits, Stop bits}
}ConfigCom;

#endif /* CONFIGCOM_H_ */
