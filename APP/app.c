/*******************************************************************************
 * [Module Name]: app.c
 *
 * [Description]: Source file that contain implementation functions for applications.
 *
 * [Date Created]: AUG 16/22
 *
 * [Author]: Mahmoud-Labib
 *******************************************************************************/

#include "app.h"

extern uint8 volatile LED_Flag;
extern uint8 volatile ledCount;
extern uint8 volatile ledPedstrianFlag;
extern uint8 volatile ledPedstrianCount;
extern uint8 volatile buttonFlag;
uint8 volatile red=0;
uint8 volatile yellowBeforeRed=0;
uint8 volatile yellowBeforegreen=0;
uint8 volatile green=0;


/*------------------------------------------------------------------------------
 *                                 private Function
 *------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:yellowLed
 [DISCRIPTION]:	This is a private function  responsible to start the yellow light in traffic of car
                and if person press the button it also blinking both the yellow light
                of Pedestarin and car in traffic .
 [Args]: void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
static void yellowLed(void){

	if(buttonFlag == TRUE){
		_delay_ms(30);
		if(buttonFlag == TRUE){
			if(ledPedstrianFlag == FALSE){
				ledCount=0;
				ledPedstrianFlag =TRUE;
				ledPedstrianCount=0;
			}
			if(ledPedstrianCount%2 == 0){
				Led_ON(YELLOW_LED_PEDESTRIAN_ID);
				Led_OFF(GREEN_LED_PEDESTRIAN_ID);
				Led_OFF(RED_LED_PEDESTRIAN_ID);
			}
			else
			{
				Led_OFF(YELLOW_LED_PEDESTRIAN_ID);
				Led_OFF(GREEN_LED_PEDESTRIAN_ID);
				Led_OFF(RED_LED_PEDESTRIAN_ID);
			}
		}

	}
	if(ledCount%2 == 0){
		Led_ON(YELLOW_LED_CAR_ID);
		Led_OFF(GREEN_LED_CAR_ID);
		Led_OFF(RED_LED_CAR_ID);
	}
	else
	{
		Led_OFF(YELLOW_LED_CAR_ID);
		Led_OFF(GREEN_LED_CAR_ID);
		Led_OFF(RED_LED_CAR_ID);
	}

}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:redCarLed
 [DISCRIPTION]:	This is a private function responsible to ON the red light in car traffic
                and handle the case if person press the button.
 [Args]: void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
static void redCarLed(void){

	green=0;

	LED_Flag = TRUE;
	ledCount=0;
	// Blinking Yellow Led for 5sec
	while(ledCount <= 19){
		yellowBeforeRed=1;


		yellowLed();


		if(ledCount == 19){
			break;
		}
	}
	LED_Flag = TRUE;
	ledCount=0;
	ledPedstrianFlag =TRUE;
	ledPedstrianCount=0;

	while(LED_Flag != FALSE){

		red=1;
		Led_ON(RED_LED_CAR_ID);
		Led_OFF(YELLOW_LED_CAR_ID);
		Led_OFF(GREEN_LED_CAR_ID);

		Led_OFF(YELLOW_LED_PEDESTRIAN_ID);
		Led_ON(GREEN_LED_PEDESTRIAN_ID);
		Led_OFF(RED_LED_PEDESTRIAN_ID);

	}
	Led_OFF(RED_LED_CAR_ID);
	Led_OFF(YELLOW_LED_CAR_ID);
	Led_OFF(GREEN_LED_CAR_ID);

	Led_OFF(YELLOW_LED_PEDESTRIAN_ID);
	Led_OFF(GREEN_LED_PEDESTRIAN_ID);
	Led_OFF(RED_LED_PEDESTRIAN_ID);

	yellowBeforegreen=0;
}




/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:greenCarLed
 [DISCRIPTION]:	This is a private function responsible to ON the green light in car traffic
                and handle the case if person press the button.
 [Args]: void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
static void greenCarLed(void){

	yellowBeforegreen=1;
	yellowBeforeRed=0;
	red=0;
	LED_Flag =TRUE;
	ledCount=0;
	// Blinking Yellow Led for 5sec
	uint8 interrupt=0;
	while(ledCount <= 19){

		yellowLed();

		if(buttonFlag == TRUE){
			interrupt=1;
		}
		if(ledCount == 19){
			break;
		}
	}

	LED_Flag = TRUE;
	ledCount=0;
	ledPedstrianFlag =TRUE;
	ledPedstrianCount=0;
	green=1;
	while(LED_Flag != FALSE && buttonFlag == FALSE){
		yellowBeforegreen=0;
		Led_ON(GREEN_LED_CAR_ID);
		Led_OFF(YELLOW_LED_CAR_ID);
		Led_OFF(RED_LED_CAR_ID);
		/*if(buttonFlag == TRUE){
			break;
		}*/

		Led_ON(RED_LED_PEDESTRIAN_ID);
		Led_OFF(GREEN_LED_PEDESTRIAN_ID);
		Led_OFF(YELLOW_LED_PEDESTRIAN_ID);
	}

	if(interrupt == 1){
		yellowBeforegreen=1;
	}

	Led_OFF(RED_LED_CAR_ID);
	Led_OFF(YELLOW_LED_CAR_ID);
	Led_OFF(GREEN_LED_CAR_ID);

	Led_OFF(YELLOW_LED_PEDESTRIAN_ID);
	Led_OFF(GREEN_LED_PEDESTRIAN_ID);
	Led_OFF(RED_LED_PEDESTRIAN_ID);

}

