#include<lpc214x.h>

void delay();

int main()
{
    unsigned int i;
    IODIR0 = 0x000000FF; 

   
        for (i = 255; i > 0; i--) 
			{
            
				IOPIN0= i;
        delay();
        
    
			}
}
			

void delay()
{
	unsigned int j;
    for(j=0;j<1000000;j++)
    {
        
    }
}
