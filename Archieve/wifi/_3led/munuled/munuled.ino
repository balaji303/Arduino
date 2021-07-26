#include "ESP8266WiFi.h" 
const char* ssid = "JINKALALA";
const char* password = "BALAJI303123"; 
int button_1 = 13; //d7
int button_2 = 12;//d6
int button_3 = 14;//d5
WiFiServer server(80);//browser port 80 
void setup() {
  Serial.begin(9600);

delay(10);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(14, OUTPUT);
digitalWrite(13, LOW);
digitalWrite(12, LOW);
digitalWrite(14, LOW); 
// Connect to WiFi network  
Serial.println(); 
 Serial.println(); 
 
 Serial.print("Connecting to ");
 Serial.println(ssid);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED)
 { delay(500);
 Serial.print(".");
 } 
 Serial.println(""); 
 Serial.println("WiFi connected");
 // Start the server
 server.begin();
 Serial.println("Server started"); 
 // Print the IP address
 Serial.print("Use this URL to connect: "); 
 Serial.print("http://"); 
 Serial.print(WiFi.localIP());
 Serial.println("/"); 
 }
 void loop()
 {
  // Check if a client has connected 
  WiFiClient client = server.available(); 
  if (!client) { 
    return;
    }
    // Wait until the client sends some data
    Serial.println("new client");
    while (!client.available()) {
      delay(1);
      }
      // Read the first line of the request
      String request = client.readStringUntil('\r');
      Serial.println(request);
      client.flush(); 
      // Match the request button_1
      int v1 = LOW;
      if (request.indexOf("/button_1=ON") != -1) { 
        digitalWrite(13, HIGH);
        v1 = HIGH;
        }
        if (request.indexOf("/stop") != -1) { 
          digitalWrite(13, LOW); 
          v1 = LOW;
          }
          // Match the request button_2
          int v2 = LOW;
          if (request.indexOf("/button_2=ON") != -1) { 
            digitalWrite(12, HIGH);
  v2 = HIGH;
  } 
  if (request.indexOf("/stop") != -1) { 
    digitalWrite(12, LOW);
    v2 = LOW;
    }
// Match the request button_3
          int v3 = LOW;
          if (request.indexOf("/button_3=ON") != -1) { 
            digitalWrite(14, HIGH);
  v3 = HIGH;
  } 
  if (request.indexOf("/stop") != -1) { 
    digitalWrite(14, LOW);
    v3 = LOW;
    }
    // Return the response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");// do not forget this one
    client.println("<!DOCTYPE HTML>");
    client.println("<html>"); 
    client.println("<head>");
    client.println("<center>");
    client.println("<h1>Rajalakshmi Institude of Technology</h1>");
    client.println("<br>"); 
    client.println("<h1>STATUS=</h1>"); 
    client.println("</center>");
    client.println("</head>");
    if (v1||v2||v3 == HIGH){
      client.print("THE DEVICE IS ON");
      } else { 
client.print("THE DEVICE IS OFF");
} 
client.println("<body>");
client.println("<center>"); 
client.println("<br><br>"); 
client.println("<a href=\"/button_1=ON\"\"><button>GREEN</button></a>");
client.println("<a href=\"/button_2=ON\"\"><button>WHITE</button></a>");
client.println("<a href=\"/button_3=ON\"\"><button>RED</button></a>"); 
client.println("<a href=\"/stop\"\"><button>STOP</button></a><br />");
client.println("</center>");
client.println("</body>");
client.println("</html>"); 
delay(1); 
Serial.println("Client disonnected"); 
Serial.println(""); 
} 
 
 
        
