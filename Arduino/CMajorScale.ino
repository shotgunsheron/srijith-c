int speakerPin = 9;

void setup() {
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  int c = 262;
  int d = 294;
  int e = 330;
  int f = 349;
  int g = 392;
  int a = 440;
  int b = 494;
  int c2 = 523;
  
  tone(speakerPin, c);
  delay(500);
  tone(speakerPin, d);
  delay(500);
  tone(speakerPin, e);
  delay(500);
  tone(speakerPin, f);
  delay(500);
  tone(speakerPin, g);
  delay(500);
  tone(speakerPin, a);
  delay(500);
  tone(speakerPin, b);
  delay(500);
  tone(speakerPin, c2);
  delay(500);
}
