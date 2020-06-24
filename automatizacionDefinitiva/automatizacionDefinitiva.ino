#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "S731N N3TW0RK";
const char* password = "s0y_el pute b1n4r1e/";
const long utcOffsetInSeconds = -10900;

char diasDeLaSemana[7][12] = {"Domingo", "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado"};

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ar.pool.ntp.org", utcOffsetInSeconds);


void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  timeClient.begin();
}

void loop() {
  leerTiempo();
  compararHorario();
}

void leerTiempo() {
  //Obtiene el dia (1~7) de NTP y lo imprime en el index de diasDeLaSemana.
  Serial.print(diasDeLaSemana[timeClient.getDay()]);
  Serial.print(", ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.print(timeClient.getSeconds());
  Serial.print(":");
  delay(1000);
}

int obtenerHora() {
  time
  return horaActual;
}
