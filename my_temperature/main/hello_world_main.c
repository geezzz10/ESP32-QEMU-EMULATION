#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO 2

void app_main(void) {
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    int led_state = 0;
    
    while(1) {
        led_state = !led_state;
        gpio_set_level(LED_GPIO, led_state);
        
        if (led_state) {
            printf("LED ON\n");
        } else {
            printf("LED OFF\n");
        }
        
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
