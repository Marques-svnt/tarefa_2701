#include <stdio.h>
#include "pico/stdlib.h"

// Definição do GPIO do LED RGB
const uint ledR_pin = 13; // Red => GPIO13
const uint ledB_pin = 12; // Blue => GPIO12
const uint ledG_pin = 11; // Green=> GPIO11
const uint button_A = 5; // Botão A = 5

// Variáveis globais
static volatile uint a = 1;
static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)

#define DELAY 1000/5 // Configurar tempo de delay para permitir que o led pisque continuamente 5 vezes por segundo (1000ms/5vezes = 200 vezes por ms)

void pinosInit(){
    // Inicializa o pino do LED RGB e configura pro GPIO13
    gpio_init(ledR_pin);
    gpio_set_dir(ledR_pin, GPIO_OUT);

    // Configurar o pino do botão A e habilitar o pull-up interno
    gpio_init(button_A);
    gpio_set_dir(button_A, GPIO_IN); 
    gpio_pull_up(button_A);
}

void ledRed() {
    gpio_put(ledR_pin, 1);  // Liga o LED RGB na cor vermelha
    sleep_ms(DELAY);
    gpio_put(ledR_pin, 0);  // Desliga o LED RGB na cor vermelha
    sleep_ms(DELAY);
}

// Função de interrupção com debouncing
void gpio_irq_handler(uint gpio, uint32_t events)
{
    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    printf("A = %d\n", a);
    // Verifica se passou tempo suficiente desde o último evento
    if (current_time - last_time > 200000) // 200 ms de debouncing
    {
        last_time = current_time; // Atualiza o tempo do último evento
        printf("Mudanca de Estado do Led R = %d\n", a);
        gpio_put(ledR_pin, !gpio_get(ledR_pin)); // Alterna o estado
        a++;                                     // incrementa a variavel de verificação
    }
}