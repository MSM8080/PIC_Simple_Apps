#include <16F88.h>
#device ADC = 10
#fuses NOWDT,HS,NOPROTECT
#define LCD_RS_PIN PIN_B0                      
#define LCD_RW_PIN PIN_B1                      
#define LCD_ENABLE_PIN PIN_B2                      
#define LCD_RS_DATA4 PIN_B4                      
#define LCD_RS_DATA5 PIN_B5                      
#define LCD_RS_DATA6 PIN_B6
#define LCD_RS_DATA7 PIN_B7                      
#use delay (clock=16000000)                         
#include <lcd.c>
                  
float d;               
float volt;              

void main(void)                     
{                                                  
   setup_adc(ADC_CLOCK_INTERNAL); 
   setup_adc_ports(ALL_ANALOG);  
   lcd_init();                   
   
   while(1)
   {                     
      // scale 1/2               
      set_adc_channel(1); // AN1
      delay_us(20); // delay s/h
      d = read_adc();
      if(d<1023)            
         {
            volt = d*(5.0/1023.0);
            volt *= 2;
            volt += 0.01;                     
         }
      else                     
      {                                     
         // scale 1/5
         set_adc_channel(2); // AN2          
         delay_us(20); // delay s/h           
         d = read_adc();                        
         if(d<1023)              
         {      
            volt = d*(5.0/1023.0);
            volt *= 5;
            volt += 0.01;
         }                  
         else
         {
            // scale 1/9           
            set_adc_channel(3); // AN3
            delay_us(20); // delay s/h
            d = read_adc();                 
            volt = d*(5.0/1023.0); 
            volt *= 9;
            volt += 0.01;
         }
      } 
      
      lcd_putc('\f');  // clear lcd
      lcd_gotoxy(1,1); // go to upper left of lcd                  
      printf(lcd_putc,"%.2f volt",volt);           
                                   
      delay_ms(1000);           
   }                                                                                       
}                           

                     
