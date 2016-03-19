// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include <math.h>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<Drivetrain> Robot::drivetrain;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Intake> Robot::intake;
std::shared_ptr<CatA> Robot::catA;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<TestRobot> testRobot;
bool prevRBumperState;

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    drivetrain.reset(new Drivetrain());
    shooter.reset(new Shooter());
    intake.reset(new Intake());
    catA.reset(new CatA());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    testRobot.reset(new TestRobot());
    // This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());
	autonomousCommand.reset(new autonCommand());
	ahrs = RobotMap::ahrs;
	Robot::drivetrain->gearShift(0);
	Robot::drivetrain->currentGear=0;

	SmartDashboard::PutNumber("Auton Number: ",0);

	//Talon SRX 15 mode bug
	Robot::drivetrain->EnableSRX();
	Robot::shooter->initShooter();
	Robot::intake->init();
	RobotMap::ahrs->ZeroYaw();
//	CameraServer::GetInstance()->StartAutomaticCapture("cam0");
}

void clearStickyFaults() {
	RobotMap::drivetraindriveSRX1->ClearStickyFaults();
	RobotMap::drivetraindriveSRX2->ClearStickyFaults();
	RobotMap::drivetraindriveSRX3->ClearStickyFaults();
	RobotMap::drivetraindriveSRX4->ClearStickyFaults();

	RobotMap::shootershooterTalon1->ClearStickyFaults();
	RobotMap::shootershooterTalon2->ClearStickyFaults();

	RobotMap::intakeintakeSpinTalon1->ClearStickyFaults();
	RobotMap::intakeintakeSpinTalon2->ClearStickyFaults();
	RobotMap::intakeintakeRotateTalon1->ClearStickyFaults();
	RobotMap::intakeintakeRotateTalon2->ClearStickyFaults();

	RobotMap::catACatA1->ClearStickyFaults();
	RobotMap::catACatA2->ClearStickyFaults();
}

/**
 *
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */

void Robot::DisabledInit(){
	clearStickyFaults();
	Robot::drivetrain->EnableSRX();
	Robot::shooter->initShooter();  //do we need this (see line 49)
	Robot::catA->init();
	if(SmartDashboard::GetBoolean("Test Talons",false)){
		Robot::testRobot->runTest();
	}
	else{
		Robot::testRobot->resetSmartDashboard();
	}
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();
	SmartDashboard::PutNumber("intake encoder dist",RobotMap::intakeEncoder->GetDistance());

	if(Robot::oi->getdriveStick()->GetRawButton(XBOX::ABUTTON)){
		RobotMap::intakeEncoder->Reset();
	}
	Robot::LogNavXValues();
	SmartDashboard::PutNumber("ticks ",Robot::shooter->shooterFrontTalon->GetEncPosition());
	SmartDashboard::PutNumber("Category A ticks",Robot::catA->catA2->GetEncPosition());
}

void Robot::AutonomousInit() {
	Robot::drivetrain->EnableSRX();
//	Robot::shooter->initShooter();
//	Robot::intake->init();
//	Robot::drivetrain->autoShift();
//	std::thread autoShiftthread(autoShift);
	Robot::toggleIntakeOff();
	RobotMap::intakeEncoder->Reset();
	SmartDashboard::PutNumber("thing happened! ",0);
	Robot::ahrs->ZeroYaw();
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();

}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
	Robot::LogNavXValues();


}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();
	Robot::drivetrain->EnableSRX();
	Robot::shooter->initShooter();
	Robot::intake->init();
//	Robot::drivetrain->autoShift();
//	std::thread autoShiftthread(autoShift);
	prevRBumperState = false;
	prevLBumperState = false;
	Robot::toggleIntakeOff();
	RobotMap::intakeEncoder->Reset();
	SmartDashboard::PutNumber("thing happened! ",0);
	Robot::ahrs->ZeroYaw();
}

void Robot::LogNavXValues(){
	SmartDashboard::PutNumber("Angle", RobotMap::ahrs->GetAngle());
	SmartDashboard::PutNumber("Temperature (degrees celcius)", RobotMap::ahrs->GetTempC());
	SmartDashboard::PutNumber("Yaw (z axis rotation,-180 to 180)",RobotMap::ahrs->GetYaw());
}

