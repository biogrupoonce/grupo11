#include <SoftwareSerial.h>  
                             
#include <Servo.h>

SoftwareSerial miBT(7, 9);  
Servo motor1;               //servomotor del brazo derecho
Servo motor2;               //servomotor del brazo izquierdo


void setup() {
  Serial.begin(9600);
  miBT.begin(9600);  // comunicacion serie entre Arduino y el modulo a 38400 bps
  motor1.attach(5);
  motor2.attach(6);
}

void loop() {
  if (miBT.available()) {  // si hay informacion disponible desde modulo
    char data_bl = miBT.read();
    Serial.write(data_bl);
    if (data_bl == 'A') {
      Serial.println("llego aqui");
      motor1.write(0);
      motor2.write(0);
      delay(2000);
      motor1.write(180);
      motor2.write(180);
    }
    if (data_bl == 'b') {
      Serial.println("llego aqui");
      motor1.write(180);

    }  
  }
  if (Serial.available()) {      // si hay informacion disponible desde el monitor serial
    miBT.write(Serial.read());  // lee monitor serial y envia a Bluetooth
    motor1.write(180);}
}