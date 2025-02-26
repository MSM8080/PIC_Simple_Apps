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
float heat;          

void main(void)                     
{                                      
   setup_adc(ADC_CLOCK_INTERNAL); 
   setup_adc_ports(ALL_ANALOG);  
   set_adc_channel(0);                                                                                      
   lcd_init();                   
   
   while(1)                   
   {                     
      delay_us(20); // delay s/h
      d = read_adc();
      //heat = d/1.0;                   
      heat = (d*500)/1023;                                                           
      lcd_putc('\f'); // clear lcd                                                                                 
      lcd_gotoxy(1,1);                              
      printf(lcd_putc,"%.2f C",heat);  
                                   
      delay_ms(1000);           
   }                                                                                       
}                           

                     
