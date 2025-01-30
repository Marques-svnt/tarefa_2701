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

// Função responsável pelo debounce
bool debounce(volatile uint32_t *last_time, uint32_t debounce_time) {
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    if (current_time - *last_time > debounce_time) {
        *last_time = current_time;
        return true;
    }
    return false;
}

// Função de interrupção com debouncing
void gpio_irq_handler(uint gpio, uint32_t events)
{
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    // Incrementação do número da matriz de leds
    if (gpio == BUTTON_A && debounce(&last_time_A, 200000))
    {
        last_time_A = current_time;
        printf("A: %d\n", a); // Para controle quando se usa o monitor serial para verificar se há bouncing
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
    // Decrementação do número da matriz de leds
    else if (gpio == BUTTON_B && debounce(&last_time_A, 200000))
    {
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