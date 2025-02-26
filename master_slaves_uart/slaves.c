#include <16F877A.h>
#fuses NOWDT,HS                 
#use delay (clock=4000000)
#use rs232 (BAUD=9600,UART1,BITS=8,PARITY=N) // slave

#int_rda // int rda need uart hardware unit(xmit,rcv) 
void isa(void)           
{
   if(input_state(PIN_C0)==1)                
      putc('1');            
   else if(input_state(PIN_C0)==0)
      putc('0');       
}      

void main(void)                      
{    
   enable_interrupts(GLOBAL); // enable all interrupts
   enable_interrupts(int_rda); // enable uart interrupt   
   while(1)                        
   {}
}                                  
                                   
                                                                  
