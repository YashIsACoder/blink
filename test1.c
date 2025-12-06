#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"
#include <math.h>
#include <stdlib.h>

#define LED_PIN CYW43_WL_GPIO_LED_PIN   // onboard LED pin

int RNG(int min, int max);

int RNG(int min, int max) {
    return rand() % (max - min + 1) + min;
}


int main() {
    stdio_init_all();

    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return -1;
    }

    // random blink
    while (true) {
        cyw43_arch_gpio_put(LED_PIN, 1);
        sleep_ms(RNG(1000, 10000));
        cyw43_arch_gpio_put(LED_PIN, 0);
        sleep_ms(RNG(1000, 10000));
    }

    // // blink every 2 seconds
    // while (true) {
    //     cyw43_arch_gpio_put(LED_PIN, 1);
    //     sleep_ms(2000);
    //     cyw43_arch_gpio_put(LED_PIN, 0);
    //     sleep_ms(2000);
    // }

    // const int wrap = 100;

    // while (true) {
    //     // Sweep through 0..2π
    //     for (int i = 0; i < 360; i++) {
    //         float radians = (float)i * (M_PI / 180.0f);
    //         float sine_val = (sinf(radians) + 1.0f) / 2.0f;
    //         int duty = (int)(sine_val * wrap);

    //         // Software PWM cycle
    //         for (int j = 0; j < wrap; j++) {
    //             if (j < duty) {
    //                 cyw43_arch_gpio_put(LED_PIN, 1);  // LED on
    //             } else {
    //                 cyw43_arch_gpio_put(LED_PIN, 0);  // LED off
    //             }
    //             sleep_us(200);
    //         }
    //     }
    // }

    return 0;
}
