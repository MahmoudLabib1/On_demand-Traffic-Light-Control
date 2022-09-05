/*******************************************************************************
 * [Module Name]: led.c
 *
 * [Description]: Source file that contain implementation functions for LEDs.
 *
 * [Date Created]: AUG 16/22
 *
 * [Author]: Mahmoud-Labib
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                                  Includes
 -------------------------------------------------------------------------------*/
#include "led.h"

/*------------------------------------------------------------------------------
 *                             Implementation Functions
 -------------------------------------------------------------------------------*/
EN_LedState_t Led_ON(EN_LedType_t LED_ID){

	switch(LED_ID){
	case RED_LED_CAR_ID:
		GPIO_SetPinDir(PORTA_ID,PIN2_ID,pin_output);
#if(LED_CAR_CONFIG == NIGATIVE_LOGIC)
		GPIO_WritePin(PORTA_ID,PIN2_ID,logic_low);
#elif(LED_CAR_CONFIG == POSITIVE_LOGIC)
		GPIO_WritePin(PORTA_ID,PIN2_ID,logic_high);
#endif
		break;

	case RED_LED_PEDESTRIAN_ID:
		GPIO_SetPinDir(PORTB_ID,PIN2_ID,pin_output);
#if(LED_PEDESTRIAN_CONFIG == NIGATIVE_LOGIC)
		GPIO_WritePin(PORTB_ID,PIN2_ID,logic_low);
#elif(LED_PEDESTRIAN_CONFIG == POSITIVE_LOGIC)
		GPIO_WritePin(PORTB_ID,PIN2_ID,logic_high);
#endif
		break;

	case YELLOW_LED_CAR_ID:
		GPIO_SetPinDir(PORTA_ID,PIN1_ID,pin_output);
#if(LED_CAR_CONFIG == NIGATIVE_LOGIC)
		GPIO_WritePin(PORTA_ID,PIN1_ID,logic_low);
#elif(LED_CAR_CONFIG == POSITIVE_LOGIC)
		GPIO_WritePin(PORTA_ID,PIN1_ID,logic_high);
#endif
		break;

	case YELLOW_LED_PEDESTRIAN_ID:
			GPIO_SetPinDir(PORTB_ID,PIN1_ID,pin_output);
#if(LED_PEDESTRIAN_CONFIG == NIGATIVE_LOGIC)
		GPIO_WritePin(PORTB_ID,PIN1_ID,logic_low);
#elif(LED_PEDESTRIAN_CONFIG == POSITIVE_LOGIC)
		GPIO_WritePin(PORTB_ID,PIN1_ID,logic_high);
#endif
		break;

	case GREEN_LED_CAR_ID:
			GPIO_SetPinDir(PORTA_ID,PIN0_ID,pin_output);
#if(LED_CAR_CONFIG == NIGATIVE_LOGIC)
	GPIO_WritePin(PORTA_ID,PIN0_ID,logic_low);
#elif(LED_CAR_CONFIG == POSITIVE_LOGIC)
	GPIO_WritePin(PORTA_ID,PIN0_ID,logic_high);
#endif
	break;

	case GREEN_LED_PEDESTRIAN_ID:
		GPIO_SetPinDir(PORTB_ID,PIN0_ID,pin_output);
#if(LED_PEDESTRIAN_CONFIG == NIGATIVE_LOGIC)
	GPIO_WritePin(PORTB_ID,PIN0_ID,logic_low);
#elif(LED_PEDESTRIAN_CONFIG == POSITIVE_LOGIC)
	GPIO_WritePin(PORTB_ID,PIN0_ID,logic_high);
#endif
	break;
	}
	return LED_ON;
}

EN_LedState_t Led_OFF(EN_LedType_t LED_ID){

	switch(LED_ID){
	case RED_LED_CAR_ID:
		GPIO_SetPinDir(PORTA_ID,PIN2_ID,pin_output);
#if(LED_CAR_CONFIG == NIGATIVE_LOGIC)
		GPIO_WritePin(PORTA_ID,PIN2_ID,logic_high);
#elif(LED_CAR_CONFIG == POSITIVE_LOGIC)
		GPIO_WritePin(PORTA_ID,PIN2_ID,logic_low);
#endif
		break;

	case RED_LED_PEDESTRIAN_ID:
		GPIO_SetPinDir(PORTB_ID,PIN2_ID,pin_output);
#if(LED_PEDESTRIAN_CONFIG == NIGATIVE_LOGIC)
		GPIO_WritePin(PORTB_ID,PIN2_ID,logic_high);
#elif(LED_PEDESTRIAN_CONFIG == POSITIVE_LOGIC)
		GPIO_WritePin(PORTB_ID,PIN2_ID,logic_low);
#endif
		break;

	case YELLOW_LED_CAR_ID:
		GPIO_SetPinDir(PORTA_ID,PIN1_ID,pin_output);
#if(LED_CAR_CONFIG == NIGATIVE_LOGIC)
		GPIO_WritePin(PORTA_ID,PIN1_ID,logic_high);
#elif(LED_CAR_CONFIG == POSITIVE_LOGIC)
		GPIO_WritePin(PORTA_ID,PIN1_ID,logic_low);
#endif
		break;

	case YELLOW_LED_PEDESTRIAN_ID:
			GPIO_SetPinDir(PORTB_ID,PIN1_ID,pin_output);
#if(LED_PEDESTRIAN_CONFIG == NIGATIVE_LOGIC)
		GPIO_WritePin(PORTB_ID,PIN1_ID,logic_high);
#elif(LED_PEDESTRIAN_CONFIG == POSITIVE_LOGIC)
		GPIO_WritePin(PORTB_ID,PIN1_ID,logic_low);
#endif
		break;

	case GREEN_LED_CAR_ID:
			GPIO_SetPinDir(PORTA_ID,PIN0_ID,pin_output);
#if(LED_CAR_CONFIG == NIGATIVE_LOGIC)
	GPIO_WritePin(PORTA_ID,PIN0_ID,logic_high);
#elif(LED_CAR_CONFIG == POSITIVE_LOGIC)
	GPIO_WritePin(PORTA_ID,PIN0_ID,logic_low);
#endif
	break;

	case GREEN_LED_PEDESTRIAN_ID:
		GPIO_SetPinDir(PORTB_ID,PIN0_ID,pin_output);
#if(LED_PEDESTRIAN_CONFIG == NIGATIVE_LOGIC)
	GPIO_WritePin(PORTB_ID,PIN0_ID,logic_high);
#elif(LED_PEDESTRIAN_CONFIG == POSITIVE_LOGIC)
	GPIO_WritePin(PORTB_ID,PIN0_ID,logic_low);
#endif
	break;
	}
	return LED_OFF;
}

