//*******************************************************************
/*!
\file   config.h
\author Thomas Breuer
\date   23.02.20232
\brief  Board specific configuration
*/

//*******************************************************************
/*
Board:    STM32-Nucleo32-L432

\see STM32-Nucleo32-L432/board_pinout.txt
*/

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//
// SETUP:
// ======


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//*******************************************************************
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
Timer_Mcu timerPwm(Timer_Mcu::TIM_2,100);		//
AnalogOutPWM motor(timerPwm, Timer::NORMAL,0);	//Motor Pin1
AnalogOutPWM rmotor(timerPwm, Timer::NORMAL,1); //Motor Pin2

AnalogOutPWM servo(timerServo, Timer::NORMAL,0); //PWM Signal
//-------------------------------------------------------------------
// Digital
//-------------------------------------------------------------------
Digital    led_A( portB, 3, Digital::Out,  0 ); // LD3 (green)
Digital    btn_A( portB, 4, Digital::InPU, 1 ); // BTN (ext)
