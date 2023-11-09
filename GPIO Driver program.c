void delay(unsigned int count);
void portWrite(int portno , int portvalue);
void pinwrite(int pinno , int pinvalue);
int pinread(int pinno);
int portRead(int portno);

//--------PINWRITE-----------------------------------

void pinwrite(int pinno , int pinvalue)
{
if(pinno < 100)
{
 IODIR0 |=(0x01<<pinno);

if(pinvalue == 0)
{
 IOCLR0 |=(0x01<<pinno);
}
else
{
 IOSET0 |=(0x01<<pinno);
}
}

else	
{
	pinno-=100;
	
	IODIR1 |=(0x01 << (pinno));
	
if(pinvalue == 0)
{
	IOCLR1 |=(0x01<< (pinno));
}
else
{
	IOSET1 |=(0x01 << (pinno));
}
}
}



//------------------DELAY------------------------------------------
void delay(unsigned int count)
	{
    while (count--) 
		{    
    }
}
//--------------PORTWRITE----------------------------------------


void portWrite(int portno,int portvalue)
{
	if(portno<10)
	{
		if(portno==0)
		{
			IODIR0=IODIR0|0xFF;
			if(portvalue==0)
			{
			IOCLR0=(IOCLR0)|(0xFF);
		  }
	  	else
		  {
			IOSET0=(IOSET0)|(0xFF);
		  }
		}
	else if(portno==1)
		{
			IODIR0 = IODIR0|0xFF00;
			if(portvalue==0)
			{
			IOCLR0=(IOCLR0)|(0xFF00);
		  }
		  else
	   	{
			IOSET0=(IOSET0)|(0xFF00);
		  }
		}
	 else if(portno==2)
		{
			IODIR0=IODIR0|0xFF0000;
			if(portvalue==0)
			{
			IOCLR0=(IOCLR0)|(0xFF0000);
	  	}
		  else
		  {
		  	IOSET0=(IOSET0)|(0xFF0000);
		  }
		}
		else if(portno==3)
		{
			IODIR0=IODIR0|0xFF000000;
			if(portvalue==0)
			{
			IOCLR0=(IOCLR0)|(0xFF000000);
	  	}
		  else
		  {
		  	IOSET0=(IOSET0)|(0xFF000000);
		  }
		}
	}
	else
	{
		if(portno==12)
		{
			IODIR1=IODIR1|0xFF0000;
			if(portvalue==0)
			{
			IOCLR1=(IOCLR1)|(0xFF0000);
		  }
	  	else
		  {
			IOSET1=(IOSET1)|(0xFF0000);
		  }
		}
		else if(portno==13)
		{
			IODIR1=IODIR1|0xFF000000;
			if(portvalue == 0)
			{
			IOCLR1=(IOCLR1)|(0xFF000000);
		  }
	  	else
		  {
			IOSET0=(IOSET1)|(0xFF000000);
		  }
		}
	}
}

//-------------PIN READ------------------------

int pinread(int pinno)
{
unsigned int mydata;
	
if(pinno < 100)
{
 IODIR0 = IODIR0 & (~(0x01<<pinno));
 mydata = IOPIN0;
	
if ((mydata & (0x01<<pinno))==0)
  {
		return 0;
	}
	else
	{
		return 1;
	}
}
else
	
{
	pinno -= 100;	
	IODIR1 = IODIR1 & (~(0x01 << pinno));	
	mydata = IOPIN1;
	if ((mydata & (0x01<<pinno))==0)
  {
		return 0;
	}
	else
	{
		return 1;
	}

}
}

//--------------PORT READ ------------------


int portRead(int portno)
{
	unsigned int mydata;
	
	if(portno == 0)
	{
		IODIR0 = IODIR0 & (0xFFFFFF00);
		mydata = IODIR0;
		return mydata & (0x000000FF); 
  }
	
	else if(portno == 1)
	{
		IODIR0 = IODIR0 & (0xFFFF00FF);
		mydata = IODIR0;
		return mydata & (0x0000FF00);
  }
	
	else if(portno == 2)
	{
		IODIR0 = IODIR0 & (0xFF00FFFF);
		mydata = IODIR0;
		return mydata & (0x00FF0000); 
  }
	
	else if(portno == 3)
	{
		IODIR0 = IODIR0 & (0x00FFFFFF);
		mydata = IODIR0;
		return mydata & (0xFF0000000); 
  }
	
	else if(portno == 12)
	{
		IODIR1 = IODIR1 & (0xFF00FFFF);
		mydata = IODIR1;
		return mydata & (0x00FF0000); 
  }
	
	else if(portno == 13)
	{
		IODIR1 = IODIR1 & (0x00FFFFFF);
		mydata = IODIR1;
		return mydata & (0xFF0000000); 
  }
}
