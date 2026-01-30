RC Car Project build on STM32l432KC with STM32CubeIDE 2.0.0

Unfinished:

Cable powered and cable controlled.

Optional:

Bluetooth or WiFi Module and Battery.

Used Components: 

Servo MG996R Metal Gear Servo Motor

datasheet: https://www.handsontec.com/dataspecs/motor_fan/MG996R.pdf 

DC Motor

Breadboard

Custom Nucleo Dev Kit

L293DNE Motor Driver

Custom Motor Driver Shield


![IMG_9482](https://github.com/user-attachments/assets/eec2511d-0b66-4d34-ac21-b3d26334befc)


Main in Src\Main.cpp 
```cpp
#include <stdio.h>
#include "EmbSysLib.h"

//-------------------------------------------------------------------
#include "ReportHandler.h"
#include "config.h"

//*******************************************************************
enum class Ms {Stop,F,B};  //Efficient State Machine which handles the input
enum class S {L,R,S};

int main(void)
{
  terminal.printf( "\r\n\nDemo/LED," __DATE__ "," __TIME__ "\r\n\n" );


Ms Ms = Ms::Stop;
S S = S::S;
            
while(1){

	  int k = terminal.get();
	  if(k != -1){
	  switch(k){

	  case Terminal::UP:
		  if(Ms == Ms::Stop)
		  Ms = Ms::F;
		  else if (Ms == Ms::B)
			  Ms = Ms::Stop;
		  break;
	  case Terminal::DOWN:
	      if (Ms == Ms::Stop)
	          Ms = Ms::B;
	      else if (Ms == Ms::F)
	          Ms = Ms::Stop;
	      break;
	  case Terminal::RIGHT:
		  if (S == S::S)
		 	          S = S::R;
		 	      else if (S == S::L)
		 	          S = S::S;
	 		  break;
	  case Terminal::LEFT:
		  if (S == S::S)
		  	S = S::L;
		  else if (S == S::R)
			  S = S::S;
	 		  break;

	  }
	  }

	 switch(Ms){

	 case Ms::F:
		 motor.set(0.4);
		 rmotor.set(0);
		 break;
	 case Ms::B:
	 		 motor.set(0);
	 		 rmotor.set(0.4);
	 		 break;
	 case Ms::Stop:
	 		 motor.set(0);
	 		 rmotor.set(0);
	 		 break;
	 }
	 switch(S){

	 	 case S::L:
	 		 servo.set(0.055);
	 		 break;
	 	 case S::R:
	 	 		servo.set(0.090);
	 	 		 break;
	 	 case S::S:
	 	 		 servo.set(0.075);
	 	 		 break;



	  }
__WFI();
  }
```
config.h in Src\Board\STM32-Nucleo32-L432\config.h
```c
using namespace EmbSysLib::Hw;
using namespace EmbSysLib::Dev;
using namespace EmbSysLib::Ctrl;
using namespace EmbSysLib::Mod;

//*******************************************************************
PinConfig::MAP PinConfig::table[] =
{
  // UART
  USART2_TX_PA2,
  USART2_RX_PA15,
  TIM1_CH1_PA8,
  TIM2_CH1_PA0,
  TIM2_CH2_PA1,

  END_OF_TABLE
};

//-------------------------------------------------------------------
// Port
//-------------------------------------------------------------------
Port_Mcu   portB( Port_Mcu::PB );

//-------------------------------------------------------------------
// UART
//-------------------------------------------------------------------
Uart_Mcu   uart ( Uart_Mcu::USART_2, 9600, 255, 255 );

Terminal   terminal( uart, 255,255,"# +" ); //Keyboard input
Timer_Mcu timerServo(Timer_Mcu::TIM_1,20000); //Servo timer
Timer_Mcu timerPwm(Timer_Mcu::TIM_2,100);		//Motor Timer(Ignore the wrong name)
AnalogOutPWM motor(timerPwm, Timer::NORMAL,0);	//Motor Pin1
AnalogOutPWM rmotor(timerPwm, Timer::NORMAL,1); //Motor Pin2

AnalogOutPWM servo(timerServo, Timer::NORMAL,0); //PWM Signal
```
