//https://www.hackster.io/kutluhan-aktar/whatsapp-notification-station-779cdf
//https://www.hackster.io/kutluhan-aktar/whatsapp-mapping-and-weather-forecast-chat-bot-6a9d39
          /////////////////////////////////////////////  
         //      WhatsApp Mapping and Weather       //
        //            Forecast Chat Bot            //
       //               (via Twilio)              //
      //           ---------------------         //
     //              NodeMCU (ESP-12E)          //           
    //              by Kutluhan Aktar          // 
   //                                         //
  /////////////////////////////////////////////

// By only subscribing to TheAmplituhedron, you will be able get your data packets from NodeMCU, or any other device that can make an HTTP GET Request, to your phone as WhatsApp messages via Twilio through TheAmplituhedron
// when you enter the keywords and control the base remotely as shown on the project tutorial page.
// You will need a Twilio account to get WhatsApp messages automatically from the two-way connection hub when you enter a keyword.
// Then, you can use your unique connection hub including the Twilio WhatsApp API by merely creating a Twilio Account and configuring your endpoint URL as your unique two-way
// connection hub path that you can find on your dashboard by cliking the implied web application.
// Note: Do not forget that you may have to take a tutorial if you do not know how to set an endpoints URls on the Twilio Sandbox.
// Note: You will also need your unique hedron to connect the WhatsApp Two-Way Connection Hub application.
//
// Click the links below for more information about Twilio.
// https://www.twilio.com/whatsapp
// https://www.theamplituhedron.com/dashboard/WhatsApp-Two-Way-Connection-Hub/
//
// As a reminder, my website has SSL protection so that you need to identify your NodeMCU connection by entering TheAmplituhedron FingerPrint or ThumbPrint.
// You can learn about it more from the link below.
// https://www.theamplituhedron.com/projects/WhatsApp-Mapping-and-Weather-Forecast-Chat-Bot/
//
// In this project turorial, I decided to use a BMP180 Pressure and Temperature Sensor, and a GY-NEO6MV2 GPS Module as data providers.
// And, to make my project base remote and controllable, I used an L298N Motor Driver and two Wheel and DC Motor Kit along with a Ball Caster.
//
// I created a free two-way connection hub for TheAmplituhedron subscribers and used it in this project. But, if you do not want to use this service,
// you can copy the source code from the link on the top and crete your own application.
// When you enter a keyword for a specific task, you can either get variables detected by NodeMCU or send commands to control wheels remotely.
// Reminder: WhatsApp Two-Way Connection Hub is created for this project and therefore all keywords are pre-defined by me but it is open-source so you can create your own application.
// KEYWORDS:
// Temperature -> Get Data_1
// Pressure -> Get Data_2
// Altitude -> Get Data_3
// Date -> Get Data_4
// Time -> Get Data_5
// Latitude and Longitude -> Get Data_6
// Map Location -> Get Google Maps link using GPS information
// Go Straight -> Send itself as a command to the device
// Go Back -> Send itself as a command to the device
// Go Right -> Send itself as a command to the device
// Go Left -> Send itself as a command to the device
// Halt -> Send itself as a command to the device
// Programmed by
// About
// How r u?
// Further information
// Contact
// Spidey -> Test media transferring
// Batman -> Test media transferring
// Help -> Print all keywords
//
// Connections
// NodeMCU (ESP-12E) :           
//                                GY-NEO6MV2 GPS Module
// D5  --------------------------- RX
// D4  --------------------------- TX
//                                BMP180 Pressure and Temperature Sensor
// D1  --------------------------- SCL
// D2  --------------------------- SDA
//                                L298N Motor Driver
// D3  --------------------------- IN_1
// D6  --------------------------- IN_2
// D7  --------------------------- IN_3
// D8  --------------------------- IN_4


// Include required libraries to send data to a website, in this case to TheAmplituhedron.com.
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

// Include TinyGPS++ to get variables from the GY-NEO6MV2 GPS Module.
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#include <SFE_BMP180.h>
#include <Wire.h>

// You will need to create an SFE_BMP180 object, here called "pressure".
SFE_BMP180 pressure;

// Connect BMP180 SDA and SCL pins to the labeled pins below.
// On NodeMCU ESP8266 12-E:
// D1            SCL
// D2            SDA

