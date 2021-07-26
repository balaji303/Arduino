#include <ESP8266WiFi.h> 
const char* ssid = "JINKALALA";
const char* password = "BALAJI303123"; 
int button_two = 13; //d7
int button_one = 12;//d6
WiFiServer server(80);//browser port 80 
void setup() {
  Serial.begin(9600);

delay(10);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
digitalWrite(13, LOW);
digitalWrite(12, LOW); 
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
      // Match the request button_2 
      int v1 = LOW;
      if (request.indexOf("/button_2=ON") != -1) { 
        digitalWrite(13, HIGH);
        v1 = HIGH;
        }
        if (request.indexOf("/stop") != -1) { 
          digitalWrite(13, LOW); 
          v1 = LOW;
          }
          // Match the request button_1
          int v2 = LOW;
          if (request.indexOf("/button_1=ON") != -1) { 
            
  digitalWrite(12, HIGH);
  v2 = HIGH;
  } 
  if (request.indexOf("/stop") != -1) { 
    digitalWrite(12, LOW);
    v2 = LOW;
    }
    // Return the response
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");// do not forget this one
    client.println("<!DOCTYPE HTML>");
    client.println("<html>"); 
    client.println("<head>");
    client.println("<center>");
    //client.println("<h1>RESPROLABS NODEMCU SERVER DEMO(</h1>"); 
    client.println("<h1>Rajalakshmi Institude of Technology(</h1>");
    client.println("<br>"); 
    client.println("<h1>STATUS=</h1>"); 
    client.println("</center>");
    client.println("</head>");
    if (v1 == HIGH){
      client.print("THE DEVICE IS ON");
      } else { 
client.print("THE DEVICE IS OFF");
} 
client.println("<body>");
client.println("<center>"); 
client.println("<br><br>"); 
client.println("<a href=\"/button_2=ON\"\"><button>DEVICE_1</button></a>");
client.println("<a href=\"/stop\"\"><button>STOP</button></a><br />");
client.println("<a href=\"/button_1=ON\"\"><button>DEVICE_2</button></a>"); 
client.println("</center>");
client.println("</body>");
client.println("</html>"); 
delay(1); 
Serial.println("Client disonnected"); 
Serial.println(""); 
} 
 
 
        


