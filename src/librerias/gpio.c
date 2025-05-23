#include "stm32f1xx.h"
#include "gpio.h"

void init_gpio(void){
	RCC->APB2ENR |= 1 << 2; //port A clk enable
	
	//PA0 config for TIMER2
	GPIOA->CRL |= (1 << 1);	//mode output 2MHz.
	GPIOA->CRL &= ~(1 << 0);
	GPIOA->CRL |= (1 << 3);	//alternate function output push-pull
	GPIOA->CRL &= ~(1 << 2);
	AFIO->MAPR &= ~((1 << 9)|(1 << 8)); 	//TIMER2 no remap
	
	//PA1 config for EXTI1
	GPIOA->CRL &= ~((1 << 5)|(1 << 4));	//input mode
	GPIOA->CRL |= (1 << 7);	//alternate function input with pull-up
	GPIOA->CRL &= ~(1 << 6);
	
	//PA2 config for EXTI2
	GPIOA->CRL &= ~((1 << 8)|(1 << 9));	//input mode
	GPIOA->CRL |= (1 << 11);	//alternate function input with pull-up
	GPIOA->CRL &= ~(1 << 10);
	
	//PA6 config for TIMER3
	GPIOA->CRL |= (1 << 25);	//mode output 2MHz.
	GPIOA->CRL &= ~(1 << 24);
	GPIOA->CRL |= (1 << 27);//alternate function output push-pull
	GPIOA->CRL &= ~(1 << 26);
	AFIO->MAPR &= ~((1 << 10)|(1 << 11)); //TIMER3 no remap
	
	/**********************************/
	
	/******* Port C *******************/
	RCC->APB2ENR |= (1 << 4);	//port A clk enable
	
	//PC13 config
	GPIOC->CRH |= (1 << 21);	//mode output 2MHz.
	GPIOC->CRH &= ~(1 << 20);
	GPIOC->CRH &= ~((1 << 23)|(1 << 22));	//general purpose output push-pull
	/**********************************/


}