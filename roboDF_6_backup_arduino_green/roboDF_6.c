#pragma config(Sensor, S1,     ll,             sensorAnalogActive)
#pragma config(Sensor, S2,     mm,             sensorAnalogActive)
#pragma config(Sensor, S3,     rr,             sensorAnalogActive)
#pragma config(Sensor, S4,     ARDUINO,            sensorI2CCustom)
#pragma config(Motor,  motorA,          l,             tmotorNXT, PIDControl, reversed, encoder)
#pragma config(Motor,  motorC,          r,             tmotorNXT, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "dInclude.h"

task main()
{
	// Changed lulululul
	clearDebugStream();
	bool lastCornerVal[4];
	ClearTimer(T1);
	StartTask(Ard);
	delay(500); //let sensor init
	while (true)
	{
		Light[left] = SensorValue(ll);
		Light[mid] = SensorValue(mm);
		Light[right] = SensorValue(rr);
		if ((Light[left] < CalLeft) && (Light[mid] < CalMid) && (Light[right] > CalRight)) //Links
		{
			//writeDebugStream("Left:\t");
			nxtDisplayCenteredBigTextLine(1, "Left");
			//while((Light[left] < CalLeft)) {Light[left] = SensorValue(ll); writeDebugStreamLine("In While"); }
			lastCornerVal[0] = (Light[left] < CalLeft);
			lastCornerVal[1] = (Light[mid] < CalMid);
			lastCornerVal[2] = (Light[right] < CalRight);
			//ClearTimer(T1);
			delay(25);
			FastLeft();
			delay(100);
		}
		Light[left] = SensorValue(ll);
		Light[mid] = SensorValue(mm);
		Light[right] = SensorValue(rr);
		if ((Light[mid] < CalMid)) //Geradeaus
		{
			//writeDebugStream("Straight:\t");
			nxtDisplayCenteredBigTextLine(1, "Straight");
			Drive();
			delay(10);
		}
		Light[left] = SensorValue(ll);
		Light[mid] = SensorValue(mm);
		Light[right] = SensorValue(rr);
		if ((Light[left] > CalLeft) && (Light[mid] < CalMid) && (Light[right] < CalRight)) //Rechts
		{
			//writeDebugStream("Right:\t");
			nxtDisplayCenteredBigTextLine(1, "Right");
			//while((Light[right] < CalRight)) {Light[right] = SensorValue(rr); writeDebugStreamLine("In While"); }
			lastCornerVal[0] = (Light[left] < CalLeft);
			lastCornerVal[1] = (Light[mid] < CalMid);
			lastCornerVal[2] = (Light[right] < CalRight);
			//ClearTimer(T1);
			delay(25);
			FastRight();
			delay(100);
		}
		Light[left] = SensorValue(ll);
		Light[mid] = SensorValue(mm);
		Light[right] = SensorValue(rr);
		if ((Light[mid] < CalMid)) //Geradeaus
		{
			//writeDebugStream("Straight:\t");
			nxtDisplayCenteredBigTextLine(1, "Straight");
			Drive();
			delay(10);
		}
		//Altes Gr�n
		/*if ((Light[left] < CalLeft) && (Light[mid] < CalMid) && (Light[right] < CalRight))
		{
			nxtDisplayBigTextLine(5, "T1: %d", time1[T1]);
			if (time1[T1] > 400 && time1[T1] < 1300)
			{
				delay(200);
				if (lastCornerVal[0])
				{
					move(-drive, drive);
					delay(300);
					ClearTimer(T2);
					while (Light[mid] > CalMid || time1[T2] < 1000)
					{
						Light[mid] = SensorValue(mm);
					}
					if (time1[T2] > 1000)
					{
						move(drive, -drive);
						delay(800);
					}
				}
				else
				{
					move(drive, -drive);
					delay(300);
					ClearTimer(T2);
					while (Light[mid] > CalMid || time1[T2] < 1000)
					{
						Light[mid] = SensorValue(mm);
					}
					if (time1[T2] > 1000)
					{
						move(-drive, drive);
						delay(800);
					}
				}
			}
			//if(time1[T1]<1000 && lastCornerVal[0] == false && lastCornerVal[1] == true && lastCornerVal[2] == true)
			//{
			//	nxtDisplayCenteredBigTextLine(5,"GreenRight");
			//	delay(100);
			//	FastRight();
			//	while(SensorValue(mm) > CalMid) { }
			//	Drive();
			//}
			//if(time1[T1]<1000 && lastCornerVal[0] == true && lastCornerVal[1] == true && lastCornerVal[2] == false)
			//{
			//	nxtDisplayCenteredBigTextLine(5,"GreenLeft");
			//	delay(100);
			//	FastLeft();
			//	while(SensorValue(mm) > CalMid) { }
			//	Drive();
			//}
		}*/

		//Neues Gr�n
		/*if (leftGreen == true)
		{
			move(-drive, -drive, 50);
			move(0, 0);
			delay(100);
			if (vArGVal[lGreen] == ARDUINO_WHITE)
			{
				arduinoBeep = true;
				move(drive, drive, 330);   // Forward
				move(-drive, drive, 300);   // Forward
				move(-drive, drive);
				Light[mid] = SensorValue(mm);
				while (Light[mid] > CalMid)
				{
					Light[mid] = SensorValue(mm);
				}
				move(drive, drive);
			}
			else
			{
				move(drive, drive);
			}
		}*/
		if (rightGreen == true)
		{
			move(-drive, -drive, 50);
			move(0, 0);
			delay(100);
			if (vArGVal[rGreen] == ARDUINO_WHITE)
			{
				arduinoBeep = true;
				move(drive, drive, 330);   // Forward
				move(drive, -drive, 300);   // Forward
				move(drive, -drive);
				Light[mid] = SensorValue(mm);
				while (Light[mid] > CalMid)
				{
					Light[mid] = SensorValue(mm);
				}
				move(drive, drive);
			}
			else
			{
				move(drive, drive);
			}
		}
		/*	ClearTimer(T1);
		}
		if (time1[T1] < 500 && vArGVal[lGreen] == ARDUINO_BLACK)
		{
			move(drive, drive, 200);   // Forward
			move(-drive, drive, 300);   // Forward
			move(-drive, drive);
			Light[mid] = SensorValue(mm);
			while (Light[mid] > CalMid)
			{
				Light[mid] = SensorValue(mm);
			}
			move(drive, drive);
		}*/


		if (vArDVal[3] == ARDUINO_LOW) //Taster
		{
			move(-drive, -drive, 100); // Back
			move(drive, -drive, 220);  // Right
			move(drive, drive, 100);   // Forward
			move(obs_l, obs_r);        // Left
			Light[mid] = SensorValue(mm);
			while (Light[mid] > CalMid)
			{
				Light[mid] = SensorValue(mm);
			}
			move(drive, drive, 200);
			move(drive, -drive);
			Light[mid] = SensorValue(mm);
			while (Light[mid] > CalMid)
			{
				Light[mid] = SensorValue(mm);
			}
		}

		nxtDisplayCenteredTextLine(3, "%d|%d|%d", lastCornerVal[0], lastCornerVal[1], lastCornerVal[2]);
		nxtDisplayCenteredTextLine(4, "%d", time1[T1]);
		nxtDisplayCenteredBigTextLine(6, "l: %d|r: %d", leftGreen, rightGreen);
		//writeDebugStreamLine("%d | %d | %d", Light[left], Light[mid], Light[right]);
		//delay(10);
	}
}
