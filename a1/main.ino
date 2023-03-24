#define right1 8
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

const int SPEED = 120;

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

void loop() {
  bool right = infared(right_i);
  bool left = infared(left_i);
  int distance = ultra(ultping, ultecho);
  bool far = distance > 25;
  bool close = distance < 15;

  sprint("right: ");
  sprint(right);
  sprint(" left: ");
  sprint(left);
  sprint(" distance: ");
  sprintln(distance);



  if (left && right && far) {
    go_forward(SPEED);
  } else if (left && !right && far) {
    go_left(SPEED, true);
  } else if (left && !right && close) {
    go_left(SPEED, false);
  } else if (!left && right && far) {
    go_right(SPEED, true);
  } else if (!left && right && close) {
    go_right(SPEED, false);
  } else if (!left && !right && far) {
    go_forward(SPEED);
  } else if (!left && !right && close) {
    go_back(SPEED);
  } else if (left && right && close) {
    go_back(SPEED);
  }
}