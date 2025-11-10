#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define POT_PIN 4  // ADC pin

TaskHandle_t TaskPotCore0;
TaskHandle_t TaskPotCore1;

// ====== TASK CORE 0 ======
void TaskPotentiometerCore0(void *pvParameters) {
  while (1) {
    int rawValue = analogRead(POT_PIN);
    float voltage = (rawValue / 4095.0) * 3.3;

    Serial.printf("[CORE 0] Raw: %d | Voltage: %.2f V | Running on CORE %d\n",
                  rawValue, voltage, xPortGetCoreID());

    vTaskDelay(pdMS_TO_TICKS(300));  // FreeRTOS delay
  }
}

// ====== TASK CORE 1 ======
void TaskPotentiometerCore1(void *pvParameters) {
  while (1) {
    int rawValue = analogRead(POT_PIN);
    float voltage = (rawValue / 4095.0) * 3.3;

    Serial.printf("[CORE 1] Raw: %d | Voltage: %.2f V | Running on CORE %d\n",
                  rawValue, voltage, xPortGetCoreID());

    vTaskDelay(pdMS_TO_TICKS(300));  // FreeRTOS delay
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Task di Core 0
  xTaskCreatePinnedToCore(
    TaskPotentiometerCore0,   // function
    "PotTaskCore0",           // name
    4096,                     // stack size
    NULL,                     // parameter
    1,                        // priority
    &TaskPotCore0,            // task handle
    0                         // core ID
  );

  // Task di Core 1
  xTaskCreatePinnedToCore(
    TaskPotentiometerCore1,
    "PotTaskCore1",
    4096,
    NULL,
    1,
    &TaskPotCore1,
    1
  );
}

void loop() {
  // Kosong, semua berjalan dalam task RTOS
}


void setup() {
  Serial.begin(115200);
  delay(1000);

  // Task membaca potensiometer di core 0
  xTaskCreatePinnedToCore(
    TaskPotentiometerCore0,
    "PotCore0",
    4096,
    NULL,
    1,
    &TaskPotCore0,
    0   // <<-------- CORE 0
  );

  // Task membaca potensiometer di core 1
  xTaskCreatePinnedToCore(
    TaskPotentiometerCore1,
    "PotCore1",
    4096,
    NULL,
    1,
    &TaskPotCore1,
    1   // <<-------- CORE 1
  );
}

void loop() {}
