


//*****************************************************************************************************
//*****************************************************************************************************
//******** This code takes 3 Rfid Cards, as we did not have the materials to complete and check *******
//*****************************************************************************************************
//*****************************************************************************************************

// Include Libraries
#include "Arduino.h"
#include "RFID.h"
#include "Button.h"


// Pin Definitions
#define RFID_1_PIN_RST	2
#define RFID_1_PIN_SDA	53
#define RFID_2_PIN_RST	3
#define RFID_2_PIN_SDA	4
#define RFID_3_PIN_RST	5
#define RFID_3_PIN_SDA	6
#define RFID_4_PIN_RST	7
#define RFID_4_PIN_SDA	8
#define RFID_5_PIN_RST	9
#define RFID_5_PIN_SDA	10
#define RFID_6_PIN_RST	11
#define RFID_6_PIN_SDA	12
#define RFID_7_PIN_RST	13
#define RFID_7_PIN_SDA	14
#define RFID_8_PIN_RST	15
#define RFID_8_PIN_SDA	16
#define RFID_9_PIN_RST	17
#define RFID_9_PIN_SDA	18
#define TOGGLESWITCH_PIN_2	19



// Global variables and defines

// object initialization
RFID rfid_1(RFID_1_PIN_SDA,RFID_1_PIN_RST);
RFID rfid_2(RFID_2_PIN_SDA,RFID_2_PIN_RST);
RFID rfid_3(RFID_3_PIN_SDA,RFID_3_PIN_RST);
RFID rfid_4(RFID_4_PIN_SDA,RFID_4_PIN_RST);
RFID rfid_5(RFID_5_PIN_SDA,RFID_5_PIN_RST);
RFID rfid_6(RFID_6_PIN_SDA,RFID_6_PIN_RST);
RFID rfid_7(RFID_7_PIN_SDA,RFID_7_PIN_RST);
RFID rfid_8(RFID_8_PIN_SDA,RFID_8_PIN_RST);
RFID rfid_9(RFID_9_PIN_SDA,RFID_9_PIN_RST);
Button ToggleSwitch(TOGGLESWITCH_PIN_2);


// define vars 

String cleanTag1; 
String cleanTag2;
String cleanTag3;
String cleanTag4;
String cleanTag5;
String cleanTag6;
String cleanTag7;
String cleanTag8;
String cleanTag9; 

