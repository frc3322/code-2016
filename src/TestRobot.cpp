/*
 * TestRobot.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: Miles
 */
#include "TestRobot.h"
#include "Robot.h"

TestRobot::TestRobot(void){

}

void TestRobot::runTest(){
	//test drivetrain talons
		if(Robot::drivetrain->driveSRX1->GetTemperature() == 0){
			SmartDashboard::PutBoolean("DriveSRX1 fault",true);
		}
		if(Robot::drivetrain->driveSRX2->GetTemperature() == 0){
			SmartDashboard::PutBoolean("DriveSRX2 fault",true);
		}
		if(Robot::drivetrain->driveSRX3->GetTemperature() == 0){
			SmartDashboard::PutBoolean("DriveSRX3 fault",true);
		}
		if(Robot::drivetrain->driveSRX4->GetTemperature() == 0){
			SmartDashboard::PutBoolean("DriveSRX4 fault",true);
		}

		//test intake talons
		if(Robot::intake->intakeRotateTalon1->GetTemperature() == 0){
			SmartDashboard::PutBoolean("IntakeRotateTalon1 fault",true);
		}
		if(Robot::intake->intakeRotateTalon2->GetTemperature() == 0){
			SmartDashboard::PutBoolean("IntakeRotateTalon2 fault",true);
		}
		if(Robot::intake->intakeSpinTalon1->GetTemperature() == 0){
			SmartDashboard::PutBoolean("IntakeSpinTalon1 fault", true);
		}
		if(Robot::intake->intakeSpinTalon2->GetTemperature() == 0){
			SmartDashboard::PutBoolean("IntaakeSpinTalon2 fault",true);
		}

		//test Cat. A talons
		if(Robot::catA->catA1->GetTemperature() == 0){
			SmartDashboard::PutBoolean("CatA1 fault",true);
		}
		if(Robot::catA->catA2->GetTemperature() == 0){
			SmartDashboard::PutBoolean("CatA2 fault",true);
		}
}
void TestRobot::resetSmartDashboard(){
		SmartDashboard::PutBoolean("DriveSRX1 fault",false);
		SmartDashboard::PutBoolean("DriveSRX2 fault",false);
		SmartDashboard::PutBoolean("DriveSRX3 fault",false);
		SmartDashboard::PutBoolean("DriveSRX4 fault",false);

		SmartDashboard::PutBoolean("IntakeRotateTalon1 fault",false);
		SmartDashboard::PutBoolean("IntakeRotateTalon2 fault",false);
		SmartDashboard::PutBoolean("IntakeSpinTalon1 fault", false);
		SmartDashboard::PutBoolean("IntakeSpinTalon2 fault", false);
		SmartDashboard::PutBoolean("CatA1 fault",false);
		SmartDashboard::PutBoolean("CatA2 fault",false);
}
