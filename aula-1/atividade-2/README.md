# Atividade 2 — Sistema de alarme

## Plataforma e link

- **Plataforma:** Tinkercad
- **Link:** https://www.tinkercad.com/things/9BFUMiQdy0P/editel?returnTo=%2Fclassrooms%2F7OjAnbHLZRm%2Factivities%2F4iyOzX8sN5v%3Fview%3Dwork%26type%3Dall

 ## Imagem do protótipo
<img width="929" height="772" alt="Grand Snaget-Robo (2)" src="https://github.com/user-attachments/assets/e9f4a18e-8def-4736-af73-c90bf7b80141" />

- Arduino Uno
- 2 botão
- led vermelho
- 220 resistor
- 1 piezzo
- 1 placa de ensaio pequena

## Como funciona
Aperte o Botão 1 → LED começa a piscar (ATIVADO).
Aperte o Botão 2 → LED fixo e buzzer toca (ALERTA).
Aperte o Botão 1 → tudo desliga (DESATIVADO).
Aperte o Botão 2 estando em DESATIVADO → nada acontece (correto).

# Testes realizados
## Saída esperada do sistema
=== Sistema de Alarme iniciado ===
Estado atual: DESATIVADO
Transicao: DESATIVADO -> ATIVADO
!!! Deteccao de intruso !!!
Transicao: ATIVADO -> ALERTA
Transicao: ALERTA -> DESATIVADO
