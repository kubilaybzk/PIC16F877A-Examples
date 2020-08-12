#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>

void display (unsigned char number, unsigned char disp_num);
void convert_num_to_digits (unsigned int number, unsigned char *hundreds, unsigned char *tens, unsigned char *ones);
void toggle_led (void);



unsigned char timer_divider;
unsigned char display_on;

void interrupt isr_vector (void)
{
    INTCONbits.GIE = 0;
    if (INTCONbits.T0IF)
    {
        INTCONbits.T0IF = 0;
        TMR0 = 178;
        timer_divider--;
        if (timer_divider == 0)
        {
            if(display_on)          //if it is one show it or if it is zero not show it 
                display_on=0;      //it means that turning on and off.
            else
                display_on=1;
            timer_divider = 100;
        }
    }
    return;
}







void main(void) 
{
    unsigned int adc_result;  //unsigned elements
    unsigned char  hndrd, ten, one;
    
    TRISD = 0;  // PORTD is output
    TRISBbits.TRISB4 = 0;   // RB4 is output to enable/disable 3rd display
    TRISBbits.TRISB5 = 0;   // RB5 is output to enable/disable 2nd display
    TRISBbits.TRISB6 = 0;   // RB6 is output to enable/disable 1st display
    ADCON0 &= 0b11000111;  //select analog input channel AN1(RA1). ADCON0,3:5 are cleared
    ADCON0 |= 0b00001000;  //select analog input channel AN1(RA1). ADCON0,3 is set 
    ADCON0bits.ADON = 1;   //enable ADC 
    ADCON1 &= 0b1011111;  //FOSC/8 according to 4MHz crystal and Table 11-1 in datasheet)
    OPTION_REGbits.T0CS = 0;//Timer 0 Clock  Source ; 0 yaparak osiloscopa ba?l?yoruz.
    OPTION_REGbits.T0SE = 0;  //Increment on low-to-high transition
    OPTION_REGbits.PSA = 0; //Prescaler is assigned to the Timer0 module
    OPTION_REG |= 0b00000110; //prescaler belirtmek
    OPTION_REG &= 0b11111110;
    TMR0 = 178;    //Tint = (1us)*256*156 =39936 us ~ 40 ms
    timer_divider = 100;//setted timer_divider 100
    INTCONbits.T0IE = 1;//BSF INTCON,TMR0IE Disaable 
    INTCONbits.GIE = 1; //BSF INTCON,GIE   Disaable all Interrupt
    
    
    
    
    
    ADCON1bits.ADFM = 0;   // ADC result LEFT justified 1( bitL  8 bit h)
    ADCON1 |= 0b00000100;  // 0100 kulland?k cause of select input
  
    
    while (1)
    {
        ADCON0bits.GO = 1;
        while (ADCON0bits.GO) {}  //  cheack analog to digital conversion is complete or  it is not complete.
        adc_result = 0;           // ADC is completed
        adc_result |= ADRESH;   // We use AdresH values. 00000000-11111111
     //   adc_result |= ADRESL;  control it .
        
        
        if(display_on){   //display on or off
            convert_num_to_digits (adc_result, &hndrd, &ten, &one);  //concert to numbers.     
        display(hndrd,1);   //Display third led
        display(ten,2);     //Display second led
        display(one,3);     //Display first led
        }
        
               
      
    }
    return;
}
void display (unsigned char number, unsigned char disp_num)
{    
    switch (disp_num)
    {
        case 0:
            PORTBbits.RB4 = 0;  //Enable or disable bits 
            PORTBbits.RB5 = 0;  //Enable or disable bits
            PORTBbits.RB6 = 0;  //Enable or disable bits
           
            break;
        case 1:
            PORTBbits.RB4 = 0;  //Enable or disable bits
            PORTBbits.RB5 = 0;  //Enable or disable bits
            PORTBbits.RB6 = 1;  //Enable or disable bits
            break;
        case 2:
            PORTBbits.RB4 = 0;  //Enable or disable bits
            PORTBbits.RB5 = 1;  //Enable or disable bits
            PORTBbits.RB6 = 0;  //Enable or disable bits
            
            break;
        case 3:
            PORTBbits.RB4 = 1;  //Enable or disable bits
            PORTBbits.RB5 = 0;  //Enable or disable bits
            PORTBbits.RB6 = 0;  //Enable or disable bits
          
            break;
        default:
            break;
    }   
    
    switch (number)
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
            PORTD = 0b01100110; ////number4
            break;
        case 5:
            PORTD = 0b01101101; //number5
            break;
        case 6:
            PORTD = 0b01011111; //number6
            break;
        case 7:
            PORTD = 0b00000111; //number7
            break;
        case 8:
            PORTD = 0b01111111; //number8
            break;
        case 9:
            PORTD = 0b01101111;//number9
            break;
        default:
            break;
    }
    _delay(1000);   // execute 1000 NOPs to increase the brightness of the 7segment displays
    PORTBbits.RB4 = 0;
    PORTBbits.RB5 = 0;
    PORTBbits.RB6 = 0;
       
}


void convert_num_to_digits (unsigned int number, unsigned char *hundreds, unsigned char *tens, unsigned char *ones)
{
    
    *hundreds = 0;  
    *tens = 0;
    *ones = 0;
    
    while (number>99)  // if its is bigger increas it one times.
    {
        number-= 100;  // number = number - 1000
        (*hundreds)++;
    } 
    while (number>9)// if its is bigger increas it one times.
    {
        number-= 10;  // number = number - 1000
        (*tens)++;
    }
    while (number>0)// if its is bigger increas it one times.
    {
        number--;  // number = number - 1000
        (*ones)++;
    }       

}