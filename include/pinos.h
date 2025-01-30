#ifndef PINOS_H
#define PINOS_H

//Declaração das funções do led vermelho e dos pinos
void ledRed();
void pinosInit();
void gpio_irq_handler(uint gpio, uint32_t events);

#endif