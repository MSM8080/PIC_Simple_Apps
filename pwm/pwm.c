#include <16F876A.h>
#fuses NOWDT,HS,NOPROTECT,NOLVP                 
#use delay (clock=16000000)
// want T = 100us
// have internal clk = 0.25us
// Tosc = external clk
  

// T(pwm period) = (PR2+1)*4*Tosc*prescale
// duty_cycle = v/ (4*(PR2+1))
 
void main(void)
{                          
   setup_ccp1(CCP_PWM);               
   setup_timer_2(T2_DIV_BY_4,99,1);      
   long v=200;
   set_pwm1_duty(v);
   while(1)                  
   {                                        
   }
}                          
                                   
                                                                  
