#include "stm32f1xx.h"
#include "garra.h"
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
void EXTI_IRQHandler_1()
{
	EXTI->PR |= (1 << 1); //verifica la interrupccion
	motor1_secuencia();
	for (volatile int i = 0; i < 100; i++);
	motor1_secuencia2();
	
	
	GPIOC->ODR ^= (1 << 13); 
}

void ext_interrupt_1(void){
	EXTI->FTSR |= (1 << 1);	 // decedente 
	EXTI->IMR |= (1 << 1);	// PA1
	NVIC->ISER[0] |= 1 << 8; // canal 1
}



void ext_interrupt_2(void){			//PA2
	EXTI->FTSR |= (1 << 2);	
	EXTI->IMR |= (1 << 2);	
	NVIC->ISER[0] |= 1 << 9;
}

void EXTI_IRQHandler_2()
{
	EXTI->PR |= (1 << 2); //verifica la interrupccion 
	motor2_secuencia1();
	for (volatile int i = 0; i < 100; i++);
	motor2_secuencia2();
	
	
	GPIOC->ODR ^= (1 << 13); 
}
