const int sensorPin = A0;
int baselineTemp = 25.0;
float oldTemperature = 20;

void setup()
{
  Serial.begin(9600); //open a serial port
  
  // intialise pin number and direction
  
  for(int pinNum=2; pinNum < 5; pinNum++ )
  {
    pinMode(pinNum, OUTPUT);
    digitalWrite(pinNum, LOW);
  }
  baselineTemp = readTemperature() - 1;
}

void loop()
{
  float temperature = readTemperature();
  /*if(  oldTemperature !=   temperature)
  {*/
    relight(temperature);
  /*  oldTemperature =   temperature;
  }*/

  delay(18);
  //flash();
}

float readTemperature()
{
  int sensorVal = analogRead(sensorPin);
  //convert ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  //convert voltage to temperature in degrees.
  float temperature = (voltage - .5) * 100;
  Serial.print("Base C:");
  Serial.print(oldTemperature);
  Serial.print("Degrees C:");
  Serial.print(temperature);
  Serial.println();
  return temperature;
}

void flash()
{
  Serial.println("flash");
    delay(20);
    lightUp0();
    delay(20);
    lightUp1();
    delay(20);
    lightUp2();
    delay(20);
    lightUp3();
}

void relight(float temperature)
{
  if(temperature < baselineTemp)
  {
    lightUp0();
  }
  else if ( (temperature >= baselineTemp +2) && 
            (temperature <= baselineTemp +4) )
  {
    lightUp1();
  }
  else if ( (temperature >= baselineTemp +4) && 
            (temperature <= baselineTemp +6) )
  {
    lightUp2();
  }
  else if ( (temperature >= baselineTemp +6) )
  {
    lightUp3();
  }
}

void lightUp0()
{
  Serial.println("lightUp0");
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void lightUp1()
{
  Serial.println("lightUp1");
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
}

void lightUp2()
{
  Serial.println("lightUp2");
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
}

void lightUp3()
{
  Serial.println("lightUp3");
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
}

