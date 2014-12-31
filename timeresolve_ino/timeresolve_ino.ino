int onePin = A0;
int twoPin = A1;
int thrPin = A2;

float outV1 = 0;
float outV2 = 0;
float outV3 = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(onePin, INPUT);
  pinMode(twoPin, INPUT);
  pinMode(thrPin, INPUT);
  
}

void loop()
{
  unsigned long starttime = millis();  
  unsigned long endtime = millis();  
  
  while(endtime-starttime<1000)
  {
    outV1 = 5.0/1023*analogRead(onePin);
    outV2 = 5.0/1023*analogRead(twoPin);
    outV3 = 5.0/1023*analogRead(thrPin); 
    
    Serial.print(endtime-starttime);
    Serial.print('\t');
    Serial.print(outV1);
    Serial.print('\t');
    Serial.print(outV2);
    Serial.print('\t');
    Serial.print(outV3);
    Serial.print('\t');
    Serial.print(Serial.available()); 
    
    delay(1);
    
  }
  
} 
