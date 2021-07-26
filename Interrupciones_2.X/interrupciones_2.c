
#include "interrupciones_2.h"
#include <xc.h>
#include <stdint.h>

uint8_t x = 0;

//u unsigned int-> 8 bits 
//u unsigned int -> 16 bit
//u unsigned int ->32 bits 

void Int_init(void){
   
TRISBbits.RB0 = 1; //entrada
TRISBbits.RB1 = 1; //entrada

INTCON3bits.INT1E = 1; //habilitando int1
INTCON3bits.INT1F = 0; //limpiar flag 

INTCONbits.INT0IE = 1;//HABILITANDO EL Int 0  //int0 siempre esta en prioridad baja 
INTCONbits.INT0IF = 0;//LIMPIAR FLAG INT0

INTCONbits.PEIE = 1;//INT PERIFERICOS ENABLE
INTCONbits.GIE = 1;// INT GLOBALES  ENABLE 


INTCON2bits.INTEDG0 = 0;//DESCENDENTE PUES TENIENDO UN PULL UP SIEMPRE ESTARA EN 1 Y HARA CAMBIO DE 1 A 0
INTCON2bits.INTEDG1 = 0;//DESCENDENTE PUES TENIENDO UN PULL UP SIEMPRE ESTARA EN 1 Y HARA CAMBIO DE 1 A 0

RCONbits.IPEN = 1; //habilitar prioridades 
INTCON3bits.INT1P = 0;//PRIORIDAD BAJA 

//INTCONbits.GIEH = 1 ;// habilitador de prioridad alta
//INTCONbits.GIEL = 1 ;//habilitador de prioridad baja 
}


//vector de interrupcion  cuando ocurra una interrupcion vendra y atendera la interrupcion 

void __interrupt(high_priority) INT0_ISR(void){
    x = 1;
INTCONbits.INT0IF = 0;//LIMPIAR FLAG INT0
}

void __interrupt(low_priority) INT1_ISR(void){
    x = 2;
INTCON3bits.INT1IF = 0;//LIMPIAR FLAG INT0
}
