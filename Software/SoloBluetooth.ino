#include <SoftwareSerial.h>	// libreria que permite establecer pines digitales
				// para comunicacion serie

SoftwareSerial miBT(7, 8); 	// pin 10 como RX, pin 11 como TX

void setup(){
  Serial.begin(115200);
  miBT.begin(9600);		// comunicacion serie entre Arduino y el modulo a 38400 bps
}

void loop(){
if (miBT.available())     	// si hay informacion disponible desde modulo
   Serial.write(miBT.read()); 	// lee Bluetooth y envia a monitor serial de Arduino

if (Serial.available())   	// si hay informacion disponible desde el monitor serial
   miBT.write(Serial.read()); 	// lee monitor serial y envia a Bluetooth

}
