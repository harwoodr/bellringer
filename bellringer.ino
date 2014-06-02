//Set Pin 13 as outputs to relay - should also light LED
//Set Pin 12 as input from button
const int buttonPin = 12;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin

// Variables will change:
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

// timing for on/off
long pulseTime = 250 - debounceDelay;	//time between pulses in ms
long onTime = 125;						//adjust up/down to increase/decrease contact time
long offTime = pulseTime - onTime;		//time to wait until next onTime
	
void setup()
{
	pinMode(buttonPin, INPUT);
	pinMode(ledPin, OUTPUT);
	
	// set initial LED state
	digitalWrite(ledPin, LOW);
}
void loop()
{
	// read the state of the switch into a local variable:
	int reading = digitalRead(buttonPin);
	
	// check to see if you just pressed the button
	// (i.e. the input went from LOW to HIGH),  and you've waited
	// long enough since the last press to ignore any noise:  
	
	// If the switch changed, due to noise or pressing:
	if (reading != lastButtonState) {
		// reset the debouncing timer
		lastDebounceTime = millis();
	}
	
	if ((millis() - lastDebounceTime) > debounceDelay) {
		// whatever the reading is at, it's been there for longer
		// than the debounce delay, so take it as the actual current state:
		
		// if the button state has changed:
		if (reading != buttonState) {
			buttonState = reading;
			
			// only toggle the LED if the new button state is HIGH
			if (buttonState == HIGH) {
				// set the LED:
				for(int i=0;i<=3;i++){
					digitalWrite(ledPin, HIGH);
					delay(onTime);
					digitalWrite(ledPin, LOW);		
					delay(offTime);
				}
		  	}
		}
	}
	


	
	
	// save the reading.  Next time through the loop,
	// it'll be the lastButtonState:
	lastButtonState = reading;	
}