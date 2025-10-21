int leds[] = {2, 3, 4, 5, 6};
int n = 5;
String data = "";
int i = 0;
int dir = 1;
bool state = false;

void setup() {
  for (int j = 0; j < n; j++) {
    pinMode(leds[j], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.readStringUntil('\n');
    if (data == "OFF") {
      for (int j = 0; j < n; j++) digitalWrite(leds[j], LOW);
    } else if (data == "ALLON") {
      for (int j = 0; j < n; j++) digitalWrite(leds[j], HIGH);
    } else if (data == "PAT1") {
      for (int j = 0; j < n; j++) {
        digitalWrite(leds[j], LOW);
      }
      digitalWrite(leds[i], HIGH);
      i = (i + 1) % n;
      delay(200);
    } else if (data == "PAT2") {
      for (int j = 0; j < n; j++) {
        digitalWrite(leds[j], LOW);
      }
      digitalWrite(leds[i], HIGH);
      i += dir;
      if (i == n - 1 || i == 0) dir = -dir;
      delay(200);
    } else if (data == "PAT3") {
      state = !state;
      for (int j = 0; j < n; j++) digitalWrite(leds[j], state);
      delay(400);
    } else if (data == "PAT4") {
      state = !state;
      for (int j = 0; j < n; j++) {
        if (state && j % 2 == 0) digitalWrite(leds[j], HIGH);
        else if (!state && j % 2 == 1) digitalWrite(leds[j], HIGH);
        else digitalWrite(leds[j], LOW);
      }
      delay(300);
    } else if (data == "PAT5") {
      for (int j = 0; j < n; j++) digitalWrite(leds[j], LOW);
      digitalWrite(leds[random(n)], HIGH);
      delay(150);
    }
  }
}
