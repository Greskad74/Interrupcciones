#include "stm32f1xx.h"
#include "gpio.h"
#include "systickdelay.h"
 //#include "systickdelay.h"  

void init_gpio(void){
	//init portA
	RCC->APB2ENR |= 1 << 2; //enable clk
	

	GPIOA->CRL |=((0 << 1)|(0 << 0));	
	GPIOA->CRL |= (0 << 3);
	GPIOA->CRL |= (1 << 2);
	
	
	//init portC
	RCC->APB2ENR |= (1 << 4);
	GPIOC->CRH &= ~((1 << 23)|(1 << 22)|(1 << 20));
	GPIOC->CRH |= (1 << 21);

}

 void led_on_off(){
	while (1)
	{
		GPIOC -> ODR ^= (1 << 13);
		systickdelay(1);
	}
	
} 
