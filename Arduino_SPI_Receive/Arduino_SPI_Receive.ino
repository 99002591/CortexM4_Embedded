#include<SPI.h>
volatile boolean received;
volatile uint16_t  Slavereceived, Slavereceived2;

void setup()
{
  Serial.begin(9600);
  pinMode(MISO,OUTPUT);                   
  pinMode(10,INPUT);
  digitalWrite(10,LOW);
  SPCR |= _BV(SPE);                       
  received = false;
  SPI.attachInterrupt();                  
}


ISR (SPI_STC_vect)                        
{
    Slavereceived = SPDR;            
    received = true;
}

 

void loop()
{
  if(received)                           
  {  
      received = false;    
      Serial.print("Humidity is  ");
      Serial.println(Slavereceived);
      delay(100);
  
  
  }
 
}
