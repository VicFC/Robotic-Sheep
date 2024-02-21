
// ---------------------------------------------------------------- // 
// Arduino Origami Bot 
// Created by Daniel Jordan, USF Department of Engineering
// Using Arduino IDE 1.8.19
// Tested Jan. 20 2023
// ---------------------------------------------------------------- // 

#define IN1 4 // connect IN1 on the H-Bridge to Arduino pin 4
#define IN2 5 // connect IN2 on the H-Bridge to Arduino pin 5

#define IN3 9 // connect IN3 on the H-Bridge to Arduino pin 9
#define IN4 10 // connect IN4 on the H-Bridge to Arduino pin 10

void setup()
{ 
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop() {
    // Moves the robot straight for 1.5 seconds
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(1500);
    
    // Turns the robot for 1.0 seconds
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(1000);

    // Moves the robot backwards for 1.0 seconds
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(1000);
    
    // Stops the robot for 1.0 seconds
    digitalWrite(IN2, LOW);
    digitalWrite(IN4, LOW);
    delay(1000);
}  
