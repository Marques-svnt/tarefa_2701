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

int main()
{
    // Inicializações
    pinosInit();
    stdio_init_all();
    initializePio();

    bool ultimo_estado_botao = true; // Último estado do botão (inicialmente solto)
    int index = 0;
    set_one_led(0, 0, 0, 100); // Número inicial que será já mostrado assim que iniciar o código
    
    // Configuração da interrupção com callback
    gpio_set_irq_enabled_with_callback(button_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(button_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    // Loop Principal
    while (1)
    {
        ledRed(); // Função responsável por fazer o led piscar 5 vezes por segundo
    }
}
