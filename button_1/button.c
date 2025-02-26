#include <16f628a.h>
#fuses INTRC_IO, NOWDT,                                                    
#use delay(clock=4000000)
 
void main(void)
{
   while(1)
   {             
      if(input(PIN_B4))
         output_high(PIN_B5);
      else
         output_low(PIN_B5);
   }              
   return;
}
                                                                                      
