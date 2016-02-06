// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Drivetrain.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    driveSRX1 = RobotMap::drivetraindriveSRX1;
    driveSRX2 = RobotMap::drivetraindriveSRX2;
    driveSRX3 = RobotMap::drivetraindriveSRX3;
    driveSRX4 = RobotMap::drivetraindriveSRX4;
    driveTrain = RobotMap::drivetraindriveTrain;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

}
std::shared_ptr<RobotDrive> Drivetrain::getDrive() {

	return driveTrain;
}


void Drivetrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Drivetrain::enableSRX(){
	Drivetrain::driveSRX1->Enable();
	Drivetrain::driveSRX2->Enable();
	Drivetrain::driveSRX3->Enable();
	Drivetrain::driveSRX4->Enable();

}


// Put methods for controlling this subsystem
// here. Call these from Commands.
