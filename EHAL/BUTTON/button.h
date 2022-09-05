/*******************************************************************************
 * [Module Name]: button.h
 *
 * [Description]: header file that contain functions prototypes for Button.
 *
 * [Date Created]: AUG 16/22
 *
 * [Author]: Mahmoud-Labib
 *******************************************************************************/

#ifndef EHAL_BUTTON_BUTTON_H_
#define EHAL_BUTTON_BUTTON_H_

/*------------------------------------------------------------------------------
 *                                  Includes
 -------------------------------------------------------------------------------*/
#include "../../utils/std_types.h"
#include "../../utils/common_macros.h"
#include "../../MCAL/GPIO/GPIO.h"

/*------------------------------------------------------------------------------
 *                              Definitions
 -------------------------------------------------------------------------------*/
#define BUTTON1_PIN      INT0

#define PULL_UP      0
#define PULL_DOWN    1

#define BUTTON_CONFIG   PULL_DOWN

typedef enum {
pressed,unpressed
}EN_Button_State_t;
/*------------------------------------------------------------------------------
 *                             Function Prototype
 -------------------------------------------------------------------------------*/
EN_Button_State_t buttonIsPressed(void);
#endif /* EHAL_BUTTON_BUTTON_H_ */
