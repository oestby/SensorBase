#include <DHT.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 7
#define DHTTYPE DHT22
#define OLED_MOSI 2
#define OLED_CLK 3
#define OLED_DC 4
#define OLED_CS 5
#define OLED_RESET 6

#define DHT_SENSOR_ID 1 

// Initialize the display and the sensor
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, 
                         OLED_DC, OLED_RESET, 
                         OLED_CS);
DHT dht(DHTPIN, DHTTYPE);

struct Data {
    float humidity = 0.f, temperature = 0.f;
} data, last_data;

char* paddedString() {
    

}
void printData(Data d) {
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Room temp:");
    display.println("");
    display.print("Temp: ");
    display.print(d.temperature);
    display.print("C\n");
    display.print("Hum: ");
    display.print(d.humidity);
    display.print("%\n");
    display.display();
}

void setup() {
    Serial.begin(9600);
    dht.begin();

    // Sets up the display correctly
    display.begin();
    display.display();
    delay(1000);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    delay(2000);
}

void loop() {
    last_data = data;
    
    data.humidity = dht.readHumidity();
    data.temperature = dht.readTemperature();

    if (!(data.humidity < 101) &&
        !(data.humidity > 0)) {
       data.humidity = last_data.humidity;
    }

    if (!(data.temperature < 80) &&
        !(data.temperature > -40)) {
        data.temperature = last_data.temperature;
    }
    
    // Sends data via serial on the format:
    // humidity,temperature\n
    Serial.print(data.humidity);
    Serial.print(",");
    Serial.print(data.temperature);
    Serial.print("\n");
    
    delay(2000); // 2 seconds between each loop.
}
  
