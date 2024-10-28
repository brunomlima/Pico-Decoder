#include <Arduino.h>

// Definição dos pinos
#define CLK_PIN 10  // Pino para CLK do encoder (Amarelo)
#define DT_PIN 11   // Pino para DT do encoder (Laranja)
#define SW_PIN 12   // Pino para o botão do encoder (Marrom)

// Variáveis de estado
int clkState, dtState;  // Estados atuais dos pinos
int clkLastState = HIGH;  // Estado anterior do CLK
bool processado = false;  // Para evitar comandos duplicados
unsigned long lastDebounceTime = 0;  // Tempo do último evento
const unsigned long debounceDelay = 5;  // Delay de debounce em ms

void setup() {
    Serial.begin(115200);  // Inicializa a Serial para debug
    pinMode(CLK_PIN, INPUT);
    pinMode(DT_PIN, INPUT);
    pinMode(SW_PIN, INPUT_PULLUP);  // Ativa o pull-up interno no botão
    delay(5000);
    Serial.println("== Teste de Encoder Iniciado ==");
}

void loop() {
    // Ler os estados atuais dos pinos CLK e DT
    int currentCLK = digitalRead(CLK_PIN);
    int currentDT = digitalRead(DT_PIN);

    // Debounce: só continua se o tempo mínimo passou
    if ((millis() - lastDebounceTime) > debounceDelay) {
        // Detecta mudança na borda de descida do CLK (evita pulsos duplicados)
        if (currentCLK == LOW && clkLastState == HIGH && !processado) {
            lastDebounceTime = millis();  // Atualiza o tempo do debounce
            processado = true;  // Marcar como processado para evitar duplicação

            // Verifica a direção do giro
            if (currentDT == LOW) {
                Serial.println("CCW (Giro Anti-Horário)");
            } else {
                Serial.println("CW (Giro Horário)");                
            }
        }

        // Se o CLK voltar a HIGH, libera para o próximo clique
        if (currentCLK == HIGH) {
            processado = false;
        }

        // Atualiza o estado anterior do CLK
        clkLastState = currentCLK;
    }

    // Verificar se o botão foi pressionado (com debounce)
    if (digitalRead(SW_PIN) == LOW) {
        delay(10);  // Debounce simples
        if (digitalRead(SW_PIN) == LOW) {  // Confirma se ainda está pressionado
            Serial.println("Botão Pressionado!");
            while (digitalRead(SW_PIN) == LOW);  // Espera o botão ser solto
        }
    }

    delay(1);  // Pequeno delay para estabilidade
}
