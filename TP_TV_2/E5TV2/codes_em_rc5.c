//

#include <16F877A.h>
#device ICD=TRUE
#fuses HS,NOLVP,NOWDT,PUT

#use delay(clock=20000000)

#define led_verte PIN_A5
#define led_rouge PIN_B5
#define led_jaune PIN_B4
#define bouton PIN_A4


int x;
void foncnl1();
void foncnl0();

main()
{
output_low(led_verte);
while(true)
 {
for(x=0;x<=2;++x)
   {
foncnl0();
   }
   for(x=0;x<=8;++x)
   {
foncnl1();
   }
foncnl0();
foncnl0();
 delay_ms(89);
 }
}

void foncnl1()
{
int varnl1;
setup_timer_2(T2_DIV_BY_1,255,1);
varnl1 = 0;

      do
      {
   output_low(pin_c4);
   set_timer2(0);
   while(get_timer2()<90);
   output_high(pin_c4);
   set_timer2(0);
   while(get_timer2()<15);

      varnl1 +=1;

     }while(varnl1<32);
   output_low(pin_c4);
   delay_us(889);
}

void foncnl0()
{
int varnl0;
setup_timer_2(T2_DIV_BY_1,255,1);
varnl0 = 0;
output_low(pin_c4);
   delay_us(889);
      do
      {
   output_high(pin_c4);
   set_timer2(0);
   while(get_timer2()<15);
   output_low(pin_c4);
   set_timer2(0);
   while(get_timer2()<90);

      varnl0 +=1;

     }while(varnl0<32);
   
}




