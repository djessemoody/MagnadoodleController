char ibyte;
void setup()
{
  Serial.begin(9600);
  delay(2500);
}

void loop()
{
  if(Serial.available()>0)
  {
    ibyte=Serial.read();
    Serial.write(ibyte);
  }
}
