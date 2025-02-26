#include <C:\Program Files (x86)\PICC\Devices\16F628A.h>
#fuses NOWDT,NOMCLR,INTRC_IO 

#use delay(clock=4000000)

void main(void)
{
   while(1)
   {
      output_high(PIN_A1);
      delay_ms(500);
      output_low(PIN_A1);
      delay_ms(500);
      
      output_high(PIN_A2);
      delay_ms(500);
      output_low(PIN_A2);
      delay_ms(500);
      
      output_high(PIN_A3);
      delay_ms(500);
      output_low(PIN_A3);
      delay_ms(500);

   }



   return;
}

