// Define the pins for the speaker and button
int speakerPin = 9;

void setup() {
  // Set the speaker pin as an output
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // Define the frequency of each note in the C major scale
  int c = 262;
  int d = 294;
  int e = 330;
  int f = 349;
  int g = 392;
  int a = 440;
  int b = 494;
  int c2 = 523;
  
  // Play the C major scale using the tone() function and delay()
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
