void titlescreen() {
  gb.display.clear();
  gb.display.setFont(font5x7);
//gb.display.print(F("123456789012345\n"));
  gb.display.print(F("    R.S.G.\n"));
  gb.display.print(F("\n"));
  gb.display.setFont(font3x5);
//gb.display.print(F("123456789012345678901\n"));
  gb.display.print(F("       \25 Start\n"));
  gb.display.print(F("   \26 Instructions\n\n"));
  gb.display.print(F(" (c)2015 deKay, v"));
  gb.display.print(version);
}

void instructions(){
  gb.display.clear();
  gb.display.setFont(font5x7);
//gb.display.print(F("123456789012345\n"));
  gb.display.print(F(" Instructions\n"));
  gb.display.print(F("\n"));
  gb.display.setFont(font3x5);
//gb.display.print(F("123456789012345678901\n"));
  gb.display.print(F("20 Misterbaddiemen\n"));
  gb.display.print(F("must be fought with\n"));
  gb.display.print(F("attacks or magic\n"));  
  gb.display.print(F("for no real reason!\n"));

}
