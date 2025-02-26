#include <16F84a.h>
#fuses NOWDT,HS,NOPROTECT                 
#use delay (clock=8000000)                
// iclk= 4us
// ovf each 0.2s 

int8 ticks=0;            
int8 second=0;
int8 minute=0;
int8 hour=0;          
                        

                    
void calc_time(void)                        
{  
   if(ticks == 18)              
   {
      ticks = 0;      
      if(second==59)                   
      {           
         second=0; 
         if(minute==59)
         { 
            minute=0;                   
            if(hour==23)
               hour=0;
            else
               hour +=1;
         }  
         else         
            minute +=1;
      } 
      else       
         second +=1;
   }                                         
   else
      ticks +=1;
}          
void display(void)
{
      int n=0;                      
      
      // 1'st seconds
      n = second;
      output_high(PIN_B2);
      output_a(n%10);    
      delay_ms(10);
      output_low(PIN_B2);
                                        
      // 2'nd seconds                                                               
      n /= 10;       
      output_high(PIN_B3);
      output_a(n%10);          
      delay_ms(10);
      output_low(PIN_B3);             
               
      // 1'st minutes
      n = minute; 
      output_high(PIN_B4);              
      output_a(n%10);       
      delay_ms(10);
      output_low(PIN_B4);
      
      // 2'nd minutes
      n /= 10;
      output_high(PIN_B5);
      output_a(n%10);       
      delay_ms(10);     
      output_low(PIN_B5);
      
      // 1'st hours                                   
      n = hour;
      output_high(PIN_B6);
      output_a(n%10);       
      delay_ms(10);      
      output_low(PIN_B6);               
      
      // 2'nd hours
      n /= 10;
      output_high(PIN_B7);
      output_a(n%10);       
      delay_ms(10);      
      output_low(PIN_B7);
}                                
                                          
void main(void)                    
{                                      
   output_b(0);                     
   while(1)
   {
    
      display();            
      calc_time();     
   }                          
}                           

                                  
                                  
/*                                             
 long int number = 5801;
   int8 n1 = number%10;
   number /= 10; 
   int8 n2 = number%10;
   number /= 10;        
   int8 n3 = number%10;
   number /= 10;                          
   int8 n4 = number%10;
*/    

/*
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
*/              

/*
 setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
   set_timer1(15536);                 
   enable_interrupts(INT_TIMER1);          
   enable_interrupts(GLOBAL);            
*/  


/*
#INT_TIMER1       // each 1s            
void time(void)
{                                                  
   if(counter==5)          
   {                         
      output_b(8);                        
      output_toggle(PIN_C5);             
      counter = 1;                           
   }
   else
   {
      counter +=1;  
   }               
}                               
*/                
                
