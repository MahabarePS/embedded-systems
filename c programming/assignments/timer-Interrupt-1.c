//1 Wap to toggle LED connected at P1.0 after every 10ms
#include<reg51.h>
sbit led = P1^0;
int main(){
	TMOD=0x01; // timer 0 mode 1
	TH0=0xEE;
	TL0=0x00;
	IE=0x82;
	return 0;
a}

void timer0mode1() interrupt 1{
	led=~led;
}