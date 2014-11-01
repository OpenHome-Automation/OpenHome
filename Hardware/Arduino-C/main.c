/*TODO: Set up success/failure returns
Set up state functions
Re-format code
*/
#include <EEPROM.h>


int red = 5;
int white = 4;
int time = 1000;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(red, OUTPUT); 
  pinMode(white, OUTPUT);  
  Serial.begin(9600);
  
  //read from previous state
  if(EEPROM.read(0) == 255){
   redLamp(1, 0);
 
  }
  if(EEPROM.read(0) == 0){
   redLamp(0, 0); 
  }
  if(EEPROM.read(1) == 255){
   whiteLamp(1, 0); 
  }
  if(EEPROM.read(1) == 0){
   whiteLamp(0, 0); 
  }
  
  
}

// the loop routine runs over and over again forever:
void loop() {
  
  if(Serial.available() > 1){
    
    char letter = Serial.read();
    
    if(letter == '1'){
     redLamp(1, 1);
     Serial.write("Red lamp off\n");  
    }
    if(letter == '2'){
     redLamp(0, 1);
     Serial.write("Red lamp on\n"); 
    }
    
    if(letter == '3'){
      whiteLamp(1, 1);
      Serial.write("White lamp off\n"); 
    }
    if(letter == '4'){
      whiteLamp(0, 1);
      Serial.write("White lamp on\n"); 
    }
    
  }
  
}

void redLamp(int x, int save) {
  if(x == 1){
    digitalWrite(red, HIGH);
    if(save == 1){
      EEPROM.write(0, 255);
    }
  }
  else {
   digitalWrite(red, LOW);
   if(save == 1){
     EEPROM.write(0, 0);
   }
  } 
  
}

void whiteLamp(int x, int save) {
  if(x == 1){
    digitalWrite(white, HIGH);
    if(save == 1){
      EEPROM.write(1, 255);
    }
  }
  else {
   digitalWrite(white, LOW);
   if(save == 1){
     EEPROM.write(1, 0);
   }
   }
   
   
}