void Robot::LogHTMLDashboardValues() {
	SmartDashboard::PutBoolean("highGear", drivetrain->isInHighGear);
	SmartDashboard::PutNumber("encoder1",RobotMap::intakeEncoder->GetDistance());
	SmartDashboard::PutNumber("encoder2",Robot::catA->catA2->GetEncPosition());
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
	cycleStartTime = Timer::GetFPGATimestamp();
	//slaving the second rotate talon
	Robot::intake->intakeRotateTalon2->Set(3);
	//ahrs (NavX) testing.  Should be disabled / commented out during competitions to reduce overhead
//	Robot::LogNavXValues();

	SmartDashboard::PutNumber("encoder dist",RobotMap::intakeEncoder->GetDistance());
	SmartDashboard::PutNumber("vel",Robot::shooter->returnVel());
//	Robot::drivetrain->driveToAngle(Robot::oi->gettechStick()->GetY());
	Robot::drivetrain->getDrive()->ArcadeDrive(Robot::oi->getdriveStick()->GetY(),-1*Robot::oi->getdriveStick()->GetRawAxis(4),true);


	if(Robot::oi->gettechStick()->GetRawButton(XBOX::LBUMPER)){
		Robot::intake->takeBallIn();
	}
	if(Robot::oi->getdriveStick()->GetRawButton(XBOX::LBUMPER)){
		Robot::catA->catA1->Set(-.5);
		Robot::catA->catA2->Set(.5);
	}
	else if(Robot::oi->getdriveStick()->GetRawButton(XBOX::RBUMPER)){
		Robot::catA->catA1->Set(.5);
		Robot::catA->catA2->Set(-.5);
	}
	else{
		Robot::catA->catA1->Set(0);
		Robot::catA->catA2->Set(0);
	}
//	prevRBumperState = Robot::oi->getdriveStick()->GetRawButton(XBOX::RBUMPER);
//	prevLBumperState = Robot::oi->getdriveStick()->GetRawButton(XBOX::LBUMPER);
//	if(Robot::oi->getdriveStick()->GetRawButton(XBOX::BACK)){
//		Robot::shooter->testPID(256*1200);
//	}
//	else if(Robot::oi->getdriveStick()->GetRawButton(XBOX::START)){
//		Robot::shooter->stopShooter();
//	}

	if(Robot::oi->getdriveStick()->GetRawButton(XBOX::ABUTTON)){
		Robot::drivetrain->gearShift(1);
	}
	else {
		Robot::drivetrain->gearShift(0);
	}

	if(Robot::oi->gettechStick()->GetRawButton(XBOX::RBUMPER)){
		holdingBall = false;
		loadingBall = false;
		grabbingBall = false;

		if(RobotMap::intakeEncoder->Get()<50){
			Robot::intake->stopIntakeSpinners();
		}

		if(Robot::oi->gettechStick()->GetRawButton(XBOX::LSTICKP)){
			Robot::intake->intakeRotateTalon1->Set(-1);
		}
		else if(Robot::oi->gettechStick()->GetRawButton(XBOX::RSTICKP)){
			Robot::intake->intakeRotateTalon1->Set(1);

		}
		else{
			Robot::intake->intakeRotateTalon1->Set(0);
		}

	}
	if(Robot::oi->gettechStick()->GetRawButton(XBOX::ABUTTON)){
		Robot::shooter->testPID(11.23);
	}
	if (Robot::oi->gettechStick()->GetRawButton(XBOX::BBUTTON) || holdingBall){
		toggleIntakeOff();
		holdingBall = true;
		Robot::intake->holdBall();
	}
	if(Robot::oi->gettechStick()->GetRawButton(XBOX::XBUTTON) && isFirstGather){
		isFirstGather = false;
		toggleIntakeOff();
		loadingBall = true;
		Robot::intake->loadingBall(cycleStartTime);
		loadStartTime = cycleStartTime;
	}
	if(Robot::intake->intakeDone){
		resetIntake();
	}
	if(Robot::oi->gettechStick()->GetRawButton(XBOX::YBUTTON) || grabbingBall){
		Robot::toggleIntakeOff();
		grabbingBall = true;
		Robot::intake->grabBall();
	}
	if(!isFirstGather && loadingBall){
		Robot::intake->loadingBall(loadStartTime);
	}
	if(Robot::oi->gettechStick()->GetRawButton(XBOX::ABUTTON)){
		Robot::intake->readyToShoot = true;
	}

	if(Robot::intake->readyToShoot){
		Robot::shooter->testPID(11.23);
	}

	if(Robot::oi->gettechStick()->GetRawButton(XBOX::START)){
		isFirstGather = true;
		RobotMap::intakeEncoder->Reset();
	}
//	if(Robot::oi->gettechStick()->GetRawButton(XBOX::BACK) || secondaryHold){
//		Robot::resetIntake();
//		Robot::intake->intakeRotateTalon1->Set(Robot::intake->calculatePID(122,RobotMap::intakeEncoder->Get(),.02,0,.08));
//		Robot::secondaryHold = true;
//	}
//	if(Robot::oi->gettechStick()->GetRawButton(XBOX::BACK)){
//		Robot::catA->chivelDeFrise();
//	}
}


void Robot::TestPeriodic() {
	lw->Run();
}
void Robot::resetIntake(){
	isFirstGather = true;
}
void Robot::toggleIntakeOff(){
	grabbingBall = false;
	loadingBall = false;
	holdingBall = false;
	secondaryHold = false;
	Robot::shooter->stopShooter();
	Robot::intake->stopIntakeSpinners();
}

START_ROBOT_CLASS(Robot);
