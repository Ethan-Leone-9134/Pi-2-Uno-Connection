# Pi-2-Uno-Connection
Repository includes the framework for a raspberry pi to arduino connection via usb.

## Example code
The repository includes an example of the connection that allows the raspberry pi to modify the values of digital output pins on the arduino.

### Python
The file ".py" houses the assoicated custom functions for the raspberry pi
#### Functions
`formSerialConnection` - For loop that pings the arduino to establish the connection and store the connection in the `uno` global variable.\n
`resetArduino` - Triggers a 2 second restart for the arduino.\n
`setPin` - Directly communicates information between devices.\n
`cleanup` - Runs on termination of code to safely disconnect devices and rest the arduino
`main` - Sends a looped set of instructions to the arduino

### Arduino
The file ".ino" houses the assoicated custom functions for an arduino uno
