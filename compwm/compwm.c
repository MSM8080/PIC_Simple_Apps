#include <16F876A.h>
#fuses NOWDT,HS,NOPROTECT,NOLVP                 
#use delay (clock=20000000)        
// want T(pulse width) = 10ms            
// have internal clk = 0.2us
 
                                                               
// T(pulse width) = (period+1)*4*(16*internal clk)*prescale     
// duty cycle(=1) = fall value / [ 4 * (period+1) ]                            
                                                      
void main(void)                       
{                          
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_4);
                                                            
   while(1)                  
   {                                                                                 
      setup_ccp1(CCP_COMPARE_SET_ON_MATCH);
      CCP_1=0;       // rise value
      set_timer1(0);       
      delay_ms(10);   // delay high pulse        
      setup_ccp1(CCP_COMPARE_CLR_ON_MATCH);
      CCP_1=780.25;       // fall value                          
      //CCP_1=25000;       // fall value                         
      set_timer1(0);                                             
      delay_ms(10);   // delay low pulse                      
   }
}                                        
                                   
                                                                  
