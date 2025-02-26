#include <16F876A.h>
#fuses NOWDT,HS                 
#use delay (clock=16000000)
#use rs232 (BAUD=9600,XMIT=PIN_C6,RCV=PIN_C7)       

void main(void)
{
   port_b_pullups(true);            
     
   while(1)                  
   {                     
      //1'st coloumn                  
      output_low(PIN_B4);
      if(!input(PIN_B0))  // A1 = 7      
         printf("keypad: 7\n\r");
      while(!input(PIN_B0)){}     
      
      if(!input(PIN_B1))  // B1 = 4
         printf("keypad: 4\n\r");
      while(!input(PIN_B1)){}        
      
      if(!input(PIN_B2))  // C1 = 1
         printf("keypad: 1\n\r");
      while(!input(PIN_B2)){}     
      
      if(!input(PIN_B3))  // D1 = ON/C   
         printf("keypad: ON/C\n\r");  
      while(!input(PIN_B3)){}
      output_float(PIN_B4);
      //------------------------------------------                            
      //2'nd coloumn                   
      output_low(PIN_B5);             
      if(!input(PIN_B0))  // A2 = 8      
         printf("keypad: 8\n\r"); 
      while(!input(PIN_B0)){}     
      
      if(!input(PIN_B1))  // B2 = 5
         printf("keypad: 5\n\r"); 
      while(!input(PIN_B1)){}        
      
      if(!input(PIN_B2))  // C2 = 2
         printf("keypad: 2\n\r");
      while(!input(PIN_B2)){}     
      
      if(!input(PIN_B3))  // D2 = 0   
         printf("keypad: 0\n\r");  
      while(!input(PIN_B3)){}
      output_float(PIN_B5);
      //------------------------------------------                            
      //3'rd coloumn                   
      output_low(PIN_B6);             
      if(!input(PIN_B0))  // A3 = 9      
         printf("keypad: 9\n\r"); 
      while(!input(PIN_B0)){}     
      
      if(!input(PIN_B1))  // B3 = 6
         printf("keypad: 6\n\r"); 
      while(!input(PIN_B1)){}        
      
      if(!input(PIN_B2))  // C3 = 3
         printf("keypad: 3\n\r");
      while(!input(PIN_B2)){}     
      
      if(!input(PIN_B3))  // D3 = =   
         printf("keypad: =\n\r");  
      while(!input(PIN_B3)){}
      output_float(PIN_B6);
      //------------------------------------------                            
      //4'th coloumn                   
      output_low(PIN_B7);             
      if(!input(PIN_B0))  // A4 = ÷       
         printf("keypad: ÷\n\r"); 
      while(!input(PIN_B0)){}     
      
      if(!input(PIN_B1))  // B4 = ×
         printf("keypad: ×\n\r"); 
      while(!input(PIN_B1)){}        
      
      if(!input(PIN_B2))  // C4 = -
         printf("keypad: -\n\r");
      while(!input(PIN_B2)){}     
      
      if(!input(PIN_B3))  // D4 = +   
         printf("keypad: +\n\r");  
      while(!input(PIN_B3)){}
      output_float(PIN_B7);
                        
   }
}
                                   
                                                                  
