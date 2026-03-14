#include <SoftwareSerial.h>

String VERSION = "ACC-4.1.1"; // ID Proyecto, Mejora, Correccion, Intento

#define UART_RX PB4
#define UART_TX PB3
#define DATA_PIN PB0
#define LATCH_PIN PB1
#define CLOCK_PIN PB2

SoftwareSerial COM(UART_RX, UART_TX);

byte pinState = 0b00000000;

void shiftOut595(byte data) {
  // Activar Latch para comenzar la transferencia
  digitalWrite(LATCH_PIN, LOW);

  // Enviar los 8 bits, MSB first
  for (int i = 7; i >= 0; i--) {
    digitalWrite(CLOCK_PIN, LOW);

    // Establecer el bit de datos
    digitalWrite(DATA_PIN, (data >> i) & 1);

    digitalWrite(CLOCK_PIN, HIGH);
  }

  // Desactivar LATCH para actualizar las salidas
  digitalWrite(LATCH_PIN, HIGH);
}

void actualizar595() {
  digitalWrite(LATCH_PIN, LOW);

  for (int i = 7; i >= 0; i--) {
    digitalWrite(CLOCK_PIN, LOW);
    digitalWrite(DATA_PIN, (pinState >> i) & 1);
    digitalWrite(CLOCK_PIN, HIGH);
  }

  digitalWrite(LATCH_PIN, HIGH);
}

void pinOn(int pin) {
  if (pin >= 0 && pin < 8) {
    pinState |= (1 << pin); // Set bit - OR con 1 en la posicion
    actualizar595();
  }
}

void pinOff(int pin) {
  if (pin >= 0 && pin < 8) {
    pinState &= ~(1 << pin); // Clear bit - AND con 0 en la posicion
    actualizar595();
  }
}

void pinToggle(int pin) {
  if (pin >= 0 && pin < 8) {
    pinState ^= (1 << pin); // XOR - invierte el bit
    actualizar595();
  }
}

void setPin(int pin, bool estado) {
  if (estado) {
    pinOn(pin);
  } else {
    pinOff(pin);
  }
}

bool getPinState(int pin) {
  if (pin >= 0 && pin < 8) {
    return(pinState >> pin) & 1;
  }
  return false;
}

void patronEspecifico(byte patron) {
  pinState = patron;
  actualizar595();
}

void allPinsOff() {
  pinState = 0b00000000;
  actualizar595();
}

void setup() {
  COM.begin(9600);
  // Configurar pines como salida
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);

  // Estado Inicial
  digitalWrite(DATA_PIN, LOW);
  digitalWrite(CLOCK_PIN, LOW);
  digitalWrite(LATCH_PIN, LOW);
  
  pinOn(7);
  delay(2000);
  pinOff(7);
}

void procesarDatoRecibido(char comando) {
  switch (comando) {
    case 'A':
      pinToggle(0);
    break;

    case 'B':
      pinToggle(1);
    break;

    case 'C':
      pinToggle(2);
    break;

    case 'D':
      pinToggle(3);
    break;

    case 'E':
      pinToggle(4);
    break;

    case 'F':
      pinToggle(5);
    break;

    case 'G':
      pinToggle(6);
    break;

    case 'H':
      pinToggle(7);
    break;
  }
}

void loop() {
  /* Uncomment if you have the Bluetooth module connected
  if (COM.available()) {
    char data = COM.read();
    procesarDatoRecibido(data);
  }
  */

  // Comment this part if you have the bluetooth module connected
  for (int i = 0; i < 4; i++){
  	pinToggle(i);
    delay(250);
  }
  
  for (int i = 0; i < 4; i++){
  	pinToggle(i);
    delay(250);
  }
  
  
  for (int i = 4; i < 8; i++){
  	pinToggle(i);
    delay(250);
  }

  for (int i = 4; i < 8; i++){
   	pinToggle(i);
    delay(250);
  }
}
