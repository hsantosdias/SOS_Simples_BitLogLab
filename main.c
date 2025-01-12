//Hugo S. Dias - 12/01/2025
// Programa para transmitir o sinal SOS em código Morse
// O LED pisca de acordo com o código Morse para "SOS" - (... --- ...)

#include <stdio.h>
#include "pico/stdlib.h"

#define LED_PIN 13 // Define o pino GPIO onde o LED está conectado
#define PONTO 200 // Duração de um ponto em ms
#define TRACO 800 // Duração de um traço em ms
#define INTERVALO 250 // Intervalo entre letras em ms
#define INTER_PULSO 125 // Intervalo entre pulsos (Espaço) em ms
#define PAUSA 3000 // Pausa entre ciclos em ms

// Função para acender o LED por um determinado tempo
// Primeira função para acender o LED por um determinado tempo
void blinkLED(int duration) {  // Recebe a duração do pulso em ms
    gpio_put(LED_PIN, 1);      // Acende o LED
    sleep_ms(duration);        // Aguarda o tempo especificado
    gpio_put(LED_PIN, 0);      // Apaga o LED
    sleep_ms(INTER_PULSO);     // Intervalo entre pulsos (GAP)
}

// Função para transmitir o sinal SOS em código Morse
// Segunda função para transmitir o sinal SOS em código Morse
void transmitirSOS() {

    // Transmite "SOS" - (... --- ...)

    // Transmite o "S"
    for (int i = 0; i < 3; i++) {
        blinkLED(PONTO);  // Ponto
    }
    sleep_ms(INTERVALO); // Intervalo entre letras
    
    // Transmite o "O"
    for (int i = 0; i < 3; i++) {
        blinkLED(TRACO);  // Traço
    }
    sleep_ms(INTERVALO); // Intervalo entre letras

    // Transmite o "S"
    for (int i = 0; i < 3; i++) {
        blinkLED(PONTO);  // Ponto 
    }

    sleep_ms(PAUSA);  // Pausa antes de reiniciar o ciclo
}

int main() {
    stdio_init_all();            // Inicializa a saída padrão (opcional)
    gpio_init(LED_PIN);          // Configura o pino do LED
    gpio_set_dir(LED_PIN, GPIO_OUT); // Define o pino como saída

    while (true) {
        transmitirSOS();           // Chama a função para transmitir o sinal SOS
    }

    return 0;
}
