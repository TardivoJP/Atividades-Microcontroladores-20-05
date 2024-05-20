
# Relatório de Experiências com Componentes Eletrônicos e Arduino

## Exercício 2

**1. Introdução**

Este relatório descreve a análise de um código Arduino, explicando o comportamento de cada linha do código e o resultado esperado em dois cenários distintos: um com um fio conectado entre a porta GND e o pino 7, e outro com um fio conectado entre a porta 5V e o pino 7. 

**2. Objetivos**

O objetivo deste relatório é entender e explicar como diferentes conexões no pino de entrada (pino 7) afetam a leitura e o comportamento do Arduino, bem como o output no monitor serial.

**3. Metodologia**

A metodologia adotada consiste na análise linha por linha do código fornecido e a realização de dois experimentos, cada um com uma configuração diferente das conexões no pino 7, para observar e explicar o comportamento e o resultado gerado.

**4. Experimentos Realizados**

A análise do código é realizada da seguinte maneira:

```arduino
byte pin7 = 0;
```
Declara-se uma variável do tipo `byte` chamada `pin7` e a inicializa com o valor 0. Esta variável armazenará o estado do pino 7.

```arduino
void setup(){
	pinMode(13, OUTPUT);
	pinMode(7, INPUT);
	Serial.begin(9600);
}
```
Na função `setup()`, que é executada uma vez quando o Arduino é energizado:
- `pinMode(13, OUTPUT);`: Configura o pino 13 como saída.
- `pinMode(7, INPUT);`: Configura o pino 7 como entrada.
- `Serial.begin(9600);`: Inicializa a comunicação serial com a taxa de transmissão de 9600 bps.

```arduino
void loop(){
	digitalWrite(13, HIGH);
	delay(1000);

	digitalWrite(13, LOW);
	delay(1000);

	pin7 = digitalRead(7);
	Serial.println(pin7);
}
```
Na função `loop()`, que executa continuamente:
- `digitalWrite(13, HIGH);`: Define o pino 13 em nível alto (ligado).
- `delay(1000);`: Aguarda 1000 milissegundos (1 segundo).
- `digitalWrite(13, LOW);`: Define o pino 13 em nível baixo (desligado).
- `delay(1000);`: Aguarda 1000 milissegundos (1 segundo).
- `pin7 = digitalRead(7);`: Lê o estado do pino 7 (entrada) e armazena o valor na variável `pin7`.
- `Serial.println(pin7);`: Envia o valor de `pin7` pela porta serial e imprime-o no monitor serial.

**5. Resultados e Discussão**

**Cenário 1: Fio conectado entre GND e pino 7**

Neste cenário, um fio conecta a porta GND (terra) ao pino 7. Ao conectar o pino 7 ao GND, o estado do pino 7 será constantemente lido como LOW (0). Isso ocorre porque o pino está diretamente conectado ao terra, fornecendo um caminho de baixa resistência para a corrente.

- O pino 13 continuará alternando entre ligado (HIGH) e desligado (LOW) a cada segundo.
- O valor lido do pino 7 será sempre 0.
- No monitor serial, o valor 0 será impresso a cada dois segundos.

**Cenário 2: Fio conectado entre 5V e pino 7**

Neste cenário, um fio conecta a porta 5V ao pino 7. Ao conectar o pino 7 ao 5V, o estado do pino 7 será constantemente lido como HIGH (1). Isso ocorre porque o pino está diretamente conectado à fonte de 5V, fornecendo um caminho de baixa resistência para a corrente.

- O pino 13 continuará alternando entre ligado (HIGH) e desligado (LOW) a cada segundo.
- O valor lido do pino 7 será sempre 1.
- No monitor serial, o valor 1 será impresso a cada dois segundos.

**6. Conclusão**

O experimento demonstra que a conexão do pino 7 ao GND ou ao 5V resulta em leituras estáveis e previsíveis. Conectar o pino 7 ao GND faz com que ele seja lido como 0, enquanto conectá-lo ao 5V faz com que seja lido como 1. A função `digitalRead()` reflete corretamente o estado lógico do pino 7 conforme as conexões estabelecidas.

**7. Sugestões para Trabalhos Futuros**

Para futuros experimentos, sugere-se integrar diferentes tipos de sensores ao pino 7 para investigar como diferentes dispositivos de entrada afetam a leitura e o comportamento do programa.
