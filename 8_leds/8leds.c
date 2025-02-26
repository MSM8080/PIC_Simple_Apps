#include <16F877A.h>                                                                                    
#fuses NOWDT,HS                 
#use delay (clock=16000000)
#define button PIN_A0
#define test_led PIN_A1                        
                    
void main(void)      
{             
   // setup
   unsigned int8 sequence = 1;         
   unsigned int1 status = 0;  
   output_b(0);        
   output_high(test_led);         
    
   while(1)                  
   {                                        
      while(status)
      {                  
         if(input(button)==1 && status == 1) // toggle sequence off
         {                       
            status=0;        
            sequence = 0; 
            output_b(sequence);
            output_low(test_led);       
            break;            
         }
         if(sequence==256)  
            sequence = 1;
                            
         output_b(sequence);         
         sequence*=2;  
         delay_ms(100);     
      }
      if(input(button)==1 && status == 0) // toggle sequence on
         {
            status=1;
            sequence = 1;
            output_b(sequence);
            output_high(test_led);  
         }
       
   }                          

}
                                   
                                                                  
