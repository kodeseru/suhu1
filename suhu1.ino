#include <DHT.h>

#define DHTPIN 2      // Pin sensor suhu
#define DHTTYPE DHT11 // Tipe sensor yang digunakan (bisa ganti DS18B20 jika pakai itu)
#define RELAY_PIN 3   // Pin untuk relay

DHT dht(DHTPIN, DHTTYPE); 

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);  // Matikan relay saat mulai
  dht.begin();                   // Mulai sensor suhu
  Serial.begin(9600);            // Untuk cek output suhu di monitor serial
}

void loop() {
  float suhu = dht.readTemperature(); // Baca suhu dalam derajat Celsius
  
  // Jika suhu di atas 32°C, aktifkan relay (pompa menyala)
  if (suhu > 32) {
    digitalWrite(RELAY_PIN, HIGH);  // Aktifkan relay
    Serial.println("Suhu tinggi, pompa menyala...");
  } else {
    digitalWrite(RELAY_PIN, LOW);   // Matikan relay
    Serial.println("Suhu normal, pompa mati...");
  }

  delay(2000);  // Baca sensor setiap 2 detik
}
