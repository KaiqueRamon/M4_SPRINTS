
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <stdio.h>
#include <string.h> //necessário para strcpy


LiquidCrystal_I2C lcd_1(0x27,2,1,0,4,5,6,7,3, POSITIVE);
LiquidCrystal_I2C lcd_2(0x26,2,1,0,4,5,6,7,3, POSITIVE);
int memoria2 = 0;
int memoria1 = 0;
int memoria3 = 0;
int escolha1 = 9;
int escolha2 =10;
char nome2[20];
char nome[20];
char resultado[50];




void soma2(){
   memoria2 = (memoria2 + 1);
}
void soma1(){
   memoria1 = (memoria1 + 1);
}
const char* ssid     = "SHARE-RESIDENTE";
const char* password = "Share@residente";


WiFiServer server(80);

void setup()
{
    
 Wire.begin(47, 48); //sda , scl
  lcd_1.begin (16,2);
  lcd_2.begin (16,2);
  lcd_1.print("Jogador 1:.........");
  lcd_2.print("jogador 2:..........");
  pinMode(40, INPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
 
  attachInterrupt(36, soma2, RISING);
  attachInterrupt(15, soma1, RISING);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(41, OUTPUT);    Serial.begin(9600);
  pinMode(46, OUTPUT);      // set the LED pin mode

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();

}

int value = 0;

void loop(){


  //jogador 2 
 
  
   if (digitalRead(36) == HIGH) {

    lcd_2.setCursor(0, 0);
    lcd_2.print("Escolha um:................");
    
  }
  if (memoria2 == 1) {
    lcd_2.setCursor(0, 1);
    lcd_2.print("Pedra..........");
    strcpy(nome2, "Pedra");
  }
  if (memoria2 == 2) {
    lcd_2.setCursor(0, 1);
    lcd_2.print("Tesoura........");
    strcpy(nome2, "Tesoura");
  }
  if (memoria2 == 3) {
    lcd_2.setCursor(0, 1);
    lcd_2.print("Papel..........");
    strcpy(nome2, "Papel");
  }

        //jogador 1
    
   if (digitalRead(15) == HIGH) {
    lcd_1.setCursor(0, 0);
    lcd_1.print("Escolha um:............");
    
  }
  if (memoria1 == 1) {
    lcd_1.setCursor(0, 1);
    lcd_1.print("Pedra.............");
    strcpy(nome, "Pedra");
  }
  if (memoria1 == 2) {
    lcd_1.setCursor(0, 1);
    lcd_1.print("Tesoura...........");
    strcpy(nome, "Tesoura");
  }
  if (memoria1 == 3) {
    lcd_1.setCursor(0, 1);
    lcd_1.print("Papel...........");
    strcpy(nome, "Papel");
  }

        //reset memoria 
  if (memoria1 > 3) {
    memoria1 = 1;
  }
          //reset memoria 
  if (memoria2 > 3) {
    memoria2 = 1;
  }

    // 
  if (digitalRead(39) == HIGH) {
    escolha2 = memoria2;
    lcd_2.setCursor(0, 0);
    lcd_2.print("Voce escolheu:.....");

  }
  
  if (digitalRead(35) == HIGH) {
    escolha1 = memoria1;
    lcd_1.setCursor(0, 0);
    lcd_1.print("Voce escolheu:.......");

  }

  //       jogador 1 ganha
  if ( (escolha1 == 1) && (escolha2 == 2 )) {
    lcd_1.setCursor(0, 0);
    lcd_1.print("Voce Ganhou:.....");
    lcd_1.setCursor(0, 1);
    lcd_1.print("You Win..........");
    lcd_2.setCursor(0, 0);
    lcd_2.print("Voce Perdeu:.....");
    lcd_2.setCursor(0, 1);
    lcd_2.print("Fatality..........");
    digitalWrite(6, HIGH);
    digitalWrite(42, HIGH);
    delay (1000);
    strcpy(resultado, "jogador 1 ganhou");
   
  } 
  if ( (escolha1 == 2) && (escolha2 == 3 )) {
    lcd_1.setCursor(0, 0);
    lcd_1.print("Voce Ganhou:.....");
    lcd_1.setCursor(0, 1);
    lcd_1.print("You Win..........");
    lcd_2.setCursor(0, 0);
    lcd_2.print("Voce Perdeu:.....");
    lcd_2.setCursor(0, 1);
    lcd_2.print("Fatality..........");
    digitalWrite(6, HIGH);
    digitalWrite(42, HIGH);
    delay (1000);    
    strcpy(resultado, "jogador 1 ganhou");
  } 
    

  if ( (escolha1 == 3) && (escolha2 == 1 )) {
    lcd_1.setCursor(0, 0);
    lcd_1.print("Voce Ganhou:.....");
    lcd_1.setCursor(0, 1);
    lcd_1.print("You Win..........");
    lcd_2.setCursor(0, 0);
    lcd_2.print("Voce Perdeu:.....");
    lcd_2.setCursor(0, 1);
    lcd_2.print("Fatality..........");
    digitalWrite(6, HIGH);
    digitalWrite(42, HIGH);
    delay (1000);
    strcpy(resultado, "jogador 1 ganhou");

  } 

  //jogador 2 ganha
    if ( (escolha2 == 1) && (escolha1 == 2 )) {
    lcd_2.setCursor(0, 0);
    lcd_2.print("Voce Ganhou:.....");
    lcd_2.setCursor(0, 1);
    lcd_2.print("You Win..........");
    lcd_1.setCursor(0, 0);
    lcd_1.print("Voce Perdeu:.....");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Fatality..........");
    digitalWrite(41, HIGH);
    digitalWrite(5, HIGH);
    delay (1000);
    strcpy(resultado, "jogador 2 ganhou");
   
  } 
  if ( (escolha2 == 2) && (escolha1 == 3 )) {
    lcd_2.setCursor(0, 0);
    lcd_2.print("Voce Ganhou:.....");
    lcd_2.setCursor(0, 1);
    lcd_2.print("You Win..........");
    lcd_1.setCursor(0, 0);
    lcd_1.print("Voce Perdeu:.....");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Fatality..........");
    digitalWrite(41, HIGH);
    digitalWrite(5, HIGH);
    delay (1000);
    strcpy(resultado, "jogador 2 ganhou");
  } 
    

  if ( (escolha2 == 3) && (escolha1 == 1 )) {
    lcd_2.setCursor(0, 0);
    lcd_2.print("Voce Ganhou:.....");
    lcd_2.setCursor(0, 1);
    lcd_2.print("You Win..........");
    lcd_1.setCursor(0, 0);
    lcd_1.print("Voce Perdeu:.....");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Fatality..........");
    digitalWrite(41, HIGH);
    digitalWrite(5, HIGH);
    delay (1000);
    strcpy(resultado, "jogador 2 ganhou");

  } 
  
 
      // empate 
  if (escolha1 == escolha2) {
     lcd_1.clear();
     lcd_2.clear();
     lcd_1.setCursor(0, 0);
     lcd_1.print("Foi............");
     lcd_1.setCursor(0, 1);
     lcd_1.print("Empate..........");
     lcd_2.setCursor(0, 0);
     lcd_2.print("Foi.............");
     lcd_2.setCursor(0, 1);
     lcd_2.print("Empate............");
     digitalWrite(5, HIGH);
     digitalWrite(6, HIGH);
     digitalWrite(42, HIGH);
     digitalWrite(41, HIGH);
     digitalWrite(46, HIGH);
     strcpy(resultado, "EMPATE");

     delay (300);

  }

 WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("<center><h2>Jogador 1 :</h2></center>");
            client.print("<center><p></p>");
            client.print(nome);
            client.print("<center><h2>Jogador 2 :</h2></center>");
            client.print("<center><p></p>");
            client.print(nome2);
            client.print("<center><h2>RESULTADO: </h2></center>");
            client.print(resultado);
          

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
