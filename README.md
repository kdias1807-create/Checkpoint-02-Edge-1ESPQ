# Checkpoint-02-Edge-1ESPQ

Vinheria Agnello — Sistema Inteligente de Monitoramento Ambiental
Sistema embarcado desenvolvido para a *Vinheria Agnello* com o objetivo de monitorar as condições ambientais do depósito de armazenamento de vinhos.

O projeto realiza o monitoramento de:

- 💡 Luminosidade
- 🌡️ Temperatura
- 💧 Umidade

Além disso, o sistema utiliza:

- LEDs de sinalização
- Buzzer para alertas sonoros
- Display LCD 16x2 para exibição das informações em tempo real

---

# 👨‍💻 Integrantes

- Antonio do Nascimento Ferreira de Sousa
568834- Kaio Nincao Maia Dias
571353 - Kaue Fernando Jaques Lopes
570884 - Matheus Martins Santos
569475- Leonardo Gonçalves Cardoso da Fonseca

---

# 🎯 Objetivo do Projeto

Garantir que os vinhos permaneçam armazenados em condições ideais, evitando danos causados por:

- excesso de luz;
- temperatura inadequada;
- baixa ou alta umidade.

O sistema fornece monitoramento em tempo real e alertas automáticos sempre que alguma condição sair da faixa ideal.

---

# ⚙️ Funcionamento do Sistema

```txt
Sensores captam informações →
Arduino processa os dados →
Sistema avalia as condições →
LCD exibe os valores →
LEDs e buzzer alertam o usuário

O Arduino realiza leituras constantes dos sensores e calcula a média de 5 leituras para melhorar a precisão das informações apresentadas no display LCD.

Os valores são atualizados automaticamente a cada 5 segundos.

💡 Monitoramento da Luminosidade

O sensor LDR mede a intensidade de luz do ambiente.

Estado	LED	Buzzer	Mensagem no LCD
🌑 Ambiente escuro	🟢 Verde	Desligado	Ambiente Escuro
🌤️ Meia luz	🟡 Amarelo	Desligado	Ambiente a meia luz
☀️ Muito claro	🔴 Vermelho	Ligado	Ambiente muito claro
🌡️ Monitoramento da Temperatura

Faixa ideal:

10°C até 15°C
Situação	LED	Buzzer	LCD
✅ Temperatura OK	—	Desligado	Temperatura OK
🔥 Temperatura Alta	🟡 Amarelo	Ligado	Temp. Alta
🧊 Temperatura Baixa	🟡 Amarelo	Ligado	Temp. Baixa
💧 Monitoramento da Umidade

Faixa ideal:

50% até 70%
Situação	LED	Buzzer	LCD
✅ Umidade OK	—	Desligado	Umidade OK
📈 Umidade Alta	🔴 Vermelho	Ligado	Umidade Alta
📉 Umidade Baixa	🔴 Vermelho	Ligado	Umidade Baixa
🚨 Sistema de Alertas

O sistema utiliza LEDs e buzzer para indicar a situação do ambiente.

Cor do LED	Significado
🟢 Verde	Ambiente ideal
🟡 Amarelo	Situação de atenção
🔴 Vermelho	Situação crítica

O buzzer é ativado quando:

a luminosidade está muito alta;
a temperatura está fora da faixa ideal;
a umidade está fora da faixa ideal.
🧩 Componentes Utilizados
Componente	Quantidade	Função
Arduino Uno R3	1x	Controle principal do sistema
LDR	1x	Sensor de luminosidade
TMP36	1x	Sensor de temperatura
Potenciômetro	1x	Simulação da umidade
LCD 16x2	1x	Exibição das informações
LED Verde	1x	Ambiente ideal
LED Amarelo	1x	Estado de alerta
LED Vermelho	1x	Estado crítico
Buzzer	1x	Alerta sonoro
Resistores 220Ω	3x	Proteção dos LEDs
Resistor 10kΩ	1x	Divisor de tensão do LDR
Protoboard	1x	Montagem do circuito
Jumpers	Vários	Conexões do sistema
🔌 Ligações do Circuito
Componente	Pino Arduino
LED Verde	D4
LED Amarelo	D5
LED Vermelho	D6
Buzzer	D7
LCD RS	D8
LCD E	D9
LCD D4	D10
LCD D5	D11
LCD D6	D12
LCD D7	D13
LDR	A0
TMP36	A1
Potenciômetro (Umidade)	A2
🧠 Estrutura do Circuito
O LDR trabalha em conjunto com um resistor de 10kΩ formando um divisor de tensão.
Os LEDs possuem resistores de 220Ω para limitar a corrente elétrica.
O buzzer é acionado diretamente pelo Arduino em situações críticas.
O display LCD mostra as condições do ambiente em tempo real.
🖥️ Monitoramento Serial

O sistema também envia informações para o Serial Monitor da Arduino IDE.

Para visualizar:

Abra o Serial Monitor (Ctrl + Shift + M)
Configure:
9600 baud

As leituras dos sensores serão exibidas continuamente.

🧪 Simulação no Tinkercad
