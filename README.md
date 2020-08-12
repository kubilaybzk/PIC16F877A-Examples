Start PICSimLab. Select the board McLab2. Select PIC16F877A as
microcontroller using the micro-controller tab. Configure the microcontroller through your
code as follows:
#pragma config FOSC = XT // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial
Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for
programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data
EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write
protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code
protection off)
Program the microcontroller so that the most significant 8-bit of the analog to digital
conversion is shown on 3 seven-segment displays on the board. Validate its operation by
changing the Pot P2. The result shown to the display should blink every 1 second as depicted
in Solution_Video_1.

Figure 1. Most significant 8-bit of the analog to digital conversion result is shown on 3 displays.

Important Note 1: Set the prescaler for TIMER0 to 1:256 using OPTION_REG register. You
are not allowed to use any other prescaler value for this task. Set the clock frequency to 4
MHz.
Important Note 2: You will lose some 2 points for use of each variable or line of code which
has no function for the task described above. Example: There is no need to use PORTC in
this task. If you configure TRISC register then you will lose point.
Important Note 3: This task will be implemented in C programming language.

Sample oral exam questions related to Q1:
1- What is the resolution of the analog to digital converter of PIC16F877A?
2- Explain how you configured timer.
3- Why do you use AN1 of the microcontroller instead of AN0?
4- What is the purpose of the use of the transistors connected to the 7-segment displays (referring
to the schematic of the board)?

Q2 (30 pts) Start PICSimLab. Select the board McLab2. Select PIC16F877A as
microcontroller using the micro-controller tab. Configure the microcontroller through your
code as follows:
#pragma config FOSC = XT // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial
Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for
programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data
EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write
protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code
protection off)
Program the microcontroller so that one-digit decimal number on the right-most display is
- incremented every 0.2 second if S3 is continuously pressed.
- decremented every 0.2 second if S4 is continuously pressed.
- not changed if none of the switches is pressed as shown in Solution_Video_2.
The number shown on the display will be 0(zero) when 9 is incremented. Similarly, the
number shown will be 9 when 0(zero) is decremented as shown in Solution_Video_2.

Figure 2. Use of right-most display to show the number incremented every 0.2 seconds.

Important Note 1: Set the prescaler for TIMER0 to 1:128 using OPTION_REG register. You
are not allowed to use any other prescaler value for this task. Set the clock frequency to 4
MHz.
Important Note 2: You will lose 2 points for use of each variable or line of code which has
no function for the task described above.

Important Note 3: This task will be implemented in C programming language.
Q3 (30 pts) Start PICSimLab. Select the board McLab2. Select PIC16F877A as
microcontroller using the micro-controller tab. Configure the microcontroller through your
code as follows:
__CONFIG _FOSC_XT &amp; _WDTE_OFF &amp; _PWRTE_OFF &amp; _MCLRE_OFF &amp; _BOREN_OFF &amp;
_LVP_OFF &amp; _CPD_OFF &amp; _CP_OFF
Program the microcontroller so that one-digit decimal number is incremented every 0.5
second as shown in Solution_Video_3.

Figure 3. Use of right-most display to show the number incremented or decremented every 0.5 second
according to button press.

Important Note 1: Set the prescaler for TIMER0 to 1:128 using OPTION_REG register. You
are not allowed to use any other prescaler value for this task. Set the clock frequency to 4
MHz.
Important Note 2: You will lose 2 points for use of each variable or instruction which has no
function for the task described above.
Important Note 3: This task will be implemented in Assembly programming language. No
point will be given if the program is written in C programming language.
Important Note 4: The display should show 0(zero) after incrementing 9(nine) as shown in
Solution_Video_3 (Implementation of this feature corresponds to 20 pts). Hint: you may use
subtraction to detect that the decimal number is larger than 9 after incrementing. Or, you
may use subtraction to understand that the decimal number is equal to 10 after incrementing.
You may check the result of the arithmetic operation be checking STATUS,C or STATUS,Z.

Here  is my Microprocessors final homeworks and my solutions.  
The Professor : Mehmet Kocaturk mkocaturk@medipol.edu.tr