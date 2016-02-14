// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Intake.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Intake::Intake() : Subsystem("Intake") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    intakeSpinTalon1 = RobotMap::intakeintakeSpinTalon1;
    intakeSpinTalon2 = RobotMap::intakeintakeSpinTalon2;
    intakeRotateTalon1 = RobotMap::intakeintakeRotateTalon1;
    intakeRotateTalon2 = RobotMap::intakeintakeRotateTalon2;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    intakeSpinTalon2->SetControlMode(CANSpeedController::kFollower);
    intakeSpinTalon2->Set(6);
    intakeRotateTalon2->SetControlMode(CANSpeedController::kFollower);
    intakeRotateTalon2->Set(8);
}

void Intake::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Intake::takeBallIn(){
	intakeSpinTalon1->Set(-1);
	intakeRotateTalon1->Set(-.4);
}