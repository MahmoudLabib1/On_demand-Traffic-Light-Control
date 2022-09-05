/*******************************************************************************
 * [Module Name]: led.h
 *
 * [Description]: header file that contain functions prototypes for LEDs.
 *
 * [Date Created]: AUG 16/22
 *
 * [Author]: Mahmoud-Labib
 *******************************************************************************/

#ifndef EHAL_LED_LED_H_
#define EHAL_LED_LED_H_

/*------------------------------------------------------------------------------
 *                                  Includes
 -------------------------------------------------------------------------------*/
#include "../../utils/std_types.h"
#include "../../MCAL/GPIO/GPIO.h"

/*------------------------------------------------------------------------------
 *                              Definitions
 -------------------------------------------------------------------------------*/
#define NIGATIVE_LOGIC    0
#define POSITIVE_LOGIC    1

#define LED_CAR_CONFIG           NIGATIVE_LOGIC
#define LED_PEDESTRIAN_CONFIG    POSITIVE_LOGIC

typedef enum{
	RED_LED_CAR_ID=1,
	YELLOW_LED_CAR_ID,
	GREEN_LED_CAR_ID,

	RED_LED_PEDESTRIAN_ID,
	YELLOW_LED_PEDESTRIAN_ID,
	GREEN_LED_PEDESTRIAN_ID
}EN_LedType_t;

typedef enum{
  LED_ON,LED_OFF
}EN_LedState_t;
/*------------------------------------------------------------------------------
 *                             Function Prototype
 -------------------------------------------------------------------------------*/
EN_LedState_t Led_ON(EN_LedType_t LED_ID);
EN_LedState_t Led_OFF(EN_LedType_t LED_ID);

#endif /* EHAL_LED_LED_H_ */
