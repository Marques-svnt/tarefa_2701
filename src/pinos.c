#include <stdio.h>
#include "pico/stdlib.h"
#include "pio.h"

// Definição do GPIO do LED RGB
const uint ledR_pin = 13; // Red => GPIO13
const uint ledB_pin = 12; // Blue => GPIO12
const uint ledG_pin = 11; // Green=> GPIO11
const uint button_A = 5;  // Botão A = 5
const uint button_B = 6;  // Botão B = 6

// Variável global para armazenar a cor (Entre 0 e 255 para intensidade)
uint8_t led_r = 0;   // Intensidade do vermelho
uint8_t led_g = 0;   // Intensidade do verde
uint8_t led_b = 100; // Intensidade do azul

// Variáveis globais
static volatile uint a = 1;
static volatile uint32_t last_time_A = 0; // Armazena o tempo do último evento (em microssegundos)
static volatile uint32_t last_time_B = 0;
static volatile int index = 0;

#define DELAY 1000 / 5 // Configurar tempo de delay para permitir que o led pisque continuamente 5 vezes por segundo (1000ms/5vezes = 200 vezes por ms)

void pinosInit()
{
    // Inicializa o pino do LED RGB e configura pro GPIO13
    gpio_init(ledR_pin);
    gpio_set_dir(ledR_pin, GPIO_OUT);

    // Configurar o pino do botão A e B e habilitar o pull-up interno
    gpio_init(button_A);
    gpio_set_dir(button_A, GPIO_IN);
    gpio_pull_up(button_A);

    gpio_init(button_B);
    gpio_set_dir(button_B, GPIO_IN);
    gpio_pull_up(button_B);
}

void ledRed()
{
    gpio_put(ledR_pin, 1); // Liga o LED RGB na cor vermelha
    sleep_ms(DELAY / 2);
    gpio_put(ledR_pin, 0); // Desliga o LED RGB na cor vermelha
    sleep_ms(DELAY / 2);
}

// Função de interrupção com debouncing
void gpio_irq_handler(uint gpio, uint32_t events)
{
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    if (gpio == button_A) {
        if (current_time - last_time_A > 200000) {  // 200 ms debounce para botão A
            last_time_A = current_time;
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