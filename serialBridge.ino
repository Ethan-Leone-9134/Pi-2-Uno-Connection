// Code takes input from a pi as a three digit number (aab) where
//  "aa" is the pin code and "b" is the targeted value


void setup() {
  // Set up pin as an output
  for (int i=3; i<=12; i++){
  pinMode(i, OUTPUT);
  }

  // Set up serial communication at 115200 baud rate
  Serial.begin(115200);
}

void loop() {
  // Read the current duty cycle from the Raspberry Pi over serial communtication 
  // and set the corresponding motor to the information input
  if (Serial.available() > 0 ) {                              // Only run if there is something in the serial buffer 
    int inputNumber = readIntFromSerial();                    // Custom function to convert the input into an "int"
    int inputValue = inputNumber % 10;                        // Finds input value by finding the remainder of dividing by 10
    int inputPin = (inputNumber - inputValue) / 10;           // Finds input pin number through math
    digitalWrite(inputPin, inputValue);
    Serial.println("Pin #" + String(inputPin) + " set to " + String(inputValue));
  }
  delay(10);        // Wait for a short period to allow motor to respond
}



int readIntFromSerial() {
  // Function converts pi input into an int number
  // Inputs  - none
  // Outputs - result (int) - resultign three digit number

  while (Serial.available() == 0);      // wait for serial data to be available
  unsigned long startTime = millis();   // Get start time
  char input[3];                        // Initialize input variable
  for (int i = 0; i < 3; i++) {         // Set the three characters
    if (Serial.available() > 0){          // If the serial buffer has a character
      input[i] = Serial.read();             // Add the serial character to the "input" variable
    }
    else {                                // If the serial buffer is empty
      input[i] = 0;                         // Set the character to zero to push it along
    }
  }
  input[3]='\0';                        // Ending character
  int result = String(input).toInt();   // convert the input to an integer
  return result;                        // return the resultant integer value
}
