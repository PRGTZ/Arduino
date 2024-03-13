#define LED 7            // Led in NodeMCU at pin GPI016 (DO).
#define LED1 6

void setup () {
pinMode (LED, OUTPUT);      // LED pin as output.
Serial.begin(9600);
pinMode (LED1, OUTPUT);     
Serial.begin(9600);
}

void loop () 
{
  Serial.println("LED PARPADEANDO");
digitalWrite (LED, HIGH);   // turn the LED off. (Note that LOw is tho
                            //the LED is on; this is because it is ad
delay (100);                // wait for 1 second.
digitalWrite (LED, LOW); // turn the LED on. 
delay (100); // wait for 1 second.
}
