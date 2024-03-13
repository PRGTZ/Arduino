const int motorBPin11 = 11;
const int motorBPin12 = 12; 
int boton1 = 8;
int boton2 = 9;
int velocidad = 6;
int PWM = 0;
int k = 1;
int k2 = 1;
int LED3 = 3;
int LED4 = 4;

void setup() {
  Serial.begin(9600);
    pinMode(motorBPin11, OUTPUT); // A favor de las manecillas
    pinMode(motorBPin12, OUTPUT); //Contra las manecillas
    pinMode(boton1, INPUT);
    pinMode(boton2, INPUT);
    pinMode(velocidad, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
}

void loop() {
 
  // Condiciones iniciales en 0  
  digitalWrite(motorBPin11,LOW); 
  digitalWrite(motorBPin12,LOW);
  digitalWrite(LED3,LOW); 
  digitalWrite(LED4,LOW);
    
    
    
  int btn1;                      // Establecer botones
  btn1=digitalRead(boton1);
  int btn2;
  btn2=digitalRead(boton2);

  if (btn1 == 1){
     digitalWrite(motorBPin11,HIGH); //Sube
     Serial.println(" Sube");
     digitalWrite(LED3,HIGH); 
      

     PWM = constrain(PWM + k,0,255);  // Aumenta la velocidad
     analogWrite(6,PWM);
     //Serial.print(PWM);
     
     if(PWM == 255){
     k = -1;
     } 

     if(PWM == 0){
     k = 1;
     }

     
     }
          
    else if (btn2== 1){
     digitalWrite(motorBPin12,HIGH); //Sube
     Serial.println("baja");
     digitalWrite(LED4,HIGH); 
    

    PWM = constrain(PWM + k2,0,255);  // Aumenta la velocidad
     analogWrite(6,PWM);
     //Serial.print(PWM);

    
     if(PWM == 255){
     k2 = -1;
     } 

     if(PWM == 0){
     k2 = 1;
     }
     }
     
}
