//============================================================================
// Name        : ECR.c
// Author      : Amr Tarek
// Version     : 1.0
// Description : Electric Cash Register.
//============================================================================

#ifndef MIDDLEWARE_ECR_H_
#define MIDDLEWARE_ECR_H_

#include <string.h>

/*
 * LRCCalc: To Calculate Longitudinal Redundancy Check.
 * Arguments: char* stream 	 			 : the Stream you want to make LRC for it.
 * 			  int size 	 				 : the Stream size.
 * Return: unsigned char				 : the calculated LRC.
 */
unsigned char LRCCalc(char *stream, int size );


/*
 * hex2hch: Convert a hexadecimal digit to a hexadecimal ASCII character.
 * Arguments: char ch 	 : a hexadecimal digit.
 * Return: 	  char		 : ch=0x00-0x09:'0'-'9', ch=0x0A-0x0F:'A'-'F', else:'0'.
 */
char hex2hch(char ch);



/*
 * LRC_String: To make Longitudinal Redundancy Check.
 * Arguments: unsigned char LRCstring[3] : for the LRC output
 * 			  char* stream 	 			 : the Stream you want to make LRC for it.
 * 			  int size 	 				 : the Stream size.
 * Return: -.
 */
void LRC_String(unsigned char LRCstring[3], char *stream, int size);


#endif /* MIDDLEWARE_ECR_H_ */
