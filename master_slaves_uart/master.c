#include <16F877A.h>
#fuses NOWDT,HS                 
#use delay (clock=4000000) 

void main(void) 
{               
   // default setup
    unsigned int8 ch1;                       
    unsigned int8 ch2;
    unsigned int8 ch3;
   
   while(1)                        
   {                                                    
      #use rs232 (BAUD=9600,XMIT=PIN_D1,RCV=PIN_D0) // slave 1
      output_high(PIN_B0); 
      putc('1');       
      ch1 = getc();                          
      output_low(PIN_B0);
      
      #use rs232 (BAUD=9600,XMIT=PIN_D3,RCV=PIN_D2) // slave 2
      output_high(PIN_B1);
      putc('1');    
      ch2 = getc();              
      output_low(PIN_B1);
                                            
      #use rs232 (BAUD=9600,XMIT=PIN_D5,RCV=PIN_D4) // slave 3
      output_high(PIN_B2);            
      putc('1');                          
      ch3 = getc();           
      output_low(PIN_B2);
                                                           
      #use rs232 (BAUD=9600,XMIT=PIN_C6,RCV=PIN_C7) // virtual terminal      
      printf("s1(%c)----",ch1);      
      printf("s2(%c)----",ch2);
      printf("s3(%c)----",ch3);
      putc('\n');
      putc('\r');
   }
}                                                 
                                    
                                                                  
