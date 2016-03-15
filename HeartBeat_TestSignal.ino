// File: HeartBeat_TestSignal.ino
//   Copyright (c) 2014 Sean Gomez Licensed under CC BY 4.0
//   http://creativecommons.org/licenses/by/4.0/
// NOTES
//   Simulates a heartbeat signal using sin(rad) function
//   sin() range is -1 to 1, move and map to ASCII terminal column range
//   Use with processing to visualize on PC.
// TESTING
//   View as ASCII barchart or int values via boolean displayAsVisual

#define SIN_CYCLE      6.283  //(2 * Pi)
#define STEP           0.2
#define SCALE          18  // ~(80 cols/4 (4 is range of 2+sin(2n))

boolean displayAsVisual = true;
float n, val;

void setup () {
  Serial.begin(9600);
}

void loop () {
  for (n = 0; n < SIN_CYCLE; n = n + STEP) {
    val = (sin(n) + sin(2*n) + 2) * SCALE;
    if (displayAsVisual) { // Display in serial terminal
      for (int num = (int)val; num > 0; num-- )
        Serial.print(' ');
      Serial.println('*');
    } else
      Serial.println((int)val);
    delay(30);
  }  
}
