int outPin = 13;      // sets amplifier input
int inPin = A0;       // Read amplifier output (analog)
int ctrlPin = A1;	  // Amplifier output control
int in3VPin = A2;	  // 3V pin control
float inVoltage = 0;  // True input voltage
float outVoltage = 0; // True output voltage
float ctrlVoltage = 0;// True control voltage
float 3VVoltage=0;    // Voltage of 3.3V 

void setup()
{
  Serial.begin(38400);        // Connect to serial 9600
  pinMode(outPin, OUTPUT);   // Set outPin to write
  pinMode(inPin, INPUT);     // Set inPin to read
  pinMode(ctrlPin,INPUT);
  pinMode(in3VPin,INPUT);
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
	ctrlVoltage= 5.0/1023*analogRead(ctrlPin); // Get control voltage (should be equal)
	3VVoltage =  5.0/1023*analogRead(in3VPin); // Get 3.3V voltage (should be 3.3)
    Serial.print('\t');
    Serial.println(outVoltage);
  }
  delay(10000);                    // Wait 10s between readings
}
