String serverString;

const int ledGreen = 12;
const int ledRed = 8;
const int ledYellow = 7;


void setup() {
  Serial.begin(9600);
    pinMode(ledGreen, OUTPUT);
    pinMode(ledRed, OUTPUT);
    pinMode(ledYellow, OUTPUT);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
  }

void loop() {
  
  if(Serial.available()) {
  
    serverString = Serial.readStringUntil('\n');
    int strLength = serverString.length();
    
    if(serverString[0] == '1') {
      int machineId = ( (serverString[1] - '0') * 10 ) + (serverString[2] - '0');
      
      int temp = strLength - 3;
      long int time = 0;
      
      for(int i = 3; i < strLength; i++) {
        time += (serverString[i] - '0') * multiplyer(temp);
        temp -= 1;
      }
      
      digitalWrite(machineId, HIGH);
      delay(time);
      digitalWrite(machineId, LOW);
    }
  
  }
}

long int multiplyer(int x) {
  x -= 1;
  long int m = 1;
  for(int i = 0; i < x; i++) {
    m *= 10;
  }
  
  return m;
}
