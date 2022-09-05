#include "MCAL/EX_INTERRUPT/ex_interrupt.h"
#include "APP/app.h"

int main(){
	TIMER_Init();
	Ex_INT_Init();
	sei();
	while(1){
		App_Start();	
	}

	return 0;

}
