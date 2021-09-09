int value; //declare a new interger variable
int returnValue; //declare a new interger called returnValue
long samples; //declare a new long variable called result

void setup() {
  Serial.begin(9600); // start serial port with 9600 baud rate
  Serial.println("Module_01_Potentiometer"); //print message over serial
  pinMode(A0, INPUT); //set pin A0 as input
}


void loop() {
  value = niceRead(A0, 20); //call the function 'niceRead' with two variables (A0 and 20). A0 is the pin that we're measuring, 20 is the amount of samples we take
  Serial.println(value); //print the value over serial
}

int niceRead(int thePin, int numSamples) { //make a new function colled niceRead. This function needs two variables to work; thePin and numSamples
  samples = 0; //set samples to 0
  for (int i = 0; i < numSamples; i++) { //this is a for loop;
    samples = samples + analogRead(thePin); //measure the voltage at 'thePin' 'numSamples' times and add the values together.
  }
  returnValue = int(samples / numSamples); //devide the total value stored in samples by the amount of samples taken. Cast this number to an int to make (if we don't castit to an it the value could be a float and we get an error
  return returnValue; //return the value
}
