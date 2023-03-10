#define sag1 8
#define sag2 10
#define sol1 3
#define sol2 11
#define buz 13
#define solK 8
#define sagK 12
#define ortU A1
#define out(x) pinMode(x, OUTPUT)
#define in(x) pinMode(x, INPUT)
#define sprint(x) Serial.print(x)
#define sprintln(x) Serial.println(x)
#define awrite(x,y) analogWrite(x,y)
#define dread(x) digitalRead(x)

void setup() {
  out(sag1);
  out(sag2);
  out(sol1);
  out(sol2);

  in(sagK);
  in(solK);
  in(ortU);
  Serial.begin(9600);
}

void loop() {
  
}
