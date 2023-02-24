//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
// This sketch is a good place to start if you're just getting started with
// Pixy and Arduino.  This program simply prints the detected object blocks
// (including color codes) through the serial console.  It uses the Arduino's
// ICSP SPI port.  For more information go here:
//
// https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:hooking_up_pixy_to_a_microcontroller_-28like_an_arduino-29
//

#include <Servo.h>
#include <Pixy2.h>

#define pblck pixy.ccc.blocks[i]

Servo horizontal;
Servo vertical;
float x = 90;
float y = 90;
float delta = 0.05;

// This is the main Pixy object
Pixy2 pixy;

void inc(float &x, float y)
{
  x += delta * y;
  if (x > 180)
  {
    x = 180;
  }
}

void dec(float &x, float y)
{
  x -= delta * y;
  if (x < 0)
  {
    x = 0;
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.print("Starting...\n");
  horizontal.attach(9);
  vertical.attach(10);
  pixy.init();
}

void loop()
{
  // grab blocks!
  pixy.ccc.getBlocks();
  int detected[4];

  // If there are detect blocks, print them!
  if (pixy.ccc.numBlocks)
  {
    detected[0] = -1;
    detected[1] = -1;
    detected[2] = 0;
    detected[3] = 0;
    Serial.print("Detected ");
    for (int i = 0; i < pixy.ccc.numBlocks; i++)
    {
      if (pixy.ccc.blocks[i].m_width * pixy.ccc.blocks[i].m_height > detected[2] * detected[3])
      {
        detected[0] = pixy.ccc.blocks[i].m_x;
        detected[1] = pixy.ccc.blocks[i].m_y;
        detected[2] = pixy.ccc.blocks[i].m_width;
        detected[3] = pixy.ccc.blocks[i].m_height;
        // Debug
        Serial.print("Block ");
        Serial.print(i);
        Serial.print(": ");
        Serial.print(pblck.m_signature);
        Serial.print(" (");
        Serial.print(pblck.m_x);
        Serial.print(",");
        Serial.print(pblck.m_y);
        Serial.print(") ");
        Serial.print(pblck.m_width);
        Serial.print("x");
        Serial.print(pblck.m_height);
        Serial.println();
        
      }

      if (detected[0] != -1 && detected[1] != -1)
      {
        if (detected[0] < 100)
          inc(x, abs(detected[0] - 100));
        else if (detected[0] > 200)
          dec(x, abs(detected[0] - 200));


        if (detected[1] < 66)
          dec(y, abs(detected[1] - 66));
        else if (detected[1] > 133)
          inc(y, abs(detected[1] - 133));
      }


      horizontal.write((int)x);
      vertical.write((int)y);
      Serial.println(y);
    }

    
  }
}
