#include <stdio.h>
#include "pico/stdlib.h"
#include "pio.h"

#define DELAY 1000 / 5 // Configurar tempo de delay para permitir que o led pisque continuamente 5 vezes por segundo (1000ms/5vezes = 200 vezes por ms)

void pinosInit()
{
    // Inicializa o pino do LED RGB e configura pro GPIO13
    gpio_init(PIN_LED_R);
    gpio_set_dir(PIN_LED_R, GPIO_OUT);

    // Configurar o pino do botão A e B e habilitar o pull-up interno
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);

    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);
}

void ledRed()
{
    gpio_put(PIN_LED_R, 1); // Liga o LED RGB na cor vermelha
    sleep_ms(DELAY / 2);
    gpio_put(PIN_LED_R, 0); // Desliga o LED RGB na cor vermelha
    sleep_ms(DELAY / 2);
}
