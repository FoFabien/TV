//PWM_1.c
#if defined (__PCM__)
#include <16F877.h>
#device ICD=TRUE
#fuses HS,NOWDT,NOPROTECT
#endif 

main() {
      byte value;  
      set_tris_c(0x00);//portC en sortie
      setup_ccp1(CCP_PWM);   // Configure CCP1 comme mode PWM
      setup_timer_2(T2_DIV_BY_16, 155, 1); //configure Timer2 mode, priode,prescaler
      //1/15000000*4*16*156=0,6656ms soit 1,5Khz.
  setup_adc_ports(ALL_ANALOG);//Vref=Vdd, RA0_1_2_3_5, RE0_1_2 analogiques
  setup_adc(adc_clock_internal); //voir fichier.h
  set_adc_channel( 0 ); //conversion de la voie 0
   while( TRUE ) {
    value=read_adc();

    set_pwm1_duty(value);  //duty cycle = value                                           //  if value is INT:
                  }

}