int rfid_1_cardVal;
int rfid_2_cardVal;
int rfid_3_cardVal;
int rfid_4_cardVal;
int rfid_5_cardVal;
int rfid_6_cardVal;
int rfid_7_cardVal;
int rfid_8_cardVal;
int rfid_9_cardVal;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect.
  
    //initialize RFID module
    rfid_1.init();
    //initialize RFID module
    rfid_2.init();
    //initialize RFID module
    rfid_3.init();
    //initialize RFID module
    rfid_4.init();
    //initialize RFID module
    rfid_5.init();
    //initialize RFID module
    rfid_6.init();
    //initialize RFID module
    rfid_7.init();
    //initialize RFID module
    rfid_8.init();
    //initialize RFID module
    rfid_9.init();
    ToggleSwitch.init();
   
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    while(RFID rfid_1.available()>0 && RFID rfid_2.available()>0 && 
          RFID rfid_3.available()>0 && RFID rfid_4.available()>0 && 
          RFID rfid_5.available()>0 && RFID rfid_6.available()>0 && 
          RFID rfid_7.available()>0 && RFID rfid_8.available()>0 && 
          RFID rfid_9.available()>0{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
//////// This is an example, I do not have the rfid nor the cards to test if it works,//////////////////////////////////////////////////
///////           Will do an example of 3 cards on each rfid reader                  ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // RFID Card Reader - #1 
    //Read RFID tag if present
    String rfid_1tag = rfid_1.readTag();
    rfid_1tag.remove(13);//removes "garbage" at the end of the String.
    rfid_1tag.remove(0,1);//removes "garbage" at the beginning of the String.
    cleanTag1 = rfid_1tag;//saves the "clean" String to the variable.

   
    if(cleanTag1 == "1F002990BF19") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_1_cardVal = 1;
      Serial.println("rfid1: "+rfid_1_cardVal+" "); // sends to data via serial port to unity.
    }
    else {rfid_1_cardVal = 0;}

    if(cleanTag1 == "1F0017B6F04E") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_1_cardVal = 2;
      Serial.println("rfid1: "+rfid_1_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_1_cardVal = 0;}

    if(cleanTag1 == "1B3024B6F06A") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_1_cardVal = 3;
      Serial.println("rfid1: "+rfid_1_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_1_cardVal = 0;}
      

    // RFID Card Reader - RC522 #2 
    //Read RFID tag if present
    String rfid_2tag = rfid_2.readTag();
    rfid_2tag.remove(13);//removes "garbage" at the end of the String.
    rfid_2tag.remove(0,1);//removes "garbage" at the beginning of the String.
    cleanTag2 = rfid_2tag;//saves the "clean" String to the variable.

   
    if(cleanTag2 == "1F002990BF19") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_2_cardVal = 1;
      Serial.println("rfid2: "+rfid_2_cardVal+" "); // sends to data via serial port to unity.
    }
    else {rfid_2_cardVal = 0;}

    if(cleanTag2 == "1F0017B6F04E") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_2_cardVal = 2;
      Serial.println("rfid2: "+rfid_2_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_2_cardVal = 0;}

    if(cleanTag2 == "1B3024B6F06A") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_2_cardVal = 3;
      Serial.println("rfid2: "+rfid_2_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_2_cardVal = 0;}

    // RFID Card Reader - RC522 #3 
    //Read RFID tag if present
    String rfid_3tag = rfid_3.readTag();
    rfid_3tag.remove(13);//removes "garbage" at the end of the String.
    rfid_3tag.remove(0,1);//removes "garbage" at the beginning of the String.
    cleanTag1 = rfid_3tag;//saves the "clean" String to the variable.

   
    if(cleanTag1 == "1F002990BF19") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_3_cardVal = 1;
      Serial.println("rfid3: "+rfid_3_cardVal+" "); // sends to data via serial port to unity.
    }
    else {rfid_3_cardVal = 0;}

    if(cleanTag3 == "1F0017B6F04E") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_3_cardVal = 2;
      Serial.println("rfid3: "+rfid_3_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_3_cardVal = 0;}

    if(cleanTag3 == "1B3024B6F06A") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_3_cardVal = 3;
      Serial.println("rfid3: "+rfid_3_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_3_cardVal = 0;}


    // RFID Card Reader - RC522 #4 
    //Read RFID tag if present
    String rfid_4tag = rfid_4.readTag();
    rfid_4tag.remove(13);//removes "garbage" at the end of the String.
    rfid_4tag.remove(0,1);//removes "garbage" at the beginning of the String.
    cleanTag4 = rfid_4tag;//saves the "clean" String to the variable.

   
    if(cleanTag4 == "1F002990BF19") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_4_cardVal = 1;
      Serial.println("rfid4: "+rfid_4_cardVal+" "); // sends to data via serial port to unity.
    }
    else {rfid_4_cardVal = 0;}

    if(cleanTag4 == "1F0017B6F04E") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_4_cardVal = 2;
      Serial.println("rfid4: "+rfid_4_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_4_cardVal = 0;}

    if(cleanTag4 == "1B3024B6F06A") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_4_cardVal = 3;
      Serial.println("rfid4: "+rfid_4_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_4_cardVal = 0;}
   
    // RFID Card Reader - RC522 #5 
    //Read RFID tag if present
    String rfid_5tag = rfid_5.readTag();
    rfid_5tag.remove(13);//removes "garbage" at the end of the String.
    rfid_5tag.remove(0,1);//removes "garbage" at the beginning of the String.
    cleanTag5 = rfid_5tag;//saves the "clean" String to the variable.

   
    if(cleanTag5 == "1F002990BF19") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_5_cardVal = 1;
      Serial.println("rfid5: "+rfid_5_cardVal+" "); // sends to data via serial port to unity.
    }
    else {rfid_5_cardVal = 0;}

    if(cleanTag5 == "1F0017B6F04E") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_5_cardVal = 2;
      Serial.println("rfid5: "+rfid_5_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_5_cardVal = 0;}

    if(cleanTag5 == "1B3024B6F06A") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_5_cardVal = 3;
      Serial.println("rfid5: "+rfid_5_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_5_cardVal = 0;}
    
    // RFID Card Reader - RC522 #6
    //Read RFID tag if present
    String rfid_6tag = rfid_6.readTag();
    rfid_6tag.remove(13);//removes "garbage" at the end of the String.
    rfid_6tag.remove(0,1);//removes "garbage" at the beginning of the String.
    cleanTag1 = rfid_6tag;//saves the "clean" String to the variable.

   
    if(cleanTag6 == "1F002990BF19") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_6_cardVal = 1;
      Serial.println("rfid6: "+rfid_6_cardVal+" "); // sends to data via serial port to unity.
    }
    else {rfid_6_cardVal = 0;}

    if(cleanTag6 == "1F0017B6F04E") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_6_cardVal = 2;
      Serial.println("rfid6: "+rfid_6_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_6_cardVal = 0;}

    if(cleanTag6 == "1B3024B6F06A") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_6_cardVal = 3;
      Serial.println("rfid6: "+rfid_6_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_6_cardVal = 0;}
 
    // RFID Card Reader - RC522 #7 
    //Read RFID tag if present
    String rfid_7tag = rfid_7.readTag();
    rfid_7tag.remove(13);//removes "garbage" at the end of the String.
    rfid_7tag.remove(0,1);//removes "garbage" at the beginning of the String.
    cleanTag7 = rfid_7tag;//saves the "clean" String to the variable.

   
    if(cleanTag7 == "1F002990BF19") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_7_cardVal = 1;
      Serial.println("rfid7: "+rfid_7_cardVal+" "); // sends to data via serial port to unity.
    }
    else {rfid_7_cardVal = 0;}

    if(cleanTag7 == "1F0017B6F04E") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_7_cardVal = 2;
      Serial.println("rfid7: "+rfid_7_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_7_cardVal = 0;}

    if(cleanTag7 == "1B3024B6F06A") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_7_cardVal = 3;
      Serial.println("rfid7: "+rfid_7_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_7_cardVal = 0;}

  
    // RFID Card Reader - RC522 #8 
    //Read RFID tag if present
    String rfid_8tag = rfid_8.readTag();
    rfid_8tag.remove(13);//removes "garbage" at the end of the String.
    rfid_8tag.remove(0,1);//removes "garbage" at the beginning of the String.
    cleanTag1 = rfid_8tag;//saves the "clean" String to the variable.

   
    if(cleanTag8 == "1F002990BF19") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_8_cardVal = 1;
      Serial.println("rfid: "+rfid_8_cardVal+" "); // sends to data via serial port to unity.
    }
    else {rfid_8_cardVal = 0;}

    if(cleanTag8 == "1F0017B6F04E") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_8_cardVal = 2;
      Serial.println("rfid: "+rfid_8_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_8_cardVal = 0;}

    if(cleanTag8 == "1B3024B6F06A") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_8_cardVal = 3;
      Serial.println("rfid: "+rfid_8_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_8_cardVal = 0;}

    // RFID Card Reader - RC522 #9 
    //Read RFID tag if present
    String rfid_9tag = rfid_9.readTag();
    rfid_9tag.remove(13);//removes "garbage" at the end of the String.
    rfid_9tag.remove(0,1);//removes "garbage" at the beginning of the String.
    cleanTag1 = rfid_9tag;//saves the "clean" String to the variable.

   
    if(cleanTag9 == "1F002990BF19") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_9_cardVal = 1;
      Serial.println("rfid: "+rfid_9_cardVal+" "); // sends to data via serial port to unity.
    }
    else {rfid_9_cardVal = 0;}

    if(cleanTag9 == "1F0017B6F04E") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_9_cardVal = 2;
      Serial.println("rfid: "+rfid_9_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_9_cardVal = 0;}

    if(cleanTag9 == "1B3024B6F06A") // This is an example, i do not have the rfid nor the cards to test if it works
    {
      rfid_9_cardVal = 3;
      Serial.println("rfid: "+rfid_9_cardVal+" ");// sends to data via serial port to unity.
    }
    else {rfid_9_cardVal = 0;}
           
           }// End of while loop.


    // ToggleSwitch
    //read Toggle Switch state. 
    //if Switch is open function will return LOW (0). 
    //if it is closed function will return HIGH (1).
    bool ToggleSwitchVal = ToggleSwitch.read();
    Serial.println(ToggleSwitchVal);
    }
 
}
