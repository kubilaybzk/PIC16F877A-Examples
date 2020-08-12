/*
 * File:   LastLab.c
 * Author: Bzk
 *
 * Created on 20 May?s 2020 Çar?amba, 23:35
 */


// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>


unsigned char timer_divider;
int temp=-1;
void toggle_led (void);
void press (void);
void not_press (void);



void interrupt isr_vector (void)
{
    
      INTCONbits.GIE = 0;
      if(PORTBbits.RB2!=1 ||PORTBbits.RB3!=1 || PORTBbits.RB4!=1){ //here we are check it press or not.
          if (INTCONbits.T0IF)
    {
        INTCONbits.T0IF = 0;  //settet T0?f 0
        TMR0 = 178;
        timer_divider--;
        if (timer_divider == 0)
        {
            
            
               if(PORTBbits.RB3==1)  // TO incremented it 
            {
               
                press(); // ?f it is okey update number.
            }
            else if(PORTBbits.RB4==1)  // TO decremented it. 
            {
                
                not_press();  // ?f it is okey update number.
                
            
            }
           
           timer_divider = 20;  // we set TMRO 178 this means that 1 sn.  if we diviver 20 ms this means tha 0,2
           
            
        }
        
        
    
            
            
    
    return;
}

      }
}
void main(void) 
{
    TRISD = 0;
    TRISBbits.TRISB4 = 0;  //output
    OPTION_REGbits.T0CS = 0;//Timer 0 Clock  Source ; 0 yaparak osiloscopa ba?l?yoruz.
    OPTION_REGbits.T0SE = 0;  //Increment on low-to-high transition
    OPTION_REGbits.PSA = 0; //Prescaler is assigned to the Timer0 module
    OPTION_REG |= 0b00000110; //setted option reg 
    OPTION_REG &= 0b11111110; //setted option reg 
    TMR0 = 178;    //Tint = (1us)*256*156 =39936 us ~ 40 ms
    timer_divider = 20;
    INTCONbits.T0IE = 1;//BSF INTCON,TMR0IE Disaable 
    INTCONbits.GIE = 1; //BSF INTCON,GIE   Disaable all Interrupt
    
        while (1)
    {
       switch (temp)  // To show numbers.
    {
        case 0:
            PORTD = 0b00111111;  //number0
            break;
        case 1:
            PORTD = 0b00000110; //number1
            break;
        case 2:
            PORTD = 0b01011011; //number2
            break;
        case 3:
            PORTD = 0b01001111; //number3
            break;
        case 4:
            PORTD = 0b01100110; //number4
            break;
        case 5:
            PORTD = 0b01101101;//number5
            break;
        case 6:
            PORTD = 0b01011111;//number6
            break;
        case 7:
            PORTD = 0b00000111;//number7
            break;
        case 8:
            PORTD = 0b01111111;//number8
            break;
        case 9:
            PORTD = 0b01101111;//number9
            break;
        default:
            break;
    }
       
    }
    
    
    return;
}



void press (void){
    
   if(temp>=9){  // LOOP'U TEKRARA SOKMAK. 
           temp=-1;
       }
   if (temp<=10)     //Tek mi çift mi kontrol ediyoruz.
       
    {
       
        PORTBbits.RB4 = 1;   //display it 
    }
          
    temp++;  //increas it.
    
}




void not_press (void){
    
    if(temp==0){  // LOOP'U TEKRARA SOKMAK. 
           temp=10;
       }
   if (temp<=10)     // for display it 
       
    {
        
        PORTBbits.RB4 = 1;   //display it 
    }
          
    temp--; //decreas it.
    
}





 
   

  