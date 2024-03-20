volatile int conteo = 0;
int anterior=0;
int pwm;
int pwm2;


const int pinTrigger = 4;  //Variable que contiene el número del pin al cual conectamos la señal "trigger"
const int pinEcho = 3;   //Variable que contiene el número del pin al cual conectamos la señal "echo"


void setup() {
  pinMode(9, OUTPUT);
  pinMode(8,OUTPUT);
  attachInterrupt(0, evento, RISING);
  Serial.begin(9600);
  digitalWrite(7,LOW);

}

void loop() {
  if (conteo > 6){
    conteo = 0;
    pwm2 = 0;
    digitalWrite(8,HIGH);
    delay(1000);
    }else{
      digitalWrite(8,LOW);
      }
  if (anterior!=conteo){
    Serial.print("Numero de interrupciones: ");
    Serial.println(conteo);
    anterior = conteo;
    Serial.print("PWM: ");
    Serial.println(pwm2);
    }
}

void evento() {
  conteo=conteo+1;
  pwm2=map(conteo,0,10,0,255);
  analogWrite(9, pwm2);
}
