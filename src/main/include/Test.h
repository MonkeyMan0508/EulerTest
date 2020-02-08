#pragma once

#include <string>
#include <frc/WPILib.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#include <frc/Servo.h>
#include <frc/AnalogInput.h>
#include <AHRS.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/smartdashboard/SendableChooser.h>

#define servoOpen     90
#define servoClosed   125

using namespace frc;
using namespace rev;

class Robot : public TimedRobot {
  public:
    void RobotInit() override;
    void RobotPeriodic() override;
    void AutonomousInit() override;
    void AutonomousPeriodic() override;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;
    double DeadZone(double speed, double zone);

    const int TALON = 5, SPARK = 7, SERVO = 0, POT1 = 0, POT2 = 3, PROX1 = 1, PROX2 = 2;

  private:
    rev::CANSparkMax *spark;
    rev::CANEncoder *sparkEncoder;
    WPI_TalonSRX *talon;
    Servo *servo;
    AnalogPotentiometer *pot1;
	AnalogPotentiometer *pot2;
	AnalogInput *prox1;
	AnalogInput *prox2;
    XboxController *xbox;
};
