# Pi-2-Uno-Connection
Repository includes the framework for a raspberry pi to arduino connection via usb. The python converts the data into a three digit integer. This integer is then converted and sent over to the arduino, which converts the integer into usable information (Pin and Value).

### Example code
The repository includes an example of the connection that allows the raspberry pi to modify the values of digital output pins on the arduino. There is support for reading print statements from the arduino.

### Python
The file `serialBridge.py` houses the assoicated custom functions for the raspberry pi
#### Functions
`formSerialConnection` - For loop that pings the arduino to establish the connection and store the connection in the `uno` global variable.<br />
`resetArduino` - Triggers a 2 second restart for the arduino.<br />
`setPin`- Directly communicates information between devices.<br />
`cleanup` - Runs on termination of code to safely disconnect devices and rest the arduino.<br />
`main` - Sends a looped set of instructions to the arduino.

### Arduino
The file `serialBridge.ino` houses the assoicated custom functions for an arduino uno
#### Functions
`readIntFromSerial` - Waits for input from the pi and converts the three digit number into an int variable. <br />
`loop` - Deconstructs the input value and sets the values accordingly
