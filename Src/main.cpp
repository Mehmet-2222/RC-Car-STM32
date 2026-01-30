//*******************************************************************
/*!
\file   main.cpp
\author Thomas Breuer
\date   07.11.2022
\brief  Sample
*/

//*******************************************************************
/*
Used Configuration (see config.h):
        btn_A, led_A

Usage:
        Press and hold button A to switch on led A
*/

//*******************************************************************
#include <stdio.h>
#include "EmbSysLib.h"

//-------------------------------------------------------------------
#include "ReportHandler.h"
#include "config.h"

//*******************************************************************
enum class Ms {Stop,F,B};
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






 /* while( 1 )
  {


//V1
	  switch(terminal.get()){



	  case Terminal::UP:
		  terminal.printf("u\r\n");
		  motor.set(0.5);
		  rmotor.set(0);
		  break;

case Terminal::DOWN:
	terminal.printf("d\r\n");
		motor.set(0);
		rmotor.set(0);
		servo.set(0.075);
	  break;
case Terminal::SHIFT_CTRL:
	terminal.printf("ALT\r\n");
	motor.set(0);
	rmotor.set(0);

	  case Terminal::RIGHT:
		  terminal.printf("r\r\n");
		  servo.set(0.095);
	  break;

	  case Terminal::LEFT:
		  terminal.printf("l\r\n");
	 		  servo.set(0.05);
	 	  break;

	  }
    }*/
}
