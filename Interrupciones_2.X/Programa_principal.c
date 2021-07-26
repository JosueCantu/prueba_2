/*
 * File:   Programa_principal.c
 * Author: josue
 *
 * Created on 20 de julio de 2021, 07:57 PM
 */

//TRIS ----> = 1; ENTRADA | 0; SALIDA
//LAT ----> = 1; NIVEL 1 | 0; NIVEL CERO /ESCRIBIR 
//PORT ----> == 1 ;PREGUNTAR ESTADO/LEER 

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "interrupciones_2.h"


extern uint8_t x;

void main(void) {
    Int_init();
    TRISD = 0x00;
    LATD = 0X00;
            
    while(1){
        if(x==1){
            LATD=0XAA;
        }
        if(x==2){
            LATD=0X66;
    }
    }
    return;
}
