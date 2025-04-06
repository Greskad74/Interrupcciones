#include "stm32f1xx.h"
#include "gpio.h"

void init_gpio(void){
	//init portA
	RCC->APB2ENR |= 1 << 2; //enable clk
	

	//pa1
	GPIOA -> CRL &=  ~(1<<4)|(1<<5);
	GPIOA -> CRL |= (1<<7);
	GPIA -> CRL |= (0 <<6);
	

	//PA2
	
	
	GPIOA -> CRL &= ~(1<<9)(1<<8);
	GPIOA -> CRL |=  (1<<11);
	GPIOA -> CRL &= ~ (1<<10);
	
	
	
	
	
	
	
	
	
	/***********pwm***************/
	
	
	//PA0 mode 2MHz.
	GPIOA->CRL |= (1 << 1);
	GPIOA->CRL &= ~(1 << 0);
	// PA6

	//PA alternate function pushpull
	GPIOA->CRL |= (1 << 3);
	GPIOA->CRL &= ~(1 << 2);
// Timer 3 PA6
	GPIOA -> CRL |= (1 << 27);
	GPIOA -> CRL &= ~(1 << 26);
	GPIOA -> CRL |= (1 << 25); 
	GPIOA -> CRL &=  ~( 1 << 24);





}