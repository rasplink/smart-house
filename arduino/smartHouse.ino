#include <ESP8266WiFi.h>

const char *ssid = "wifiName";
const char *password = "wifiPassword";

int pin6 = D6;
int pin7 = D7;
WiFiServer server(80);

void setup()
{
  Serial.begin(9600);
  delay(10);

  // special case to wemos d1 wifi, high means off, low means on
  // relays | initial status
  // 6
  pinMode(pin6, OUTPUT);
  digitalWrite(pin6, HIGH);
  // 7
  pinMode(pin7, OUTPUT);
  digitalWrite(pin7, HIGH);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop()
{
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available())
  {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // handle pins signal (on/off) based on the endpoint route
  int value6 = HIGH;
  int value7 = HIGH;
  // 6
  if (request.indexOf("/pin6/on") != -1)
  {
    digitalWrite(pin6, LOW);
    value6 = LOW;
  }
  if (request.indexOf("/pin6/off") != -1)
  {
    digitalWrite(pin6, HIGH);
    value6 = HIGH;
  }
  // 7
  if (request.indexOf("/pin7/on") != -1)
  {
    digitalWrite(pin7, LOW);
    value7 = LOW;
  }
  if (request.indexOf("/pin7/off") != -1)
  {
    digitalWrite(pin7, HIGH);
    value7 = HIGH;
  }

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Access-Control-Allow-Origin: *");
  client.println("Content-Type: application/json");
  client.println(""); // do not forget this one
  client.println("{success: true}");

  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
