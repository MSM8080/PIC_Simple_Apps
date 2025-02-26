#include <16F877A.h>
#fuses NOWDT,HS                 
#use delay (clock=16000000)
                     
void main(void)
{
   // default setup
   unsigned char status = 'n';
   output_high(PIN_B1);         
   
   while(1)                  
   { 
      if(input(PIN_B2)==1 && status == 'n') // toggle it off
      {                       
         output_low(PIN_B1);
         status = 'f';
      }                                                                                                         
      else if(input(PIN_B2)==1 && status == 'f') // toggle it on
      {                       
         output_high(PIN_B1);
         status = 'n';            
      }
   
   }

}
                                   
                                                                  
