// morse.h
// defines morse representation for nums + letters
// each number indicates how many times the LED should flash.

#include <Arduino.h>

unsigned int morse_chars [37][5]{
  {1, 3, 0, 0, 0}, // A
  {3, 1, 1, 1, 0}, // B
  {3, 1, 3, 1, 0}, // C
  {3, 1, 1, 0, 0}, // D
  {1, 0, 0, 0, 0}, // E
  {1, 1, 3, 1, 0}, // F
  {3, 3, 1, 0, 0}, // G
  {1, 1, 1, 1, 0}, // H
  {1, 1, 0, 0, 0}, // I
  {1, 3, 3, 3, 0}, // J
  {3, 1, 3, 0, 0}, // K
  {1, 3, 1, 1, 0}, // L
  {3, 3, 0, 0, 0}, // M
  {3, 1, 0, 0, 0}, // N
  {3, 3, 3, 0, 0}, // O
  {1, 3, 3, 1, 0}, // P
  {3, 3, 1, 3, 0}, // Q
  {1, 3, 1, 0, 0}, // R
  {1, 1, 1, 0, 0}, // S
  {3, 0, 0, 0, 0}, // T
  {1, 1, 3, 0, 0}, // U
  {1, 1, 1, 3, 0}, // V
  {1, 3, 3, 0, 0}, // W
  {3, 1, 1, 3, 0}, // X
  {3, 1, 3, 3, 0}, // Y
  {3, 3, 1, 1, 0}, // Z
  {3, 3, 3, 3, 3}, // 0
  {1, 3, 3, 3, 3}, // 1
  {1, 1, 3, 3, 3}, // 2
  {1, 1, 1, 3, 3}, // 3
  {1, 1, 1, 1, 3}, // 4
  {1, 1, 1, 1, 1}, // 5
  {3, 1, 1, 1, 1}, // 6
  {3, 3, 1, 1, 1}, // 7
  {3, 3, 3, 1, 1}, // 8
  {3, 3, 3, 3, 1}, // 9
  {0, 0, 0, 0, 0}, // BLANK
};

int convertByte(byte incomingByte){ //converts a byte char into the array position
  if (incomingByte == 0x20) {
        return 36; //space, indicates end of word
      }
      else if ((incomingByte >= 0x30) && (incomingByte <= 0x39)){ //it's a number
        return (incomingByte - 22);
      }
      else if ((incomingByte >= 0x41) && (incomingByte <= 0x5A)){ //capital letter
        return (incomingByte - 65);
      } 
      else if ((incomingByte >= 0x61) && (incomingByte <= 0x7A)){ //lowercase letter
        return (incomingByte - 97);
      }
      else{
        return -1; //incompatible byte
      }
}


