/*
 * debug_printf.c
 *
 *  Created on: May 22, 2025
 *      Author: User
 */

#include <stdint.h>

#include "stm32f4xx_hal.h"

#include "debug_printf.h"


// redefine weak _write() to send data through USB virual COM port
int _write(int file, char *ptr, int len) {

    //CDC_Transmit_FS((uint8_t*) ptr, len);

	for(size_t i = 0; i < len; i++)
	{
		ITM_SendChar(*ptr);
		ptr++;
	}

    return len;
}


//debug_printf sends a max of 256 characters to the ITM SWO trace debugger
//It uses a _variable length argument_, same as normal printf
//Indeed, just call this function as if it was printf, and you'll get the behaviour you expect
//I also like doing it this way since I can change the definition of the function as needed
void DebugPrintfItm(const char *fmt, ...)
{

  char buffer[DEBUGPRINTF_BUF_LEN];
  va_list args;
  va_start(args, fmt);
  vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);

  uint16_t i = 0;
  while(buffer[i] != '\0')
  {
    ITM_SendChar(buffer[i]);
    i++;
  }

}
