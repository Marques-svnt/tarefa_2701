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
#define button_B 6

// Variáveis globais
static volatile uint a = 1;
static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)

// Variável global para armazenar a cor (Entre 0 e 255 para intensidade)
uint8_t led_r = 0;   // Intensidade do vermelho
uint8_t led_g = 0;   // Intensidade do verde
uint8_t led_b = 100; // Intensidade do azul

int main()
{
    // Inicializações
    pinosInit();
    stdio_init_all();
    initializePio();

    bool ultimo_estado_botao = true; // Último estado do botão (inicialmente solto)
    int index = 0;
    // Loop Principal
    while (1)
    {
        ledRed(); // Função responsável por fazer o led piscar 5 vezes por segundo

        bool estado_atual_botao_A = gpio_get(button_A);
        bool estado_atual_botao_B = gpio_get(button_B);

        // Condições associadas aos botões
        if (estado_atual_botao_A == false && ultimo_estado_botao == true)
        {
            if (index != 9)
            {
                index++;
                printf("A = %d\n", index);
                set_one_led(index, led_r, led_g, led_b);
            }
        }
        else if (estado_atual_botao_B == false && ultimo_estado_botao == true)
            if (index != 0)
            {
                index--;
                printf("A = %d\n", index);
                set_one_led(index, led_r, led_g, led_b);
            }
        ultimo_estado_botao = estado_atual_botao_A;
        ultimo_estado_botao = estado_atual_botao_B;
    }

    // Configuração da interrupção com callback
    gpio_set_irq_enabled_with_callback(button_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(button_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
}
