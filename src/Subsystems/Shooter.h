// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Shooter: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<CANTalon> shooterBackTalon;
	std::shared_ptr<Encoder> frontWheelEncoder;
	std::shared_ptr<PIDController> frontWheelPID;
	std::shared_ptr<CANTalon> shooterFrontTalon;
	std::shared_ptr<Encoder> backWheelEncoder;
	std::shared_ptr<PIDController> backWheelPID;

public:
	Shooter();
	void InitDefaultCommand();
	void shootRaw();
	void initShooter();
	void stopShooter();
	void testPID(float setpointFront, float setpointRear, double pF, double iF, double dF, double pR, double iR, double dR);
	int returnVel();
	float returnVoltVal();
	float returnAmpVal();
};

#endif