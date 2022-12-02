
#include <Servo.h>


// Declaramos la variable para controlar el servo
//declaración de variables:
Servo motor1; //servomotor del brazo derecho
Servo motor2; //servomotor del brazo izquierdo



void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  motor1.attach(3);
  motor2.attach(4);

}
 
void loop() {
  
  // Desplazamos a la posición 0º
  motor1.write(0);
    // Desplazamos a la posición 180º
  motor2.write(180);
  // Esperamos 1 segundo
  delay(1000);
  
  // Desplazamos a la posición 90º
  motor1.write(90);
    
  // Desplazamos a la posición 90º
  motor2.write(90);
  // Esperamos 1 segundo
  delay(1000);
  
  // Desplazamos a la posición 180º
  motor1.write(180);
  motor2.write(0);



  delay(1000);
}
