#include<lpc214x.h>

void delay(unsigned int count);

int main()
{
    unsigned int i, count = 1;
    IODIR0 = 0x000000FF; 

    while (1) 
			{
        for (i = 0; i < 8; i++) 
			{
            if ((count & (1 << i)) != 0) 
							{
                IOSET0 = 1 << i; 
            } 
							else
								{
                IOCLR0 = 1 << i;
            }
        }
        delay(2000000); 
        count++; 
        if (count > 255)
					{
            count = 1; 
        }
				
    
			}
}

void delay(unsigned int count)
{
    while (count--)
    {
        
    }
}
