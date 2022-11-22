#include <AFMotor.h>

AF_DCMotor MotorEsquerda(3);
AF_DCMotor MotorDireita(2);


int BTN_W = A0;
int BTN_A = A1;
int BTN_S = A2;
int BTN_D = A3;
int BTN_E = A4;

String commands = "";

void setup()
{
  pinMode(BTN_W, INPUT);
  pinMode(BTN_A, INPUT);
  pinMode(BTN_S, INPUT);
  pinMode(BTN_D, INPUT);
  pinMode(BTN_E, INPUT);
  
  Serial.begin(9600);

  Serial.println("Projeto Robo Educacional");
}

void loop()
{  
  if (digitalRead(BTN_W)) {
    commands.concat("W ");
    Serial.println(commands);
    delay(200);
  }  
  if (digitalRead(BTN_A)) {
    commands.concat("A ");
    Serial.println(commands);
    delay(200);
  }  
  if (digitalRead(BTN_S)) {
    commands.concat("S ");
    Serial.println(commands);
    delay(200);
  }  
  if (digitalRead(BTN_D)) {
    commands.concat("D ");
    Serial.println(commands);
    delay(200);
  }    
      
  if (digitalRead(BTN_E)) {    
     executeCommands();     
  }      
}

void executeCommands(){  
  while (commands.length() > 0)
  {
    int index = commands.indexOf(' ');
    {
      String currentCommand = commands.substring(0, index);      
      commands = commands.substring(index+1);
      
      execute(currentCommand);
      
      delay(1000);
    }
  }
  commands = "";
}


void execute(String command) {
    String aComa = command.substring(0,1);
  
    Serial.println(aComa);
    
    if (aComa == "W") {
      Frente();
      delay(1000);
      Parar();
    }

    if (aComa == "D"){
      Direita();
      delay(1000);
      Parar();
    }

    if (aComa == "A"){
      Esquerda();
      delay(1000);
      Parar();
    }    
    
}
void Frente(){
  
  MotorEsquerda.setSpeed(255);
  MotorDireita.setSpeed(255);
  MotorEsquerda.run(FORWARD); 
  MotorDireita.run(FORWARD);  
}

void Direita(){
  MotorEsquerda.setSpeed(255);  
  MotorEsquerda.run(FORWARD); 
  MotorDireita.run(RELEASE);   
}

void Esquerda(){
  MotorDireita.setSpeed(255);  
  MotorDireita.run(FORWARD); 
  MotorEsquerda.run(RELEASE);

}

void Parar(){ 
  
  MotorEsquerda.run(RELEASE);  
  MotorDireita.run(RELEASE); 

}
  // continuar o código
