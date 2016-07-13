/*
 * LEDControl.cpp
 *
 *  Created on: Jun 15, 2016
 *      Author: snekiam
 *	i2c communication with an Arduino
 *	to control our invisible LEDs
 *	Passes different signals for Red/Blue alliance
 *	Also passes different signals for teleop, auto, and disabled
 *
 */

#include "Robot.h"
#include "LEDControl.h"
void LEDControl::initialize(I2C i2c){
	//LEDControl::i2c = i2c;
}
void LEDControl::sendAlliance(){
	switch(DriverStation::GetInstance().GetAlliance()){
	case 1:
		alliance[0] = red;
		break;
	case 2:
		alliance[0] = blue;
		break;
	default:
		alliance[0] = none;
		break;
	}
	i2c.Transaction(alliance,1,NULL,0);
}
void LEDControl::setMode(int state){
	switch(state){
		case 0:
			mode[0] = auton;
			break;
		case 1:
			mode[0] = teleop;
			break;
		default:
			mode[0] = disabled;
			break;
	}
	i2c.Transaction(mode,1,NULL,0);
}
