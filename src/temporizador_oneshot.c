#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED_BLUE 11
#define LED_RED 12
#define LED_GREEN 13
#define BUTTON 5

volatile bool led_active = false;

bool turn_off_callback(alarm_id_t id, void *user_data) {
    static int state = 2;
    if (state == 2) {
        gpio_put(LED_BLUE, 0);
    } else if (state == 1) {
        gpio_put(LED_RED, 0);
    } else {
        gpio_put(LED_GREEN, 0);
        led_active = false;
        state = 3;
    }
    state--;
    if (state >= 0) {
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }
    return true;
}

void button_callback(uint gpio, uint32_t events) {
    if (!led_active) {
        led_active = true;
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
        gpio_put(LED_GREEN, 1);
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }
}

int main() {
    stdio_init_all();
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);
    gpio_init(LED_GREEN);
    gpio_init(BUTTON);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_RISE, true, &button_callback);
    
    while (1) {
        sleep_ms(100);
    }
}