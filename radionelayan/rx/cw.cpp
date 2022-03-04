#include <arduino.h>
#include "cw.h"

/*
- class "CW"
- vor dem Funktionsnamen wird der Klassenname mit :: gesetzt (Nama kelas diletakkan di depan nama fungsi dengan ::)
- die Funktionen heissen jetzt 'Members' (fungsinya sekarang disebut 'Members')
*/

// Voreinstellungen , "Instanziierung" (Preferensi, "Instansiasi")
// kein void am Anfang ! (no void at the beginning!)
CW::CW (int pin, int wpm, int frequenz)
{
  pin_ton = pin;
  t_dit   = 1200/wpm ;
  hertz   = frequenz;    
}

// traeger fuer n Millisekunden (carrier for n milliseconds)
void CW::carrier(int n)
{
  tone(pin_ton,hertz);
  delay(n);
  noTone(pin_ton);
  delay(t_dit);
}
//************************
// kurzes Morseelement ("Punkt") (short Morse element ("point"))
// Eine Zeiteinheit an und eine Zeiteinheit aus (One time unit on and one time unit off)
void CW::dit()
{
  tone(pin_ton,hertz);
  delay(t_dit);
  noTone(pin_ton);
  delay(t_dit);
}
//************************
// langes Morseelement ("Strich") // long Morse element ("dash")
// 3 Zeiteinheiten an und eine Zeiteinheit aus // 3 time units on and one time unit off
void CW::dah( )
{
  tone(pin_ton,hertz);
  delay(t_dit*3);
  noTone(pin_ton);
  delay(t_dit);
}

//*************************
// Abstand zwischen den zeichen = 3 Zeiteinheiten // Distance between the characters = 3 time units
// hier nur 2 Zeiteinheiten , da eine Pause von einer Zeiteinheit // here only 2 time units, there is a pause of one time unit
// beim vorhergehenden dit oder dah gewartet wurde. // waited on the previous dit or dah.
void CW::zeichen_abstand()
{
  delay(t_dit*2);
}