/*------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 *                           Functions Implementation
 *-----------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:App_Start
 [DISCRIPTION]:	This function is responsible to start the Application
 [Args]: void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void App_Start(void){

	if(buttonFlag == FALSE)
	{
		normalMode();
	}
	else
	{
		pedstrianMode();
	}
}


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:normalMode
 [DISCRIPTION]:	This function is responsible to work the Led's of traffic for car
                like in real life (yellow -> red -> yellow -> green).
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void normalMode(void){

	if(red == 1){

		greenCarLed();
	}
	else
	{
		redCarLed();
	}

}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:pedstrianMode
 [DISCRIPTION]:	This function is responsible to work the traffic of pedestrain when person
                Press the button.
 [Args]: void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void pedstrianMode(void){

	if(buttonFlag == TRUE){
		_delay_ms(30);
		if(buttonFlag == TRUE){
			//secoundCase();
			fristCase();
			theardCase();
			buttonFlag = FALSE;
		}
	}
}


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:fristCase
 [DISCRIPTION]:	This function is responsible to handle the balance between the two Traffic
                when the person press the Button when traffic of car was in Green light
                or yellow light.
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void fristCase(void){
	if(green == 1){
		LED_Flag = TRUE;
		ledCount=0;
		ledPedstrianFlag =TRUE;
		ledPedstrianCount=0;
		// Blinking Yellow Led for 5sec
		if(yellowBeforegreen!=1){
			while(ledCount <= 19 || ledPedstrianCount <= 19){

				if(buttonFlag == TRUE){
					_delay_ms(30);
					if(buttonFlag == TRUE){
						if(ledPedstrianFlag == FALSE){
							ledCount=0;
							ledPedstrianFlag =TRUE;
							ledPedstrianCount=0;
						}
						if(ledPedstrianCount%2 == 0){
							Led_ON(YELLOW_LED_PEDESTRIAN_ID);
							Led_OFF(GREEN_LED_PEDESTRIAN_ID);
							Led_OFF(RED_LED_PEDESTRIAN_ID);
						}
						else
						{
							Led_OFF(YELLOW_LED_PEDESTRIAN_ID);
							Led_OFF(GREEN_LED_PEDESTRIAN_ID);
							Led_OFF(RED_LED_PEDESTRIAN_ID);
						}
					}
				}
				if(ledCount%2 == 0){
					Led_ON(YELLOW_LED_CAR_ID);
					Led_OFF(GREEN_LED_CAR_ID);
					Led_OFF(RED_LED_CAR_ID);
				}
				else
				{
					Led_OFF(YELLOW_LED_CAR_ID);
					Led_OFF(GREEN_LED_CAR_ID);
					Led_OFF(RED_LED_CAR_ID);
				}

				if(ledCount == 19 || ledPedstrianCount == 19){
					break;
				}
			}
		}


		LED_Flag = TRUE;
		ledCount=0;
		ledPedstrianFlag = TRUE;
		ledPedstrianCount=0;

		while(LED_Flag != FALSE && ledPedstrianFlag != FALSE){
			red=1;
			Led_ON(RED_LED_CAR_ID);
			Led_OFF(YELLOW_LED_CAR_ID);
			Led_OFF(GREEN_LED_CAR_ID);

			Led_ON(GREEN_LED_PEDESTRIAN_ID);
			Led_OFF(YELLOW_LED_PEDESTRIAN_ID);
			Led_OFF(RED_LED_PEDESTRIAN_ID);
			if(ledPedstrianCount == 19 && ledCount == 19){
				break;
			}
		}
		Led_OFF(RED_LED_CAR_ID);
		Led_OFF(YELLOW_LED_CAR_ID);
		Led_OFF(GREEN_LED_CAR_ID);

		Led_OFF(RED_LED_PEDESTRIAN_ID);
		Led_OFF(YELLOW_LED_PEDESTRIAN_ID);
		Led_OFF(GREEN_LED_PEDESTRIAN_ID);
		buttonFlag = FALSE;
	}
}


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:theardCase
 [DISCRIPTION]:	This function is responsible to handle the balance between the two Traffic
                when the person press the Button when the traffic of car was in Red light
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void theardCase(void){
	if(red == 1){
		buttonFlag = FALSE;
	}
}



