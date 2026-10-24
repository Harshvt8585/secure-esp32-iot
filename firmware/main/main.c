/*
 * Secure ESP32 IoT Device — Phase 0/1 skeleton.
 *
 * Current state: placeholder entry point.
 * Phase 1 will add: Wi-Fi connect, DHT11 read, plaintext MQTT publish.
 * Phase 2 will add: TLS (mqtts://, port 8883), device certificate auth.
 * Phase 3 will add: OTA update check + firmware signature verification.
 *
 * See /docs and the project README for the phase plan.
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "secure_iot_node";

void app_main(void)
{
    ESP_LOGI(TAG, "Secure ESP32 IoT node booting (Phase 0 skeleton)");

    while (1) {
        ESP_LOGI(TAG, "placeholder loop — sensor read + MQTT publish land in Phase 1");
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
