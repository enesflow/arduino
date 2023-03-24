#define right1 9
#define right2 10
#define left1 3
#define left2 11
#define buz 13
#define left_i 8
#define right_i 12
#define ultping A0
#define ultecho A1
#define out(x) pinMode(x, OUTPUT)
#define in(x) pinMode(x, INPUT)
#define sprint(x) Serial.print(x)
#define sprintln(x) Serial.println(x)
#define awrite(x,y) analogWrite(x,y)
#define dread(x) digitalRead(x)
#define dwrite(x,y) digitalWrite(x,y)

const int SPEED = 160;

void setup() {
  out(right1);
  out(right2);
  out(left1);
  out(left2);

  in(right_i);
  in(left_i);

  out(ultping);
  in(ultecho);

  Serial.begin(9600);
}
const int des = 25;
bool prev = true; // true: right, false: left
bool prev2 = true; // true: forward, false: backwards
void loop() {
  bool right = infared(right_i);
  bool left = infared(left_i);
  int distance = ultra(ultping, ultecho);
  sprint(left);
  sprint(" ");
  sprint(right);
  sprint(" ");
  sprint(distance);
  sprintln();
  
  // rotation
  if (right && !left) {
    if (prev) brake();
    prev = false;
    go_left(SPEED, distance > des);
  } else if (!right && left) {
    if (!prev) brake();
    prev = true;
    go_right(SPEED, distance > des);
  } else if (!right && !left && distance > des) {
    if (prev) go_right(SPEED, false);
    else go_left(SPEED, false);
  } else { // direction correct
    sprintln("-_-");
    if (distance > des) {
      if (!prev2) brake();
      prev2 = true;
      go_forward(SPEED);
    } else if (distance < des - 5) {
      if (prev2) brake();
      prev2 = false;
      go_back(SPEED);
    } else {
      prev2 = true;
      brake();
    }
  }
}
