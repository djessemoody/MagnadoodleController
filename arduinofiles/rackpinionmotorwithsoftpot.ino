/*
	
	SIMPLE MOTOR CONTROLLER
		COPYRIGHT DAVID JESSE MOODY III
	Reads input, pushes motor.

*/ 
int sensorValue = 0;
int goalValue = 0; //between 0 and 1023 (corresponds to 0 to 5 volts)
int sensorPin = A0;
void setup() {
  
  pinMode(2, INPUT); //Digital Input for forward
  pinmode(4, INPUT); //Digital Input for backward
  digitalWrite(2, HIGH);//pullup resistor
  digitalWrite(4, HIGH);//pullup resistor
  //Setup Channel A
  
  
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
 
  Serial.begin(9600) //begins usb communication at 9600 bps 
}

void loop(){
  if (Serial.available() > 0) {
  	goalValue = Serial.read();
  	
  }
  sensorValue = analogRead(sensorPin);
  
  //may need to change for correct directions  
  if(sensorValue == goalValue) { // STOPPED
  	digitalWrite(9,HIGH);
  } else if (sensorValue < goalValue) { //FORWARD
  	digitalWrite(12, HIGH);
  	digitalWrite(9, LOW);
  	//analogWrite(3, 123);   //Spins the motor on Channel A at half speed
  	analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  } else if (sensorValue > goalValue) { //BACKWARD
  	digitalWrite(12, LOW);
  	digitalWrite(9, LOW);
  	//analogWrite(3, 123);   //Spins the motor on Channel A at half speed
  	analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  }
    
}