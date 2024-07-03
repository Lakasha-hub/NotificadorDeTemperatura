//Libreria de display LCD
#include <LiquidCrystal.h>

//Declaración de pines a usar por el LCD: (5 RS, 4 E, 3 D4, 2 D5, 1 D6, 0 D7)
LiquidCrystal lcd(5,4,3,2,1,0);
//Declaración de pines de los Leds
int ledA = 13;
int ledV = 12;
int ledR = 11;

void setup (){
  //Se configuran los pines como salidas
  pinMode(ledA, OUTPUT);
  pinMode(ledV, OUTPUT);
  pinMode(ledR, OUTPUT);
  //Inicialización de LCD con su tamaño (16x2)
  lcd.begin(16,2);
}

void loop(){
  //Se limpia el lcd al inicio de cada loop
  lcd.clear();
  //Lectura del sensor de temperatura
  int lectura = analogRead(A0);
  //Se convierte la lectura analogica(0 a 1023) a voltaje
  float voltaje = lectura * 5.0;
  voltaje /= 1024.0;
  //Se convierte el voltaje real en grados celsius
  float temperatura = (voltaje - 0.5) * 100;

  //Se establece el cursor en (0,0)
  lcd.setCursor(0,0);
  //Se imprime la temperatura actual
  lcd.print("Temp: ");
  lcd.print(temperatura);
  lcd.print("C");

  //Si la temperatura es menor a 9°C, decimos que la temperatura es baja
  if(temperatura < 9.0){
    //Se imprime en la segunda fila un mensaje que lo indica
    lcd.setCursor(0,1);
    lcd.print("Hace friooo");
    //Se enciende el Led Azul que indica Frio
    digitalWrite(ledA, HIGH);
    digitalWrite(ledV, LOW);
    digitalWrite(ledR, LOW);
    } 
    //Si la temperatura es mayor a 25°C, decimos que la temperatura es alta
    else if(temperatura > 25.0){
      //Se imprime en la segunda fila un mensaje que lo indica
      lcd.setCursor(0,1);
      lcd.print("Hace calooor");
      //Se enciende el Led Rojo que indica Calor y se apagan los demás
      digitalWrite(ledR, HIGH);
      digitalWrite(ledV, LOW);
      digitalWrite(ledA, LOW);
    }
    //Si no ocurre ningún caso la temperatura se encuentra entre 9 y 25, decimos que la temperatura es agradable
    else{
      //Se imprime en la segunda fila un mensaje que lo indica
      lcd.setCursor(0,1);
      lcd.print("Agradable");
      //Se enciende el Led Verde y se apagan los demás
      digitalWrite(ledV, HIGH);
      digitalWrite(ledR, LOW);
      digitalWrite(ledA, LOW);
    }

    //Se coloca un Delay para observar bien los cambios de temperatura y no sobreexigir los leds
    delay(1000);
}
