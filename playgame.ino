void playrsg() {
  //gb.display.clear();
  if (misterbaddieman[baddienumber] == 0) { 
    baddienumber++;
  };
  displayHUD();
}

void attacking() {
}

void attack(String attacktype) {
  gamestate = ATTACK;
  hebedead = 0;
  int baddiedamage = 0;
  int edam = 0; // Obligatory cheese reference
  String damagetext = "";

  // Normal Attack - damage 0 to 5, with 8/12/25 Super Attack chance
  if (attacktype == "a") {
    baddiedamage = int(random(6));
    damagetext = "ATTACK!";
    // Super Attack?
    if (baddiedamage == 0) {
      edam = int(random(5));
      if (edam == 0) { 
        baddiedamage = 25; 
        damagetext = "BESTATTACK!";
      };
      if (edam == 1) { 
        baddiedamage = 12; 
        damagetext = "SUPERATTACK!";
      };
      if (edam == 2) { 
        baddiedamage = 8; 
        damagetext = "SUPERATTACK!";
      };
      if (edam > 2) { 
        baddiedamage = 0;
      };
    }
  }

  // Magic Attack - damage 5 to 15  
  if (attacktype == "m") {
    damagetext = "MAGIC!";
    baddiedamage = int(random(11)+5);
    if (mp == 0) {
      damagetext = "NO MP!"; 
      baddiedamage = 0;
    }
    mp-- ;
    if (mp < 0) { 
      mp = 0;
    };
  }

  misterbaddieman[baddienumber] = misterbaddieman[baddienumber] - baddiedamage;
  if (misterbaddieman[baddienumber] < 0) {
    misterbaddieman[baddienumber] = 0;
  };

  gb.display.clear();

  gb.display.setFont(font5x7);

  gb.display.println(damagetext);
  gb.display.print(F("Damage: "));
  gb.display.println(baddiedamage);
  gb.display.setFont(font3x5);
  gb.display.print(F("\n(press \26)"));

  if (misterbaddieman[baddienumber] == 0) { 
    gb.display.setFont(font5x7);
    gb.display.print(F("\n\nHE'S DEAD!!"));
    baddienumber++;
    hebedead = 1;
    if (baddienumber == 20) {
      hebedead = 2;
    };
  }
 // while (!gb.buttons.released(BTN_B)) {
    gb.display.update();
 // }
}

void baddieattacking() {
}

void baddieattack() {
  gamestate = BADDIEATTACK;

  if (hebedead == 0) {  
    int damage = 0;
    damage=int(random(3+random(baddienumber/5)));   
    gb.display.clear();
    gb.display.setFont(font5x7);
    gb.display.print(F("He attacks...\n"));
    gb.display.print(F("Damage: "));
    gb.display.println(damage);
    gb.display.setFont(font3x5);
    gb.display.print(F("\n(press \26)"));
    hp = hp - damage;
    if (hp < 0) { hp = 0 ;};
  }

  if (hebedead == 1) {
    gb.display.clear();
    gb.display.setFont(font3x5);
    gb.display.print(F("Another assailant!\n"));
    gb.display.print(F("Misterbaddieman "));
    gb.display.println(baddienumber+1);
    gb.display.setFont(font3x5);
    gb.display.print(F("\n(press \26)"));
  }
  //gb.display.update();
}

void displayHUD() {
  gb.display.clear();
  gb.display.setFont(font3x5);
  gb.display.print(F("Misterbaddieman "));
  gb.display.println(baddienumber+1);
  gb.display.print(F("\nHIM: HP "));
  gb.display.println(misterbaddieman[baddienumber]);
  gb.display.print(F("YOU: HP "));
  gb.display.print(hp);
  gb.display.print(F("   MP "));
  gb.display.println(mp);
  gb.display.print(F("\n\25 Attack or \26 Magic?"));
  //gb.display.update();
}

