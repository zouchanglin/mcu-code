#include <REGX51.H>
#include <INTRINS.H>
#include <STRING.H>

#include "UART.h"
#include "LCD1602.h"
#include "Delay.h"
#include "ESP8266.h"

unsigned char i = 0;
unsigned char flag = 0;
unsigned char receive[50] = {'\0'};


// 收到数据触发中断
void UART_Routine() interrupt 4
{
    char res;
    res=SBUF;
    RI=0;
    if(res=='+'||i>0)
    {
        receive[i]=res;
        i++;
        if(res=='\n')
        {
			LCD_ShowNum(2,1,flag++,3);
			LCD_ShowString(2,4,receive);
			// 收到后做出响应【可选】,参数为客户端ID、内容、长度，注意都是字符串表示形式
			ESP8266_SendString("0", "ABC12345678", "11");
            i=0;
            //添加对收到信息的处理代码
            memset(receive,0,50);
        }
    }
}

void main()
{
	LCD_Init();
	UART_Init();
	ESP8266_Connect_Init();
	LCD_ShowString(1,1,"success");
	while(1)
	{
		
	}
}