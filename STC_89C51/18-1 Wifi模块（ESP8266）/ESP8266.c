#include "Delay.h"
#include "UART.h"
#include "LCD1602.h"

// 初始化ESP8266
void ESP8266_Connect_Init()
{
    char *muxCmd="AT+CIPMUX=1\r\n";
    char *serverCmd="AT+CIPSERVER=1,8080\r\n";
	
	Delay(200);
    UART_SendString(muxCmd);
	Delay(200);
    UART_SendString(serverCmd);
}

// 发送到客户端，客户端ID，内容，内容长度
void ESP8266_SendString(char *clientId, char *str, char *length)
{	
	// 串口发送数据传出指令, AT+CIPSEND=0,10
	UART_SendString("AT+CIPSEND=");
	UART_SendString(clientId);
	UART_SendString(",");
	UART_SendString(length);
	UART_SendString("\r\n");
	Delay(100);
	UART_SendString(str);
	Delay(20);
}


