const int motorBPin11 = 11;
const int motorBPin12 = 12; 
int boton1 = 8;
int boton2 = 9;
int velocidad = 6;
int vel;
int PWM = 0;
int POT = A0;

void setup() {
  Serial.begin(9600);
    pinMode(motorBPin11, OUTPUT); // A favor de las manecillas
    pinMode(motorBPin12, OUTPUT); //Contra las manecillas
    pinMode(boton1, INPUT);
    pinMode(boton2, INPUT);
    pinMode(velocidad, OUTPUT);
}

void loop() {
 
  // Condiciones iniciales en 0  
  digitalWrite(motorBPin11,LOW); 
  digitalWrite(motorBPin12,LOW);
  analogRead(POT);
  vel = map(analogRead(POT), 0, 1023, 0, 255);
  //Serial.println(vel);
  
    
  int btn1;                      // Establecer botones
  btn1=digitalRead(boton1);
  int btn2;
  btn2=digitalRead(boton2);

  if (btn1 == 1){
     digitalWrite(motorBPin11,HIGH); //Sube
     Serial.println(" Sube");

     analogWrite(6,vel);
          
    } else if (btn2== 1){
     digitalWrite(motorBPin12,HIGH); //Baja
     Serial.println("baja");

     analogWrite(6,vel);
     
    }
     
}
