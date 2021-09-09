int value; //declare a new interger variable

void setup() {
  Serial.begin(9600); // start serial port with 9600 baud rate
  Serial.println("Module_01_Potentiometer"); //print message over serial 
  pinMode(A0, INPUT); //set pin A0 as input
}


void loop() {
  value = analogRead(A0); //measure the voltage at pin A0 and store it in the int 'value' 
  Serial.println(value); //print the value over serial
}
