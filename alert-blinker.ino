void setup() {
  // put your setup code here, to run once:
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
tone(12,500);
delay(1000);
noTone(12);
delay(500);
tone(12,500);
delay(1000);
noTone(12);
delay(500);
tone(12,500);
delay(1000);
noTone(12);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(11,HIGH);
delay(10000);
digitalWrite(11,LOW);
delay(1000);
}
