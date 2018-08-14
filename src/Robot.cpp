/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "WPILib.h"
#include "ctre/Phoenix.h"

#include "Drive/DifferentialDrive.h"

#include <iostream>

#include <SmartDashboard/SmartDashboard.h>


class Robot: public IterativeRobot
{
public:
	XboxController *stick = new XboxController (0);
	WPI_TalonSRX * frontRight = new WPI_TalonSRX(0);
	WPI_TalonSRX * rearRight = new WPI_TalonSRX(3);
	WPI_TalonSRX * frontLeft = new WPI_TalonSRX(1);
	WPI_TalonSRX * rearLeft = new WPI_TalonSRX(2);
	DifferentialDrive *myRobot = new DifferentialDrive{*frontLeft, *frontRight};
	int autoLoopCounter = 0;
	Robot()
	{


	}
	void RobotInit()
	{
	rearRight->Follow(*frontRight);
	rearLeft->Follow(*frontLeft);
	rearRight->SetInverted(false);
	rearLeft->SetInverted(false);
	frontRight->SetInverted(false);
	frontLeft->SetInverted(false);


	}

	void AutonomousInit()
	{
		autoLoopCounter = 0;
	}

	void AutonomousPeriodic()
	{
		if(autoLoopCounter < 100)
		{
			myRobot->TankDrive(0.1, 0.1);
			autoLoopCounter++;
		}else{
			myRobot->TankDrive(0, 0);
		}
	}
	void TeleopInit()
	{

	}
	void TeleopPeriodic()
	{
		myRobot->TankDrive(stick->GetRawAxis(1), stick->GetRawAxis(5));
	}


};
START_ROBOT_CLASS(Robot)
