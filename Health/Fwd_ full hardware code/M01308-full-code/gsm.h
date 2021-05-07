#ifndef GSM_H
#define GSM_H

void send_sms(String number, String text)
{
  Serial1.println("AT");
  delay(500);
  Serial1.println("AT+CMGF=1");
  delay(500);
  Serial1.println("AT+CMGS=\"+91"+number+"\"\r");
  delay(500);
  Serial1.println(text);
  delay(500);
  Serial1.println(char(26));
  delay(1000);
}
#endif
