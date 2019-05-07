#include <MKRGSM.h>

GSM gsmAccess;
GSM_SMS sms;

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by
int led = 13;           // the PWM pin the LED is attached to

char senderNumber[20];

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("SMS Messages Receiver");
  boolean connected = false;
  gsmAccess.begin();
  Serial.println("GSM initialized");
  Serial.println("Waiting for messages");
}

void loop() {
  int c;
  if (sms.available()) {
    Serial.println("Message received from:");
    if (sms.peek() == '#') {
      Serial.println("Discarded SMS");
      sms.flush();
    }
    while ((c = sms.read()) != -1) {
      if (c == '1') {
        Serial.println("woo!");
        // Turn on LED
        digitalWrite(LED_BUILTIN, HIGH);
        delay(5000);
        // Turn off LED
        digitalWrite(LED_BUILTIN, LOW);
        delay(3000);
      } else if (c == '0') {
        Serial.println("sad!");
      } else {
        Serial.println("incorrect message");
      }
    }
    Serial.println("\nEND OF MESSAGE");
    sms.flush();
    Serial.println("MESSAGE DELETED");
  }
  delay(1000);
}
