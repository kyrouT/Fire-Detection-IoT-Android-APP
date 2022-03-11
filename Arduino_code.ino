// Code to use SoftwareSerial
#include <DHT.h>
#define DHTPIN 5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#include <SoftwareSerial.h>


// WiFi

SoftwareSerial espSerial =  SoftwareSerial(2, 3);     // arduino RX pin=2  arduino TX pin=3    connect the arduino RX pin to esp8266 module TX pin   -  connect the arduino TX pin to esp8266 module RX pin


String apiKey = "XENRG81WZAEGP5B1";     // replace with your channel's thingspeak WRITE API key

String ssid = "youriwifi";  // Wifi network SSID
String password = "yourpassword"; // Wifi network password

boolean DEBUG = true;

//======================================================================== showResponce
void showResponse(int waitTime) {
  long t = millis();
  char c;
  while (t + waitTime > millis()) {
    if (espSerial.available()) {
      c = espSerial.read();
      if (DEBUG) Serial.print(c);
    }
  }

}

//========================================================================
boolean thingSpeakWrite(float value1, float value2, float value3, float value4) {
  String cmd = "AT+CIPSTART=\"TCP\",\"";                  // TCP connection
  cmd += "184.106.153.149";                               // api.thingspeak.com
  cmd += "\",80";
  espSerial.println(cmd);
  if (DEBUG) Serial.println(cmd);
  if (espSerial.find("Error")) {
    if (DEBUG) Serial.println("AT+CIPSTART error");
    return false;
  }


  String getStr = "GET /update?api_key=";   // prepare GET string
  getStr += apiKey;

  getStr += "&field1=";
  getStr += String(value1);
  getStr += "&field2=";
  getStr += String(value2);
  getStr += "&field3=";
  getStr += String(value3);
  getStr += "&field4=";
  getStr += String(value4);
  //getStr +="&field5=";
  //getStr += String(value5);
  //getStr +="&field6=";
  //getStr += String(value6);

  // ...
  getStr += "\r\n\r\n\r\n\r\n";

  // send data length
  cmd = "AT+CIPSEND=";
  cmd += String(getStr.length());
  espSerial.println(cmd);
  if (DEBUG)  Serial.println(cmd);

  delay(100);
  if (espSerial.find(">")) {
    espSerial.print(getStr);
    if (DEBUG)  Serial.print(getStr);
  }
  else {
    espSerial.println("AT+CIPCLOSE");
    // alert user
    if (DEBUG)   Serial.println("AT+CIPCLOSE");
    return false;
  }
  return true;
}
//================================================================================ setup
void setup() {
  pinMode(8, OUTPUT);
  pinMode(A5, INPUT);
  DEBUG = true;         // enable debug serial
  dht.begin();
  Serial.begin(9600);

  espSerial.begin(9600);

  //115200

  // espSerial.println("AT+UART_DEF=9600,8,1,0,0");    // Enable this line to set esp8266 serial speed to 9600 bps
  // showResponse(1000);

  // espSerial.println("AT+RST");         // Enable this line to reset the module;
  // showResponse(1000);


  espSerial.println("AT+CWMODE=1");   // set esp8266 as client
  showResponse(1000);

  espSerial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\""); // set your home router SSID and password
  showResponse(5000);

  if (DEBUG)  Serial.println("Setup completed");
}


// ====================================================================== loop
void loop() {

  float h = dht.readHumidity();
  //Smoke
  float s = analogRead(A5);

  Serial.print(" Smoke: ");
  Serial.println(s);
  // Checks if it has reached the threshold value
  if (s > 400.0)
  {
    digitalWrite(8, HIGH);
  }
  else
  {
    digitalWrite(8, LOW);

  }

  // Temperature and humidity
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  //Windspeed
  float w = analogRead(A0);
  //Map 0-1023 to discrete 0-50-100...250 values for LED
  // analogWrite(9, sensorValue * (51.0 / 1023.0) * 50);


  Serial.print(" Wind: ");
  Serial.println(w);
  Serial.print(" ");


  // float hif = dht.computeHeatIndex(f, h);
  // float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("\n  Temperature: "));
  Serial.println(t);




  thingSpeakWrite(t, h, w, s);
  delay(16000);
  /*
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));
    delay(2000);
  */
}




