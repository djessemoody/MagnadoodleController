/*
	
	SIMPLE MOTOR CONTROLLER
		COPYRIGHT DAVID JESSE MOODY III
	Reads input, pushes motor.

*/ 
int sensorValue = 0;
int goalValue = 0; //between 0 and 1023 (corresponds to 0 to 5 volts)
int sensorPin = A0;
int outPin = 7;
void setup() {
   
  Serial.begin(9600); //begins usb communication at 9600 bps

   
  pinMode(outPin, OUTPUT); //5V output
  pinMode(4, OUTPUT);
  //Setup Channel A
  

}

void loop(){
  digitalWrite(outPin, HIGH);//Output 5v
  digitalWrite(4, LOW);
  goalValue = Serial.println(sensorValue);

  sensorValue = analogRead(sensorPin);
  
    
}
