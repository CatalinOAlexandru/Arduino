int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

int count = 0;

byte leds = 0;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);  
  pinMode(buttonBpin, INPUT_PULLUP);  
}

void loop() 
{
  if (digitalRead(buttonApin) == LOW)
  {
    count += 1;
    if(count > 12345)
    {
      print(count);
      digitalWrite(ledPin, HIGH);
    }
  }
  if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
}
