#include "stm32f1xx.h"

/*
EXTI program:
- Enable the clocks for GPIOs and AFIO.
- Configure the Alternate Function to use a GPIO (usually standard after reset).
- Configure the interrupt input pin as input using CRL and CRH registers.
- Select the interrupt input pin using AFIO_EXTICR.
- Configure the RTSR and FTSR registers to choose the interrupt edge.
- Set the EXTI_IMR register to enable the interrupt for the line.
- Enable the EXTI interrupt using the ISER register or NVIC_EnableIRQ function.
- Clear the PR flag in the interrupt routine.
*/


/*
	Selects PB4 as the input for external interrupt.
	On each falling edge, an interrupt is generated.
	Interrupt service routine toggles Led on PC13.
*/
void EXTI_IRQHandler()
{
	EXTI->PR |= (1 << 1); //verifica la interrupccion
	GPIOC->ODR |= (1 << 13); 
}

void ext_interrupt(void){
	EXTI->FTSR |= (1 << 1);	 // decedente 
	EXTI->IMR |= (1 << 1);	// PA1
	NVIC->ISER[0] |= 1 << 8; // canal 1
}



void ext_interrupt(void){			//PA2
	EXTI->FTSR |= (1 << 1);	
	EXTI->IMR |= (1 << 2);	
	NVIC->ISER[0] |= 1 << 9;
}

void EXTI_IRQHandler()
{
	EXTI->PR |= (1 << 2); //verifica la interrupccion 
	GPIOC->ODR |= (1 << 13); 
}
