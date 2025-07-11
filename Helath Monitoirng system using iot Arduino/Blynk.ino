#include <Wire.h>
#include <MPU6050.h>
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>

// ---------- Wi-Fi Credentials ----------
const char* ssid = "realme 14x 5G";
const char* password = "123456780";

// ---------- Firebase Credentials ----------
#define FIREBASE_HOST "https://health-a3bc3-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "AIzaSyDp5n2an6-gzKkuGPtOrA7b7FX5uw6RcE4"


// ---------- Hardware Pins ----------
const int lm35Pin = A0;
const int ledPin = LED_BUILTIN;

// ---------- Sensor and Firebase Objects ----------
MPU6050 mpu;
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long lastSendTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Connect to Wi-Fi
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ Wi-Fi connected");
  Serial.println(WiFi.localIP());

  // Firebase Initialization
  config.host = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  Serial.println("✅ Firebase initialized");

  // MPU6050 Initialization
  Wire.begin(D2, D1);  // SDA = D2, SCL = D1
  mpu.initialize();
  if (mpu.testConnection()) {
    Serial.println("✅ MPU6050 connected");
  } else {
    Serial.println("❌ MPU6050 not connected");
  }
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  int raw = analogRead(lm35Pin);
  float voltage = (raw / 1024.0) * 3.3;
  float tempC = voltage * 100.0;

  Serial.println("📍 Sensor Readings:");
  Serial.print("Temp: "); Serial.print(tempC); Serial.println(" °C");
  Serial.print("Accel X: "); Serial.println(ax / 16384.0);
  Serial.print("Accel Y: "); Serial.println(ay / 16384.0);
  Serial.print("Accel Z: "); Serial.println(az / 16384.0);
  Serial.println("----");

  if (Firebase.ready() && millis() - lastSendTime > 1000) {
    Firebase.RTDB.setFloat(&fbdo, "/SensorData/Temperature", tempC);
    Firebase.RTDB.setFloat(&fbdo, "/SensorData/AccelX", ax / 16384.0);
    Firebase.RTDB.setFloat(&fbdo, "/SensorData/AccelY", ay / 16384.0);
    Firebase.RTDB.setFloat(&fbdo, "/SensorData/AccelZ", az / 16384.0);
    lastSendTime = millis();
  }

  delay(200);
}