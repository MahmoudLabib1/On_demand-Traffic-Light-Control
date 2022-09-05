/*******************************************************************************
 * [Module Name]: button.c
 *
 * [Description]: Source file that contain implementation functions for Button.
 *
 * [Date Created]: AUG 17/22
 *
 * [Author]: Mahmoud-Labib
 *******************************************************************************/

#include "button.h"

EN_Button_State_t buttonIsPressed(void){
#if(BUTTON_CONFIG == PULL_DOWN)
	if(!(BIT_IS_SET(PIND,BUTTON1_PIN))){
		return pressed;
	}
	else
	{
		return unpressed;
	}
}
#endif