// Define a baseline pressure (sea-level or other) in mb to predict altitude. 
#define p0 1013

// Define your WIFI settings.
const char *ssid = "Your_WiFi_SSID";
const char *password = "Your_WiFi_Password";

// Define required variables by TinyGPS++ library.
static const int RXPin = D4, TXPin = D5;
static const uint32_t GPSBaud = 9600;

// Create data holders to send data packets.
String fingerPrint, connectionHub, HEDRON, DATA, Command;
String latitude, longitude, date, month, day, year, _time, hour, minute, second, centisecond;
double Temperature, Pressure, Altitude;

// Define the output pins for the L298N Motor Driver
#define IN_1 D3
#define IN_2 D6
#define IN_3 D7
#define IN_4 D8

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  
  Serial.begin(115200);

  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  
  // Initiate the GPS Module.
  ss.begin(GPSBaud);
  // Initialize the sensor (it is important to get calibration values stored on the device).
  pressure.begin();
  
  // It is just for assuring that if the connection is alive.
  WiFi.mode(WIFI_OFF);
  delay(1000);
  // This mode allows NodeMCU to connect any WiFi directly.
  WiFi.mode(WIFI_STA);        
  // Connect NodeMCU to your WiFi.
  WiFi.begin(ssid, password);
  
  Serial.print("\n\n");
  Serial.print("Try to connect to WiFi. Please wait! ");
  Serial.print("\n\n");
  // Halt the code until connected to WiFi.
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("*");
  }
 
  // If connection is successful, write WiFi SSID to serial monitor along with assigned IPAddress.
  Serial.print("\n\n");
  Serial.print("-------------------------------------");
  Serial.print("\n\n");
  Serial.print("Connection is successful!");
  Serial.print("\n\n");
  Serial.print("Connected WiFi SSID : ");
  Serial.print(ssid);
  Serial.print("\n\n");
  Serial.println("Connected IPAddress : ");
  //Serial.println(WiFi.localIP());
  Serial.print("\n\n");
  
  // Give time to ESP8266 for rebooting properly.
  delay(3000);
  
}

void loop() {
  
  // This sketch displays information every time a new sentence is correctly encoded on the GPS Module.
    while (ss.available() > 0)
    if (gps.encode(ss.read()))
      get_GPS_Data();
  // Check whether the GPS connection is alive or not.
  if (millis() > 5000 && gps.charsProcessed() < 10) { Serial.println("No GPS detected: check wiring."); while(true); }

  // Get temperature, pressure, and altitude from the BMP180 Pressure Sensor.
  get_temperature_pressure_altitude();

  // Send variables to WhatsApp Two-Way Connection Hub to be saved to MySQL Database.
  send_variables_to_server_and_get_command();
  // Activate features by commands.
  activate_commands();
  
}

void get_GPS_Data(){
  Serial.print("\nGathering information from the GPS Module...\n------------------------------\n");
  if(gps.location.isValid()){
      longitude = String(gps.location.lng(), 6);
      latitude = String(gps.location.lat(), 6);
      Serial.print("Location: " + latitude + " , " + longitude + "\n");
  }else{
     longitude = "NotDetected";
     latitude = "NotDetected";
     Serial.print("Location: Not detected...\n");
  }

    if (gps.date.isValid()){
    month = String(gps.date.month());
    day = String(gps.date.day());
    year = String(gps.date.year());
    date = month + "/" + day + "/" + year;
    Serial.print("Date: " + date + "\n");
  }else{
    date = "Failed";
    Serial.print("Date: Failed...\n");
  }

  if (gps.time.isValid()){
    if (gps.time.hour() < 10){ hour = "0" + String(gps.time.hour()); }else{ hour = String(gps.time.hour());}
    if (gps.time.minute() < 10){ minute = "0" + String(gps.time.minute()); }else{ minute = String(gps.time.minute()); } 
    if (gps.time.second() < 10){ second = "0" + String(gps.time.second()); }else{ second = String(gps.time.second()); }
    if (gps.time.centisecond() < 10){ centisecond = "0" + String(gps.time.centisecond()); }else{ centisecond = String(gps.time.centisecond()); }
    _time = hour + ":" + minute + ":" + second + "." + centisecond;
    Serial.print("Time: " + _time + "\n");
  }
  else{
    _time = "Failed";
    Serial.print("Time: Failed...\n");
  }
}

