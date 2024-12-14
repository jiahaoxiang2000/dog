#ifndef __SERIAL_H
#define __SERIAL_H

#include <stdio.h>
#include "stdint.h"
#include "usart.h"

void Serial_Init(void);
void Serial_SendByteOne(uint8_t Byte);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendStringOne(char *String);
void Serial_SendNumber(uint32_t Number, uint8_t Length);
void Serial_Printf(char *format, ...);

uint8_t Serial_GetRxFlagOne(void);
uint8_t Serial_GetRxDataOne(void);

#endif
