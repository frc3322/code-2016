/*
 * LEDControl.h
 *
 *  Created on: Jun 15, 2016
 *      Author: sneki
 */

#ifndef SRC_LEDCONTROL_H_
#define SRC_LEDCONTROL_H_
#include "Robot.h"
class LEDControl{
private:
	uint8_t alliance[1];
	uint8_t mode[1];

	I2C i2c;
	int blue = 0;
	int red = 1;
	int none = 2;

	int teleop = 3;
	int auton = 4;
	int disabled = 5;

public:
	void initialize(I2C i2c);
	void sendAlliance();
	void setMode(int mode);
};
#endif /* SRC_LEDCONTROL_H_ */
