//============================================================================
// Name        : Communicate.h
// Author      : Amr Tarek
// Version     : 1.0
// Description : Middle ware Communication header file.
//============================================================================

#ifndef MIDDLEWARE_COMMUNICATE_H_
#define MIDDLEWARE_COMMUNICATE_H_


#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include "../Configuration/ConfigCom.h"
#include "../Libs/rs232.h"

#define MAX_REC_BUFFER 4096
extern ConfigCom ConfigComData;

/*
 * ComSend: to send data to serial.
 * Arguments:	char* data :the data you want to sent
 * Return: unsigned char - 0: success, 1: error.
 */
unsigned char ComSend(char* data);


/*
 * ComReceive: to receive data from serial.
 * Arguments: char* data: the data you want to receive
 * 			  unsigned int dataSize: the data size you want to receive.
 * Return: unsigned char - 0: success, 1: error.
 */
unsigned char ComReceive(char* data, unsigned int dataSize);


#endif /* MIDDLEWARE_COMMUNICATE_H_ */
