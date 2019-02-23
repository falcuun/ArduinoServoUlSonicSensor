#include <Servo.h>

#define TRIG_PIN 2
#define ECHO_PIN 3
#define SERVO_PIN 6

int starting_distance;
Servo myservo;

void setup()
{
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    myservo.attach(SERVO_PIN);
    starting_distance = get_distance();
    Serial.begin(9600);
}
void loop()
{
    int temp_distance = get_distance();
    if (temp_distance < starting_distance - 3)
    {
        myservo.write(90);
        delay(150);
    }
    else
    {
        myservo.write(-90);
        delay(150);
    }
}

int get_distance()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(5);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(15);
    digitalWrite(TRIG_PIN, LOW);

    int duration = pulseIn(ECHO_PIN, HIGH);
    return duration / 58;
}