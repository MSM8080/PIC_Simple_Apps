#include <16F876A.h>
#fuses NOWDT,HS,NOPROTECT                 
#use delay (clock=16000000) 

void main(void)            
{        
   long int number = 5801;
   int8 n1 = number%10;
   number /= 10; 
   int8 n2 = number%10;
   number /= 10;
   int8 n3 = number%10;
   number /= 10;
   int8 n4 = number%10;
                       
   while(1)
   {  
    
      output_high(PIN_C3); 
      output_b(n1);
      delay_ms(10);
      output_low(PIN_C3); 
      
      output_high(PIN_C2);             
      output_b(n2);
      delay_ms(10);
      output_low(PIN_C2);
       
      output_high(PIN_C1); 
      output_b(n3);
      delay_ms(10);
      output_low(PIN_C1);
      
                  
      output_high(PIN_C0); 
      output_b(n4);
      delay_ms(10);
      output_low(PIN_C0);
                        
   }                          
}     
                                   
                                                                  
