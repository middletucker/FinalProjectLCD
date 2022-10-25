/***************************************************************************//**
 * @file memlcd_app.c
 * @brief Memory Liquid Crystal Display (LCD) example functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
#include <stdio.h>

#include "sl_board_control.h"
#include "sl_simple_button_instances.h"
#include "em_assert.h"
#include "glib.h"
#include "dmd.h"

#include "blink.c"
#include "read.c"

/*******************************************************************************
 *******************************   DEFINES   ***********************************
 ******************************************************************************/

#ifndef BUTTON_INSTANCE_0
#define BUTTON_INSTANCE_0   sl_button_btn0
#endif

#ifndef BUTTON_INSTANCE_1
#define BUTTON_INSTANCE_1   sl_button_btn1
#endif

/*******************************************************************************
 ***************************  LOCAL VARIABLES   ********************************
 ******************************************************************************/
static GLIB_Context_t glibContext;
static int currentLine = 0;

long duration;
int distance;

int xdistance;

/*******************************************************************************
 **************************   GLOBAL FUNCTIONS   *******************************
 ******************************************************************************/

/***************************************************************************//**
 * Initialize example.
 ******************************************************************************/
void memlcd_app_init(void)
{
  uint32_t status;

  /* Enable the memory lcd */
  status = sl_board_enable_display();
  EFM_ASSERT(status == SL_STATUS_OK);

  /* Initialize the DMD support for memory lcd display */
  status = DMD_init(0);
  EFM_ASSERT(status == DMD_OK);

  /* Initialize the glib context */
  status = GLIB_contextInit(&glibContext);
  EFM_ASSERT(status == GLIB_OK);

  glibContext.backgroundColor = White;
  glibContext.foregroundColor = Black;

  /* Fill lcd with background color */
  GLIB_clear(&glibContext);

  /* Use Narrow font */
  GLIB_setFont(&glibContext, (GLIB_Font_t *) &GLIB_FontNarrow6x8);


  sprintf("Distance = %ld m\r\n", distance);

  if (xdistance < 128)
    {
      GLIB_drawPixel(&glibContext, xdistance, distance);
       xdistance++;
    }

  GLIB_drawStringOnLine(&glibContext,
                          distance,
                          currentLine = 7,
                          GLIB_ALIGN_RIGHT,
                          1,
                          1,
                          true);
  DMD_updateDisplay();

}
void set_leds()
 {
   //if distance > a enter em1/2
   //if distance < x turn on led0
   //if distance < y < x enter sleep mode

   if (distance > 15) {
     // exit em4
     sl_led_turn_on(&sl_led_led1);

   }
   /*else if (distance > 20) {
     // turn led off, enter em2
     sl_led_turn_off(&sl_led_led1);

   } else if (distance < 30)
   {
       //exit em2
   } else if (distance < 10)
   {
         //enter em4
   }
 */

 }
/***************************************************************************//**
 * Ticking function.
 ******************************************************************************/
void memlcd_app_process_action(void)
{
  return;
}

/***************************************************************************//**
 * Callback on button change.
 *
 * This function overrides a weak implementation defined in the simple_button
 * module. It is triggered when the user activates one of the buttons.
 *
 ******************************************************************************/
void sl_button_on_change(const sl_button_t *handle)
{
  if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED) {
    if (&BUTTON_INSTANCE_0 == handle) {
      currentLine = 0;
      GLIB_clear(&glibContext);
    } else if (&BUTTON_INSTANCE_1 == handle) {
      GLIB_drawStringOnLine(&glibContext,
                            "Hello World!",
                            currentLine++,
                            GLIB_ALIGN_LEFT,
                            5,
                            5,
                            true);
    }
    DMD_updateDisplay();
  }
}

