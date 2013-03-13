#include<reg52.h>
#include<stdio.h>

//LCD
sfr LCDdata=0x80;
sbit LCDrs=P3^3;
sbit LCDen=P3^2;

//SENSOR
sbit LDR=P2^1;
sbit color=P2^0;

//Motor
sbit armP=P1^0;
sbit armN=P1^1;
sbit gripP=P1^2;
sbit gripN=P1^3;
sbit conP=P1^6;
sbit conN=P1^7;



void MSdelay(unsigned int rtime)
	{
	unsigned int r,s;
	for(r=0;r<rtime;r++)
	for(s=0;s<1275;s++);
	}
void lcdcmd (unsigned char DATA)
	{

				LCDrs=0;
				LCDen=1;
				LCDdata=DATA;
				LCDrs=0;
				LCDen=0;
	}

void delay (unsigned int a ) 
	{  
				  unsigned int k; unsigned char l;  
				  for (k=0;k<a;k++)
				 	 {
					for (l=0;l<10;l++)
						{
				    						
						}
					 }
	}

void initialize (void) 
	{
				lcdcmd (0x30);
				delay(30);
				lcdcmd (0x38);
				delay(30);
				lcdcmd (0x0C);
				delay(30);
				lcdcmd (0x01);
				delay(30);
				lcdcmd (0x06);
				delay(30);
	}


void lcddat (unsigned int DATA)
	{      

				LCDrs=1;
				LCDen=1;
				LCDdata=DATA;
				LCDen=0;
	}



void display_lcd (unsigned char location, unsigned char *d)
	{  
					lcdcmd(0x80 | location); 
					delay(1);
					while(*d)
					 	{
					 	  lcddat(*d++);  
					 	  //delay(1);
					 	}	 
	}


void main()
{
unsigned char white[16]=0,black[16]=0;
unsigned int i=0,b_count=0,w_count=0;
P2=0xFF;
P1=0x00;


initialize ();
			
			display_lcd(0x00, "     OBJECT     ");	
            display_lcd(0x40, " SORTING ROBOT  ");
			MSdelay(300);

while(1)
	{

conP=0;
conN=1;

			display_lcd(0x00, " Conveyor Belt  ");	
            display_lcd(0x40, "    Running!    ");

			if(LDR==0 && color==1)	//white object		
			{
				w_count++;
				conP=0;
				conN=0;
				display_lcd(0x00, "  WHITE OBJECT  ");
				sprintf(white,"    Count=%d    ",w_count);	
	            display_lcd(0x40,white);

				MSdelay(200);
				conP=0;
				conN=1;
				MSdelay(400);
				conP=0;
				conN=0;
				delay(30);
				gripP=1;
				gripN=0;
				MSdelay(800);
				gripP=0;
				gripN=0;
				MSdelay(100);
					armP=0;
					armN=1;
					MSdelay(400);
					armP=0;
					armN=0;
				gripP=0;
				gripN=1;
				MSdelay(800);
				gripP=0;
				gripN=0;
					armP=1;
					armN=0;
					MSdelay(400);
					armP=0;
					armN=0;	

				}

			if(LDR==0 && color==0)	//black object		
			{
			b_count++;
				conP=0;
				conN=0;
				display_lcd(0x00, "  BLACK OBJECT  ");
				sprintf(white,"    Count=%d    ",b_count);	
	            display_lcd(0x40,white);

				MSdelay(200);
				conP=0;
				conN=1;
				MSdelay(400);
				conP=0;
				conN=0;
				delay(30);
				gripP=1;
				gripN=0;
				MSdelay(800);
				gripP=0;
				gripN=0;
				MSdelay(100);
					armP=1;
					armN=0;
					MSdelay(400);
					armP=0;
					armN=0;
				gripP=0;
				gripN=1;
				MSdelay(800);
				gripP=0;
				gripN=0;
					armP=0;
					armN=1;
					MSdelay(400);
					armP=0;
					armN=0;
				}

	}
}