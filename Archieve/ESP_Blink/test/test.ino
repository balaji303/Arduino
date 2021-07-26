#include <ESP8266WiFi.h>
const char* ssid = "ChaosFather";
const char* password = "BALAJIbalaji"; 
int button_two = 13; //d7 
int button_one = 12;//d6
WiFiServer server(80);//browser port 80 
void setup() {
  Serial.begin(9600); 
  delay(10);
  pinMode(button_two, OUTPUT);
  pinMode(button_one, OUTPUT);
  digitalWrite(button_two, LOW); 
  digitalWrite(button_one, LOW); // Connect to WiFi network  
  Serial.println("@");
  Serial.println("#");
 Serial.print("Connecting to ");  
 Serial.println(ssid); 
 WiFi.begin(ssid, password);
}
    
 
void loop(){
 while (WiFi.status() != WL_CONNECTED) 
 {
  delay(500);
  Serial.print("."); 
  }
  Serial.println("$");
  Serial.println("WiFi connected");
}
