
/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest
  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.
    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app
  Blynk library is licensed under MIT license
  This example code is in public domain.
 *************************************************************
  =>
  =>          USB HOWTO: http://tiny.cc/BlynkUSB
  =>
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT DebugSerial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


// You could use a spare Hardware Serial on boards that have it (like Mega)
#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "vWYp-ZYRUt75KwfwPbhs8QSR8eOtK36t";

BlynkTimer timer;
String s;    //to store incoming text ingredient
bool Voice;
bool Switch_T;
bool Switch;
bool State;
bool State_V;

BLYNK_WRITE(V0)     // it will run every time a string is sent by Blynk app
{
  s=param.asStr();
  Serial.print(s); //string sent by Blynk app will be printed on Serial Monitor
   if(s=="on" && State == false)
  {
    State = true;      //Pin 7 has been set in setup()
  }
  else if(s=="off")
  {
    State = false;
  }
  else{
    Serial.print("Say on or off");
  }
}


void setup()
{
  pinMode(7,OUTPUT); 
  pinMode(5,OUTPUT);
  pinMode(6,INPUT);
  // Debug console
  DebugSerial.begin(9600);
  timer.setInterval(1L, switchhh);

  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}

void switchhh(){
    Switch = digitalRead(6);
  if (Switch != Switch_T){
      State = !State;
    }
      digitalWrite (7,State);
      Switch_T = Switch;
  }

void loop()
{
  
  
  Blynk.run();
  timer.run();

  
  

  
}

