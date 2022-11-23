#include <p18f4550>
#include "vetor_relocate"
void msdelay(unsigned int time);
void main()
{
	TRISCbits.TRISC2=0;
	PR2=0XBB;
	CCPICON=0x0C;
	T2CON=0x07;
	PORTDbits.RD5=1;
	PORTDbits.RD6=0;
	
	while(1){
		CCPR1L=0xBB;
		CCPICONbits.DC1B0=0;
		CCPICONbits.DC1B1=0;
		msdelay(3000);
		
		CCPR1L=149;
		CCPICONbits.DC1B0=0;
		CCPICONbits.DC1B1=1;
		msdelay(3000);
		
		CCPR1L=112;
		CCPICONbits.DC1B0=1;
		CCPICONbits.DC1B1=0;
		msdelay(3000);
		
		CCPR1L=0x4A;
		CCPICONbits.DC1B0=1;
		CCPICONbits.DC1B1=1;
		msdelay(3000);
		
		CCPR1L=0x25;
		CCPICONbits.DC1B0=0;
		CCPICONbits.DC1B1=1;
		msdelay(3000);
	}
}

void msdelay(unsigned int time){
	unsigned int i,j;
	for(i=0;i<time;i++)
	for(j=0;j<1275;j++);
}