
// Sensores
int sensorIzq = 3;   
int sensorDer = 2;   

//Sensor Ultrasonico 
int echo = 11;
int trig = 12 ;
int detente = 30 ;

// Motor izquierdo
int ENA = 5;
int IN1 = 6;
int IN2 = 7;

// Motor derecho
int ENB = 10;
int IN3 = 8;
int IN4 = 9;

int velIzq = 150; 
int velDer = 150;   

int negro = 1;
int blanco = 0;

void setup() {
  pinMode(sensorIzq, INPUT);
  pinMode(sensorDer, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {

  int distancia = medirDistancia();
  if (distancia > 0 && distancia < detente) {
    parar();
    return;
  }
  int izq = digitalRead(sensorIzq);
  int der = digitalRead(sensorDer);

  if (izq == negro && der == negro) {
    adelante();
  }
  else if (izq == blanco && der == negro) {
    girarDerecha();
  }
  else if (izq == negro && der == blanco) {
    girarIzquierda();
  }
  else {
    parar();
  }
}
int medirDistancia() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long tiempo = pulseIn(echo, HIGH, 20000);   
  int cm = tiempo / 58;
  return cm;
}

void adelante() {
  analogWrite(ENA, velIzq);
  analogWrite(ENB, velDer);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
}
  void girarIzquierda() {
  analogWrite(ENA, velIzq);
  analogWrite(ENB, velDer);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);   
}

void girarDerecha() {
  analogWrite(ENA, velIzq);
  analogWrite(ENB, velDer);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  
}

void parar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}