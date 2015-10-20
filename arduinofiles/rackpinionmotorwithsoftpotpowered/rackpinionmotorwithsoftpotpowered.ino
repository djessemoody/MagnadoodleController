/*
	
	SIMPLE MOTOR CONTROLLER
		COPYRIGHT DAVID JESSE MOODY III
	Reads input, pushes motor.

*/ 
int sensorValue = -1;
int goalValue = -1; //between 0 and 1023 (corresponds to 0 to 5 volts)
int sensorPin = A4;
int done = 0;
int tolerance = 5;

void setup() {
  
  pinMode(2, INPUT); //Digital Input for forward
  pinMode(4, INPUT); //Digital Input for backward
  pinMode(7, OUTPUT); //5V output
  digitalWrite(2, HIGH);//pullup resistor
  digitalWrite(4, HIGH);//pullup resistor
  digitalWrite(7, HIGH);//Output 5v
  //Setup Channel A
  
  
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
 
  Serial.begin(9600); //begins usb communication at 9600 bps 
}

void loop(){
  while (Serial.available() == 0) ;

  goalValue = 1000;
  digitalWrite(9,HIGH);
  
  //may need to change for correct directions  
  while (1) {
    sensorValue = analogRead(sensorPin);
    digitalWrite(12,HIGH);
    digitalWrite(9,LOW);
    /*if (goalValue == -1 || (sensorValue < 240 && goalValue <= sensorValue)  || (sensorValue > 990 && sensorValue < goalValue)) {

        digitalWrite(9,HIGH);
        if (goalValue != -1) done = 1;
        break;
    } else if(sensorValue < goalValue + tolerance && sensorValue > goalValue - tolerance) { // STOPPED

  	digitalWrite(9,HIGH);
        done = 1;
        break;
    } else if (sensorValue > goalValue && goalValue != -1) { //FORWARD

  	digitalWrite(12, HIGH);
  	digitalWrite(9, LOW);
  	//analogWrite(3, 123);   //Spins the motor on Channel A at half speed
  	analogWrite(3, 255);   //Spins the motor on Channel A at full speed
    } else if (sensorValue < goalValue && goalValue != -1) { //BACKWARD
 
  	digitalWrite(12, LOW);
  	digitalWrite(9, LOW);
  	//analogWrite(3, 123);   //Spins the motor on Channel A at half speed
  	analogWrite(3, 255);   //Spins the motor on Channel A at full speed
    } */
  } 
}
