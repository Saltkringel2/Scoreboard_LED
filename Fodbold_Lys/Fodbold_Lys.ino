//**************************************************************//
//  Name    : Fodbold_Lys                                
//  Author  : Jacob Kjær Terp, Peter Madsen 
//  Date    : 23 Aug, 2017    
//  Modified: 23 Aug, 2017                                 
//  Version : 1.0                                                                        
//****************************************************************

//Pin connected to ST_CP of 74HC595
int latchPin = 6; 
//Pin connected to SH_CP of 74HC595
int clockPin = 9;
////Pin connected to DS of 74HC595
int dataPin = 3;

int input;

byte tal[11] = {
	B00000100, // 0
	B11110101, // 1
	B00101000, // 2
	B01100000, // 3
	B01010001, // 4
	B01000010, // 5
	B00000010, // 6
	B01110100, // 7
	B00000000, // 8
	B01000000, // 9
	B00001010  // Visuel "E" for "Error"
};

void setup() {
	//set pins to output so you can control the shift register
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
	Serial.begin(9600);
	delay(500);
}

void loop() {
/*
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, MSBFIRST, B01111011);
	digitalWrite(latchPin, HIGH);
	*/

	/* Array (tal) der indeholder info om hvilke LED der skal tændes */
	/* NB. disse skal stemme overens med tilslutningen af LED */
	/* PIN - LAYOUT || NB. PIN 8 ER KOLON */
	/*          */
	/*   1111   */
	/*  6    2  */
	/*  6    2  */
	/*   3333   */
	/*  7    4  */
	/*  7    4  */
	/*   5555   */
	/*          */
	/************/
	//Serial.println("Code start");
	
	
	//if (Serial.available() > 0)

		//digitalWrite(latchPin, LOW);
		for (int i = 0; i < 11; i++) 
		{
			digitalWrite(latchPin, HIGH);
			//delay(1000);
			shiftOut(dataPin, clockPin, MSBFIRST, tal[i]);
			digitalWrite(latchPin, LOW);
			delay(500);
		}


}