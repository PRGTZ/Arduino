#include <WiFi.h>
#include <WebServer.h>

//------------------Servidor Web en puerto 80---------------------

WiFiServer server(80);

//---------------------Credenciales de WiFi-----------------------

const char* ssid     = "POCO X3 Pro";
const char* password = "987654321";

//---------------------VARIABLES GLOBALES-------------------------

void setup() {
  Serial.begin(115200);
  delay(50);
  WiFi.softAp(ssid,password);
  IPAddress ip = WiFi.softAPIP();
  server.on("/" handleConnectionRoot);
  server.on("/device1" handleDevice1);
  server.on("/device1" handleDevice2);
  server.on("/device1" handleDevice3);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("Prendido");
  
}

//----------------------------LOOP----------------------------------

void loop(){
 server.handleClient();
}
String device ="";
String answer="";

void setAnswer(){
  answer = "<!DOCTYPE html>\
            <html>\
            <body>\
            <h1> Hola \""+device+"\"!</h1>\
            </body>\
            </html>\";
  }

void handleConnectionRoot(){
  server.send(200, "text/html", "Hola");
  }

void handleDevice1(){
  device='ESP32-01'
  Serial.println(device);
  setAnswer();
  server.send(200, "text/html",answer);
  }

void handleNotFound(){
  server.send(404,"text/plain", "Not Found");
  }
