
/*
A simple "hello world" example.
Set the screen background color and palette colors.
Then write a message to the nametable.
Finally, turn on the PPU to display video.
*/

#include "neslib.h"
#include "apu.h"

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// main function, run after console reset
void main(void) {

  // set palette colors
  pal_col(0,0x00);	// dark grey
  pal_col(1,0x14);	// fuchsia
  pal_col(2,0x20);	// grey
  pal_col(3,0x30);	// white

  APU_ENABLE(ENABLE_PULSE0);
  APU_PULSE_SUSTAIN(1,2,2,2);

  //music_play(1); // Menu Music
  
  // write text to name table
  vram_adr(NTADR_A(10,10));	// set address
  vram_write("",10);	// write bytes to video RAM
  
  vram_adr(NTADR_A(8,20));
  vram_write("Press A to start", 16);
  
  // enable PPU rendering (turn on screen)
  ppu_on_all();

  // infinite loop
  while (1) {
//    if () { // Check for 'A' input
//      // Clear Screen to start the game
//      
//    }
  };
}
