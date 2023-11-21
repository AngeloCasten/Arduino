#include <Servo.h>

Servo indicadorServo;
Servo medioServo;
Servo anelarServo;
Servo menorServo;
Servo polegarServo;

#define Botao_A 2
#define Botao_B 3
#define Botao_C 4
#define Botao_D 5
#define Botao_E 6
#define Botao_F 7
#define Botao_K 8

void setup() {
    Serial.begin(9600);
    
    indicadorServo.attach(9);  
    medioServo.attach(10);
    anelarServo.attach(11);
    menorServo.attach(12);
    polegarServo.attach(13);

    pinMode(Botao_A, INPUT_PULLUP);
    pinMode(Botao_B, INPUT_PULLUP);
    pinMode(Botao_C, INPUT_PULLUP);
    pinMode(Botao_D, INPUT_PULLUP);
    pinMode(Botao_E, INPUT_PULLUP);
    pinMode(Botao_F, INPUT_PULLUP);
    pinMode(Botao_K, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(Botao_A) == LOW) {
        movimentoIndicador();
    }
    if (digitalRead(Botao_B) == LOW) {
        movimentoMedio();
    }
    if (digitalRead(Botao_C) == LOW) {
        movimentoAnelar();
    }
    if (digitalRead(Botao_D) == LOW) {
        movimentoMenor();
    }
    if (digitalRead(Botao_E) == LOW) {
        movimentoPolegar();
    }
    if (digitalRead(Botao_F) == LOW) {
        
        moveAllFingers(10);
        delay(1000);
        moveAllFingers(90);
    }
    if (digitalRead(Botao_K) == LOW) {
        
        resetFingerPositions();
    }
}

void movimentoIndicador() {
    indicadorServo.write(10);
    delay(1000);
    indicadorServo.write(90);
}

void movimentoMedio() {
    medioServo.write(10);
    delay(1000);
    medioServo.write(90);
}

void movimentoAnelar() {
    anelarServo.write(10);
    delay(1000);
    anelarServo.write(90);
}

void movimentoMenor() {
    menorServo.write(10);
    delay(1000);
    menorServo.write(90);
}

void movimentoPolegar() {
    polegarServo.write(10);
    delay(1000);
    polegarServo.write(90);
}

void moveAllFingers(int position) {
    indicadorServo.write(position);
    medioServo.write(position);
    anelarServo.write(position);
    menorServo.write(position);
    polegarServo.write(position);
}

void resetFingerPositions() {
    moveAllFingers(90);
}
