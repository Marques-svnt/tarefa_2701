#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pio.h"
#include "pinos.h"

#define IS_RGBW false
#define NUM_PIXELS 25
#define WS2812_PIN 7
#define button_A 5

// Variáveis globais
static volatile uint a = 1;
static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)

// Variável global para armazenar a cor (Entre 0 e 255 para intensidade)
uint8_t led_r = 0; // Intensidade do vermelho
uint8_t led_g = 0; // Intensidade do verde
uint8_t led_b = 100; // Intensidade do azul

int main()
{
    pinosInit();
    stdio_init_all();
    initializePio();

    // Loop Principal
    while (1)
    {
        ledRed(); // Função responsável por fazer o led piscar 5 vezes por segundo
    }

    // Configuração da interrupção com callback
    gpio_set_irq_enabled_with_callback(button_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
}
