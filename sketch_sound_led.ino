int green = 12 ;// define LED Interface
int yellow = 8 ;
int yellow2 = 7 ;
int red = 4 ;
int red2 = 2 ;
int buttonpin = A5; // define D0 Sensor Interface
int val = 0;// define numeric variables val
void setup ()
{
 pinMode (red, OUTPUT) ;// define LED as output interfacepinMode
 pinMode (yellow, OUTPUT) ;// define LED as output interface
 pinMode (green, OUTPUT) ;// define LED as output interface
  pinMode (yellow2, OUTPUT) ;// define LED as output interface
 pinMode (red2, OUTPUT) ;// define LED as output interface
 pinMode (buttonpin, INPUT) ;// output interface D0 is defined sensor
}
void loop ()
{
 val = analogRead(buttonpin);//
 if (val >= 58) //
 {
 digitalWrite (green, HIGH);
 }
 else
 {
   digitalWrite (green, LOW);
 }
 
  if (val >= 63) //
 {
 digitalWrite (yellow, HIGH);
 }
 else
 {
   digitalWrite (yellow, LOW);
 }
 
  if (val >= 68) //
 {
 digitalWrite (yellow2, HIGH);
 }
 else
 {
   digitalWrite (yellow2, LOW);
 }

  if (val >= 73) //
 {
 digitalWrite (red, HIGH);
 }
 else
 {
   digitalWrite (red, LOW);
 }
 
  if (val >= 78) //
 {
 digitalWrite (red2, HIGH);
 }
 else
 {
   digitalWrite (red2, LOW);
 }
}
