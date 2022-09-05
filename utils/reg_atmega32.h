/*******************************************************************************
 * [   Module  ]: REG_ATMEGA16
 *
 * [ File Name ]: reg_atmega16.h
 *
 * [Description]: IO memory address File For ATmega16 micro-controller.
 *
 * [   Author  ]: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_UTILS_REG_ATMEGA16_H_
#define SRC_UTILS_REG_ATMEGA16_H_

/*------------------------------------------------------------------------------
 *                                  INCLUDES
 *------------------------------------------------------------------------------*/
#include "avr_reg_defs.h"
/*------------------------------------------------------------------------------
 *                              GPIO REGISTERS
 *------------------------------------------------------------------------------*/
#define DDRA      __SFR_IO8_RW(0x3A)
#define DDRB      __SFR_IO8_RW(0x37)
#define DDRC      __SFR_IO8_RW(0x34)
#define DDRD      __SFR_IO8_RW(0x31)

#define PORTA     __SFR_IO8_RW(0x3B)
#define PORTB     __SFR_IO8_RW(0x38)
#define PORTC     __SFR_IO8_RW(0x35)
#define PORTD     __SFR_IO8_RW(0x32)

#define PINA      __SFR_IO8_R(0x39)
#define PINB      __SFR_IO8_R(0x36)
#define PINC      __SFR_IO8_R(0x33)
#define PIND      __SFR_IO8_R(0x30)
/*------------------------------------------------------------------------------
 *                              TIMER REGISTERS
 *------------------------------------------------------------------------------*/
#define TIMSK     __SFR_IO8_RW(0x39)
#define TIFR      __SFR_IO8_RW(0x38)
/*------------------------------------------------------------------------------
 *                              TIMER0  REG
 *------------------------------------------------------------------------------*/
#define TCCR0     __SFR_IO8_RW(0x33)
#define TCNT0     __SFR_IO8_RW(0x32)
#define OCR0      __SFR_IO8_RW(0x3C)
/*------------------------------------------------------------------------------
 *                              TIMER1  REG
 *------------------------------------------------------------------------------*/
#define TCCR1A    __SFR_IO8_RW(0x2F)
#define TCCR1B    __SFR_IO8_RW(0x2E)

/*Combination of TCNT1(H/L)*/
#define TCNT1      __SFR_IO16_RW(0x2C)

#define TCNT1H     __SFR_IO8_RW(0x2D)
#define TCNT1L     __SFR_IO8_RW(0x2C)

/*Combination of OCRA1(H/L)*/
#define OCR1A      __SFR_IO16_RW(0x2A)

#define OCR1AH     __SFR_IO8_RW(0x2B)
#define OCR1AL     __SFR_IO8_RW(0x2A)

/*Combination of OCR1B(H/L)*/
#define OCR1B      __SFR_IO16_RW(0x28)

#define OCR1BH     __SFR_IO8_RW(0x29)
#define OCR1BL     __SFR_IO8_RW(0x28)

/*Combination of ICR1(H/L)*/
#define ICR1       __SFR_IO16_RW(0x26)

#define ICR1H      __SFR_IO8_RW(0x27)
#define ICR1L      __SFR_IO8_RW(0x26)
/*------------------------------------------------------------------------------
 *                              TIMER2  REG
 *------------------------------------------------------------------------------*/
#define TCCR2     __SFR_IO8_RW(0x25)
#define TCNT2     __SFR_IO8_RW(0x24)
#define OCR2      __SFR_IO8_RW(0x23)
/*------------------------------------------------------------------------------
 *                              External Interrupt REG
 *------------------------------------------------------------------------------*/
#define MCUCR     __SFR_IO8_RW(0x35)
#define MCUCSR    __SFR_IO8_RW(0x34)
#define GICR      __SFR_IO8_RW(0x3B)
#define GIFR      __SFR_IO8_RW(0x3A)
/*------------------------------------------------------------------------------
 *                                    SPI REG
 *------------------------------------------------------------------------------*/
#define SPCR     __SFR_IO8_RW(0x0D)
#define SPSR     __SFR_IO8_RW(0x0E)
#define SPDR     __SFR_IO8_RW(0x0F)










#endif /* SRC_UTILS_REG_ATMEGA16_H_ */
