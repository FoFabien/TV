#if defined (__PCM__)
#include <16F877A.h>
#device ICD=TRUE
#fuses HS,NOWDT,NOPROTECT
#endif
#use delay(clock=20000000)

#define val1 0xE1
byte a,n,i,x,var,val2,var0,var1,var_tim0,ID; // variable

#int_timer0
void tmer0_int()
{
set_timer0(118); // interruption tout les 1.778ms
var_tim0=1;
}

void init(void);
void trans(void); // fonction de transmission

main()
{
x = 0; // chaine (nombre de fois qu'on appuie sur le bouton)
val2 = 0x00;

while(n<200)
{
   while(pin_A4 == 1 || n<200)
   {
   n++;
   delay_ms(25); // 5 secondes
   }
   if(n<200)
   {
   x = x + 1;
   }
}

n = 0;
x = x % 6;

if(x == 0)
val2 = 0x00;
else if (x == 1)
val2 = 0x04;
else if (x == 2)
val2 = 0x08;
else if (x == 3)
val2 = 0x0C;
else if (x == 4)
val2 = 0x10;
else if (x == 5)
val2 = 0x14; 

init();
   
while(true){
for(a=0; a<2; a++)
{
set_timer0(12);
enable_interrupts(INT_TIMER0);
i=7;
switch (a)
{
   case 0 :
      n=0;
      var=val1;
      break;
   case 1 :
      n=2;
      var=val2;
      break;
}
trans();
disable_interrupts(INT_TIMER0);
}
delay_us(889);
output_low(pin_c4);
}
}

void init(void){
setup_counters(RTCC_INTERNAL,RTCC_DIV_64);
set_tris_c( 0x00);
output_c(0x00);
n=0;
do{
output_high(pin_b5);
delay_ms(500);
output_low(pin_b5);
delay_ms(500);
n++;
}while(n<=5);
enable_interrupts(GLOBAL);
}

void trans(void){
do{
while(var_tim0==0){};
var_tim0=0;
if(bit_test(var,i)==1)
{
   output_low(pin_c4);
   delay_us(889);
   output_high(pin_c4);
}
else
{ 
   output_high(pin_c4);
   delay_us(889);
   output_low(pin_c4);
}
i--;n++;
}while(n<8);
}
