int outPin = 13;      // sets amplifier input
int inPin = A0;       // Read amplifier output (analog)
float inVoltage = 0;  // True input voltage
float outVoltage = 0; // True output voltage

void setup()
{
  Serial.begin(38400);        // Connect to serial 9600
  pinMode(outPin, OUTPUT);   // Set outPin to write
  pinMode(inPin, INPUT);     // Set inPin to read
}

void loop()
{
  for(int inValue=0;inValue<=255;inValue++)  // loop through all values 0-255
  {
    analogWrite(outPin,inValue);  // set amplifier input to inValue
    inVoltage=inValue*5.0/255;    // Convert to true voltage
    Serial.print(inVoltage);      // print true voltage of amplifier IN
    delay(1);                   // Give it .1 s to stabilize
    
    outVoltage = 5.0/1023*analogRead(inPin);   // Get amplifier OUT
    Serial.print('\t');
    Serial.println(outVoltage);
  }
  delay(10000);                    // Wait 10s between readings
}
