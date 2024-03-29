Start PICSimLab. Select the board McLab2. Select PIC16F877A as microcontroller using the micro-controller tab. Configure the microcontroller through your code as follows:
#pragma config FOSC = XT // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off) 

Program the microcontroller so that the most significant 8-bit of the analog to digital conversion is shown on 3 seven-segment displays on the board. Validate its operation by changing the Pot P2. The result shown to the display should blink every 1 second as depicted in Solution_Video_1.
 
![image](https://user-images.githubusercontent.com/48950686/90071670-a833ea80-dcfe-11ea-91f6-d7a5843ab151.png)
Figure 1. Most significant 8-bit of the analog to digital conversion result is shown on 3 displays.

Important Note 1: Set the prescaler for TIMER0 to 1:256 using OPTION_REG register. You are not allowed to use any other prescaler value for this task. Set the clock frequency to 4 MHz.
Important Note 2: You will lose some 2 points for use of each variable or line of code which has no function for the task described above.  Example: There is no need to use PORTC in this task. If you configure TRISC register then you will lose point. 
Important Note 3: This task will be implemented in C programming language. 




Start PICSimLab. Select the board McLab2. Select PIC16F877A as microcontroller using the micro-controller tab. Configure the microcontroller through your code as follows:
#pragma config FOSC = XT // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off) 

Program the microcontroller so that one-digit decimal number on the right-most display is 
-	incremented every 0.2 second if S3 is continuously pressed. 
-	decremented every 0.2 second if S4 is continuously pressed. 
-	not changed if none of the switches is pressed as shown in Solution_Video_2.
The number shown on the display will be 0(zero) when 9 is incremented. Similarly, the number shown will be 9 when 0(zero) is decremented as shown in Solution_Video_2.
 
![image](https://user-images.githubusercontent.com/48950686/90071694-b1bd5280-dcfe-11ea-95c3-3462f83eb045.png)

Figure 2. Use of right-most display to show the number incremented every 0.2 seconds.

Important Note 1: Set the prescaler for TIMER0 to 1:128 using OPTION_REG register. You are not allowed to use any other prescaler value for this task. Set the clock frequency to 4 MHz.
Important Note 2: You will lose 2 points for use of each variable or line of code which has no function for the task described above.  
Important Note 3: This task will be implemented in C programming language. 
Q3 (30 pts) Start PICSimLab. Select the board McLab2. Select PIC16F877A as microcontroller using the micro-controller tab. Configure the microcontroller through your code as follows:
__CONFIG _FOSC_XT & _WDTE_OFF & _PWRTE_OFF & _MCLRE_OFF & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _CP_OFF
Program the microcontroller so that one-digit decimal number is incremented every 0.5 second as shown in Solution_Video_3.
 
![image](https://user-images.githubusercontent.com/48950686/90071708-b71a9d00-dcfe-11ea-89bd-f5989b693e9b.png)

Figure 3. Use of right-most display to show the number incremented or decremented every 0.5 second according to button press.

Important Note 1: Set the prescaler for TIMER0 to 1:128 using OPTION_REG register. You are not allowed to use any other prescaler value for this task. Set the clock frequency to 4 MHz.
Important Note 2: You will lose 2 points for use of each variable or instruction which has no function for the task described above.  
Important Note 3: This task will be implemented in Assembly programming language. No point will be given if the program is written in C programming language.   
Important Note 4: The display should show 0(zero) after incrementing 9(nine) as shown in Solution_Video_3 (Implementation of this feature corresponds to 20 pts). Hint: you may use subtraction to detect that the decimal number is larger than 9 after incrementing. Or, you may use subtraction to understand that the decimal number is equal to 10 after incrementing. You may check the result of the arithmetic operation be checking STATUS,C or STATUS,Z.


Here is my Microprocessors final homework problems and their solutions.
Professor: Mehmet Kocatürk (mkocaturk@medipol.edu.tr)
