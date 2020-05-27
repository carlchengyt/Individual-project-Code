#include <SPI.h>
#include <WiFly.h>

// Wifi parameters
char passphrase[] = "12344321";
char ssid[] = "carl";

WiFlyClient client("google.com", 80);

void setup() {
  
  Serial.begin(9600);

  WiFly.begin();
  
  if (!WiFly.join("carl", "12344321")) {
    Serial.println("Association failed.");
    while (1) {
      // Hang on failure.
    }
  }  

  Serial.println("connecting...");

  if (client.connect()) {
    Serial.println("connected");
    client.println("GET /search?q=arduino HTTP/1.0");
    client.println();
  } else {
    Serial.println("connection failed");
  }
  
}

void loop() {
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    for(;;)
      ;
  }
}
