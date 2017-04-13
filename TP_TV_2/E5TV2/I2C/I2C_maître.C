//I2C_maître.c 
//ce programme n'a pas été testé; il est livré sans garantie
//ce programme utilise les routines du compilateur concernant le bus i2c.
//ce programme emet sur le bus I2C un nombre d'octets composant le buffer
//utilisation  de l'interruption générée par le buffer I2C
#if defined (__PCM__)
#include <16F873.h>
#device ICD=TRUE
#fuses HS,NOWDT,NOPROTECT
#endif 
#use i2c (master,sda=pin_c4,scl=pin_c3,address=0xa0,slow)

//declaration des variables
typedef enum {etat0,etat1,etat2,etat3}I2C_etats;
I2C_etats N_etat;
int adresse,buffer[0x10],oct_1,oct_2,oct_3,oct_4,i;  


//declaration de la fonction interruption
#int_ssp
void ssp_int()
{  
	if (N_etat==etat0)
	{
		i2c_start();	//condition de start
		N_etat=etat1;
		}
	else if (N_etat==etat1)
		{
		i2c_write(adresse);	//adresse du recepteur
		N_etat=etat2;
		}
	else if (N_etat==etat2)
		{
			if(i==0X04)
			{
			N_etat=etat3;
			i2c_write(buffer[i]);
			}
			else
			{
			i2c_write(buffer[i]);
			i++;
			N_etat=etat2;
			} 
		}
	else if (N_etat==etat3)
		{
		i2c_stop();
		N_etat=etat0;
		}
}
		
//debut du programme 
main() {  
i=0;
N_etat=etat0;
oct_1=0x3A;oct_2=0x14;oct_3=0x65;oct_4=0x35;
adresse=0XFE;	//adresse du recepteur
set_tris_c( 0b00000000);  //portC en sortie surtout C3 et C4
buffer[0]=adresse;
buffer[1]=oct_1;
buffer[1]=oct_2;
buffer[1]=oct_3;
buffer[1]=oct_4;
enable_interrupts(global); //autorise les interruptions.
enable_interrupts(int_ssp); //demasque EXT INT

while (TRUE) {}
}
