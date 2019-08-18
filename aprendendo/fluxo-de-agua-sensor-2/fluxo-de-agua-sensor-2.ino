const byte interruptPin = 2;
volatile byte interruptCounter = 0;
int numberOfInterrupts = 0;

void ICACHE_RAM_ATTR handleInterrupt() {
  interruptCounter++;
}

 
void setup() {
 
  Serial.begin(115200);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, CHANGE);

  Serial.println("Inicando...");
 
}

 
void loop() {
 
  if(interruptCounter>0){
 
      interruptCounter--;
      numberOfInterrupts++;
 
      Serial.print("An interrupt has occurred. Total: ");
      Serial.println(numberOfInterrupts);
  }
 
}
