void winning(){
  gb.display.clear();
  gb.display.setFont(font5x7);

//gb.display.print(F("123456789012345\n"));
  gb.display.print(F("   YOU WIN!!\n\n"));
  gb.display.print(F("     YAY!\n"));
  gb.display.setFont(font3x5);
//gb.display.print(F("123456789012345678901\n"));

  gb.display.print(F("\n(press \27)"));  
  gb.display.update();
  

}

void losing(){
  
//gb.display.print(F("123456789012345\n"));
  gb.display.print(F(" YOU'RE DEAD!!\n\n"));
  gb.display.print(F("   Rubbish!\n"));
  gb.display.setFont(font3x5);
//gb.display.print(F("123456789012345678901\n"));

  gb.display.print(F("\n(press \27)"));  
  gb.display.update();
}
