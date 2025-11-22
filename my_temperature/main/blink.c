#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"

void app_main(void)
{
    int count = 0;
    while(1) {
        float temperature = 20.0 + (count % 100) * 0.1;
        printf("Temperature: %.1f C\n", temperature);
        count++;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
