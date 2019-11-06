#include <TimerOne.h>
#include <Wire.h>
#include <Zumo32U4.h>
Zumo32U4Motors motors;
Zumo32U4LCD lcd;
Zumo32U4LineSensors lineSensors;
Zumo32U4Encoders encoders;
Zumo32U4ButtonA buttonA;

void setup() {
  lineSensors.initFiveSensors();
  calibrateLineSensors();
   lcd.print(" READY");
  buttonA.waitForButton();
    lcd.clear();
   lcd.print(F("Lightnin"));
   lcd.gotoXY(0, 1);
   lcd.print("McQueen");
}

void calibrateLineSensors()
{
 // To indicate we are in calibration mode, turn on the yellow LED
 // and print "Line cal" on the LCD.
 ledYellow(1);
 lcd.clear();
 lcd.print(F("Line cal"));
 for (uint16_t i = 0; i < 400; i++)
 {
 lcd.gotoXY(0, 1);
 lcd.print(i);
 lineSensors.calibrate();
 }
 ledYellow(0);
 lcd.clear();
}



void loop(){ 
  
  uint16_t lineSensorValues[5] = { 0, 0, 0, 0, 0 };
  lineSensors.readCalibrated(lineSensorValues);  
  if(lineSensorValues[1] < 400 && lineSensorValues[3] > 400) {
     motors.setLeftSpeed(200);
     motors.setRightSpeed(200);
  }
  else if(lineSensorValues[1] > 400){
     motors.setLeftSpeed(-100);
     motors.setRightSpeed(200);
  }
  else if(lineSensorValues[1] < 400 && lineSensorValues[3] < 400){
     motors.setLeftSpeed(200);
     motors.setRightSpeed(-100);
  }
}
