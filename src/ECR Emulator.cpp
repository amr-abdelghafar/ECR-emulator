//============================================================================
// Name        : ECR.cpp
// Author      : Amr Tarek
// Version     : 1.0
// Description : ECR Emulator
//============================================================================

#include <iostream>
extern "C" {
#include "MiddleWare/Communicate.h"
#include "MiddleWare/ECR.h"
}
using namespace std;

int main() {
	// Wait for enter to start.
	cout << "*********************************************" << endl;
	cout << "** Welcome to the ECR simulator on console **" << endl;
	cout << "*********************************************" << endl;
	cout << "******************Com Port*******************" << endl;
	char dataToSend[50],temp[50];
	char* ptr;
	int ch;
	string sString;
	while(1) {
		cout << "Enter 1 for COM1 and 2 for COM2 and so on... (1 - 9):";
		cin >> sString;
		sString[0] -= 0x30;
		if(sString.length() == 1)
			if(sString[0] < 10 && sString[0] > 0){
				cout << "COM" << +sString[0] << " seleced"<< endl;
				ConfigComData.comPortNr = sString[0]-1;
				break;
			}
		cout << "Please Enter number from 1 to 9:"<< endl;
	};
	cout << "*********************************************" << endl << endl;
	cout << "***************Operation mode****************" << endl;
	while(1) {
		cout << "Enter 1 for Sale and 2 for Refund operation. (1 - 2):";
		cin >> sString;
		sString[0] -= 0x30;
		if(sString.length() == 1)
			if(sString[0] < 3 && sString[0] > 0){
				if(sString[0] == 1) cout << "Operation -Sale- seleced"<< endl;
				if(sString[0] == 2) cout << "Operation -Refund- seleced"<< endl;
				sprintf(dataToSend,"%02d",sString[0]);
				break;
			}
		cout << "Please Enter number from 1 to 2:"<< endl;
	};
	cout << "*********************************************" << endl << endl;
	cout << "********************Amount*******************" << endl;
	long itemp,iAmount, iAmountCents;
	string sAmount, sAmountCents;
	while(1) {
		cout << "Enter the amount in cents (0.01 - 10000.00):";
		cin >> sString;
		itemp = sString.find('.');
		if(itemp > 0){
			sAmount = sString.substr(0,itemp);
			iAmount = strtol(sAmount.c_str(),&ptr,10);
			if(iAmount >= 0){
				sAmountCents = sString.substr(itemp+1, sString.length()-1);
				iAmountCents = strtol(sAmountCents.c_str(),&ptr,10);
				if(iAmountCents && (sAmountCents.length() <= 2)){
					if((iAmount < 10000) || (iAmountCents < 100 && iAmountCents > 0)){
						cout << "Amount:" << sString << endl;
						sprintf(&dataToSend[strlen(dataToSend)],"+%ld.%s",iAmount,sAmountCents.c_str());
						break;
					}
				}
			}
		}else{
			iAmount = strtol(sString.c_str(),&ptr,10);
			if(iAmount){
				cout << "Amount:" << sString << endl;
				sprintf(&dataToSend[strlen(dataToSend)],"+%ld.00",iAmount);
				break;
			}
		}
		cout << "Please Enter number from 0.01 to 10000.00:"<< endl;
	};
	cout << "*********************************************" << endl << endl;
	cout << "**************Referance Number***************" << endl;
	while(1) {
		cout << "Enter the Referance number -maximum size 15 digit:";
		cin >> sString;
		if(sString.length() <= 15){
			itemp = strtol(sString.c_str(),&ptr,10);
			if(itemp > 0 ){
				cout << "Referance Num:" << sString << endl;
				sprintf(&dataToSend[strlen(dataToSend)],"+%015ld",itemp);
				break;
			}
		}
		cout << "Please Enter number with maximum 15 digits:"<< endl;
	};
	cout << "*********************************************" << endl << endl;
	cout << "**********Mobile Number (Optional)***********" << endl;
		while(1) {
			cout << "Enter the Mobile number -size 11 digit, you can pass it by enter 0:";
			cin >> sString;
			if(sString.length() == 11 || sString.length() == 1){
				itemp = strtol(sString.c_str(),&ptr,10);
				if((sString.length() == 11) && (itemp > 0)){
					cout << "Mobile Num:" << sString << endl;
					sprintf(&dataToSend[strlen(dataToSend)],"+%s",sString.c_str());
					break;
				}else if(itemp == 0 ){
					cout << "Mobile Num bypassed" << endl;
					break;
				}
			}
			cout << "Please Enter number with maximum 15 digits:"<< endl;
		};
		// Add LRC and head(0F) and trail (0FF)
		unsigned char LRCstring[3];
		LRC_String(LRCstring, dataToSend, strlen(dataToSend));
		memset(temp,0,sizeof(temp));
		sprintf(temp,"0F+%s",dataToSend);
		sprintf(dataToSend,"%s+0FF%s",temp,LRCstring);

	cout << "*********************************************" << endl;
	cout << "dataToSend: " << dataToSend << endl;

	cout << "Press Enter when the Terminal ready to receive" << endl;
	while ((ch = getchar()) != '\n' && ch != EOF);
	getchar();
	if(ComSend(dataToSend)){
		cout << "Send Success" << endl;
	}else{
		cout << "Send Error" << endl;
		cout << "Press Enter to Exit !!\n" << endl;
		while ((ch = getchar()) != '\n' && ch != EOF);
		getchar();
		return(0);
	}

	cout << endl << "*********************************************" << endl;
	cout 		 << "******Waiting for the terminal response******" << endl;
	cout 		 << "*********************************************" << endl << endl;

	char data[100];
	while(ComReceive(data,sizeof(data))){
		/* the End of the ECR string*/
		ptr = strstr(data,"+0FF");
		if(ptr !=0 ){
			cout << data << endl << "Receive Success " << endl;
			break;
		}
	}

	sString = data;

//	sString = "0F+03+029343+000+47617xxxxxx10465+000001+0001+0FF12";
	string lrcString,authCode,serverRes,pan,batchNm,recNm,trailer;
//	char LRC[3];

	lrcString = sString.substr(sString.find('+')+1);
	sString = sString.substr(sString.find('+')+1);
	sString = sString.substr(sString.find('+')+1);
	authCode = sString.substr(sString.find('+')+1);
	authCode = sString.substr(0,sString.find('+'));
	sString = sString.substr(sString.find('+')+1);
	serverRes = sString.substr(sString.find('+')+1);
	serverRes = sString.substr(0,sString.find('+'));
	sString = sString.substr(sString.find('+')+1);
	pan = sString.substr(sString.find('+')+1);
	pan = sString.substr(0,sString.find('+'));
	sString = sString.substr(sString.find('+')+1);
	batchNm = sString.substr(sString.find('+')+1);
	batchNm = sString.substr(0,sString.find('+'));
	sString = sString.substr(sString.find('+')+1);
	recNm = sString.substr(sString.find('+')+1);
	recNm = sString.substr(0,sString.find('+'));
	sString = sString.substr(sString.find('+')+1);
	trailer = sString;
//	LRC[0] = trailer[trailer.length()-2];
//	LRC[1] = trailer[trailer.length()-1];
	lrcString = lrcString.substr(0,lrcString.find(trailer)-1);


	cout << "Authorization Code :" <<authCode <<endl;
	cout << "Server Response    :" <<serverRes <<endl;
	cout << "PAN                :" <<pan <<endl;
	cout << "Batch Number       :" <<batchNm <<endl;
	cout << "Receipt Number     :" <<recNm <<endl;
//	cout << "Trailer            :" << trailer <<endl;
//	cout << "LRC                :" << LRC <<endl;
//	cout << "lrcString          :" << lrcString <<endl;


	cout << "You can Exit now !!\n" << endl;
	while(1);
	return 0;
}
