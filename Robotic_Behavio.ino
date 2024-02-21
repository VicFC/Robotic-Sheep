#include <Servo.h>
 
const int trigPin = 9;  // Pin del detector de proximidad
const int echoPin = 10; // Pin del detector de proximidad
long duration;
int distance;
Servo motorD; // Objeto para controlar el servo
Servo motorI; // Objeto para controlar el servo
int m1Pin = 5; // Pin al que está conectado el servo 1
int m1Pin2 = 6; // Pin al que está conectado el servo 1
int ledPinQ = 2;  // Pin para la luz LED 'q'
int ledPinE = 3;  // Pin para la luz LED 'e'
int ledPinReverse = 4;  // Pin para la luz LED reversa

void setup() {
  Serial.begin(9600); //Comienza la comunicación serie
  pinMode(trigPin, OUTPUT); // Settea trigPin como output
  pinMode(echoPin, INPUT); // Settea echoPin como input
  pinMode(ledPinQ, OUTPUT);  // Configura el pin de la luz LED de 'q' como salida
  pinMode(ledPinE, OUTPUT);  // lo mismo pero con la opción 'e'
  pinMode(ledPinReverse, OUTPUT);  // lo mismo pero para reversa
  motorD.attach(m1Pin); // Conecta el objeto motor al pin del servo
  motorI.attach(m1Pin2); // Lo mismo pero al motor 2
  motorD.write(90);    // Establece la posición inicial del motor 1 en 90 grados, la cual es la posicion neutra.
  motorI.write(15);    // Lo mismo pero al motor 2. La posición neutra es 15 porque está descalibrado.
}
void loop() {
  sensorReversa(proximidad());
  if (Serial.available()) {  // Verifica si hay datos disponibles en el puerto serie
    char c = Serial.read();  // Lee el carácter ingresado
    switch (c) {
      case 'w': // Avanza
        Serial.println("adelante");
        motorD.write(105);
        motorI.write(-360);
        digitalWrite(ledPinReverse, LOW);
        digitalWrite(ledPinE, LOW);
        digitalWrite(ledPinQ, LOW);
        break;
      case 'a': // Retrocede
        Serial.println("izquierda");
        motorD.write(200);
        motorI.write(165);
        digitalWrite(ledPinReverse, LOW);
        digitalWrite(ledPinE, LOW);
        digitalWrite(ledPinQ, LOW);
        break;
      case 's': // Gira a la izquierda
        Serial.println("atrás");
        motorD.write(0);
        motorI.write(165);
        digitalWrite(ledPinE, LOW);
        digitalWrite(ledPinQ, LOW);        
        break;
      case 'd': // Gira a la derecha
        Serial.println("derecha");
        motorD.write(0);
        motorI.write(0);
        digitalWrite(ledPinReverse, LOW);
        digitalWrite(ledPinE, LOW);
        digitalWrite(ledPinQ, LOW);
        break;
      case 'q': // Enciende la luz LED de 'q'
        Serial.println("LED q");
        digitalWrite(ledPinQ, HIGH);
        digitalWrite(ledPinReverse, LOW);
        digitalWrite(ledPinE, LOW);
        break;
      case 'e': // Enciende la luz LED de 'e'
        Serial.println("LED e");
        digitalWrite(ledPinE, HIGH);
        digitalWrite(ledPinReverse, LOW);
        digitalWrite(ledPinQ, LOW);
        break;
      case 'r': // Pone los motores en su posición neutral
        Serial.println("detenerse");
        digitalWrite(ledPinReverse, LOW);
        motorD.write(90);
        motorI.write(15);
        digitalWrite(ledPinE, LOW);
        digitalWrite(ledPinQ, LOW);
        break;
      default:
        Serial.println("Letra no válida");
        break;
    }
  }
}
void sensorReversa(int distancia){
  if(distancia<10)
    digitalWrite(ledPinReverse, HIGH);
  else if (distancia==0 || distancia ==5 || distancia ==6 || distancia ==2)
    digitalWrite(ledPinReverse, LOW);
  else
    digitalWrite(ledPinReverse, LOW);
}
int proximidad(){ // Recibe la distancia a la que está el sensor de un obstaculo
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
