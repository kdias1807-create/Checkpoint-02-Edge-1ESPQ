#include <Wire.h>

#include <LiquidCrystal_I2C.h>
 
#include <Adafruit_Sensor.h>

#include <DHT.h>

#include <DHT_U.h>
 
// ================= SENSOR DHT =================

#define DHTTYPE DHT11

#define DHTPIN 3
 
DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;
 
// ================= DISPLAY =================

#define col 16

#define lin 2

#define ende 0x27
 
LiquidCrystal_I2C lcd(ende, col, lin);
 
// ================= PINOS =================

int ldr = A0;
 
int ledVerde = 8;

int ledAmarelo = 9;

int ledVermelho = 10;
 
int buzzer = 11;
 
// ================= SETUP =================

void setup()

{

  Serial.begin(9600);
 
  dht.begin();
 
  sensor_t sensor;

  dht.temperature().getSensor(&sensor);

  dht.humidity().getSensor(&sensor);
 
  delayMS = sensor.min_delay / 1000;
 
  lcd.init();

  lcd.backlight();

  lcd.clear();
 
  pinMode(ledVerde, OUTPUT);

  pinMode(ledAmarelo, OUTPUT);

  pinMode(ledVermelho, OUTPUT);
 
  pinMode(buzzer, OUTPUT);

}
 
// ================= LOOP =================

void loop()

{

  float somaTemp = 0;

  float somaUmidade = 0;

  int somaLdr = 0;
 
  // ===== MEDIA DE 5 LEITURAS =====

  for(int i = 0; i < 5; i++)

  {

    sensors_event_t event;
 
    dht.temperature().getEvent(&event);

    somaTemp += event.temperature;
 
    dht.humidity().getEvent(&event);

    somaUmidade += event.relative_humidity;
 
    somaLdr += analogRead(ldr);
 
    delay(1000);

  }
 
  float temperatura = somaTemp / 5;

  float umidade = somaUmidade / 5;

  int valorLdr = somaLdr / 5;
 
  // ===== LIMPA DISPLAY =====

  lcd.clear();
 
  // ===== DESLIGA TUDO =====

  digitalWrite(ledVerde, LOW);

  digitalWrite(ledAmarelo, LOW);

  digitalWrite(ledVermelho, LOW);

  digitalWrite(buzzer, LOW);
 
  // =====================================================

  // CONTROLE DE LUMINOSIDADE

  // =====================================================
 
  // Ambiente escuro

  if(valorLdr < 500 )

  {

    digitalWrite(ledVerde, HIGH);
 
    lcd.setCursor(0,0);

    lcd.print("Ambiente Esc");
    Serial.print(valorLdr);

  }
 
  // Ambiente meia luz

  else if(valorLdr > 500)

  {

    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, HIGH);
 
    lcd.setCursor(0,0);

    lcd.print("Meia Luz");
    Serial.print(valorLdr);

  }
 
  // Ambiente muito claro

  else

  {

    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, HIGH);

    digitalWrite(buzzer, HIGH);
 
    lcd.setCursor(0,0);

    lcd.print("Muito Claro");
    Serial.print(valorLdr);

  }
 
  // =====================================================

  // TEMPERATURA

  // =====================================================
 
  lcd.setCursor(0,1);
 
  // Temperatura ideal

  if(temperatura >= 10 && temperatura <= 15)

  {

    lcd.print("Temp OK ");

    lcd.print(temperatura);

    lcd.print("C");

  }
 
  // Temperatura baixa

  else if(temperatura < 10)

  {

    digitalWrite(ledAmarelo, HIGH);

    digitalWrite(buzzer, HIGH);
 
    lcd.print("Temp Baixa ");

    lcd.print(temperatura);

  }
 
  // Temperatura alta

  else

  {

    digitalWrite(ledAmarelo, HIGH);

    digitalWrite(buzzer, HIGH);
 
    lcd.print("Temp Alta ");

    lcd.print(temperatura);

  }
 
  delay(3000);
 
  // =====================================================

  // UMIDADE

  // =====================================================
 
  lcd.clear();
 
  lcd.setCursor(0,0);
 
  // Umidade ideal

  if(umidade >= 50 && umidade <= 70)

  {

    lcd.print("Umidade OK");

    lcd.setCursor(0,1);

    lcd.print(umidade);

    lcd.print("%");

  }
 
  // Umidade baixa

  else if(umidade < 50)

  {

    digitalWrite(ledVermelho, HIGH);

    digitalWrite(buzzer, HIGH);
 
    lcd.print("Umid Baixa");

    lcd.setCursor(0,1);

    lcd.print(umidade);

    lcd.print("%");

  }
 
  // Umidade alta

  else

  {

    digitalWrite(ledVermelho, HIGH);

    digitalWrite(buzzer, HIGH);
 
    lcd.print("Umid Alta");

    lcd.setCursor(0,1);

    lcd.print(umidade);

    lcd.print("%");

  }
 
  // ===== Atualiza a cada 5 segundos =====

  delay(5000);

}
