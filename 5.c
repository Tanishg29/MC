#include <p18f4520.h>
#include "vector_relocate"
Bootloader
void msdelay(unsigned int time){
	unsigned int i,j;
	for (i=0;i<time;i++)
	for (j=0;j<1275;j++);
}

void main()
{
	unsigned int i,key=0,a=0x01;
	TRISA=0x00;
	TRISBbits.RB1=1;
	TRISBbits.RB0=1;
	
	TRISDbits.RD7=0;
	TRISCbits.RC2=0;
while(1)
  {
	if(PORTBbits.RB1==0)
	key=0;
	if(PORTBbits.RB0==0)
	key=1;

	if(key==0){
		a=0x080;
		PORTDbits.RD7=1;
		PORTCbits.RC2=1;
		for (i=0;i<8;i++){
			PORTA=a;
			a = a >> 1;
			msdelay(100);
		}
	}
	
	if(key==1){
		a=0x01;
		PORTDbits.RD7=0;
		PORTCbits.RC2=0;
		for(i=0;i<8;i++){
			PORTA=a;
			a=a << 1;
			msdelay(100);
		}
	}
  }
}