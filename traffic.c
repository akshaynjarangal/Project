#include<htc.h>
#include<pic.h>
#define _XTAL_FREQ   20000000  
#define BAUDRATE 9600  //bps
#define stat_led RD0
#define data_led RD1
#define j1_r RB7
#define j1_y RB6
#define j1_g RB5
#define j2_r RB4
#define j2_y RB3
#define j2_g RB2
#define j3_r RB1
#define j3_y RB0
#define j3_g RD7
#define j4_r RD6
#define j4_y RD5
#define j4_g RD4
#define buzer RC3
#define button1 RC5
#define button2 RC1
#define button3 RC2
#define button4 RC0

#define uc unsigned char

unsigned char rec_data,p,value[12];
unsigned int i,j,count1,r,cnt1,cnt2;
bit flag1,flag2,flag3,flag4,button1_flag,button2_flag,button3_flag,button4_flag,jn1_flag,jn2_flag,jn3_flag,jn4_flag,receive_flag;

void delay(unsigned int k);
void delay1() 
{ for(r=0;r<=2000;r++);
}

void delay(unsigned int k) 
{ for(i=0;i<=k;i++)
	{
	 for(j=0;j<=1000;j++);
}
}


__CONFIG(FOSC_HS&WDTE_OFF&PWRTE_ON&CP_OFF&BOREN_ON&LVP_OFF&CPD_OFF&
DEBUG_OFF);

void uart_init(void)
{
    TRISC6 = 1;   					// TX Pin
	TRISC7 = 1;   					// RX Pin
	SPBRG = ((_XTAL_FREQ/16)/BAUDRATE) - 1;
	BRGH  = 1;                   	// Fast baudrate
	SYNC  = 0;						// Asynchronous
	SPEN  = 1;						// Enable serial port pins
	CREN  = 1;						// Enable reception

	TXIE  = 0;						// Disable tx interrupts
	RCIE  = 1;						// Enable rx interrupts
	TX9   = 0;						// 8-bit transmission
	RX9   = 0;						// 8-bit reception
	TXEN  = 0;						// Reset transmitter
	TXEN  = 1;	
}

void InitTimer0(void)
{
	// Timer0 is 8bit timer, select T0CS and PSA to be zero
	OPTION_REG &= 0xC0;     // Make Prescalar 1:2
	
	T0IE = 1;				// Enable Timer0 interrupt
	GIE = 1;				// Enable global interrupts
}
void interrupt ISR(void)
{
	if(T0IF)  //If Timer0 Interrupt
	{
	
        
     count1++;  
    if(count1>3000) 
   { count1=0;
     stat_led=~stat_led;


   }  
     
		T0IF = 0;   // Clear the interrupt
	}
    	if(RCIF)  // If UART Rx Interrupt
	{
		if(OERR) // If over run error, then reset the receiver
		{
			CREN = 0;
			CREN = 1;
		}

		rec_data=RCREG;	// Echo back received char

      if(rec_data!='\0')
	    {
           
	      if(receive_flag==0)
			{
	           value[p]=rec_data;

               if(++p>11)
		
		       {
				p=0;
				buzer=1;
				data_led=0;
				delay(300);
				buzer=0;
				if(value[8]=='7'&&value[9]=='1'&&value[10]=='5'&&value[11]=='4')
				{
					flag1=1;
				}
		       }
}

		       
		}

  



	 
		 
	
	}

}
void emergency1()
 {
 j1_g=1;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=0;
 j2_r=1;
 j3_r=1;
 j4_r=1;
 cnt2=0;
 while(cnt2<1000)
 {
  delay1();
  cnt2++;
 }
 cnt2=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=1;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=0;
 j2_r=1;
 j3_r=1;
 j4_r=1;
 while(cnt2<500)
 {
  delay1();
  cnt2++;

 }
 cnt2=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=1;
 j3_r=1;
 j4_r=1;
 while(cnt2<400)
 {
  delay1();
  cnt2++;

 }
 cnt2=0;
}
void emergency2()
 {
 j1_g=0;
 j2_g=1;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=0;
 j3_r=1;
 j4_r=1;
 cnt2=0;
 while(cnt2<1000)
 {
  delay1();
  cnt2++;
 }
 cnt2=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=1;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=0;
 j3_r=1;
 j4_r=1;
 while(cnt2<500)
 {
  delay1();
  cnt2++;

 }
 cnt2=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=1;
 j3_r=1;
 j4_r=1;
 while(cnt2<400)
 {
  delay1();
  cnt2++;

 }
cnt2=0;
}
void emergency3()
 {
 j1_g=0;
 j2_g=0;
 j3_g=1;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=1;
 j3_r=0;
 j4_r=1;
 cnt2=0;
 while(cnt2<1000)
 {
  delay1();
  cnt2++;
 }
 cnt2=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=1;
 j4_y=0;
 j1_r=1;
 j2_r=1;
 j3_r=0;
 j4_r=1;
 while(cnt2<500)
 {
  delay1();
  cnt2++;

 }
 cnt2=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=1;
 j3_r=1;
 j4_r=1;
 while(cnt2<400)
 {
  delay1();
  cnt2++;

 }
cnt2=0;
}
void emergency4()
 {
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=1;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=1;
 j3_r=1;
 j4_r=0;
 cnt2=0;
 while(cnt2<1000)
 {
  delay1();
  cnt2++;
 }
 cnt2=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=1;
 j1_r=1;
 j2_r=1;
 j3_r=1;
 j4_r=0;
 while(cnt2<500)
 {
  delay1();
  cnt2++;

 }
 cnt2=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=1;
 j3_r=1;
 j4_r=1;
 while(cnt2<400)
 {
  delay1();
  cnt2++;

 }
cnt2=0;
}
void checking()
{

  if(button1==0)button1_flag=1;
  if(button1==1&&button1_flag==1)
  { 
   button1_flag=0;

   jn1_flag=1;
   jn2_flag=0;
   jn3_flag=0;
   jn4_flag=0;
	buzer=1;
	delay(200);
    buzer=0;
	delay(200);
  }
  if(button2==0)button2_flag=1;
  if(button2==1&&button2_flag==1)
  { 
   button2_flag=0;
   jn1_flag=0;
   jn2_flag=1;
   jn3_flag=0;
   jn4_flag=0;
	buzer=1;
	delay(200);
    buzer=0;
	delay(200);
  }
  if(button3==0)button3_flag=1;
  if(button3==1&&button3_flag==1)
  { 
   button3_flag=0;
   jn1_flag=0;
   jn2_flag=0;
   jn3_flag=1;
   jn4_flag=0;
	buzer=1;
	delay(200);
    buzer=0;
	delay(200);
  }
  if(button4==0)button4_flag=1;
  if(button4==1&&button4_flag==1)
  { 
   button4_flag=0;
   jn1_flag=0;
   jn2_flag=0;
   jn3_flag=0;
   jn4_flag=1;
	buzer=1;
	delay(200);
    buzer=0;
	delay(200);
  }
    if(flag1==1&&jn1_flag==1)
  {
    flag1=0;
    jn1_flag=0;
    data_led=1;
	buzer=1;
	TXREG='A';
    delay(100);
    data_led=0;
	buzer=0;
    
    delay(100);
emergency1();
  }
  if(flag1==1&&jn2_flag==1)
  {
    flag1=0;
	jn2_flag=0;
	buzer=1;
TXREG='A';
    delay(100);
    data_led=0;
	buzer=0;
    delay(100);
emergency2();
  }
  if(flag1==1&&jn3_flag==1)
  {
    flag1=0;
	jn3_flag=0;
	buzer=1;
TXREG='A';
    delay(100);
    data_led=0;
	buzer=0;
    delay(100);
emergency3();
  }
  if(flag1==1&&jn4_flag==1)
  {
    flag1=0;
jn4_flag=0;
	buzer=1;
TXREG='A';
    delay(100);
    data_led=0;
	buzer=0;
    delay(100); 
emergency4();
  }
}

