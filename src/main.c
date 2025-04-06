#include "timers.h"
#include "gpio.h"
#include "interupcciones.h"

int main(void) {
  init_gpio();
  ext_interrupt_1();
  ext_interrupt_2();
  while (1)
  {
  }
  
    }
