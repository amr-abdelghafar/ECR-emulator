//============================================================================
// Name        : ConfigCom.h
// Author      : Amr Tarek
// Version     : 1.0
// Description : Configuration file for COM port communication
//============================================================================

#include "ConfigCom.h"

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/********************** Configure this area ********************/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
ConfigCom ConfigComData = {
		COM2,						/* /dev/ttyS0 (COM1 on windows) */
		BAUDRATE_115200,			/* 115200 baud */
		{DATA_8,PARITY_N,STOP_1,0}	/*  Mode {Data, Parity bits, Stop bits}*/
};
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
