#include <WiFi.h>

int tempPin = 32;       
int phPin = 34;         
int doPin = 35;         
int turbPin = 39;  
int salPin = 36;   
int amomPin = 4;     

void setup() {
  Serial.begin(115200);
  delay(500);
  
  Serial.println("System starting...");
  
  pinMode(tempPin, INPUT);
  pinMode(phPin, INPUT);
  pinMode(doPin, INPUT);
  pinMode(turbPin, INPUT);
  pinMode(salPin, INPUT);
  pinMode(amomPin, INPUT);
}

void loop() {
  int rTemp = analogRead(tempPin);
  int rPh = analogRead(phPin);
  int rDo = analogRead(doPin);
  int rTurb = analogRead(turbPin);
  int rSal = analogRead(salPin);
  int rAmom = analogRead(amomPin);

  float temp = 15.0 + (rTemp / 4095.0) * 20.0;     
  float ph = (rPh / 4095.0) * 14.0;                        
  float oxy = (rDo / 4095.0) * 15.0;           
  float turb = (rTurb / 4095.0) * 100.0;         
  float sal = (rSal / 4095.0) * 50.0;            
  float amom = (rAmom / 4095.0) * 5.0;               

  Serial.println("-----------------");
  Serial.print("Temp: "); Serial.println(temp);
  Serial.print("pH: "); Serial.println(ph);
  Serial.print("O2: "); Serial.println(oxy);
  Serial.print("Turbidity: "); Serial.println(turb);
  Serial.print("Salinity: "); Serial.println(sal);
  Serial.print("Ammonia: "); Serial.println(amom);

  if ((temp > 29.0 && turb > 45.0) || oxy < 4.0 || amom > 1.5) {
    Serial.println("WARNING: High risk detected! Sending alert...");
  } else {
    Serial.println("Status: Normal");
  }

  delay(10000); 
}
