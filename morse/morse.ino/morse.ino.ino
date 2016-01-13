
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pins as outputs.
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  int interval = 400;
  //two dimensional array
  int Matrix[][5] = { {1,2,0,0,0},{2,1,1,1,0},{2,1,2,1,0},{2,1,1,0,0},{1,0,0,0,0},//a-e
                      {1,1,2,1,0},{2,2,1,0,0},{1,1,1,1,0},{1,1,0,0,0},{1,2,2,2,0},//f-j
                      {2,1,2,0,0},{1,2,1,1,0},{2,2,1,1,0},{2,1,0,0,0},{2,2,2,0,0},//k-o
                      {1,2,2,1,0},{2,2,1,2,0},{1,2,1,0,0},{1,1,1,0,0},{2,0,0,0,0},//p-t
                      {1,1,2,0,0},{1,1,1,2,0},{1,2,2,0,0},{2,1,1,2,0},{2,1,2,2,0},//u-y
                      {2,2,1,1,0}
                     };
                      
  while (Serial.available() > 0) {//wait for communication with screen to become available
    String val = String((char)Serial.read()); // cast to String
    val.toLowerCase(); // morse is always lowercase
    Serial.print(val);
    byte bytes[2];//create buffer
    val.getBytes(bytes, 2);//place byte value of contents in buffer
    int value = (int)bytes[0];
    //Serial.println(value);
    int letter = value-97;//create offset into array
    if (letter == -65 || letter == -87){//ignore newlines and spaces
      Serial.println();
    } else {
      for(int i=0;i<5;i++){
        //Serial.print(Matrix[letter][i]);
        int symbol = Matrix[letter][i];

        if (symbol == 1) {//a "1" from the array corresponds to a morse "dot"
          digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(1*interval);              
          digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW 
          delay(1*interval);
        } else if (symbol == 2) {//a "2" from the array corresponds to a morse "line"
          digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(2*interval);
          digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
          delay(1*interval);
        }
      }
      // signify the end of transmission of the character
      digitalWrite(2, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(0.5*interval);              
      digitalWrite(2, LOW);    // turn the LED off by making the voltage LOW
      delay(1*interval);
    }
    
  }
}
