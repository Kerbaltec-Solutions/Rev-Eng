/*
  Author: Björn Schnabel
  Email: bjoern-uwe.schnabel@tu-freiberg.de
  This program is distributed and can be used under MIT-License
  This program is distributed as-is with no guarantee of it working as inteded
*/

void setup() {
  Serial.begin(9600);
  static byte ap=18;
  byte ins[ap];
  byte inN = 0;
  bool hexU = false;

  //should the logic table be converted to hexadecimal
  Serial.print("Format output as hexadecimal?: ");
  while(!Serial.available()){
    delay(20);
  }
  String input = Serial.readString();
  input.trim(); 
  if(input.equals("Y") || input.equals("y")){
    hexU = true;
    Serial.println("YES");
  }else{
    Serial.println("NO");
  }
  
  //Assign arduino pins to IC input pins
  for(int i=0; i<ap; i++){
    Serial.print("Pin for IC input "+String(i)+" : ");
    while(!Serial.available()){
      delay(20);
    }
    String input = Serial.readString();
    input.trim(); 
    int pin=input.toInt();
    if(String(pin).equals(input)){
      if(pin>1 && pin<20){
        bool inpV=true;
        for (int j=0; j<inN && inpV==true; j++) {
          if (pin==ins[j]) inpV=false;
        }
        if(inpV){
          ins[i]=pin;
          inN++;
          Serial.println(String(pin));
        }else{
          Serial.println("The pin "+input+" is allready assigned. Please choose a different one.");
          i--;
        }
      }else{
        Serial.println("The pin "+input+" cannot be assigned. Please choose a different one.");
        i--;
      }
    }else if(input.equals("e") || input.equals("E")){
      Serial.println("END");
      break;
    }else{
      Serial.println("\""+input+"\" is not a valid pin number. Please choose a different one.");
      i--;
    }
  }

  byte outs[ap-inN];
  byte outN = 0;

  //Assign arduino pins to IC output pins
  for(int i=0; i<ap-inN; i++){
    Serial.print("Pin for IC output "+String(i)+" : ");
    while(!Serial.available()){
      delay(20);
    }
    String input = Serial.readString();  //read until timeout
    input.trim(); 
    int pin=input.toInt();
    if(String(pin).equals(input)){
      if(pin>1 && pin<20){
        bool inpV=true;
        for (int j=0; j<inN && inpV==true; j++) {
          if (pin==ins[j]) inpV=false;
        }
        for (int j=0; j<outN && inpV==true; j++) {
          if (pin==outs[j]) inpV=false;
        }
        if(inpV){
          outs[i]=pin;
          outN++;
          Serial.println(String(pin));
        }else{
          Serial.println("The pin "+input+" is allready assigned. Please choose a different one.");
          i--;
        }
      }else{
        Serial.println("The pin "+input+" cannot be assigned. Please choose a different one.");
        i--;
      }
    }else if(input.equals("e") || input.equals("E")){
      Serial.println("END");
      break;
    }else{
      Serial.println("\""+input+"\" is not a valid pin number. Please choose a different one.");
      i--;
    }
  }

  int results[int(pow(2,inN))+1]; //create array for logic table
  
  //Initialize the in- and output pins
  for(int i=0; i<inN; i++){
    pinMode(ins[i], OUTPUT);
  }
  for(int i=0; i<outN; i++){
    pinMode(outs[i], INPUT);
  }

  //iterate through combinations of input pins and record the state of the output pins
  for(int i=0; i<pow(2,inN); i++){
    for(int j=0; j<inN; j++){
      digitalWrite(ins[j], bitRead(i,j));
    }
    delay(500);
    results[i]=0;
    for(int j=0; j<outN; j++){
      results[i]+=int(digitalRead(outs[j]))*pow(2,j);
    }
  }
  for(int j=0; j<inN; j++){
    digitalWrite(ins[j], 0); //set input pins back to OFF
  }

  if(hexU){
    byte hexLi=((inN-inN%4)/4+1);
    byte hexLo=((outN-outN%4)/4+1);
    
    //print logic table
      //header
    String out="I";
    for(int i=0; i<hexLi; i++){
      out+=" ";
    }
    out+="| O";
    Serial.println(out);
      //seperation line
    out="";
    for(int j=0; j<hexLi+1; j++){
      out+="-";
    }
    out+="+";
    for(int j=0; j<hexLo+1; j++){
      out+="-";
    }
    Serial.println(out);
      //body
    out="";
    for(int i=0; i<pow(2,inN); i++){
      for(int j=0; j<hexLi-((i-i%16)/16+1); j++){
        out+="0";
      }
      out+=String(i,HEX);
      out+=" | ";
      for(int j=0; j<hexLo-((results[i]-results[i]%16)/16+1); j++){
        out+="0";
      }
      //out+=String(results[i],HEX);
      out+=String(results[i]);
      Serial.println(out);
      out="";
    }
  }else{
    //print logic table
      //header
    String out;
    for(int i=0; i<inN; i++){
      out+=String(i)+" ";
    }
    out+="| ";
    for(int i=0; i<outN; i++){
      out+=String(i)+" ";
    }
    Serial.println(out);
      //seperation line
    out="";
    for(int j=0; j<inN*2; j++){
      out+="-";
    }
    out+="+";
    for(int j=0; j<outN*2; j++){
      out+="-";
    }
    Serial.println(out);
      //body
    out="";
    for(int i=0; i<pow(2,inN); i++){
      for(int j=0; j<inN; j++){
        out+=String(bitRead(i,j))+" ";
      }
      out+="| ";
      for(int j=0; j<outN; j++){
        out+=String(bitRead(results[i],j))+" ";
      }
      Serial.println(out);
      out="";
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
