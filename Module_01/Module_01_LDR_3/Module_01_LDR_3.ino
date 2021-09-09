int value; //declare a new interger variable
int thresshold = 512; //declare 'thresshold' and set it to 512
int ledPin = 13; //declare a int called ledPin and set it to 13;
int ldrPin = A0;

void setup() {
  Serial.begin(9600); // start serial port with 9600 baud rate
  Serial.println("Module_01_LDR"); //print message over serial
  pinMode(A0, INPUT); //set pin A0 as input
  pinMode(ledPin, OUTPUT); // set the pin with the value of variable ledPin (13) as an output)
}


void loop() {
  value = analogRead(ldrPin); //measure the voltage at pin A0 and store it in value
  Serial.print(value); //print the value over serial
  Serial.print("\t"); //print a tab
  Serial.print(0); //print a 0
  Serial.print("\t"); //print another tab
  Serial.println(1024); //print 1024
  
  if (value > thresshold) { //if the value we measure is bigger that the thresshold value we set ledPin to high
    digitalWrite(ledPin, HIGH);
  } else { //else we set it to low
    digitalWrite(ledPin, LOW);
  }
  
}
