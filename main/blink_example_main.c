#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BLINK_GPIO 2

static void configure_led(void) {
    gpio_reset_pin(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

static void blink_led(void) {
    int currentState = gpio_get_level(BLINK_GPIO);
    gpio_set_level(BLINK_GPIO, !currentState);
}

void app_main(void) {

    /* Configure the peripheral according to the LED type */
    configure_led();

    while (1) {
        /* Toggle the LED state */
        blink_led();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}