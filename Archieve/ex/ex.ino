char *data = "[08:30:15]1.2.3.4=99";
int hour = 14;
int minute = 4;
int number = 3;
char string[16];

void setup() {
  Serial.begin(115200);
  Serial.println("\nInitializing");
  Serial.println(data);
  sscanf(data, "[%02d:%02d:%*d]%15s=%02d", hour, minute, string, number);
  Serial.println(hour);
  Serial.println(minute);
  Serial.println(string);
  Serial.println(number);
}

    
void loop() {}
