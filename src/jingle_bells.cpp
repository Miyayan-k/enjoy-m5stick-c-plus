#include <M5StickCPlus.h>
#include "jingle_bells.h"

// シシシ　シシシ　シレソラシ　ドドドド　ドシシシ
void jingleBellsA()
{
	M5.Lcd.setCursor(10, 45);
	M5.Lcd.setTextSize(2);
	M5.Lcd.fillScreen(TFT_RED);
	M5.Lcd.print("Jingle bells,\n");
	// シシシ　シシシ
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(1000);

	M5.Lcd.print("  Jingle bells,");
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(1000);

	M5.Lcd.fillScreen(TFT_GREEN);

	M5.Lcd.setCursor(10, 45);
	M5.Lcd.setTextSize(2);
	M5.Lcd.print("jingle \n  all the way!");
	// シレソラシ
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(587);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(783);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(440);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(1000);

	M5.Lcd.fillScreen(TFT_RED);

	M5.Lcd.setCursor(10, 45);
	M5.Lcd.setTextSize(2);
	M5.Lcd.print("O what fun\n");
	// ドドドド
	M5.Beep.tone(523);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(523);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(523);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(523);
	delay(500);
	M5.Beep.mute();
	delay(100);

	M5.Lcd.print("  it is to ride\n");
	// ドシシシ
	M5.Beep.tone(523);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(100);
}

// Beep画面点滅処理
void jingleBells()
{
	jingleBellsA();

	M5.Lcd.fillScreen(TFT_RED);

	M5.Lcd.setCursor(10, 45);
	M5.Lcd.setTextSize(2);
	M5.Lcd.print("In a one-horse\n  open sleigh");
	// シララソラ
	M5.Beep.tone(493);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(440);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(440);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(783);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(440);
	delay(500);
	M5.Beep.mute();
	delay(500);

	M5.Lcd.fillScreen(TFT_GREEN);

	// レ
	M5.Beep.tone(587);
	delay(500);
	M5.Beep.mute();
	delay(1000);

	jingleBellsA();

	M5.Lcd.fillScreen(TFT_RED);

	M5.Lcd.setCursor(10, 45);
	M5.Lcd.setTextSize(2);
	M5.Lcd.print("In a one-horse\n  open sleigh");
	// レレドラソ
	M5.Beep.tone(587);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(587);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(523);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(440);
	delay(500);
	M5.Beep.mute();
	delay(100);
	M5.Beep.tone(783);
	delay(500);
	M5.Beep.mute();
	delay(100);

	M5.Lcd.fillScreen(TFT_GREEN);

	M5.Beep.mute();
	delay(100);
	M5.Beep.mute();
	M5.Lcd.setCursor(10, 45);
	M5.Lcd.setTextSize(3);
	M5.Lcd.println("Merry \n  Christmas!!");
	delay(5000);
}