//*************************
// Ausgabe einer Zeichenkette in Morsezeichen // Output of a string in Morse code
// Eingang : zeichenkette s[] = ein Array von zeichen // input: string s [] = an array of characters
// strlen() zaehlt die Anzahl der Zeichen bis eine Null kommt, // strlen () counts the number of characters until a zero comes,
// die das Ende der Zeichenkette markiert. // which marks the end of the string.
void CW::sende_text( char s[] )
{
  int i; // laufvariable
  for( i=0; i< strlen(s); i=i+1)
  {
    sende_zeichen( s[i]);
  }
}
//*************************
// Sende ein Zeichen ( Buchstabe ); // send a character (letter);
// Eingang: zu sendender Buchstabe: zeichen // input: letter to be sent: character
// Ausgang: ton // output: ton
// Fuer jeden Buchstaben gibt es einen "case". // There is a "case" for each letter.
// Wenn der case zutrifft, so wird der Programm- // If the case applies, the program
// abschnitt dieses case bis 'break' ausgeführt. // section of this case executed until 'break'.
// Nach 'break' geht es weiter hinter der // After 'break' it continues behind the
// schliessenden geschweiften Klammer von 'switch'  // closing curly bracket of 'switch'
//  Copyright (c) 2008, Shaun O'Neil <shaun@oneil.me.uk>
// libmorse/Morse.cpp, Arduino morse library; ( modifiziert )
void CW::sende_zeichen( char zeichen) //send characters
{
  switch(zeichen) {
  case 'a':
  case 'A':
    dit();
    dah();
    zeichen_abstand(); // character spacing
    break;
  case 'b':
  case 'B':
    dah();
    dit();
    dit();
    dit();
    zeichen_abstand();
    break;
  case 'c':
  case 'C':
    dah();
    dit();
    dah();
    dit();
    zeichen_abstand();
    break;
  case 'd':
  case 'D':
    dah();
    dit();
    dit();
    zeichen_abstand();
    break;
  case 'e':
  case 'E':
    dit();
    zeichen_abstand();
    break;
  case 'f':
  case 'F':
    dit();
    dit();
    dah();
    dit();
    zeichen_abstand();
    break;
  case 'g':
  case 'G':
    dah();
    dah();
    dit();
    zeichen_abstand();
    break;
  case 'h':
  case 'H':
    dit();
    dit();
    dit();
    dit();
    zeichen_abstand();
    break;
  case 'i':
  case 'I':
    dit();
    dit();
    zeichen_abstand();
    break;
  case 'j':
  case 'J':
    dit();
    dah();
    dah();
    dah();
    zeichen_abstand();
    break;
  case 'k':
  case 'K':
    dah();
    dit();
    dah();
    zeichen_abstand();
    break;
  case 'l':
  case 'L':
    dit();
    dah();
    dit();
    dit();
    zeichen_abstand();
    break;
  case 'm':
  case 'M':
    dah();
    dah();
    zeichen_abstand();
    break;
  case 'n':
  case 'N':
    dah();
    dit();
    zeichen_abstand();
    break;
  case 'o':
  case 'O':
    dah();
    dah();
    dah();
    zeichen_abstand();
    break;
  case 'p':
  case 'P':
    dit();
    dah();
    dah();
    dit();
    zeichen_abstand();
    break;
  case 'q':
  case 'Q':
    dah();
    dah();
    dit();
    dah();
    zeichen_abstand();
    break;
  case 'r':
  case 'R':
    dit();
    dah();
    dit();
    zeichen_abstand();
    break;
  case 's':
  case 'S':
    dit();
    dit();
    dit();
    zeichen_abstand();
    break;
  case 't':
  case 'T':
    dah();
    zeichen_abstand();
    break;
  case 'u':
  case 'U':
    dit();
    dit();
    dah();
    zeichen_abstand();
    break;
  case 'v':
  case 'V':
    dit();
    dit();
    dit();
    dah();
    zeichen_abstand();
    break;
  case 'w':
  case 'W':
    dit();
    dah();
    dah();
    zeichen_abstand();
    break;
  case 'x':
  case 'X':
    dah();
    dit();
    dit();
    dah();
    zeichen_abstand();
    break;
  case 'y':
  case 'Y':
    dah();
    dit();
    dah();
    dah();
    zeichen_abstand();
    break;
  case 'z':
  case 'Z':
    dah();
    dah();
    dit();
    dit();
    zeichen_abstand();
    break;
  case '1':
    dit();
    dah();
    dah();
    dah();
    dah();
    zeichen_abstand();
    break;
  case '2':
    dit();
    dit();
    dah();
    dah();
    dah();
    zeichen_abstand();
    break;
  case '3':
    dit();
    dit();
    dit();
    dah();
    dah();
    zeichen_abstand();
    break;
  case '4':
    dit();
    dit();
    dit();
    dit();
    dah();
    zeichen_abstand();
    break;
  case '5':
    dit();
    dit();
    dit();
    dit();
    dit();
    zeichen_abstand();
    break;
  case '6':
    dah();
    dit();
    dit();
    dit();
    dit();
    zeichen_abstand();
    break;
  case '7':
    dah();
    dah();
    dit();
    dit();
    dit();
    zeichen_abstand();
    break;
  case '8':
    dah();
    dah();
    dah();
    dit();
    dit();
    zeichen_abstand();
    break;
  case '9':
    dah();
    dah();
    dah();
    dah();
    dit();
    zeichen_abstand();
    break;
  case '0':
    dah();
    dah();
    dah();
    dah();
    dah();
    zeichen_abstand();
    break;
  case ' ':  // Leerzeichen = Wort-Abstand // Space = Word Spacing
    zeichen_abstand(); // character spacing
    zeichen_abstand();
    break;
  case '.':
    dit();
    dah();
    dit();
    dah();
    dit();
    dah();
    zeichen_abstand();
    break;
  case ',':
    dah(); 	
    dah(); 	
    dit(); 
    dit(); 
    dah(); 	
    dah(); 	
    zeichen_abstand();
    break;
  case '?':
    dit(); 
    dit(); 
    dah(); 	
    dah(); 	
    dit(); 
    dit(); 
    zeichen_abstand();
    break;
  case '\'':
    dit(); 
    dah(); 	
    dah(); 	
    dah(); 	
    dah(); 	
    dit(); 
    zeichen_abstand();
    break;
  case '!':
    dah(); 	
    dit(); 
    dah(); 	
    dit(); 
    dah(); 	
    dah(); 	
    zeichen_abstand();
    break;
  case '/':
    dah(); 	
    dit(); 
    dit(); 
    dah(); 	
    dit(); 
    zeichen_abstand();
    break;
  case '(':
    dah(); 	
    dit(); 
    dah(); 	
    dah(); 	
    dit(); 
    zeichen_abstand();
    break;
  case ')':
    dah(); 	
    dit(); 
    dah(); 	
    dah(); 	
    dit(); 
    dah(); 	
    zeichen_abstand();
    break;
  case '&':
    dit(); 
    dah(); 	
    dit(); 
    dit(); 
    dit(); 
    zeichen_abstand();
    break;
  case ':':
    dah(); 	
    dah(); 	
    dah(); 	
    dit(); 
    dit(); 
    dit(); 
    zeichen_abstand();
    break;
  case ';':
    dah(); 	
    dit(); 
    dah(); 	
    dit(); 
    dah(); 	
    dit(); 
    zeichen_abstand();
    break;
  case '=':
    dah(); 	
    dit(); 
    dit(); 
    dit(); 
    dah(); 	
    zeichen_abstand();
    break;
  case '+':
    dit(); 
    dah(); 	
    dit(); 
    dah(); 	
    dit(); 
    zeichen_abstand();
    break;
  case '-':
    dah(); 	
    dit(); 
    dit(); 
    dit(); 
    dit(); 
    dah(); 	
    zeichen_abstand();
    break;
  case '_':
    dit(); 
    dit(); 
    dah(); 	
    dah(); 	
    dit(); 
    dah(); 	
    zeichen_abstand();
    break;
  case '"':
    dit(); 
    dah(); 	
    dit(); 
    dit(); 
    dah(); 	
    dit(); 
    zeichen_abstand();
    break;
  case '$':
    dit(); 
    dit(); 
    dit(); 
    dah(); 	
    dit(); 
    dit(); 
    dah(); 	
    zeichen_abstand();
    break;
  case '@':
    dit(); 
    dah(); 	
    dah(); 	
    dit(); 
    dah(); 	
    dit(); 
    zeichen_abstand();
    break;
  default:
    zeichen_abstand();
    break;
  }
}
