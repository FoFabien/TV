
#include <16f877a.h>


#fuses HS,NOLVP,NOWDT,PUT

#use delay (clock = 20000000)
#use rs232 (baud = 1200 , xmit = PIN_C6 , rcv = PIN_C7 ,PARITY=E, BITS=8)
void send(char c)
      {putc(c);}


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

#define LED_VERTE PIN_A5
#define LED_JAUNE PIN_B4
#define LED_ROUGE PIN_B5
#define bouton PIN_A4
#include<stdlib.h>

main()
	{

while(true)
      {

		send('A');
      output_low(LED_VERTE);
      affelcd('A');
		delay_ms(1000);

      send('B');
      output_high(LED_VERTE);
      affelcd('B');
		delay_ms(1000);


      }


}
