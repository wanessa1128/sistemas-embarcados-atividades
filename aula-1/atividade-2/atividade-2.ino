// ===== Sistema de Alarme =====
const int BOTAO_ATIVAR = 2;
const int BOTAO_SENSOR = 3;
const int LED          = 8;
const int BUZZER       = 9;

const int DESATIVADO = 0;
const int ATIVADO    = 1;
const int ALERTA     = 2;

int estado = DESATIVADO;

bool ultimoAtivar = HIGH;
bool ultimoSensor = HIGH;
bool ledLigado = false;
unsigned long ultimoPisca = 0;

const char* nomeEstado(int e) {
  if (e == DESATIVADO) return "DESATIVADO";
  if (e == ATIVADO)    return "ATIVADO";
  return "ALERTA";
}

void mudarEstado(int novo) {
  Serial.print("Transicao: ");
  Serial.print(nomeEstado(estado));
  Serial.print(" -> ");
  Serial.println(nomeEstado(novo));
  estado = novo;

  if (estado == DESATIVADO) {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
  } else if (estado == ATIVADO) {
    noTone(BUZZER);
    ledLigado = false;
    digitalWrite(LED, LOW);
    ultimoPisca = millis();
  } else {
    digitalWrite(LED, HIGH);
    tone(BUZZER, 1000);
  }
}

void setup() {
  pinMode(BOTAO_ATIVAR, INPUT_PULLUP);
  pinMode(BOTAO_SENSOR, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
  Serial.println("=== Sistema de Alarme iniciado ===");
  Serial.println("Estado atual: DESATIVADO");
}

void loop() {
  bool atualAtivar = digitalRead(BOTAO_ATIVAR);
  bool atualSensor = digitalRead(BOTAO_SENSOR);

  bool apertouAtivar = (ultimoAtivar == HIGH && atualAtivar == LOW);
  bool apertouSensor = (ultimoSensor == HIGH && atualSensor == LOW);

  ultimoAtivar = atualAtivar;
  ultimoSensor = atualSensor;

  if (estado == DESATIVADO) {
    if (apertouAtivar) {
      mudarEstado(ATIVADO);
    }
  } else if (estado == ATIVADO) {
    if (apertouAtivar) {
      mudarEstado(DESATIVADO);
    } else if (apertouSensor) {
      Serial.println("!!! Deteccao de intruso !!!");
      mudarEstado(ALERTA);
    } else if (millis() - ultimoPisca >= 500) {
      ultimoPisca = millis();
      ledLigado = !ledLigado;
      digitalWrite(LED, ledLigado);
    }
  } else if (estado == ALERTA) {
    if (apertouAtivar) {
      mudarEstado(DESATIVADO);
    }
  }
  
  delay(20);
}
