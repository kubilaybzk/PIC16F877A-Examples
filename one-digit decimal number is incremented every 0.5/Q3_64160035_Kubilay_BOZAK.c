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
int temp=-1;  //setted temp 0 because of started from 0.
void toggle_led (void);

void interrupt isr_vector (void)
{
    INTCONbits.GIE = 0;
    if (INTCONbits.T0IF)
    {
        INTCONbits.T0IF = 0;
        TMR0 = 178;
        timer_divider--;     //decreasing timer _diveder
        if (timer_divider == 0)
        {
            toggle_led (); //called tooglle_led function.
            timer_divider = 50; //time diveder sette 50 .
        }
    }
    return;
}


void main(void) 
{
    TRISD = 0; //set all tr?sd 0.
    TRISBbits.TRISB4 = 0;  //output
    ADCON0 &= 0b11000111;
    ADCON0 |= 0b00001000;
    ADCON0bits.ADON = 1 ; // A/D converter module is powered up
    ADCON1 &= 0b10111111;
    ADCON1bits.ADFM = 1;  //Right justified.
    OPTION_REGbits.T0CS = 0;//Timer 0 Clock  Source ; 0 yaparak osiloscopa ba?l?yoruz.
    OPTION_REGbits.T0SE = 0;  //Increment on low-to-high transition
    OPTION_REGbits.PSA = 0; //Prescaler is assigned to the Timer0 module
    OPTION_REG |= 0b00000110; //prescaler belirtmek
    OPTION_REG &= 0b11111110;
    TMR0 = 178;    //Tint = (1us)*256*156 =39936 us ~ 1sn
    timer_divider = 50;
    INTCONbits.T0IE = 1;//BSF INTCON,TMR0IE Disaable 
    INTCONbits.GIE = 1; //BSF INTCON,GIE   Disaable all Interrupt
    
        while (1)
    {
       switch (temp)
    {
        case 0:
            PORTD = 0b00111111;  //Number0
            break;
        case 1:
            PORTD = 0b00000110;  //Number1
            break;
        case 2:
            PORTD = 0b01011011;  //Number2
            break; 
        case 3:
            PORTD = 0b01001111; //Number3
            break;
        case 4:
            PORTD = 0b01100110; //Number4
            break;
        case 5:
            PORTD = 0b01101101; //Number5
            break;
        case 6:
            PORTD = 0b01011111; //Number6
            break;
        case 7:
            PORTD = 0b00000111;  //Number7
            break;
        case 8:
            PORTD = 0b01111111;  //Number8
            break;
        case 9:
            PORTD = 0b01101111;  //Number9
            break;
        default:
            break;
    }
       
    }
    
    
    return;
}


void toggle_led (void)
{
    if(temp>=9){  // LOOP'U TEKRARA SOKMAK. 
           temp=-1;
       }
   if (temp%2==0)     //Tek mi çift mi kontrol ediyoruz.
       
    {
        PORTBbits.RB4= 1;   // E?er tek iste  sol taraf.
       
    }
    else
    {
      
        PORTBbits.RB4 = 1; //here ? used this type because ? dont want  to display every time.
        
    }        
    temp++;    //increasing temp values.    
}