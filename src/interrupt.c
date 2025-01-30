#include <stdio.h>
#include "pico/stdlib.h"
#include "pio.h"

// Variável global para armazenar a cor (Entre 0 e 255 para intensidade)
uint8_t led_r = 0;   // Intensidade do vermelho
uint8_t led_g = 0;   // Intensidade do verde
uint8_t led_b = 100; // Intensidade do azul

// Variáveis globais
static volatile uint a = 1;
static volatile uint32_t last_time_A = 0; // Armazena o tempo do último evento (em microssegundos)
static volatile uint32_t last_time_B = 0;
static volatile int index = 0;
static volatile  uint button_A = 5;  // Botão A = 5
static volatile  uint button_B = 6;  // Botão B = 6

// Função de interrupção com debouncing
void gpio_irq_handler(uint gpio, uint32_t events)
{
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    if (gpio == button_A) {
        if (current_time - last_time_A > 200000) {  // 200 ms debounce para botão A
            last_time_A = current_time;
            printf("A: %d\n", a);
            a++;
            if (index != 9)
            {
                index++;
                set_one_led(index, led_r, led_g, led_b);
            }
            else
            {
                set_one_led(index, 100, 0, 0);
            }
        }
    } else if (gpio == button_B) {
        if (current_time - last_time_B > 200000) {  // 200 ms debounce para botão B
            last_time_B = current_time;
            printf("B: %d\n", a);
            a++;
            {
            if (index != 0)
            {
                index--;
                set_one_led(index, led_r, led_g, led_b);
            }
            else
            {
                set_one_led(index, 100, 0, 0);
            }
        }
        }
    }
}