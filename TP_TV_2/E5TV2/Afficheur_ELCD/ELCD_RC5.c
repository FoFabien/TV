#include <16f877a.h>
#include<stdlib.h>

#fuses HS,NOLVP,NOWDT,PUT

#define LED_VERTE PIN_A5
#define LED_JAUNE PIN_B4
#define LED_ROUGE PIN_B5
#define bouton PIN_A4


#use delay (clock = 20000000)

#use rs232 (baud = 1200 , xmit = PIN_C6 , rcv = PIN_C7 ,PARITY=E, BITS=8)
char recepline()
      {return(getc());}


#use rs232 (baud = 19200 , xmit = PIN_D6 , rcv = PIN_D7)
void affelcd(char ELCD)
   {
 printf("%c",0xa0);
          delay_ms(40);

         printf("%c%c",0xa3,0xa1);
          delay_ms(20);

          printf("%c%c%c",0xa1,0,0);
          delay_ms(20);
          printf("%c%c%c",0xa2,ELCD,0);
   }

main()
	{
   char recep;
while(true)
      {
       recep=recepline();

		output_low(LED_VERTE);
		delay_ms(800);

      if(Recep=='A')
         {
      output_high(LED_JAUNE);
      output_low(LED_ROUGE);
      affelcd('A');
          }
      else
         { if(Recep=='B')
            {
      output_high(LED_ROUGE);
      output_low(LED_JAUNE);
      affelcd('B');
            }
         }
       }
      Recep=0;

      affelcd(Recep);

      }



