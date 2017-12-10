//============================================================================
// Name        : Communicate.c
// Author      : Amr Tarek
// Version     : 1.0
// Description : Middle ware Communication source file.
//============================================================================

#include "Communicate.h"

unsigned char ComSend(char* data){
	if(RS232_OpenComport(ConfigComData.comPortNr, ConfigComData.baudRate, ConfigComData.mode)){
		printf("Can not open com port: %d\n", ConfigComData.comPortNr+1);
		return(0);
	}
		RS232_cputs(ConfigComData.comPortNr, data);
		printf("%s\n", data);
#ifdef _WIN32
		Sleep(1000);
#else
		usleep(1000000);  /* sleep for 1 Second */
#endif
	return(1);
}


unsigned char ComReceive(char* data, unsigned int dataSize){
	unsigned char buf[MAX_REC_BUFFER];
	int i = 0, n;
	while(1)
	{
		n = RS232_PollComport(ConfigComData.comPortNr, buf, MAX_REC_BUFFER);
		if(n > 0)
		{
			buf[n] = 0;   /* always put a "null" at the end of a string! */
			for(i=0; i < n; i++)
			{
				if(buf[i] < 32)  /* replace unreadable control-codes by dots */
				{
					buf[i] = '.';
				}
			}
			//printf("received %i bytes: %s\n", n, (char *)buf);
//			if(n<dataSize){
				memset(data,'\0',strlen(data));
				memcpy(data,buf,n);
				return(1);
//			}else{
//				printf("*****************************************************\n");
//				printf("Error: Received data are more than the expected limit\n");
//				printf("*****************************************************\n");
//				return(0);
//			}

		}
//		else{
//			printf("***************************************************\n");
//			printf("Error: Received data are more than the buffer limit\n");
//			printf("***************************************************\n");
//			return(0);
//		}
#ifdef _WIN32
		Sleep(100);
#else
		usleep(100000);  /* sleep for 100 milliSeconds */
#endif
	}
	return(0);
}
