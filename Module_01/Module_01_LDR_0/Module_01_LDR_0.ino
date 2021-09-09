int value; //declare a new interger variable

void setup() {
  Serial.begin(9600); // start serial port with 9600 baud rate
  Serial.println("Module_01_LDR"); //print message over serial
  pinMode(A0, INPUT); //set pin A0 as input
}


void loop() {
  value = analogRead(A0); //measure the voltage at pin A0 and store it in the int 'value'
  Serial.print(value); //print the value over serial
  Serial.print("\t"); //print a tab
  Serial.print(0); //print a 0
  Serial.print("\t"); //print another tab
  Serial.println(1024); //print 1024
  //by printing a 0 and 1024 we defina a min and max value in the serial plotter. Now when we open the serial plotter arduino's software doesn't auto scale the values anymore
  
}
