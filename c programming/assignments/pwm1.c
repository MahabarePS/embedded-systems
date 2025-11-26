//WAP to generate PWM freq of 2KHz with 25% duty cycle using any one timer, on P1.0
//Using timer0 in mode 1
#include<reg51.h>
sbit pwm = P1^0;
void timer0mode1();
int main(){
	TMOD=0x01;
	TR0=1;
	IE=0x82;
	return 0;
}
void timer0mode1() interrupt 1
{
	if(pwm ==1){
		pwm = 0;
		TR0 = 0;	
		TH0=0xFE;
		TL0=0xA7;
		TR0=1;
	}else{
		pwm = 1;
		TR0=0;	  
		TH0=0xFF;
		TL0=0xA8;
		TR0=1;
	}

	
}