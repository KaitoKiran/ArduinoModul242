//RGB LED pins 
int ledDigitalOne[] = {10, 11, 9}; //the three digital pins of the digital LED
int ledOben = 5;
int ledRechts = 4;
int ledUnten = 3;
int ledLinks = 2;
//10 = redPin, 11 = greenPin, 9 = bluePin 
const boolean ON = HIGH;     //Define on as LOW (this is because we use a 
//common  
                            //Anode RGB LED (common pin is connected to +5 
//volts) 
const boolean OFF = LOW;   //Define off as HIGH 
//Predefined Colors 
const boolean RED[] = {ON, OFF, OFF};     
const boolean GREEN[] = {OFF, ON, OFF};  
const boolean BLUE[] = {OFF, OFF, ON};  
const boolean YELLOW[] = {ON, ON, OFF};  
const boolean CYAN[] = {OFF, ON, ON};  
const boolean MAGENTA[] = {ON, OFF, ON};  
const boolean WHITE[] = {ON, ON, ON};  
const boolean BLACK[] = {OFF, OFF, OFF};  
//An Array that stores the predefined colors (allows us to later randomly display a color) 
const boolean* COLORS[] = {RED, GREEN, BLUE, YELLOW, CYAN, MAGENTA, WHITE, 
BLACK}; 
int sensorPin = 5; 
int value1 = 0; 
int value2 = 0;
void setup() {
  pinMode(ledLinks, OUTPUT); 
  pinMode(ledOben, OUTPUT); 
  pinMode(ledUnten, OUTPUT); 
  pinMode(ledRechts, OUTPUT); 
  pinMode(3, OUTPUT); 
  Serial.begin(9600); 
  for(int i = 0; i < 3; i++){ 
   pinMode(ledDigitalOne[i], OUTPUT);   //Set the three LED pins as outputs 
  }
} 
void loop() { 
  value1 = analogRead(0); 
  Serial.print("X:"); 
  Serial.print(value1, DEC); 
  value2 = analogRead(1); 
  Serial.print(" | Y:"); 
  Serial.println(value2, DEC); 

  delay(1); 
  /* Example - 1 Set a color 
   Set the three LEDs to any predefined color 
*/ 
   if(value2 > 1000 && value1 <= 1000 && value1 >0){
   setColor(ledDigitalOne, BLUE);  
   }else if(value1 == 0 && value2 > 500){
    setColor(ledDigitalOne, CYAN); 
   }else if(value1 == 0 && value2 <= 500){
    setColor(ledDigitalOne, GREEN); 
   }else if(value1 <= 510 && value2 == 0){
    setColor(ledDigitalOne, YELLOW); 
   }else if(value1 > 510 && value2 == 0){
    setColor(ledDigitalOne, RED); 
   }else if (value1 > 1000 && value2 > 500 ){
    setColor(ledDigitalOne, MAGENTA); 
   }else{
    setColor(ledDigitalOne, WHITE); 
   }

   if(value2 < 500){
    digitalWrite(ledLinks, HIGH);
   }else{
    digitalWrite(ledLinks, LOW);
   }
   if(value2 > 600){
    digitalWrite(ledRechts, HIGH);
   }else{
    digitalWrite(ledRechts, LOW);
   }
   if(value1 > 600){
    digitalWrite(ledOben, HIGH);
   }else{
    digitalWrite(ledOben, LOW);
   }
   if(value1 < 500){
    digitalWrite(ledUnten, HIGH);
   }else{
    digitalWrite(ledUnten, LOW);
   }
} 
/* Sets an led to any color 
   led - a three element array defining the three color pins (led[0] = 
redPin, led[1] = greenPin, led[2] = bluePin) 
   color - a three element boolean array (color[0] = red value (LOW = on, 
IDUINO for maker’s life 
                            www.openplatform.cc                             43 
HIGH = off), color[1] = green value, color[2] =blue value) 
*/ 
void setColor(int* led, boolean* color){ 
 for(int i = 0; i < 3; i++){ 
   digitalWrite(led[i], color[i]); 
 } 
} 
void setColor(int* led, const boolean* color){ 
  boolean tempColor[] = {color[0], color[1], color[2]}; 
  setColor(led, tempColor); }
