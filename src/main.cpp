#include <M5StickCPlus.h>
#include "MAX30100_PulseOximeter.h"
#include "jingle_bells.h"

#define LED_PIN 10 // G10
#define REPORTING_PERIOD_MS 1000
#define MAX_SPO2 100

PulseOximeter pox;
uint32_t tsLastReport = 0;

void pulseOximeter()
{
	pox.update();

	// 心拍数と酸化度を非同期でシリアルにダンプ
	// どちらも0は "無効 "
	if (millis() - tsLastReport > REPORTING_PERIOD_MS)
	{
		M5.Lcd.fillScreen(BLACK);
		M5.Lcd.setCursor(3, 5, 1);
		M5.Lcd.print("SpO2 \n");
		M5.Lcd.print((pox.getSpO2() > MAX_SPO2) ? MAX_SPO2 : pox.getSpO2());
		M5.Lcd.println(" %\n");
		M5.Lcd.print("PR \n");
		M5.Lcd.print(pox.getHeartRate());
		M5.Lcd.println(" bpm");

		tsLastReport = millis();
	}
}

// パルス検出時Lチカ
void onBeatDetected()
{
	digitalWrite(LED_PIN, LOW);
	delay(1);
	digitalWrite(LED_PIN, HIGH);
}

void setup()
{
	M5.begin();
	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, HIGH);
	M5.Axp.ScreenBreath(10);
	M5.Lcd.setRotation(3);
	M5.Lcd.fillScreen(BLACK);
	M5.Lcd.setTextSize(3);
	M5.Lcd.print("MAX30100");
	M5.Lcd.setCursor(0, 40);

	Serial.begin(115200);
	Serial.print("Initializing pulse oximeter");

	// パルスオキシメータインスタンスの初期化
	if (!pox.begin())
	{
		Serial.println("FAILED");
		for (;;)
			;
	}
	else
	{
		Serial.println("SUCCESS");
	}

	// IR LEDのデフォルトの電流は50mAですが、以下の行をコメントアウト解除することで変更可能
	// 利用可能なすべてのオプションについては、MAX30100_Registers.hを確認
	// pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);

	// パルス検出用コールバック
	pox.setOnBeatDetectedCallback(onBeatDetected);
	M5.Lcd.fillScreen(BLACK);
}

void loop()
{
	M5.update();
	pulseOximeter();

	// M5ボタン判定(ジングルベル)
	if (M5.BtnA.wasPressed())
	{
		jingleBells();
	}

	delay(50);
}
