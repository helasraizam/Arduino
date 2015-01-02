int Pin2 = A0;  // input pin 2
int Pin3 = A4;  // other side of amp : ground pin3 
int Pin6 = A2;  // output pin6
int grndPin = A3;

float outV1 = 0;
float outV2 = 0;
float outV3 = 0;
float outV4 = 0; //our ground

void setup()
{
  Serial.begin(9600);
  pinMode(Pin2, INPUT);
  pinMode(Pin3, INPUT);
  pinMode(Pin6, INPUT);
  
}

void loop()
{
  unsigned long starttime = millis();  
  unsigned long endtime = starttime;  
  
  while(endtime-starttime<1000)
  {
    outV1 = 3.3/680*analogRead(Pin2);
    outV2 = 3.3/680*analogRead(Pin3);
    outV3 = 3.3/680*analogRead(Pin6); 
    outV4 = 3.3/680*analogRead(grndPin);
    
    endtime = millis();
    
    Serial.print(endtime-starttime);
    Serial.print('\t');
    Serial.print(outV1);
    Serial.print('\t');
    Serial.print(outV2);
    Serial.print('\t');
    Serial.print(outV3);
    Serial.print('\t');
    Serial.print(outV4);
    //Serial.print(Serial.available()); 
    Serial.println();
    delay(500);
    
  }
  delay(1);
} 
