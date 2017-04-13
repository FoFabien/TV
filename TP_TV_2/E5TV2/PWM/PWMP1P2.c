//PWM_1.c
#if defined (__PCM__)
#include <16F876.h>
#device ICD=TRUE
#fuses HS,NOWDT,NOPROTECT
#endif
#use delay(clock=4000000)
main() {
      byte value;
      set_tris_a(0x00);
      set_tris_c(0x00);//portC en sortie
      setup_ccp2(CCP_PWM);   // Configure CCP1 comme mode PWM
      setup_timer_2(T2_DIV_BY_16, 255, 1); //configure Timer2 mode, periode,prescaler
      //1/15000000*4*16*156=0,6656ms soit 1,5Khz.
      value=250;
      set_pwm2_duty(value);  //duty cycle = value sortie sur RC1
   while( TRUE ) {

   OUTPUT_HIGH(  PIN_A0 ); //  broche A0 au niv 1=P1
   OUTPUT_LOW(  PIN_A2 );// broche A2 au niv 0=/P1
   OUTPUT_LOW( PIN_A1 );// broche A1 au niv 0 = P2
   OUTPUT_HIGH(  PIN_A3 );// broche A3 au niv 1=/P2
   DELAY_MS(1000);//delay de 2ms
   OUTPUT_HIGH(  PIN_A1 );
   OUTPUT_LOW( PIN_A3 );
   DELAY_MS(1000);
   OUTPUT_LOW( PIN_A0 );
   OUTPUT_HIGH( PIN_A2 );
   DELAY_MS(1000);
   OUTPUT_LOW( PIN_A1 );
   OUTPUT_HIGH( PIN_A3 );
   DELAY_MS(1000);

   }


}
