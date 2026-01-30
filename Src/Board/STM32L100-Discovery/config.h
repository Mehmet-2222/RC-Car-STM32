//*******************************************************************
/*!
\file   config.h
\author Thomas Breuer
\date   23.02.2023
\brief  Board specific configuration
*/

//*******************************************************************
/*
Board:    STM32L100-Discovery

\see STM32L100-Discovery/board_pinout.txt
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
  USART1_TX_PA9,
  USART1_RX_PA10,

  END_OF_TABLE
};

//-------------------------------------------------------------------
// Port
//-------------------------------------------------------------------
Port_Mcu   portA( Port_Mcu::PA );
Port_Mcu   portC( Port_Mcu::PC );

//-------------------------------------------------------------------
// UART
//-------------------------------------------------------------------
Uart_Mcu   uart ( Uart_Mcu::USART_1, 9600, 100, 100 );

Terminal   terminal( uart, 255,255,"erw" );

//-------------------------------------------------------------------
// Digital
//-------------------------------------------------------------------
Digital    led_A   ( portC, 8, Digital::Out, 0 ); // LD4 (blue)
Digital    btn_A   ( portA, 0, Digital::In,  0 ); // B1 (user button)
