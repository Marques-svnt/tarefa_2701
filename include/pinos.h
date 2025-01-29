#ifndef LEDRED_H
#define LEDRED_H

//Declaração das funções do led vermelho
void ledRed();
void pinosInit();
void gpio_irq_handler(uint gpio, uint32_t events);

#endif