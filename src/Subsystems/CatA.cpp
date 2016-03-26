// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "CatA.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

CatA::CatA() : Subsystem("CatA") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    catA1 = RobotMap::catACatA1;
    catA2 = RobotMap::catACatA2;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    double lastError;
    double setpoint;
    double iTerm;
}
void CatA::init(){
	catA1->Enable();
	catA2->Enable();
	catA2->SetEncPosition(0);
}

/*void CatA::setPosition(int setpoint,float p,float i,float d,float f){

//	RobotMap::intakeEncoder->Reset();
	catA1->SetPID(p,i,d,f);
	catA2->SetPID(p,i,d,f);
	catA1->Enable();
	catA2->Enable();
	catA1->SetSetpoint(setpoint);
	catA2->SetSetpoint(setpoint);
}*/

void CatA::armPosinit() {
	int posArr[5];
	int replaceArr = 0;
	for(int i=0; i<5; ++i) {
		posArr[i] = static_cast<int>(RobotMap::pot->Get());
	}
}
int CatA::armPos(int pos) {
	posArr[replaceArr] = static_cast<int>(RobotMap::pot->Get()); //bottom = 578, top = 660
	++replaceArr;
	replaceArr = replaceArr%5;
	int armPos = 0;
	for (int i=0; i<5; i++) {
		armPos = armPos + posArr[i];
	}
	return static_cast<int>(armPos/5);
}

void CatA::moveArm() {
	catA2->Set(computePID(setpoint, armPos(static_cast<int>(RobotMap::pot->Get())), .05, 0, 0, 0)); //test PID values
	SmartDashboard::PutNumber("Setpoint", setpoint);
}

void CatA::chivelDeFrise(){
	//catA2->Set(CatA::calculatePID(0,catA2->GetEncPosition(),.02,0,.08));   //1350, 480
	setpoint = 592; //change as needed, approximated to be right above the chivel de frise
}

void CatA::portcollisInit(){
	setpoint = 580; //change as needed, approximated to be right above the carpet
}

void CatA::portcollisLift(){
	setpoint = 580; //change as needed, approximated to be raised as high as possible w/out hitting robot
}

void CatA::lower() {
	catA1->Set(.3);
	catA2->Set(-.3);
}

void CatA::stop() {
	catA1->Set(0);
	catA2->Set(0);
}

void CatA::initPID() {
	iTerm = 0;
	lastError = setpoint - catA2->GetEncPosition();
}
double CatA::computePID(double target, double potPos, double kP, double kI, double kD, double decay) {
		double error = target - potPos; //assuming 200 is where robot starts
        double pTerm = error * kP;
        iTerm = iTerm * decay + error * kI;
        double dTerm = (lastError - error) * kD;
        lastError = error;
        double power = pTerm + iTerm + dTerm;
        return power;
}

void CatA::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

