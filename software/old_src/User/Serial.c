#include "main.h" // Device header
#include "Serial.h"
#include <stdio.h>
#include <stdarg.h>

#include <stdlib.h>

uint8_t Serial_RxData1;
uint8_t Serial_RxFlagOne;

uint8_t Serial_RxData3;
uint8_t Serial_RxFlag3;

void Serial_Init(void)
{
	// initialization of USART1 by stm32cubemx
}

void Serial_SendByteOne(uint8_t Byte)
{
	HAL_UART_Transmit(&huart1, &Byte, 1, HAL_MAX_DELAY);
}

void Serial_SendArray(uint8_t *Array, uint16_t Length)
{
	uint16_t i;
	for (i = 0; i < Length; i++)
	{
		Serial_SendByteOne(Array[i]);
	}
}

void Serial_SendStringOne(char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		Serial_SendByteOne(String[i]);
	}
}

uint32_t Serial_Pow(uint32_t X, uint32_t Y)
{
	uint32_t Result = 1;
	while (Y--)
	{
		Result *= X;
	}
	return Result;
}

void Serial_SendNumber(uint32_t Number, uint8_t Length)
{
	uint8_t i;
	for (i = 0; i < Length; i++)
	{
		Serial_SendByteOne(Number / Serial_Pow(10, Length - i - 1) % 10 + '0');
	}
}

int fputc(int ch, FILE *f)
{
	(void)f;
	Serial_SendByteOne(ch);
	return ch;
}

void Serial_Printf(char *format, ...)
{
	char String[100];
	va_list arg;
	va_start(arg, format);
	vsprintf(String, format, arg);
	va_end(arg);
	Serial_SendStringOne(String);
}

uint8_t Serial_GetRxFlagOne(void)
{
	if (Serial_RxFlagOne == 1)
	{
		Serial_RxFlagOne = 0;
		return 1;
	}
	return 0;
}

uint8_t Serial_GetRxDataOne(void)
{
	return RxBufferOne[0];
}
uint8_t Serial_GetRxData3(void)
{
	return Serial_RxData3;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART1)
	{
		// Process received data
		// Example: Echo received data
		HAL_UART_Transmit(&huart1, RxBufferOne, RxBufferOneSize, HAL_MAX_DELAY);
		Serial_RxFlagOne = 1;

		// Restart UART reception
		HAL_UART_Receive_IT(&huart1, RxBufferOne, RxBufferOneSize);
	}
}

// void USART1_IRQHandler(void)
// {
// 	if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET) // 判断是否是USART1的接收事件触发的中断
// 	{
// 		Serial_RxData1 = USART_ReceiveData(USART1);		// 读取数据寄存器，存放在接收的数据变量
// 		Serial_RxFlag1 = 1;								// 置接收标志位变量为1
// 		USART_ClearITPendingBit(USART1, USART_IT_RXNE); // 清除USART1的RXNE标志位
// 														// 读取数据寄存器会自动清除此标志位
// 														// 如果已经读取了数据寄存器，也可以不执行此代码
// 	}
// }
