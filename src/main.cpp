#include <M5StickCPlus.h>
#include "MAX30100_PulseOximeter.h"

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
		if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
				M5.Lcd.fillScreen(BLACK);
				M5.Lcd.setCursor(3, 5, 1);
				M5.Lcd.print("SpO2 \n");
				M5.Lcd.print((pox.getSpO2() > MAX_SPO2)? MAX_SPO2 : pox.getSpO2() );
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
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
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
		pulseOximeter();

		M5.update();
    delay(50);
}

/*
*******************************************************************************
* Copyright (c) 2022 by M5Stack
*                  Equipped with M5Core sample source code
*                          配套  M5Core 示例源代码
* Visit for more information: https://docs.m5stack.com/en/core/gray
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/core/gray
*
* Describe: Heart Rate.  心率
* Date: 2021/8/16
*******************************************************************************
  Please connect to Port A, HEART Unit obtains the original value of the heart
rate detection and displays it on the screen. The user can also use the Arduino
IDE Serial Plotter to view the line graph output. 请连接端口A,HEART
Unit获取心率检测的原始值并显示在屏幕上。用户还可以使用Arduino IDE Serial
Plotter查看线图输出。
*/

// #include <M5StickCPlus.h>
// #include <FS.h>
// #include <SPI.h>
// #include <Wire.h>

// #include "MAX30100.h"

// #define SAMPLING_RATE   MAX30100_SAMPRATE_100HZ
// #define IR_LED_CURRENT  MAX30100_LED_CURR_24MA
// #define RED_LED_CURRENT MAX30100_LED_CURR_27_1MA
// #define PULSE_WIDTH     MAX30100_SPC_PW_1600US_16BITS
// #define HIGHRES_MODE    true

// MAX30100 sensor;  // Instantiate a MAX30100 sensor class.  实例化一个MAX30100传感器类

// void setup() {
//     M5.begin();        // Init M5Stack.  初始化M5Stack
//     M5.Axp.begin();  // Init power  初始化电源模块
//     Serial.print("Initializing MAX30100..");

//     while (!sensor.begin()) {  // Initialize the sensor.  初始化传感器
//         M5.Lcd.setTextFont(4);
//         M5.Lcd.setCursor(50, 100, 4);
//         M5.Lcd.println("Sensor not found");
//         delay(1000);
//     }
//     M5.Lcd.fillScreen(BLACK);
//     // Set up the wanted parameters.  设置所需的参数
//     sensor.setMode(MAX30100_MODE_SPO2_HR);
//     sensor.setLedsCurrent(IR_LED_CURRENT, RED_LED_CURRENT);
//     sensor.setLedsPulseWidth(PULSE_WIDTH);
//     sensor.setSamplingRate(SAMPLING_RATE);
//     sensor.setHighresModeEnabled(HIGHRES_MODE);
// }

// void loop() {
//     uint16_t ir, red;
//     sensor.update();  //更新传感器读取到的数据
//     while (sensor.getRawValues(&ir, &red)) {  //如果获取到数据
//         M5.Lcd.setTextFont(4);
//         M5.Lcd.setCursor(100, 100, 4);
//         M5.Lcd.printf("IR:%d               ", ir);
//         M5.Lcd.setCursor(100, 130, 4);
//         M5.Lcd.printf("RED:%d              ", red);
//     }
// }