#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define BLINK_GPIO 2

static void configure_led(void) {
    gpio_reset_pin(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

static void blink_led(void) {
    int nextState = !gpio_get_level(BLINK_GPIO);
    gpio_set_level(BLINK_GPIO, nextState);
    if(nextState)
        ESP_LOGI("LED", "LED ON");
    else
        ESP_LOGI("LED", "LED OFF");
}

void app_main(void) {
    configure_led();
    while (1) {
        blink_led();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}