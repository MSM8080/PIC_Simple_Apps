#include <16F877A.h>
#fuses NOWDT,HS                 
#use delay (clock=16000000)
#use rs232 (BAUD=9600,XMIT=PIN_C6,RCV=PIN_C7)       

void main(void)
{
   // default setup
   unsigned char ch;         
   
   while(1)                  
   { 
      if(kbhit()) // check uart buffer           
      {                           
         ch = getc();
         putc(ch);              
      }        
      output_toggle(PIN_A0);
   }                          
}
                                   
                                                                  
