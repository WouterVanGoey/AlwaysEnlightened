// This little program keeps your room always lit by turning on a light when the room darkens.
// Alternatively it can link one light to another in a room, turning them on and off together.

// You'll want to set up a servo so that it can somehow control the light switch of your lamp.
// When you've set up a servo to control the switch, you will want to find it's on/off positions.

// Upload Examples > Servo > Knob to your arduino. Add "Serial.begin(1200);" under void setup(){.
// Next add "Serial.print(val);" under void loop(){. Open the serial monitor to get your values.

int maxPos = 100;
int minPos = 28;

//  Set this to the room brightness you want your light to turn off at. Don't set this too low.

int maxBright = 400;

#include <Servo.h> 
#include <TinkerKit.h>

TKLightSensor ldr(I0);   // If neccesary change I0 to the pin you hooked your light sensor up to.

int pos;
boolean lightison;

Servo myservo;

void setup() 
{ 
  myservo.attach(11);
  Serial.begin(1200);
  myservo.write(maxPos);
  delay(5000);
}

void loop()

{
  Serial.print("--------------");
  
  int brightVal = ldr.read();
  
// You can check the light sensor and servo values. Make sure the serial monitor is set at 1200.
  Serial.print("brightness = " );    
  Serial.println(brightVal);   
  Serial.print("servo position = " );
  Serial.println(pos);  

//  Switch "lightoff();" and "lighton();" to change to the mode where lights turn on/off together.

  if(brightVal >= maxBright)
  {
    lightoff();   // Turns off your light
    Serial.println("Light off");
  }
  else
  {
    lighton();   // Turns on your light
    Serial.println("Light on");
  }
  delay(10);                    
}

void lighton()
{
  if(!lightison)
  {
    for(pos = maxPos; pos>=minPos; pos -= 1)
    {
      myservo.write(pos); 
    }
  }
  lightison = true;
}

void lightoff()
{
  if(!!lightison)
  {
    for(pos = minPos; pos < maxPos; pos += 1)
    {
      myservo.write(pos); 
    }
  }
  lightison = false;    
}

////////////////////////////
// Made by Wouter Van Goey//
////////////////////////////