void get_temperature_pressure_altitude(){
// You must first get a temperature measurement to perform a pressure reading.
  
// Start a temperature measurement:
// If request is successful, the number of ms to wait is returned.
// If request is unsuccessful, 0 is returned.

  char status = pressure.startTemperature();
  Serial.print("\nGathering information from the BMP180 Pressure Sensor...\n------------------------------\n");
  if (status != 0){
     // Wait for the measurement to complete:
     delay(status);
     // Retrieve the completed temperature measurement:
     // Note that the measurement is stored in the variable Temperature.
     // Function returns 1 if successful, 0 if failure.
     status = pressure.getTemperature(Temperature);
     if (status != 0){
      Serial.print("Temperature: " + String(Temperature) + " C\n");
      // Start a pressure measurement:
      // The parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
      // If request is successful, the number of ms to wait is returned.
      // If request is unsuccessful, 0 is returned.
      status = pressure.startPressure(0);
        if (status != 0){
          // Wait for the measurement to complete:
          delay(status);
          // Retrieve the completed pressure measurement:
          // Note that the measurement is stored in the variable Pressure.
          // Note also that the function requires the previous temperature measurement(Temperature).
          // (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
          // Function returns 1 if successful, 0 if failure.
          status = pressure.getPressure(Pressure,Temperature);
            if (status != 0){
              Serial.print("Pressure: " + String(Pressure) + " mb\n");
              // Determine your altitude from the pressure reading,
              // use the altitude function along with a baseline pressure (sea-level or other).
              // Parameters: Pressure = absolute pressure in mb, p0 = baseline pressure in mb.
              // Result: a = altitude in m.
              Altitude = pressure.altitude(Pressure,p0);
              Serial.print("Altitude: " + String(Altitude) + " m\n");
              }else{
                Serial.print("Altitude: Failed...\n");
              }

          }else{
            Serial.print("Pressure: Failed...\n");
          }
          
      }else{
        Serial.print("Tempature: None...\n");
      }
  
   }else{
    Serial.print("Tempature: Failed...\n");
   }

   delay(1000);
   
 }

void send_variables_to_server_and_get_command(){
    // Enter the fingerprint.
    fingerPrint = "46 3c 5c 2c 67 11 cd 88 b7 e9 76 74 41 34 48 bd bc a5 b9 cf";

   // Enter your hedron provided by TheAmplituhedron to use the connection hub if you will use WhatsApp Two-Way Connection Hub.
    HEDRON = "Your_Hedron";

    DATA = "/?Data_1=" + String(Temperature) + "*C&Data_2=" + String(Pressure) + "mb&Data_3=" + String(Altitude) + "m&Data_4=" + date + "&Data_5=" + _time + "&Data_6=" + latitude + "," + longitude;
    connectionHub = "https://www.theamplituhedron.com/dashboard/WhatsApp-Two-Way-Connection-Hub/" + HEDRON + DATA;
    
     // Create HTTP object to make a request.
    HTTPClient http;    
    // Send a request. 
    http.begin(connectionHub, fingerPrint);
  
    int httpCode = http.GET();
    Command = http.getString();           
    if(httpCode == 200){ Serial.print("\n\nVariables are transferred to the server successfully!\nComannd: " + Command + "\n"); }else{ Serial.print("Server Failed! Error Code: " + httpCode); }
 
    // End HTTP Get Request.
    http.end();

}

void activate_commands(){
  if(Command == "Go Straight"){
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    }else if(Command == "Go Back"){
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, HIGH);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, HIGH);
    }else if(Command == "Go Right"){
    digitalWrite(IN_1, HIGH);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
    }else if(Command == "Go Left"){
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, HIGH);
    digitalWrite(IN_4, LOW);
    }else if(Command == "Halt"){
    digitalWrite(IN_1, LOW);
    digitalWrite(IN_2, LOW);
    digitalWrite(IN_3, LOW);
    digitalWrite(IN_4, LOW);
    }
  }
