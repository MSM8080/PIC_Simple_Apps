#include <16F877A.h>
#fuses NOWDT,HS,NOPROTECT
#use delay (clock=16M)
#use rs232 (BAUD=9600,XMIT=PIN_C6,RCV=PIN_C7 )                

int8 rcv_data;                   
 
void main(void)
{                          
   setup_spi(SPI_MASTER);  
   output_low(PIN_B0);  
   while(1)                  
   {
      spi_write(1); 
      rcv_data = spi_read();
      delay_ms(500);
      printf("Master recieved data: %d\r\n",rcv_data);
   }
}                          
                                   
                                                                  
