// RSG
// v1.01
// deKay - @deKay01 andyk@lofi-gaming.org.uk

// Very simple, terrible RPG

#include <SPI.h>
#include <Gamebuino.h>

Gamebuino gb;

const char version[] = "1.01";

extern const byte font3x3[]; //a really tiny font
extern const byte font3x5[]; //a small but efficient font (default)
extern const byte font5x7[]; //a large, comfy font

const byte logo[] PROGMEM = {64,36,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00001110,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01111111,B10000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000001,B11111111,B11000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000011,B11111111,B11100000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000111,B11111111,B11100000,
B00000000,B00000000,B00000000,B00000000,B11000000,B00001111,B11100011,B11100000,
B00000000,B00000000,B00000000,B00000111,B11110000,B00001111,B00000001,B11000000,
B00000000,B00000000,B00000000,B00011111,B11111000,B00011110,B00000000,B10000000,
B00000000,B00000000,B00000000,B00111111,B11111100,B00011100,B00000000,B00000000,
B00000000,B00000000,B00000000,B01111000,B00111100,B00111100,B00000000,B00000000,
B00000000,B00001111,B11000000,B11110000,B00111000,B00111000,B00000000,B00000000,
B00000000,B11111111,B11100000,B11110000,B00000000,B00111000,B00000000,B00000000,
B00000111,B11110001,B11100000,B11111100,B00000000,B01111000,B00000000,B00000000,
B00001111,B00000000,B11100000,B01111111,B11100000,B01111000,B00001111,B11100000,
B00001111,B00000001,B11100000,B00111111,B11111000,B01111000,B00001111,B11100000,
B00001111,B00011111,B11000000,B00011111,B11111100,B01111000,B00001111,B11100000,
B00001111,B11111111,B10000000,B00000001,B11111110,B01111000,B00001111,B11100000,
B00001111,B01111110,B00000000,B00000000,B00011110,B00111000,B00001111,B11100000,
B00001111,B00000111,B10000001,B11100000,B00001110,B00111000,B00000000,B11100000,
B00001111,B00000011,B11000001,B11100000,B00001110,B00111100,B00000000,B11100000,
B00001111,B00000001,B11000000,B11110000,B00011110,B00111110,B00000000,B11100000,
B00000011,B00000001,B11100000,B11111110,B11111110,B00011111,B00000001,B11100000,
B00000000,B00000000,B11110000,B01111111,B11111100,B00001111,B11000111,B11100000,
B00000000,B00000000,B00000000,B00011111,B11111000,B00001111,B11111111,B11100000,
B00000000,B00000000,B00000000,B00000011,B11110000,B00000111,B11111111,B11100000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000011,B11111111,B11000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B11111111,B00000000,
B00000000,B00000000,B00000000,B01000001,B00000000,B00000000,B00000000,B00001000,
B00000000,B00000000,B00000000,B01000001,B00000000,B00000000,B00000000,B00001000,
B00000000,B00000000,B00000001,B11001001,B01011001,B01000011,B00110000,B10101010,
B00000000,B00000000,B00000010,B01010101,B10000101,B01000100,B01001000,B10101100,
B00000000,B00000000,B00000010,B01010001,B01010101,B01000100,B01001000,B10101010,
B00000000,B00000000,B00000001,B11001101,B01001100,B10010011,B00110010,B01101010,
B00000000,B00000000,B00000000,B00000000,B00000000,B10000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000001,B00000000,B00000000,B00000000,
};


int const TITLES = 0;
int const PLAYGAME = 1;
int const WINGAME = 2;
int const LOSEGAME = 3;
int const INSTRUCTIONS = 4;
int const ATTACK = 5;
int const BADDIEATTACK = 6;
int gamestate;
int* misterbaddieman = new int[20];
int hp;
int mp;
int baddienumber;
int hebedead = 0; // 0 if he's alive, 1 if he's dead, 2 if they're all dead

void setup() {
  // put your setup code here, to run once:
  gb.begin();
  gb.display.setFont(font5x7);
  gb.titleScreen(F(""),logo);
 // gb.setFrameRate(1);
 gb.display.persistence = true;
  gb.pickRandomSeed();
  gameSetup();
}

void gameSetup(){
  gb.battery.show = true;
  initgame();
}

void initgame() {
//  gamestate = TITLES;

  // Set up misterbaddiemans 0-19
  misterbaddieman[0] = int(random(8)+5);
  for (int i=1; i < 20; i++) {
    misterbaddieman[i] = misterbaddieman[i-1] + int(random(4)+1);
  }

  // Set up hp and mp
  hp = int(random(35))+65;
  mp = int(random(12)+5);

  baddienumber = 0;
  gb.display.clear();

}

void keyPressed() {

  switch(gamestate) {
  case TITLES:
    if (gb.buttons.pressed(BTN_A)) { 
      gamestate = PLAYGAME;
      initgame();
    }; 
    if (gb.buttons.pressed(BTN_B)) { 
      gamestate = INSTRUCTIONS;
    }; 
    break;
  case INSTRUCTIONS:
    if(gb.buttons.pressed(BTN_A)){
      initgame();
      gamestate = TITLES;      
    };
    break;
  case PLAYGAME:
    if (gb.buttons.pressed(BTN_A)) { 
      attack("a");
    }; 
    if (gb.buttons.pressed(BTN_B)) { 
      attack("m");
    }; 
    break;
  case ATTACK:
    if (gb.buttons.pressed(BTN_B)) { 
      baddieattack();
    }; 
    break;
  case BADDIEATTACK:
    if (gb.buttons.pressed(BTN_B)) { 
      if (hp == 0) { 
        gamestate = LOSEGAME; 
        break;
      }
      if (hebedead ==2) { 
        gamestate = WINGAME;
      } 
      else { 
        gamestate = PLAYGAME;
      };
    } // 32 = SPACE
    break; 
  case WINGAME:
    if (gb.buttons.pressed(BTN_B)) { 
      initgame();
    }; // 32 = SPACE
    break;
  case LOSEGAME:
    if (gb.buttons.pressed(BTN_B)) { 
      initgame();
    }; // 32 = SPACE
    break; 
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(gb.update()){
//    gb.display.print(F("State: "));
//    gb.display.print(gamestate);
  switch(gamestate) {
  case TITLES:
    titlescreen();
    break;
  case PLAYGAME:
    playrsg();
    break;
  case INSTRUCTIONS:
    instructions();
    break;
  case ATTACK:
    attacking();
    break;
  case BADDIEATTACK:
    baddieattacking();
    break;
  case WINGAME:
    winning();
    break;
  case LOSEGAME:
    losing();
    break;
  }
  
  // If you don't do this you get stuck in PLAYGAME  
  if(gb.buttons.pressed(BTN_A)||gb.buttons.pressed(BTN_B)) {
    keyPressed();
    } else if(gb.buttons.pressed(BTN_C)){
      gb.display.setFont(font5x7);
      gb.titleScreen(F(""),logo);
      gamestate = TITLES;
    }
  }

}
