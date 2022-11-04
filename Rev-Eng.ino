/*
	Author: Björn Schnabel
	Email: bjoern-uwe.schnabel@tu-freiberg.de
	This program is distributed and can be used under MIT-License
	This program is distributed as-is with no guarantee of it working as inteded
*/

void setup() {
  Serial.begin(9600);
  byte ins[] = {11,12,13};
  byte inN = 3;
  byte outs[] = {5,7};
  byte outN = 2;
  bool results[int(pow(2,inN))][int(outN)];
  
  for(int i=0; i<inN; i++){
    pinMode(ins[i], OUTPUT);
  }
  for(int i=0; i<outN; i++){
    pinMode(outs[i], INPUT);
  }

  for(int i=0; i<pow(2,inN); i++){
    for(int j=0; j<inN; j++){
      digitalWrite(ins[j], bitRead(i,j));
    }
    delay(50);
    for(int j=0; j<outN; j++){
      results[i][j]=bool(digitalRead(outs[j]));
    }
  }
  String out;
  for(int i=0; i<inN; i++){
    out+=String(i)+" ";
  }
  out+="|";
  for(int i=0; i<outN; i++){
    out+=String(i)+" ";
  }
  Serial.println(out);
  out="";
  for(int i=0; i<inN*2+outN*2+1; i++){
    out+="-";
  }
  Serial.println(out);
  out="";
  for(int i=0; i<pow(2,inN); i++){
    for(int j=0; j<inN; j++){
      out+=String(bitRead(i,j))+" ";
    }
    out+="|";
    for(int j=0; j<outN; j++){
      out+=String(int(results[i][j]))+" ";
    }
    Serial.println(out);
    out="";
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
