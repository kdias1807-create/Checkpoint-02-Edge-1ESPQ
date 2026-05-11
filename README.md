# Checkpoint-02-Edge-1ESPQ

Sistema embarcado de monitoramento ambiental desenvolvido para a **Vinheria Agnello**.  
O projeto monitora luminosidade, temperatura e umidade do ambiente, exibindo as informações em um display LCD e acionando alertas visuais e sonoros quando alguma condição estiver fora do ideal.

---

## Integrantes

- Antonio do Nascimento Ferreira de Sousa
- Kaio Nincao Maia Dias
- Kaue Fernando Jaques Lopes
- Matheus Martins Santos
- Leonardo Gonçalves Cardoso da Fonseca

---

## Como funciona

```txt
Sensores captam os dados → Arduino processa as leituras → LCD exibe as informações → LEDs e buzzer indicam alertas
```

O sistema utiliza um **LDR** para medir a luminosidade, um **TMP36** para medir a temperatura e um **potenciômetro** para simular a umidade no Tinkercad.

O Arduino realiza a média de **5 leituras** dos sensores e atualiza as informações no display LCD a cada **5 segundos**.

> **Nota sobre a simulação:** Como o DHT11 pode apresentar limitações no Tinkercad, a umidade foi simulada com um potenciômetro e a temperatura foi medida com o TMP36.

---

## Estados de luminosidade

| Estado | LED | Buzzer | Mensagem no LCD |
|--------|-----|--------|-----------------|
| ✅ Ambiente escuro | 🟢 Verde | Desligado | `Ambiente Escuro` |
| ⚠️ Meia luz | 🟡 Amarelo | Desligado | `Ambiente a meia luz` |
| 🚨 Muito claro | 🔴 Vermelho | Ligado | `Ambiente muito CLARO` |

---

## Estados de temperatura

| Estado | LED | Buzzer | Faixa |
|--------|-----|--------|-------|
| ✅ Temperatura OK | — | Desligado | `10°C a 15°C` |
| ⚠️ Temperatura baixa | 🟡 Amarelo | Ligado | `< 10°C` |
| ⚠️ Temperatura alta | 🟡 Amarelo | Ligado | `> 15°C` |

---

## Estados de umidade

| Estado | LED | Buzzer | Faixa |
|--------|-----|--------|-------|
| ✅ Umidade OK | — | Desligado | `50% a 70%` |
| 🚨 Umidade baixa | 🔴 Vermelho | Ligado | `< 50%` |
| 🚨 Umidade alta | 🔴 Vermelho | Ligado | `> 70%` |

---

## Componentes

| Componente | Qtd. | Conexão | Observação |
|------------|------|---------|------------|
| Arduino Uno R3 | 1x | — | Microcontrolador principal |
| LDR | 1x | `A0` | Sensor de luminosidade |
| TMP36 | 1x | `A1` | Sensor de temperatura |
| Potenciômetro | 1x | `A2` | Simulação da umidade |
| LCD 16x2 | 1x | `D8 até D13` | Exibição dos dados |
| LED Verde | 1x | `D4` | Ambiente adequado |
| LED Amarelo | 1x | `D5` | Estado de alerta |
| LED Vermelho | 1x | `D6` | Estado crítico |
| Buzzer | 1x | `D7` | Alarme sonoro |
| Resistor 220Ω | 3x | — | Proteção dos LEDs |
| Resistor 10kΩ | 1x | — | Divisor de tensão com o LDR |
| Protoboard | 1x | — | Montagem dos componentes |
| Jumpers | vários | — | Conexões do circuito |

---

## Estrutura do circuito

- O **LDR** forma um divisor de tensão com o resistor de 10kΩ.
- O **TMP36** envia a leitura de temperatura para a entrada analógica `A1`.
- O **potenciômetro** simula a porcentagem de umidade pela entrada `A2`.
- Cada LED possui um resistor de 220Ω em série.
- O buzzer é acionado pelo pino digital `D7`.
- O LCD 16x2 mostra as mensagens e os valores lidos.

---

## Como monitorar via Serial

Com a simulação iniciada, abra o **Serial Monitor** e configure a taxa para:

```txt
9600 baud
```

Assim é possível acompanhar os valores lidos pelos sensores e verificar se os limites estão funcionando corretamente.

---

## Simulação no Tinkercad

Acesse o projeto completo pelo link abaixo:

[🔗 Abrir projeto no Tinkercad](https://www.tinkercad.com/things/3RmV3SrOXu5-projetocp2vinheriaagnello?sharecode=fdE0wT112oAWaOokitOm9k9-W4aiCL64Q3wAYbFgNv8)

Para testar:

1. Inicie a simulação.
2. Clique no LDR para alterar a luminosidade.
3. Ajuste o potenciômetro para simular a umidade.
4. Altere o TMP36 para testar a temperatura.
5. Observe os LEDs, o buzzer e as mensagens no LCD.

---

## Resultado esperado

O sistema deve:

- mostrar luminosidade, temperatura e umidade no LCD;
- acender o LED verde em condição adequada;
- acender o LED amarelo em situação de alerta;
- acender o LED vermelho em situação crítica;
- ativar o buzzer quando houver condição fora do ideal.

---

*Projeto desenvolvido como atividade acadêmica — Vinheria Agnello · Monitoramento Ambiental com Arduino*
