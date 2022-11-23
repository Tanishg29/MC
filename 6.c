#include <p18f4550>
#include "vector_relocate"
void timer_irs(void);
extern void _startup(void);
#pragma code RESET_INTERRUPT_VECTOR=0x1000
void reset(void){
	_asm
	goto _startup
		_endasm
}
#pragma code

#pragma code HIGH_INTERRUPT_VECTOR=0x1008
void high_IRS(void)
{
	_asm
	goto timer_irs
		_endasm
}
#pragma code
#pragma interrupt timer_irs
void timer_irs(void)
{
	PORTDbits.RD0= ~PORTDbits.RD0;
	TMR0H=0x6D;
	TMR0L=0X75;
}
void main()
{
	TRISDbits.RD0=0;
	PORTDbits.RD0=0;
	T0CON=0x03;
	TMR0H=0x0D;
	TMR0L=0x75;
	INTCONbits.GIE=1;
	INTCONbits.TMR0ON=1
	while(1);
}