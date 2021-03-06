#include <iostream>
#include "Test.h"

void Robot::RobotInit() {   
	xbox         = new frc::XboxController(0);
	spark        = new CANSparkMax(SPARK, CANSparkMax::MotorType::kBrushless);
	talon        = new WPI_TalonSRX(TALON);
	servo        = new Servo(SERVO);
	pot1         = new AnalogPotentiometer(POT1, 1.0, 0.0);
	pot2         = new AnalogPotentiometer(POT2, 1.0, 0.0);
	prox1		 = new AnalogInput(PROX1);
	prox2		 = new AnalogInput(PROX2);
	irSensor	 = new DigitalInput(IR_SENSOR);
    sparkEncoder = new CANEncoder(*spark);
}

void Robot::RobotPeriodic()  {
    TeleopPeriodic();
}

void Robot::AutonomousInit() {
    TeleopInit();
}

void Robot::AutonomousPeriodic() {
    
}

void Robot::TeleopInit() {
}

void Robot::TeleopPeriodic() {
    spark->Set(DeadZone(xbox->GetY(GenericHID::JoystickHand::kLeftHand), .25));
    talon->Set(DeadZone(xbox->GetY(GenericHID::JoystickHand::kRightHand), .25));
    if (xbox->GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand) > .1) {
        servo->SetAngle(servoOpen);
    } else {
        servo->SetAngle(servoClosed);
    }
	frc::SmartDashboard::PutNumber("pot1",  pot1->Get());
	frc::SmartDashboard::PutNumber("pot2",  pot2->Get());
	frc::SmartDashboard::PutNumber("prox1", prox1->GetVoltage());
	frc::SmartDashboard::PutNumber("prox2", prox2->GetValue());
	frc::SmartDashboard::PutNumber("ir_sensor", irSensor->Get());
}

void Robot::TestPeriodic() {
    TeleopPeriodic();
}

double Robot::DeadZone(double speed, double zone) {
    if (abs(speed) < zone) {
        return 0;
    }
    return speed;
}

#ifndef RUNNING_FRC_TESTS
int main()  { 
  return frc::StartRobot<Robot>();
}
#endif