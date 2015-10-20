/*
	
	SIMPLE MOTOR CONTROLLER
		COPYRIGHT DAVID JESSE MOODY III
	Reads input, pushes motor.

*/ 

void setup() {
  
  pinMode(2, INPUT); //Digital Input for forward
  pinmode(4, INPUT); //Digital Input for backward
  digitalWrite(2, HIGH);//pullup resistor
  digitalWrite(4, HIGH);//pullup resistor
  //Setup Channel A
  
  
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  
}

void loop(){
  
  
  if(digitalRead(2) == digitalRead(4)) { // STOPPED
  	digitalWrite(9,HIGH);
  } else if (digitalRead(2) == HIGH) { //FORWARD
  	digitalWrite(12, HIGH);
  	digitalWrite(9, LOW);
  	//analogWrite(3, 123);   //Spins the motor on Channel A at half speed
  	analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  } else if (digitalRead(4) == HIGH) { //BACKWARD
  	digitalWrite(12, LOW);
  	digitalWrite(9, LOW);
  	//analogWrite(3, 123);   //Spins the motor on Channel A at half speed
  	analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  }
    
}