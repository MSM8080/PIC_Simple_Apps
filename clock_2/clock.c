#include <16F876A.h>
#fuses NOWDT,HS,NOPROTECT,NOLVP                 
#use delay (clock=20000000)
#use rs232 (baud=9600,xmit=PIN_C6,rcv=PIN_C7)
// internal clk: 0.2 us     
unsigned long T,F;

#int_ccp2
void isr()                              
{                                                         
   T = (((CCP_2-CCP_1)+1)*0.2*1*2)/1000;                          
   F = (1000/T);       
   printf("period: %lu ms <<<<<<<<>>>>>>>>> freq: %lu Hz\n\r",T,F);  
}
                             
                                                    
void main(void)          
{                                    
   setup_ccp1(CCP_CAPTURE_RE);
   setup_ccp2(CCP_CAPTURE_FE);                  
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);   
   set_timer1(0);
   enable_interrupts(INT_CCP2);
   enable_interrupts(GLOBAL);                 
   
   while(1)                  
   {
   }
}
                                   
                                                                  
