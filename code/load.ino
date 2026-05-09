/**
 * Complete project details at https://RandomNerdTutorials.com/arduino-load-cell-hx711/
 *
 * HX711 library for Arduino - example file
 * https://github.com/bogde/HX711
 *
 * MIT License
 * (c) 2018 Bogdan Necula
 *
**/

#include <Arduino.h>
#include "HX711.h"
#include <Wire.h> // Include Wire library for I2C communication
#include <Adafruit_LiquidCrystal.h> // Include Adafruit LCD library
#include <MPU6050.h>
#include <math.h>



// Define LCD parameters
#define LCD_ADDR 0x27     // I2C address of your LCD module
#define LCD_COLS 16       // Number of columns in the LCD
#define LCD_ROWS 2        // Number of rows in the LCD

// Initialize LCD object
Adafruit_LiquidCrystal lcd(LCD_ADDR);

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 7;
const int LOADCELL_SCK_PIN = 6;
int a, b;

HX711 scale;


//MPU vatiables
MPU6050 mpu;

int16_t ax, ay, az;
int16_t gx, gy, gz;

float roll = 0, pitch = 0;
float roll_acc, pitch_acc;

unsigned long prevTime = 0;
float dt;

void setup()
{
    Serial.begin(9600);
    Serial.println("HX711 Demo");
    Serial.println("Initializing the scale");

    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

    // Initialize LCD
    lcd.begin(LCD_COLS, LCD_ROWS);
    lcd.clear();
    lcd.print("Initializing...");

    Serial.println("Before setting up the scale:");
    Serial.print("read: \t\t");
    Serial.println(scale.read()); // print a raw reading from the ADC

    Serial.print("read average: \t\t");
    Serial.println(scale.read_average(20)); // print the average of 20 readings from the ADC

    Serial.print("get value: \t\t");
    Serial.println(scale.get_value(5)); // print the average of 5 readings from the ADC minus the tare weight (not set yet)

    Serial.print("get units: \t\t");
    Serial.println(scale.get_units(5), 1); // print the average of 5 readings from the ADC minus tare weight (not set) divided
                                            // by the SCALE parameter (not set yet)

    scale.set_scale(269.259);
    //scale.set_scale(-471.497);                      // this value is obtained by calibrating the scale with known weights; see the README for details
    scale.tare(); // reset the scale to 0

    Serial.println("After setting up the scale:");

    Serial.print("read: \t\t");
    a = scale.read();
    b = a * 10;
    Serial.println(b); // print a raw reading from the ADC

    Serial.print("read average: \t\t");
    Serial.println(scale.read_average(20)); // print the average of 20 readings from the ADC

    Serial.print("get value: \t\t");
    Serial.println(scale.get_value(5)); // print the average of 5 readings from the ADC minus the tare weight, set with tare()

    Serial.print("get units: \t\t");
    Serial.println(scale.get_units(5), 1); // print the average of 5 readings from the ADC minus tare weight, divided
                                            // by the SCALE parameter set with set_scale

    Serial.println("Readings:");

    init_mpu();
}

void loop()
{
//    Serial.print("one reading:\t");
//    Serial.print(scale.get_units(), 1);
//    Serial.print("\t| average:\t");
//    Serial.println(scale.get_units(10), 5);
//    

    // Display readings on LCD
    if(roll > 60 && <= -25)
    {
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Reading:");
      lcd.setCursor(0, 1);
      lcd.print(scale.get_units(), 1);

      delay(1000);
    }

    mpu_sense();
}

void init_mpu()
{
  mpu.initialize();
  mpu.setSleepEnabled(false);

  if (mpu.testConnection()) {
    Serial.println("MPU6050 Connected!");
  } else {
    Serial.println("Connection Failed!");
    Serial.println("Close the prg now");
    while (1);
    
  }

  prevTime = millis();
}

void mpu_sense()
{
  
  unsigned long currentTime = millis();
  dt = (currentTime - prevTime) / 1000.0;
  prevTime = currentTime;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  float Ax = ax;
  float Ay = ay;
  float Az = az;

  roll_acc  = atan2(Ay, Az) * 180 / PI;
  pitch_acc = atan2(-Ax, sqrt(Ay * Ay + Az * Az)) * 180 / PI;

  // Gyroscope (convert to deg/sec)
  float Gx = gx / 131.0;
  float Gy = gy / 131.0;

  // Complementary filter
  roll  = 0.98 * (roll + Gx * dt) + 0.02 * roll_acc;
  pitch = 0.98 * (pitch + Gy * dt) + 0.02 * pitch_acc;

  Serial.print("Roll: ");
  Serial.print(roll);
  Serial.print("  |  Pitch: ");
  Serial.println(pitch);

  delay(1000);
}
