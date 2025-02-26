#include <16F88.h>
#device ADC = 10
#fuses NOWDT,HS,NOPROTECT
#use delay (clock=16000000)   
#use rs232(baud=9600,UART1)
                  
float d;  
float vin;
float light_res;          
float light;
                             
void main(void)                     
{                                      
   setup_adc(ADC_CLOCK_INTERNAL); 
   setup_adc_ports(ALL_ANALOG);  
   set_adc_channel(0);                                                                                                     
             
   while(1)                   
   {                           
      delay_us(20); // delay s/h                                                                   
      d = read_adc();   
      vin = d*5.0/1023.0;              
      light_res = vin*1000.0/(5.0-vin);
      light = -268.7903226*vin+1341.36371;      
      printf("%.2f lux | %.2f lux \n\r",light,vin);  
                                            
      delay_ms(1000);           
   }                                                                                       
}                           

                     
