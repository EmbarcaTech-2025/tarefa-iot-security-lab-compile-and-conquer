#include <string.h>
#include <time.h>               // Para funções de string como strlen()
#include "pico/stdlib.h"            // Biblioteca padrão do Pico (GPIO, tempo, etc.)
#include "pico/cyw43_arch.h"        // Driver WiFi para Pico W
#include "include/wifi_conn.h"      // Funções personalizadas de conexão WiFi
#include "include/mqtt_comm.h"      // Funções personalizadas para MQTT
#include "include/xor_cipher.h"     // Funções de cifra XOR

int main() {
    stdio_init_all();
    connect_to_wifi("Xiaomi", "Testinho");
    mqtt_setup("bitdog2", "192.168.121.228", "aluno", "aluno123");

char buffer[128];
char criptografada[128];
float valor = 26.5;

mqtt_comm_subscribe("escola/sala1/temperatura", 0);


    while (true) {
        //uint32_t timestamp = time(NULL);

        // Monta JSON com valor e timestamp
        //sprintf(buffer, "{\"valor\":%.2f,\"ts\":%lu}", valor, timestamp);
        // Criptografa a mensagem
        //xor_encrypt((uint8_t*)buffer, (uint8_t*)criptografada, strlen(buffer), 42);

        // Publica a mensagem criptografada
        //mqtt_comm_publish("escola/sala1/temperatura", (uint8_t*)criptografada, strlen(buffer));

        //printf("Mensagem publicada: %s\n", buffer);

        // Aguarda 5 segundos
        sleep_ms(5000);
    }

    return 0;
}

/* 
 * Comandos de terminal para testar o MQTT:
 * 
 * Inicia o broker MQTT com logs detalhados:
 * mosquitto -c mosquitto.conf -v
 * 
 * Assina o tópico de temperatura (recebe mensagens):
 * mosquitto_sub -h localhost -p 1883 -t "escola/sala1/temperatura" -u "aluno" -P "senha123"
 * 
 * Publica mensagem de teste no tópico de temperatura:
 * mosquitto_pub -h localhost -p 1883 -t "escola/sala1/temperatura" -u "aluno" -P "senha123" -m "26.6"
 */
