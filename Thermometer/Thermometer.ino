#include <SimpleDHT.h>
#include <LiquidCrystal.h>
#define BLUE 5

int pinDHT11 = 2;
SimpleDHT11 dht11;
int tempPin = 0;

//pins           BS  E  D4 D5  D6  D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(BLUE, OUTPUT);
  digitalWrite(BLUE, HIGH);
}

void loop()
{
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  
  int tempReading = analogRead(tempPin);
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  float tempC = tempK - 273.15;            // Convert Kelvin to Celcius
  float tempF = (tempC * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
 
  // Display Temperature in C
  lcd.setCursor(0, 0);
  lcd.print("Temp1      C  ");
  lcd.setCursor(6, 0);
  lcd.print(tempC);
  lcd.setCursor(13, 0);
  lcd.print("RH");


  // Display Temperature 2 in C
  lcd.setCursor(0, 1);
  lcd.print("Temp2      C  ");
  lcd.setCursor(6, 1);
  
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
   Serial.print("FAIL");
  }

for (int i = 0; i < 40; i++) {
    Serial.print((int)data[i]);
    if (i > 0 && ((i + 1) % 4) == 0) {
      Serial.print(' ');
    }
  }

  Serial.println("");  
  Serial.print("Read: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
  
  lcd.print((int)temperature);
  lcd.setCursor(8, 1);
  lcd.print(".00");

  lcd.setCursor(13, 1);
  lcd.print((int)humidity);
  lcd.setCursor(15, 1);
  lcd.print("%");

  digitalWrite(BLUE, LOW);
  delay(1200);
  digitalWrite(BLUE, HIGH);
}
