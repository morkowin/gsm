
#include "LedControl.h"


 
byte max_units = 4;
LedControl lc=LedControl(8,10,9,max_units);

int integ = 0;
int device = 0;
unsigned long delaytime=1;
int counterfor;
void setup() {

  
}


void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte SM[8]={B00101110, B00101010, B00111010, B00000000, B00111110, B00000100,B00001000,B00000100};
  byte E[8]={B00111110, B00000000, B00100000, B00010000, B00001000, B00001100,B00001010,B00001100};
  byte L[8]={B00001000, B00010000, B00100000, B00000000, B00111110,B00001010,B00010100,B00100000};
  byte O[8]={B00000000, B00000010, B00000010, B00111110, B00000010,B00000010,B00000000,B00000000};
 

  /* now display them one by one with a small delay */
  lc.setRow(0,0,SM[0]);
  lc.setRow(0,1,SM[1]);
  lc.setRow(0,2,SM[2]);
  lc.setRow(0,3,SM[3]);
  lc.setRow(0,4,SM[4]);
  lc.setRow(0,5,SM[5]);
  lc.setRow(0,6,SM[6]);
  lc.setRow(0,7,SM[7]);
  delay(delaytime); 
  lc.setRow(1,0,E[0]);
  lc.setRow(1,1,E[1]);
  lc.setRow(1,2,E[2]);
  lc.setRow(1,3,E[3]);
  lc.setRow(1,4,E[4]);
  lc.setRow(1,5,E[5]);
  lc.setRow(1,6,E[6]);
  lc.setRow(1,7,E[7]);
  delay(delaytime); 
  lc.setRow(2,0,L[0]);
  lc.setRow(2,1,L[1]);
  lc.setRow(2,2,L[2]);
  lc.setRow(2,3,L[3]);
  lc.setRow(2,4,L[4]);
  lc.setRow(2,5,L[5]);
  lc.setRow(2,6,L[6]);
  lc.setRow(2,7,L[7]);
  delay(delaytime); 
  lc.setRow(3,0,O[0]);
  lc.setRow(3,1,O[1]);
  lc.setRow(3,2,O[2]);
  lc.setRow(3,3,O[3]);
  lc.setRow(3,4,O[4]);
  lc.setRow(3,5,O[5]);
  lc.setRow(3,6,O[6]);
  lc.setRow(3,7,O[7]);
  delay(delaytime); 
}
void writeArduinoOnMatrix2() {
  /* here is the data for the characters */
  byte SM[8]={B00000000, B00111110, B00001000, B00001000, B00111110, B00000000,B00111110,B00100010};
  byte E[8]={B00111110, B00000000, B00111110, B00100000, B00100000, B00100000,B00111110,B00000000};
  byte L[8]={B00101110, B00101010, B00111010, B00000000, B00111110,B00101010,B00101010,B00000000};
  byte O[8]={B00000000, B00001000, B01111100, B01000010, B01000001,B01000010,B01111100,B00001000};
 

  /* now display them one by one with a small delay */
  lc.setRow(0,0,SM[0]);
  lc.setRow(0,1,SM[1]);
  lc.setRow(0,2,SM[2]);
  lc.setRow(0,3,SM[3]);
  lc.setRow(0,4,SM[4]);
  lc.setRow(0,5,SM[5]);
  lc.setRow(0,6,SM[6]);
  lc.setRow(0,7,SM[7]);
  delay(delaytime); 
  lc.setRow(1,0,E[0]);
  lc.setRow(1,1,E[1]);
  lc.setRow(1,2,E[2]);
  lc.setRow(1,3,E[3]);
  lc.setRow(1,4,E[4]);
  lc.setRow(1,5,E[5]);
  lc.setRow(1,6,E[6]);
  lc.setRow(1,7,E[7]);
  delay(delaytime); 
  lc.setRow(2,0,L[0]);
  lc.setRow(2,1,L[1]);
  lc.setRow(2,2,L[2]);
  lc.setRow(2,3,L[3]);
  lc.setRow(2,4,L[4]);
  lc.setRow(2,5,L[5]);
  lc.setRow(2,6,L[6]);
  lc.setRow(2,7,L[7]);
  delay(delaytime); 
  lc.setRow(3,0,O[0]);
  lc.setRow(3,1,O[1]);
  lc.setRow(3,2,O[2]);
  lc.setRow(3,3,O[3]);
  lc.setRow(3,4,O[4]);
  lc.setRow(3,5,O[5]);
  lc.setRow(3,6,O[6]);
  lc.setRow(3,7,O[7]);
  delay(delaytime); 
}








 
 void set_unit(byte number_of_unit){
   
  lc.shutdown(number_of_unit-1,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(number_of_unit-1,1);
  /* and clear the display */
  lc.clearDisplay(number_of_unit-1);
 }
 
 
void single(byte number_of_unit) {
  for(int row=0;row<8;row++) {
    for(int col=0;col<8;col++) {
      delay(delaytime);
      lc.setLed(number_of_unit-1,row,col,true);
      delay(delaytime);
    }
  }
}

void loop() { 
 delay(1000);
  for(byte i=1;i<5;i++)
  {
    set_unit(i);
  }
   for(int col=0;col<4;col++) {
      delay(delaytime);
      for(int rup=0;rup<8;rup++) {
        for(int dup=0;dup<8;dup++) {
          lc.setLed(col,rup,dup,true);
          delay(10);
        }      
      }   
    }
    writeArduinoOnMatrix();
   delay(2000);
    for(int dup=0;dup<8;dup++) {
      for(int foreb=0;foreb<8;foreb++) {
          lc.setLed(0,foreb,dup,true);
      }   
      for(int foreb=0;foreb<8;foreb++) {
          lc.setLed(1,foreb,dup,true);
      }   
      for(int foreb=0;foreb<8;foreb++) {
          lc.setLed(2,foreb,dup,true);
      }   
      for(int foreb=0;foreb<8;foreb++) {
          lc.setLed(3,foreb,dup,true);
      }   
          delay(100); 
    } 


         
   
      
    
 // for (byte i=1;i<5;i++)
//{
 // single(i);
//}
  

  
  writeArduinoOnMatrix2();
  delay(2000);
  /* for(byte i=1;i<6;i++)
  {
  set_unit(i);
  }*/
 
  
}
