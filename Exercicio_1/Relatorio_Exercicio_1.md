
# Relat�rio de Experi�ncias com Componentes Eletr�nicos e Arduino

## Exerc�cio 1

**1. Introdu��o**

  

Este relat�rio descreve a an�lise de um c�digo Arduino, explicando o comportamento de cada linha do c�digo e o resultado esperado ao executar o programa com o Arduino apenas energizado e sem quaisquer outras conex�es.

  

**2. Objetivos**

  

O objetivo deste relat�rio � entender e explicar o funcionamento de um programa b�sico de Arduino que envolve a configura��o de pinos, leitura de entradas e sa�das digitais, e comunica��o serial.

  

**3. Metodologia**

  

A metodologia adotada consiste na an�lise linha por linha do c�digo fornecido, identificando as fun��es e instru��es utilizadas. Tamb�m ser� descrito o comportamento esperado do Arduino quando o c�digo � carregado e executado.

  

**4. Experimentos Realizados**

  

A an�lise do c�digo � realizada da seguinte maneira:

  

```arduino
byte pin7 = 0;
```

Declara-se uma vari�vel do tipo `byte` chamada `pin7` e a inicializa com o valor 0. Esta vari�vel armazenar� o estado do pino 7.

  

```arduino
void setup(){
	pinMode(13, OUTPUT);
	pinMode(7, INPUT);
	Serial.begin(9600);
}
```

Na fun��o `setup()`, que � executada uma vez quando o Arduino � energizado:

- `pinMode(13, OUTPUT);`: Configura o pino 13 como sa�da.

- `pinMode(7, INPUT);`: Configura o pino 7 como entrada.

- `Serial.begin(9600);`: Inicializa a comunica��o serial com a taxa de transmiss�o de 9600 bps.

  

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

Na fun��o `loop()`, que executa continuamente:

- `digitalWrite(13, HIGH);`: Define o pino 13 em n�vel alto (ligado).

- `delay(1000);`: Aguarda 1000 milissegundos (1 segundo).

- `digitalWrite(13, LOW);`: Define o pino 13 em n�vel baixo (desligado).

- `delay(1000);`: Aguarda 1000 milissegundos (1 segundo).

- `pin7 = digitalRead(7);`: L� o estado do pino 7 (entrada) e armazena o valor na vari�vel `pin7`.

- `Serial.println(pin7);`: Envia o valor de `pin7` pela porta serial e imprime-o no monitor serial.

  

**5. Resultados e Discuss�o**

  

Quando o Arduino � energizado, o seguinte comportamento � observado:

1. O pino 13 ficar� alternando entre os estados energizado (HIGH) e desligado (LOW) a cada segundo.

2. Como n�o h� conex�es no pino 7, o valor lido e imprimido no terminal ser� 0.

3. O valor lido do pino 7 � enviado ao monitor serial a cada dois segundos (tempo total de um ciclo de ligar/desligar o pino).

  

**6. Conclus�o**

  

O c�digo analisado demonstra um exemplo b�sico de configura��o e utiliza��o de pinos digitais como entrada e sa�da no Arduino, al�m de usar a comunica��o serial para monitoramento. O pino 13 troca de estado a cada segundo, e o valor lido do pino 7 � impresso no monitor serial, como nada est� conectado a ele, sempre ser� 0.

  

**7. Sugest�es para Trabalhos Futuros**

  

Sugere-se explorar diferentes entradas para o pino 7, para verificar como ele se comparta. Este estudo pode ser estendido para incluir diferentes sensores e atuadores, ampliando o conhecimento sobre o uso de entradas e sa�das digitais no Arduino.
