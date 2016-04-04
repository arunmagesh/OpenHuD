/*

  HelloWorld.pde
  
  "Hello World!" example code.
  
  >>> Before compiling: Please remove comment from the constructor of the 
  >>> connected graphics display (see below).
  
  Universal 8bit Graphics Library, https://github.com/olikraus/u8glib/
  
  Copyright (c) 2012, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
  
*/


#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(10, 9);		// HW SPI Com: CS = 10, A0 = 9 (Hardware Pins are  SCK = 13 and MOSI = 11)


void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
 // u8g.setFont(u8g_font_unifont);
  u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 0, 22, "thgiL");
   u8g.setPrintPos(0, 44); 
   int a = analogRead(A0);
   a = map(a, 0 , 1024, 0 , 100);
   u8g.setPrintPos(14, 44); 
   u8g.print((int)a);  u8g.print("%");
   
   u8g.drawStr( 0, 66, "dnS");
      u8g.setPrintPos(0, 88);
   
   int b = analogRead(A1);
   b = map(b, 0 , 1024, 0 , 100);
    u8g.setPrintPos(14, 88); 
   u8g.print((int)b);  u8g.print("%");
   digitalWrite(2, LOW);
digitalWrite(3, LOW);
  
}
void ace(void) {
  // graphic commands to redraw the complete screen should be placed here  
 // u8g.setFont(u8g_font_unifont);
  u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 0, 22, "x:");
   u8g.setPrintPos(0, 44); 
   int a = analogRead(A2);
   a = map(a, 0 , 1024, -100 , 100);
   u8g.setPrintPos(20, 22); 
   u8g.print((int)a); 
   
   u8g.drawStr( 0, 44, "y:");
      u8g.setPrintPos(0, 44);
   
   int b = analogRead(A3);
   b = map(b, 0 , 1024, -100 , 100);
    u8g.setPrintPos(20, 44); 
   u8g.print((int)b);  
   digitalWrite(2, LOW);
digitalWrite(3, LOW);
 u8g.drawStr( 0, 66, "z:");
      u8g.setPrintPos(0, 66);
   
   int c = analogRead(A4);
   c = map(b, 0 , 1024, -100 , 100);
    u8g.setPrintPos(20, 66); 
   u8g.print((int)c);  
   digitalWrite(2, LOW);
digitalWrite(3, LOW);
  
}

void message(void) {
 u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 55, "========");
  u8g.drawStr( 0, 66, "|  __  |");
  u8g.drawStr( 0, 77, "|______|");  
  digitalWrite(2, LOW);
digitalWrite(3, LOW);
 
   
}
void left(void) {
 
 u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 0, 55, " <<<");
  u8g.drawStr( 0, 66, "<");
  u8g.drawStr( 0, 77, " <<<");  
  digitalWrite(2, LOW);
digitalWrite(3, LOW);
  
}
void right(void) {
 
 u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 0, 55, " >>>");
  u8g.drawStr( 0, 66, "      >");
  u8g.drawStr( 0, 77, " >>>");  
  digitalWrite(2, LOW);
digitalWrite(3, LOW);
}
void up(void) {
 
 u8g.setFont(u8g_font_osb21);
  u8g.drawStr( 0, 55, "  ^^");
  u8g.drawStr( 0, 66, " ^^^^");
  u8g.drawStr( 0, 77, " ^^^^");  
  digitalWrite(2, LOW);
digitalWrite(3, LOW);
}
void vib(void) {
 
digitalWrite(2, HIGH);  
  digitalWrite(3, LOW);
  delay(500);         
  digitalWrite(3, HIGH);
  digitalWrite(2, LOW);    
  delay(500);
  digitalWrite(3, LOW);
}
void call(void) {
 
 u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 55, "  ==}");
  u8g.drawStr( 0, 66, " ||");
  u8g.drawStr( 0, 77, " ||");  
  u8g.drawStr( 0, 88, "  ==}");  
  digitalWrite(2, LOW);
digitalWrite(3, LOW);
  
}
void lig(void) {
 
 
}


void setup(void) {
   Serial.begin(9600);
   pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  // flip screen, if required
   u8g.setRot90();
  
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
}

void loop(void) {

  while (Serial.available() > 0) {
  
    int red = Serial.parseInt();
digitalWrite(2, LOW);
digitalWrite(3, LOW);
if (Serial.read() == '.') {
  if(red==1)
  {
 
         u8g.firstPage();  
           do {
                 draw(); 
                 } while( u8g.nextPage() );
  
            delay(50);
  
  }

  else if(red==2)
  {
     u8g.firstPage();  
           do {
                 message(); 
                 } while( u8g.nextPage() );
  
            delay(50);
  }
  else if(red ==3)
  {
     u8g.firstPage();  
           do {
                 left(); 
                 } while( u8g.nextPage() );
  
            delay(50);
  }
    else if(red ==4)
  {
     u8g.firstPage();  
           do {
                 right(); 
                 } while( u8g.nextPage() );
  
            delay(50);
  }
    else if(red ==5)
  {
     u8g.firstPage();  
           do {
                 up(); 
                 } while( u8g.nextPage() );
  
            delay(50);
  }
    else if(red ==6)
  {
     
                 vib(); 
               
  }
    else if(red ==7)
  {
     u8g.firstPage();  
           do {
                 call(); 
                 } while( u8g.nextPage() );
  
            delay(50);
  }
  else if(red ==8)
  {
     u8g.firstPage();  
           do {
                 lig(); 
                 } while( u8g.nextPage() );
  
            delay(50);
  }
  else if(red ==9)
  {
     u8g.firstPage();  
           do {
                 ace(); 
                 } while( u8g.nextPage() );
  
            delay(50);
  }
  
  }
  }            

}
