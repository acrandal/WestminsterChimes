/**
 *   Westminster Chimes Demo
 *   
 *   Plays a simple Westminster Chimes melody
 *    Provides a method for chimes and gongs
 *   
 *   circuit:
 *     - 8 ohm speaker (piezio) on digital pin 8
 *     
 *     created 21 Jan 2010
 *     modified 30 Aug 2011
 *     modified 06 Nov 2021 - Aaron S. Crandall <crandall@gonzaga.edu>
 *     
 *     Original code from: http://www.arduino.cc/en/Tutorial/Tone
 *      by Tom Igoe
 *      This example code is in the public domain.
 * 
 *  Good example of the Westminster Chimes sheet music:
 *   https://levysheetmusic.mse.jhu.edu/collection/169/090
 */


#include "pitches.h"
int buzzerPin = 8;

// Westminster Chimes music:
int melody[] = {
  NOTE_A2, NOTE_G2, NOTE_F2, NOTE_C2, REST, REST, NOTE_F2, NOTE_G2, NOTE_A2, NOTE_F2, REST, REST, NOTE_A2, NOTE_F2, NOTE_G2, NOTE_C2, REST, REST, NOTE_C2, NOTE_G2, NOTE_A2, NOTE_F2, REST, REST
};

// Chimes music durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};

int noteQuantity = 24;


/**
 * Plays the Westminster Chimes music
 */
void playWestminsterChimes() {
  // Iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < noteQuantity; thisNote++) {
    // To calculate the note duration, take one second divided by the note type.
    //  e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    
    int noteDuration = 1200 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    // To distinguish the notes, set a minimum time between them.
    // The note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // Stop the tone playing:
    noTone(buzzerPin);
  }  
}

/**
 * Play a single bong
 * 
 * @param bongDuration: length of bong in ms
 */
void playBong(int bongDuration) {
  tone(buzzerPin, NOTE_B0, bongDuration);
  delay(bongDuration);
  noTone(buzzerPin);
}


void setup() {
  int hourOfDay = 4;
  playWestminsterChimes();
  for(int i = 0; i < hourOfDay; i++ ) {
    playBong(1200); // Should be about the same length as a full measure
    delay(600);     // Should be about 1/2 the length of a bong duration
  }
}

void loop() {
  // No further sounds
}
