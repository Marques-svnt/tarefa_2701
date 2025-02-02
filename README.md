# Projeto: Controle de LEDs e Matriz de LEDs com Interrupções

## Descrição

Este projeto utiliza a placa RP2040 (BitDogLab) para demonstrar o controle de LEDs e uma matriz 5x5 de LEDs WS2812, empregando interrupções para interação com botões físicos. Ele explora técnicas de debouncing por software e manipulação de LEDs endereçáveis.

---

## Funcionalidades

- **Piscar LED RGB:**
  - O LED vermelho pisca continuamente 5 vezes por segundo.
- **Interação com Botões:**
  - **Botão A:** Incrementa o número exibido na matriz de LEDs.
  - **Botão B:** Decrementa o número exibido na matriz de LEDs.
- **Exibição de Números na Matriz:**
  - A matriz exibe números de 0 a 9 usando LEDs configurados para padrões fixos.

---

## Requisitos

- Placa RP2040 (BitDogLab)
- Matriz 5x5 de LEDs WS2812 conectada ao GPIO 7
- LED RGB conectado aos GPIOs 11, 12 e 13
- Botão A no GPIO 5
- Botão B no GPIO 6

---

## Configuração

### Mapeamento de Botões

| Botão  | Função                                   |
|--------|----------------------------------------------|
| **A**  | Incrementa o número exibido na matriz       |
| **B**  | Decrementa o número exibido na matriz       |

---

## Compilação e Execução

1. Certifique-se de que o SDK do Raspberry Pi Pico está configurado no seu ambiente.
2. Compile o programa utilizando a extensão **Raspberry Pi Pico Project** no VS Code:
   - Abra o projeto no VS Code.
   - Navegue até a extensão do **Raspberry Pi Pico Project** e clique em **Compile Project**.
3. Coloque a placa em modo boot cell e copie o arquivo `main.uf2`, que está na pasta build, para o microcontrolador conectado via USB.

---

## Emulação com Wokwi

Para testar o programa sem hardware físico, você pode utilizar o **Wokwi** para emulação no VS Code:

1. Instale a extensão **Wokwi for VS Code**.
2. Inicie a emulação:
   - Clique no arquivo `diagram.json` e inicie a emulação.
3. Teste o funcionamento do programa diretamente no ambiente emulado.

---

## Demonstração no YouTube

Confira a demonstração completa deste projeto no YouTube: [Demonstração do Projeto](https://www.youtube.com)

---

## Colaboradores

- [Gabriel Marques](https://github.com/Marques-svnt)

---

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).

