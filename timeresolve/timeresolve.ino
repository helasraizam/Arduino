int onePin = A0;  // input pin 2
int twoPin = A1;  // other side of amp : ground pin3 
int thrPin = A2;  // output pin5

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
// out put is V2, change dat
void loop()
{
  unsigned long starttime = millis();  
  unsigned long endtime = starttime;  
  
  while(endtime-starttime<1000)
  {
    outV1 = 5.0/1023*analogRead(onePin);
    outV2 = 5.0/1023*analogRead(twoPin);
    outV3 = 5.0/1023*analogRead(thrPin); 
    
    endtime = millis();
    
    Serial.print(endtime-starttime);
    Serial.print('\t');
    Serial.print(outV1);
    Serial.print('\t');
    Serial.print(outV2);
    Serial.print('\t');
    Serial.print(outV3);
    Serial.print('\t');
    Serial.print(Serial.available()); 
    Serial.println();
    delay(5);
    
  }
  delay(20000);
} 
