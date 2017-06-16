/*
 * RAINBOW RGB LED
 * by Ethan Och
 */

int RED_PIN = 11;
int GRN_PIN = 10;
int BLU_PIN = 9;
int SPEED = 25;
int ONBOARD_LED = 13;

#define COMMON_ANODE

void setup()
{
  //pinMode(RED_PIN, OUTPUT);
  //pinMode(GRN_PIN, OUTPUT);
  //pinMode(BLU_PIN, OUTPUT);
  pinMode(ONBOARD_LED, OUTPUT);
}

void loop()
{
  digitalWrite(ONBOARD_LED, HIGH);
  for(int i = 0; i <= 255; i += 5)
  {
    SET_COLOR(255, i, 0);
    delay(SPEED);
  }

  digitalWrite(ONBOARD_LED, LOW);
  for(int i = 255; i >= 0; i -= 5)
  {
    SET_COLOR(i, 255, 0);
    delay(SPEED);
  }

  digitalWrite(ONBOARD_LED, HIGH);
  for(int i = 0; i <= 255; i += 5)
  {
    SET_COLOR(0, 255, i);
    delay(SPEED);
  }
  
  digitalWrite(ONBOARD_LED, LOW);
  for(int i = 255; i >= 0; i -= 5)
  {
    SET_COLOR(0, i, 255);
    delay(SPEED);
  }

  digitalWrite(ONBOARD_LED, HIGH);
  for(int i = 0; i <= 255; i += 5)
  {
    SET_COLOR(i, 0, 255);
    delay(SPEED);
  }
  
  digitalWrite(ONBOARD_LED, LOW);
  for(int i = 255; i >= 0; i -= 5)
  {
    SET_COLOR(255, 0, i);
    delay(SPEED);
  }
}

void SET_COLOR(int R, int G, int B)
{
  #ifdef COMMON_ANODE
  
  R = 255 - R;
  G = 255 - G;
  B = 255 - B;
  
  #endif
  
  analogWrite(RED_PIN, R);
  analogWrite(GRN_PIN, G);
  analogWrite(BLU_PIN, B);
}
