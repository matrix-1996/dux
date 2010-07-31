
/*
 * This code is based on information from
 * http://www.nondot.org/sabre/os/files/Communication/ser_port.txt
 */

#include <metodo/metodo.h>
#include <metodo/hal/serial.h>

void UartSend(char c)
{
	if (c == '\n')
		UartSend_int('\r');
	UartSend_int(c);
}

static void UartSend_int(char c)
{
	/* wait until UART is ready to send */
	while ((HalInPort(UART_BASE_REGISTER + LineStatus) & THRE) == 0);

	HalOutPort(UART_BASE_REGISTER, (uint8_t)c);
}

int UartInit()
{
	HalOutPort(UART_BASE_REGISTER + LineControl, DLAB);
	HalOutPort(UART_BASE_REGISTER, UART_BAUDRATE_DIVISOR);
	HalOutPort(UART_BASE_REGISTER + LineControl, UART_LCR);
	HalOutPort(UART_BASE_REGISTER + ModemControl, 0);

	return 0;
}

struct DisplayDevice UartDisplayDevice = {
	.Init		= (void*)UartInit,
	.DisplayChar	= (void*)UartSend,
	.DisplayClear	= NULL,	/* nothing, for now */
};
