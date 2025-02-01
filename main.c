#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pio.h"
#include "pinos.h"
#include "interrupt.h"

int main()
{
    // Inicializações
    pinosInit();
    stdio_init_all();
    initializePio();

    int index = 0; // Variável de controle de qual número será exibido na matriz 5x5
    set_one_led(0, 0, 0, 100); // Número inicial que será já mostrado assim que iniciar o código

    // Configuração da interrupção com callback
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    // Loop Principal
    while (1)
    {
        ledRed(); // Função responsável por fazer o led piscar 5 vezes por segundo
    }
}