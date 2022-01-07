
const int ledPin = 13;
int MIN_DELAY = 100;
int MAX_DELAY = 5000;

bool loaded = false;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  delay(1000);
}

void injectCommand() {
  
   digitalWrite(ledPin, HIGH); 
   Keyboard.press(MODIFIERKEY_GUI);
   Keyboard.press(KEY_R);
   delay(MIN_DELAY);
 
   Keyboard.release(MODIFIERKEY_GUI);
   Keyboard.release(KEY_R);
   delay(MIN_DELAY);
   
   Keyboard.print("cmd");
   delay(MIN_DELAY);
 
   Keyboard.press(KEYPAD_ENTER);
   delay(MIN_DELAY);
   Keyboard.release(KEYPAD_ENTER);

   delay(MIN_DELAY);
   Keyboard.print("ping 8.8.8.8");

   delay(MIN_DELAY);

   Keyboard.press(KEYPAD_ENTER);
   delay(MIN_DELAY);
   Keyboard.release(KEYPAD_ENTER);

  delay(MAX_DELAY);

   Keyboard.print("exit");
   delay(MIN_DELAY);
   
   Keyboard.press(KEYPAD_ENTER);
   delay(MIN_DELAY);
   Keyboard.release(KEYPAD_ENTER);

   digitalWrite(ledPin, LOW); 
}

void loop() {

  if(!loaded) {
    loaded = true;
    injectCommand();
  }
  delay(5000);
}
