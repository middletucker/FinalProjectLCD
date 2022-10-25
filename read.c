
#include "time.h"
#include <stdio.h>

#include "sl_board_control.h"
#include "sl_simple_button_instances.h"
#include "em_assert.h"
#include "glib.h"
#include "dmd.h"

#ifndef BUTTON_INSTANCE_0
#define BUTTON_INSTANCE_0   sl_button_btn0
#endif

long duration;
int distance;




sl_udelay_wait(2);




/*
#define trigger_pin //#
#define echo_pin //#

#include "time.h"

long duration;
int distance;

void setup()
{
  GPIO_PinModeSet (GPIO_Port_TypeDef port, unsigned int pin, GPIO_Mode_TypeDef mode, unsigned int out)
  GPIO_PinOutSet(gpioPortB,8);//for trigger gpioModeInput
  GPIO_PinOutSet(gpioPortD,8); //for echo gpioModeWiredAnd
  GPIO_PinOutClear()
}

void loop()
{
  //set trigger to low for 2 us

  sl_udelay_wait(2);

  //set trigger to high for 10 us

  sl_udelay_wait(10);

  //start clock
  clock_t begin = clock();

  // if echo = high, end clock
  if (echo_pin == HIGH)//??
    {
      clock_t end = clock();
      duration = (double)(end-begin) / CLOCKS_PER_SEC;
    }

   //ask about double??

  distance = duration * 0.034/2;

}
*/
