int value; //declare a new interger variable
int returnValue; //declare a new interger called returnValue
long samples; //declare a new long variable called result

int thresshold = 512; //declare 'thresshold' and set it to 512
int ledPin = 13; //declare a int called ledPin and set it to 13;

void setup() {
  Serial.begin(9600); // start serial port with 9600 baud rate
  Serial.println("Module_01_LDR"); //print message over serial
  pinMode(A0, INPUT); //set pin A0 as input
  pinMode(ledPin, OUTPUT); // set the pin with the value of variable ledPin (13) as an output)
}


void loop() {
  value = niceRead(A0, 200); //call the function 'niceRead' with two variables (A0 and 20). A0 is the pin that we're measuring, 200 is the amount of samples we take
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

int niceRead(int thePin, int numSamples) { //make a new function colled niceRead. This function needs two variables to work; thePin and numSamples
  samples = 0; //set samples to 0
  for (int i = 0; i < numSamples; i++) { //this is a for loop;
    samples = samples + analogRead(thePin); //measure the voltage at 'thePin' 'numSamples' times and add the values together.
  }
  returnValue = int(samples / numSamples); //devide the total value stored in samples by the amount of samples taken. Cast this number to an int to make (if we don't castit to an it the value could be a float and we get an error
  return returnValue; //return the value
}
