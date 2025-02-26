#include <16F877A.h>
#fuses NOWDT,HS,NOPROTECT
#use delay (clock=16M)
#use rs232 (BAUD=9600,XMIT=PIN_C6,RCV=PIN_C7 )                
                 
int8 rcv_data;                   
 
void main(void)
{                          
   setup_spi(SPI_SLAVE);  
   while(1)                  
   {
      if(spi_data_is_in())
      {
         rcv_data = spi_read();
         spi_write(5);
         printf(" Slave recieved data: %d\r\n",rcv_data);
      }
   } 
}                          
                                   
                                                                  
