# Projeto: Temporizadores no Raspberry Pi Pico W

Este repositório contém dois programas em C desenvolvidos para o Raspberry Pi Pico W utilizando o **Pico SDK**. As atividades implementam o uso de temporizadores para controle de LEDs, seguindo os requisitos da tarefa.

## 📌 Descrição das Atividades

### 1️⃣ Temporizador Periódico (Semáforo)
- Utiliza a função `add_repeating_timer_ms()` para alternar os LEDs do semáforo a cada **3 segundos**.
- LEDs controlados: **vermelho, amarelo e verde**.
- Mensagem é impressa a cada **1 segundo** na porta serial.

### 2️⃣ Temporizador de Um Disparo (One Shot)
- Utiliza a função `add_alarm_in_ms()` para ativar LEDs após o pressionamento de um botão.
- LEDs ativam simultaneamente e desligam em sequência com um intervalo de **3 segundos**.
- Impede novas ativações enquanto a sequência não for concluída.

## 📂 Estrutura do Projeto
```
Tarefa-2-Aula-Sincrona-29-01/
├── src/
│   ├── diagram_temp_periodico.json
│   ├── diagram_temp_oneshot.json
│   ├── temporizador_periodico.c  # Código do semáforo
│   ├── temporizador_oneshot.c    # Código do botão com temporizador
├── .gitignore
├── CMakeLists.txt                 # Configuração do CMake
├── pico_sdk_import.cmake          # Importação do Pico SDK
├── README.md                      # Este arquivo
├── wokwi.toml
```