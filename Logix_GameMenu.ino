#include "src/utils/Arduboy2Ext.h"

uint8_t menuSelection0 = 0;
uint8_t menuSelection1 = 0;
ItemType gateIndex = ItemType::AND;
uint8_t successCount = 0;

const uint8_t y[] = { 4, 13, 22, 31, 43 };


void GameMenu() {

  render();
  
  arduboy.fillRect(0, 0, 40, 55, BLACK);
  arduboy.drawRect(1, 1, 38, 53, WHITE);
  arduboy.drawHorizontalDottedLine( 5, 36, 41, WHITE);

  font4x6.setTextColor(WHITE);
  font4x6.setCursor(8, 4);
  font4x6.print(F("Back\nTest\nInfo\nHelp"));
  font4x6.setCursor(8, 43);
  font4x6.print(F("Quit"));
  font4x6.setTextColor(BLACK);
  font4x6.setCursor(8, y[menuSelection0]);
  arduboy.fillRect(4, y[menuSelection0], 32, 8, WHITE);


  // Top level seelection ..

  switch (menuSelection0) {

    case 0:
      font4x6.print(F("Back"));
      break;

    case 1:
      font4x6.print(F("Test"));
      break;

    case 2:
      font4x6.print(F("Info"));
      Sprites::drawErase(31, 24, arrowRight, 0);
      break;

    case 3:
      font4x6.print(F("Help"));
      Sprites::drawErase(31, 33, arrowRight, 0);
      break;

    case 4:
      font4x6.setCursor(8, 43);
      font4x6.print(F("Quit"));
      break;

  }


  // Second level menu items ..

  font4x6.setTextColor(WHITE);

  switch (menuSelection1) {
      
    case 2:
      break;

    case 3:
      {
        arduboy.fillRect(36, 8, 81, 57, BLACK); 
        arduboy.drawRect(37, 9, 79, 55, WHITE); 
        arduboy.fillRect(113, 9, 7, 55, WHITE); 
        Sprites::drawOverwrite(114, 10, arrowUp, 0);
        Sprites::drawOverwrite(114, 54, arrowDown, 0);
        arduboy.drawHorizontalDottedLine(40, 110, 19, WHITE);

        Sprites::drawOverwrite(51, 33, logicGates, static_cast<uint8_t>(gateIndex));

        font4x6.setCursor(40, 10);
        font4x6.print(reinterpret_cast<const __FlashStringHelper *>(pgm_read_word(&itemTypes[static_cast<uint8_t>(gateIndex)])));

        if (gateIndex != ItemType::NOT) {

          font4x6.setCursor(85, 10);
          font4x6.print(F("A B O"));
          font4x6.setCursor(42, 32);
          font4x6.print(F("A\nB"));
        }
        else {
          font4x6.setCursor(85, 10);
          font4x6.print(F("A   O"));
          font4x6.setCursor(42, 36);
          font4x6.print(F("A"));
        }
        font4x6.setCursor(71, 37);
        font4x6.print(F("O"));

        uint8_t start = (static_cast<uint8_t>(gateIndex) * 12);

        font4x6.setCursor(85, 21);
        renderDataLine(start);
        arduboy.drawHorizontalDottedLine(82, 110, 30, WHITE);
        font4x6.setCursor(85, 32);
        renderDataLine(start);
        arduboy.drawHorizontalDottedLine(82, 110, 41, WHITE);

        if (gateIndex != ItemType::NOT) {

          font4x6.setCursor(85, 43);
          renderDataLine(start);
          arduboy.drawHorizontalDottedLine(82, 110, 52, WHITE);
          font4x6.setCursor(85, 54);
          renderDataLine(start);
          arduboy.drawHorizontalDottedLine(82, 110, 63, WHITE);

        }

      }
      break;

  }


  // Handle keypresses ..

  if (arduboy.justPressed(UP_BUTTON) && menuSelection0 > 0 && menuSelection1 == 0)      { menuSelection0--; }
  if (arduboy.justPressed(UP_BUTTON) && menuSelection1 == 3)                            { gateIndex++; if (gateIndex == ItemType::BLANK) gateIndex = ItemType::AND; }
  if (arduboy.justPressed(DOWN_BUTTON) && menuSelection0 < 4 && menuSelection1 == 0)    { menuSelection0++; }
  if (arduboy.justPressed(DOWN_BUTTON) && menuSelection1 == 3)                          { gateIndex--; if (gateIndex == ItemType::BLANK) gateIndex = ItemType::NOT; }

  if (arduboy.justPressed(RIGHT_BUTTON) && menuSelection0 == 3 && menuSelection1 == 0)  { menuSelection1 = 3; }
  if (arduboy.justPressed(LEFT_BUTTON) && menuSelection1 > 0)                           { menuSelection1 = 0; }
  if (arduboy.justPressed(B_BUTTON) && menuSelection1 == 0)                             { gameState = GameState::GamePlay; selection.reset(); }
  if (arduboy.justPressed(B_BUTTON) && menuSelection1 > 0)                              { menuSelection1 = 0; }

  if (arduboy.justPressed(A_BUTTON)) {

    switch (menuSelection0) {

      case 0:
        selection.reset();
        gameState = GameState::GamePlay;
        break;

      case 3:
        menuSelection1 = 3;
        break;
    
    }

  }

}


void renderDataLine(uint8_t &start) {

    font4x6.print(pgm_read_byte(&data[start++]));
    font4x6.print(" ");

    uint8_t x = pgm_read_byte(&data[start++]);

    if (x < 2) {
      font4x6.print(x);
    }
    else {
      font4x6.print(" ");
    }

    font4x6.print(" ");
    font4x6.print(pgm_read_byte(&data[start++]));

}