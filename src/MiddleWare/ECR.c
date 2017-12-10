//============================================================================
// Name        : ECR.c
// Author      : Amr Tarek
// Version     : 1.0
// Description : Electric Cash Register.
//============================================================================

#include "ECR.h"


unsigned char LRCCalc(char *stream, int size )
   {
   int i;
   unsigned char lrc;
   for (i = lrc = 0; i<size; i++)
      lrc ^= stream[i];
   lrc &= 0xff;
   return (lrc);
}

char hex2hch(char ch)
{
	unsigned char tmpch;
	tmpch = (unsigned char)ch;
	if (tmpch <= 9) {
		tmpch += '0';
	} else if (tmpch <= 0x0F) {
		tmpch += 0x37;
	} else {
		tmpch = '0';
	}
	return (char)tmpch;
}

void LRC_String(unsigned char LRCstring[3],char *stream, int size){
	unsigned char ret = 0;
	char retRight, retLeft;
	memset(LRCstring,'\0',3);
	ret = LRCCalc(stream,size);
	retRight = (ret & 0x0F);
	retLeft  = ((ret>>4) & 0x0F);
	LRCstring[0] = hex2hch(retLeft);
	LRCstring[1] = hex2hch(retRight);
}

