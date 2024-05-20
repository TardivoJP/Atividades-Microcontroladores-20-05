#include <BluetoothSerial.h>

BluetoothSerial SerialBT;


void setup()
{

	SerialBT.begin("ESP32 LED");

	pinMode(2, OUTPUT);

}


void loop(){

	if(SerialBT.available())
{

		char c = SerialBT.read();


		if(c == '1'){

			digitalWrite(2, HIGH);

			SerialBT.println("LED on");

		}

		if(c == '0'){
		
	digitalWrite(2, LOW);
			
SerialBT.println("LED off");

		

		}

	}
	delay(20);

}