void junction1()
 {
 j1_g=1;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=0;
 j2_r=1;
 j3_r=1;
 j4_r=1;
 cnt1=0;
 while(cnt1<1000)
 {
  delay1();
  cnt1++;
  checking();
 }
 cnt1=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=1;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=0;
 j2_r=1;
 j3_r=1;
 j4_r=1;
 while(cnt1<500)
 {
  delay1();
  cnt1++;
checking();
 }
 cnt1=0;
 j1_g=0;
 j2_g=1;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=0;
 j3_r=1;
 j4_r=1;
 while(cnt1<1000)
 {
  delay1();
  cnt1++;
checking();
 }
}

void junction2()
{
 j1_g=0;
 j2_g=1;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=0;
 j3_r=1;
 j4_r=1;
 cnt1=0;
 while(cnt1<1000)
 {
  delay1();
  cnt1++;
checking();
 }
 cnt1=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=1;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=0;
 j3_r=1;
 j4_r=1;
 while(cnt1<500)
 {
  delay1();
  cnt1++;
checking();
 }
 cnt1=0;
 j1_g=0;
 j2_g=0;
 j3_g=1;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=1;
 j3_r=0;
 j4_r=1;
 while(cnt1<1000)
 {
  delay1();
  cnt1++;
checking();
 }
}


void junction3()
{
 j1_g=0;
 j2_g=0;
 j3_g=1;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=1;
 j3_r=0;
 j4_r=1;
 cnt1=0;
 while(cnt1<1000)
 {
  delay1();
  cnt1++;
checking();

 }
 cnt1=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=1;
 j4_y=0;
 j1_r=1;
 j2_r=1;
 j3_r=0;
 j4_r=1;
 while(cnt1<500)
 {
  delay1();
  cnt1++;
  checking();

 }
 cnt1=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=1;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=0;
 j1_r=1;
 j2_r=1;
 j3_r=1;
 j4_r=0;
 while(cnt1<1000)
 {
  delay1();
  cnt1++;
 checking();

 }
}



void junction4()
{

 cnt1=0;
 j1_g=0;
 j2_g=0;
 j3_g=0;
 j4_g=0;
 j1_y=0;
 j2_y=0;
 j3_y=0;
 j4_y=1;
 j1_r=1;
 j2_r=1;
 j3_r=1;
 j4_r=0;
 while(cnt1<500)
 {
  delay1();
  cnt1++;
  checking();

 }
 cnt1=0;

}


void main()
{
 
  PORTB = 0x00;
  TRISB = 0x00; //PORTB as output
  PORTC = 0x00;
  TRISC = 0x00; //PORTC as output
  PORTD = 0x00;
  TRISD = 0x00; //PORTC as output
  TRISC0=1;
  TRISC1=1;
  TRISC2=1;
  TRISC5=1;
  data_led=0;
  InitTimer0();
  uart_init();
  buzer=1;
  delay(200);
  buzer=0;
  delay(200);
receive_flag=0;
button1_flag=0;
button2_flag=0;
button3_flag=0;
button4_flag=0;
jn1_flag=0;
jn2_flag=0;
jn3_flag=0;
jn4_flag=0;

while(1)
{
  junction1();
  junction2();
  junction3();
  junction4();

}
}
