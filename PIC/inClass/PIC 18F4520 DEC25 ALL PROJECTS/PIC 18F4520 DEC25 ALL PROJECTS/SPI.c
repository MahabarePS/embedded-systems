#include"SPI.h"
#define SCK RC3 
#define SDI RC4 
#define SD0 RC5 
#define SS RC6

#define SCK_dir TRISC3
#define SDI_dir TRISC4
#define SDO_dir TRISC5
#define SS_dir TRISC6

#define WREN 0x06 
#define WRDI 0x04 
#define WRITE 0x02
#define READ 0x03
#define RDSR 0x05 

char data[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

int address[16] = {0x0000,0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0009,0x000A,0x000B,0x000C,0x000D,0x000E,0x000F};

void SPI_init(void);
void SPI_write(char);
char SPI_read(char);
void EEPROM_write(int address,char data);
char EEPROM_read(int address);
char EEPROM_status(void);
char EEPROM_busy(void);


void main(void)
{
unsigned char c;
unsigned int i=0;
ADCON1=0x0f;
lcdinit();
SPI_init();


for( i = 0 ; i < 16 ; i++ )
EEPROM_write(address[i],data[i]);

//
for( i = 0 ; i < 16 ; i++ )
{
    c = EEPROM_read(address[i]);
    LCD_data(c);
    __delay_ms(1000);

}
while(1);

}


void SPI_init(void)
{
SCK_dir = 0;
SDI_dir = 1;
SDO_dir = 0;
SS_dir = 0;
SSPSTAT = 0x80;
SSPCON1 = 0x30;

}

void SPI_write(char data)
{
SSPBUF = data;
while(BF == 0);
}

char SPI_read(char dummy)
{
SSPBUF = dummy; 
while(BF == 0);

return SSPBUF;
}

void EEPROM_write(int address,char data)
{
while( EEPROM_busy() == 1 );


SS = 0;
SPI_write(WREN);
SS = 1; 

SS = 0;
SPI_write(WRITE);
SPI_write(address>>8);
SPI_write(address & 0x00ff);
SPI_write(data);
SS = 1;
}

char EEPROM_read(int address)
{
while( EEPROM_busy() == 1 ); 

SS = 0;
SPI_write(READ);
SPI_write(address>>8); //Higher Byte
SPI_write(address & 0x00ff); //Lower Byte
char data = SPI_read(0);
SS = 1;

return data;
}

char EEPROM_status(void)
{
SS = 0;
SPI_write(RDSR); 
char status = SPI_read(0) ; 
SS = 1;

return status;
}

char EEPROM_busy(void)
{
char busy = EEPROM_status();

return (busy & 0x01); 
}