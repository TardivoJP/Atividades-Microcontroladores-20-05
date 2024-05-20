
# Relatório de Experiências com Componentes Eletrônicos e Arduino

## Exercício 1

**1. Introdução**

  

Este relatório descreve a análise de um código Arduino, explicando o comportamento de cada linha do código e o resultado esperado ao executar o programa com o Arduino apenas energizado e sem quaisquer outras conexões.

  

**2. Objetivos**

  

O objetivo deste relatório é entender e explicar o funcionamento de um programa básico de Arduino que envolve a configuração de pinos, leitura de entradas e saídas digitais, e comunicação serial.

  

**3. Metodologia**

  

A metodologia adotada consiste na análise linha por linha do código fornecido, identificando as funções e instruções utilizadas. Também será descrito o comportamento esperado do Arduino quando o código é carregado e executado.

  

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

  

Quando o Arduino é energizado, o seguinte comportamento é observado:

1. O pino 13 ficará alternando entre os estados energizado (HIGH) e desligado (LOW) a cada segundo.

2. Como não há conexões no pino 7, o valor lido e imprimido no terminal será 0.

3. O valor lido do pino 7 é enviado ao monitor serial a cada dois segundos (tempo total de um ciclo de ligar/desligar o pino).

  

**6. Conclusão**

  

O código analisado demonstra um exemplo básico de configuração e utilização de pinos digitais como entrada e saída no Arduino, além de usar a comunicação serial para monitoramento. O pino 13 troca de estado a cada segundo, e o valor lido do pino 7 é impresso no monitor serial, como nada está conectado a ele, sempre será 0.

  

**7. Sugestões para Trabalhos Futuros**

  

Sugere-se explorar diferentes entradas para o pino 7, para verificar como ele se comparta. Este estudo pode ser estendido para incluir diferentes sensores e atuadores, ampliando o conhecimento sobre o uso de entradas e saídas digitais no Arduino.
