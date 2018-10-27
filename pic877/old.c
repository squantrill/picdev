#define NO_BIT_DEFINES
#include <pic16f877a.h>
#include <stdint.h>


__code uint16_t __at (_CONFIG) __configword = _FOSC_HS & _WDTE_OFF & _LVP_OFF;

#define LED_PORT PORTAbits.RA0
#define LED_TRIS TRISAbits.TRISA0


#define CM0 CMCONbits.CM0
#define CM1 CMCONbits.CM1
#define CM2 CMCONbits.CM2


unsigned char pwmstep;
unsigned char pwmval;
unsigned char debounce;

const unsigned char sine[5] = {52,57,62,66,70,74,77,80,82,84,85,86,86,
				  86,85,83,81,78,75,72,69,65,61,56,52,
				48,44,39,35,31,28,25,22,19,17,15,14,14,
				14,15,16,18,20,23,26,30,34,38,43,48};

void delay(uint16_t iterations)
{
	uint16_t i;
	for (i = 0; i< iterations; i++) {
		__asm nop __endasm;
	}
}
	


void main(void) {
	
	LED_TRIS = 0; // Pin as output
	LED_PORT = 0; // LED off
        CM0 = 1;
	CM1 = 1;
	CM2 = 1;
	
	pwmstep=0;
	debounce=0;



	while (1) {
		LED_PORT = 1;
		delay(10000);
		LED_PORT = 0;
		delay(10000);
	}


}
