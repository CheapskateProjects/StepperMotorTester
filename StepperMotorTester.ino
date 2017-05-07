/*
  Stepper motor tester

  This project uses Arduino and easy driver board to test stepper motors.

  Stepper motor is connected to the easy driver and 3 position (on/off/on) momentary toggle switch is used to control direction through Arduino. 

  Connections:
  pin2 -> toggle switch
  pin3 -> toggle switch
  pin8 -> easy driver direction
  pin9 -> easy driver step
  
  created   May 2017
  by CheapskateProjects

  ---------------------------
  The MIT License (MIT)

  Copyright (c) 2017 CheapskateProjects

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

int Stepping = false;

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}


void loop()
{
  if (digitalRead(3) == LOW)
  {
    digitalWrite(8, LOW);
    Stepping = true;
  }
  else if (digitalRead(2) == LOW)
  {
    digitalWrite(8, HIGH);
    Stepping = true;
  }
  else
  {
    Stepping = false;
  }

  if (Stepping == true)
  {
    digitalWrite(9, HIGH);
    delay(1);
    digitalWrite(9, LOW);
    delay(1);
  }
}

