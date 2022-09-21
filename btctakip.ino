#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16, 2);
ESP8266WiFiMulti WiFiMulti;

const char* ssid = "TA1AFS";
const char* password = "?sngMuDvk@#";
int y = 0;
int sure = 2;
void setup() {
  Wire.begin(0, 2);
  lcd.begin(); 
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("Coin Ticker v1.0"); 
  lcd.setCursor(0, 1); lcd.print("made by Sercan"); delay(1000);
  devam1:
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("WiFi pairing");
  lcd.setCursor(0, 1); lcd.print(ssid);
  
  WiFi.mode(WIFI_STA);

  for (int c=12 ; c<15 ; c++) {  lcd.setCursor(c,0); lcd.print("."); 
       WiFiMulti.addAP(ssid , password);
      
       if ((WiFiMulti.run() == WL_CONNECTED)) {   
           lcd.clear(); lcd.print("WiFi connected"); 
           lcd.setCursor(0, 1);  lcd.print(ssid); 
        
           delay(1250); lcd.clear();
        
           lcd.setCursor(0, 0); lcd.print("WiFi got IP"); 
           lcd.setCursor(0, 1); lcd.print(WiFi.localIP());
           delay(1500); break;}
                                      
         if(c==15){ c = 12; lcd.setCursor(12,0); lcd.print(".   "); } 
      }
      
if ((WiFiMulti.run() != WL_CONNECTED)) 
{ lcd.clear();lcd.setCursor(0,0); lcd.print("WiFi failed"); 
              lcd.setCursor(0,1); lcd.print(ssid); delay(5000); 
              goto devam1; }  

lcd.clear();
                                          
}

void loop() {
  devam2:
  
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    WiFiClient client;
    HTTPClient http;  
    
for ( y=0;y<sure;y++) {
  satir1();
  satir2();
  if (y==sure) {y = 0; break; }
  }

  for ( y=0;y<sure;y++) {
  satir1();
  satir2A();
  if (y==sure) {y = 0; break; }
  }
  for ( y=0;y<sure;y++) {
  satir1();
  satir2B();
  if (y==sure) {y = 0; break; }
  }

  for ( y=0;y<sure;y++) {
  satir1();
  satir2C();
  if (y==sure) {y = 0; break; }
  }
  
  } else if ((WiFiMulti.run() != WL_CONNECTED)) { 
            lcd.clear();
            lcd.setCursor(0, 0); lcd.print("Connection"); 
            lcd.setCursor(0, 1); lcd.print("Lost"); delay(2000);
            lcd.clear(); lcd.setCursor(0, 0); lcd.print("Retrying"); 
            for ( int j=0 ; j <=16  ; j++ ) {lcd.setCursor(j,1); lcd.print (".");  
            WiFiMulti.addAP(ssid , password);
            if ((WiFiMulti.run() == WL_CONNECTED)) {lcd.clear(); lcd.setCursor(0,0); 
            lcd.print("WiFi OK"); delay(3000); goto devam2; }
            if (j==16){j=0; lcd.setCursor(0,1); lcd.print(".               ");}
               }           
              } 
}

void satir1(){
    WiFiClient client;
    HTTPClient http; 
if (http.begin(client, "http://api.thingspeak.com/apps/thinghttp/send_request?api_key=H5PFIEFXVXLQB4JL")) {  // HTTP
    int httpCode = http.GET();
   if (httpCode > 0) { if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          lcd.setCursor(0, 0);
          lcd.print("UMA:"); 
          lcd.print(payload);lcd.print("        ");} } 
      http.end(); } }
 
void satir2(){
    WiFiClient client;
    HTTPClient http;  
if (http.begin(client, "http://api.thingspeak.com/apps/thinghttp/send_request?api_key=O2DTUCCV7VH9UKN3")) {  // HTTP
    int httpCode = http.GET();
   if (httpCode > 0) { if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload2 = http.getString();
          lcd.setCursor(0, 1);
          lcd.print("SHB:"); 
          lcd.print(payload2);lcd.print("        ");} } 
      http.end(); } }

void satir2A(){
    WiFiClient client;
    HTTPClient http; 
if (http.begin(client, "http://api.thingspeak.com/apps/thinghttp/send_request?api_key=IDUUX1L8L2ICDK1Q")) {  // HTTP
    int httpCode = http.GET();
   if (httpCode > 0) { if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload3 = http.getString();
          lcd.setCursor(0, 1);
          lcd.print("BTC:"); 
          lcd.print(payload3);lcd.print("        ");} } 
      http.end(); } }

void satir2B(){
    WiFiClient client;
    HTTPClient http; 
if (http.begin(client, "http://api.thingspeak.com/apps/thinghttp/send_request?api_key=C11YTGN6ANBZ3L9V")) {  // HTTP
    int httpCode = http.GET();
   if (httpCode > 0) { if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload4 = http.getString();
          lcd.setCursor(0, 1);
          lcd.print("GALA:"); 
          lcd.print(payload4);lcd.print("        ");} } 
      http.end(); } }

      void satir2C(){
    WiFiClient client;
    HTTPClient http; 
if (http.begin(client, "http://api.thingspeak.com/apps/thinghttp/send_request?api_key=KIPEFAK0O3NL8Y0C")) {  // HTTP
    int httpCode = http.GET();
   if (httpCode > 0) { if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload5 = http.getString();
          lcd.setCursor(0, 1);
          lcd.print("TRX:"); 
          lcd.print(payload5); } } 
      http.end(); } }
