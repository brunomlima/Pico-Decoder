# Pico-Decoder

Este projeto demonstra como utilizar o **Raspberry Pi Pico** em conjunto com um **encoder rotativo**, detectando o sentido da rotação (horário e anti-horário) e cliques no botão do encoder. 

## 🔧 **Componentes Utilizados:**
- Raspberry Pi Pico
- Protoboard
- Encoder rotativo (CLK, DT, SW)
- Jumpers e resistores (se necessário)

## 📝 **Descrição do Código**
O código em C++ foi desenvolvido na plataforma Arduino. Ele realiza a leitura do encoder e exibe as informações no **Serial Monitor**, detectando:
- **CW (Clockwise):** Sentido horário
- **CCW (Counter-Clockwise):** Sentido anti-horário
- **Botão pressionado:** Detecta cliques no encoder

## 🚀 **Como Usar**
1. Monte o circuito conforme o diagrama (CLK -> GPIO 10, DT -> GPIO 11, SW -> GPIO 12).
2. Carregue o código `.ino` no Raspberry Pi Pico usando a IDE Arduino.
3. Abra o monitor serial (115200 baud) para ver as informações da rotação e cliques.

## 📂 **Download do Código**
Você pode baixar o código diretamente [aqui](./Pico-Decoder.ino) ou cloná-lo para o seu computador:
```bash
git clone https://github.com/seu-usuario/Pico-Decoder.git
