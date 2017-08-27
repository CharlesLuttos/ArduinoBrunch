#define ldr 1
#define led 11
int luz;

void setup() {
  pinMode(ldr,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  luz = analogRead(ldr)/4.0117647059;
  analogWrite(led,luz);
  Serial.println(luz);
}
