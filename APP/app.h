/*******************************************************************************
 * [Module Name]: app.h
 *
 * [Description]: header file that contain functions prototypes for applications.
 *
 * [Date Created]: AUG 16/22
 *
 * [Author]: Mahmoud-Labib
 *******************************************************************************/
#ifndef APP_APP_H_
#define APP_APP_H_

/*------------------------------------------------------------------------------
 *                                  Includes
 -------------------------------------------------------------------------------*/
#include "../utils/std_types.h"
#include "../EHAL/LED/led.h"
#include "../MCAL/TIMER/timer.h"
#include <util/delay.h>
#include <avr/interrupt.h>
/*------------------------------------------------------------------------------
                              Functions Prototypes
 -------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:App_Start
 [DISCRIPTION]:	This function is responsible to start the Application
 [Args]: void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/

void App_Start(void);
/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:normalMode
 [DISCRIPTION]:	This function is responsible to work the Led's of traffic for car
                like in real life (yellow -> red -> yellow -> green).
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/

void normalMode(void);
/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:pedstrianMode
 [DISCRIPTION]:	This function is responsible to work the traffic of pedestrain when person
                Press the button.
 [Args]: void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/

void pedstrianMode(void);
/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:fristCase
 [DISCRIPTION]:	This function is responsible to handle the balance between the two Traffic
                when the person press the Button when traffic of car was in Green light
                or yellow light.
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/

void fristCase(void);
/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:theardCase
 [DISCRIPTION]:	This function is responsible to handle the balance between the two Traffic
                when the person press the Button when the traffic of car was in Red light
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/

void theardCase(void);



#endif /* APP_APP_H_ */
