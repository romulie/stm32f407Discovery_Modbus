/*
 * debug_printf.h
 *
 *  Created on: May 22, 2025
 *      Author: User
 */

#ifndef APP_DEBUG_PRINTF_H_
#define APP_DEBUG_PRINTF_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdarg.h>

#define DEBUGPRINTF_BUF_LEN		(256u)

//debug_printf sends a max of 256 characters to the ITM SWO trace debugger
//It uses a _variable length argument_, same as normal printf
//Indeed, just call this function as if it was printf, and you'll get the behaviour you expect
//I also like doing it this way since I can change the definition of the function as needed
void debug_printf(const char *fmt, ...);



#endif /* APP_DEBUG_PRINTF_H_ */
