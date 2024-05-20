
# Relat�rio de Experi�ncias com Componentes Eletr�nicos e Arduino

## Exerc�cio 2

**1. Introdu��o**

Este relat�rio descreve a an�lise de um c�digo Arduino, explicando o comportamento de cada linha do c�digo e o resultado esperado em dois cen�rios distintos: um com um fio conectado entre a porta GND e o pino 7, e outro com um fio conectado entre a porta 5V e o pino 7. 

**2. Objetivos**

O objetivo deste relat�rio � entender e explicar como diferentes conex�es no pino de entrada (pino 7) afetam a leitura e o comportamento do Arduino, bem como o output no monitor serial.

**3. Metodologia**

A metodologia adotada consiste na an�lise linha por linha do c�digo fornecido e a realiza��o de dois experimentos, cada um com uma configura��o diferente das conex�es no pino 7, para observar e explicar o comportamento e o resultado gerado.

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

**Cen�rio 1: Fio conectado entre GND e pino 7**

Neste cen�rio, um fio conecta a porta GND (terra) ao pino 7. Ao conectar o pino 7 ao GND, o estado do pino 7 ser� constantemente lido como LOW (0). Isso ocorre porque o pino est� diretamente conectado ao terra, fornecendo um caminho de baixa resist�ncia para a corrente.

- O pino 13 continuar� alternando entre ligado (HIGH) e desligado (LOW) a cada segundo.
- O valor lido do pino 7 ser� sempre 0.
- No monitor serial, o valor 0 ser� impresso a cada dois segundos.

**Cen�rio 2: Fio conectado entre 5V e pino 7**

Neste cen�rio, um fio conecta a porta 5V ao pino 7. Ao conectar o pino 7 ao 5V, o estado do pino 7 ser� constantemente lido como HIGH (1). Isso ocorre porque o pino est� diretamente conectado � fonte de 5V, fornecendo um caminho de baixa resist�ncia para a corrente.

- O pino 13 continuar� alternando entre ligado (HIGH) e desligado (LOW) a cada segundo.
- O valor lido do pino 7 ser� sempre 1.
- No monitor serial, o valor 1 ser� impresso a cada dois segundos.

**6. Conclus�o**

O experimento demonstra que a conex�o do pino 7 ao GND ou ao 5V resulta em leituras est�veis e previs�veis. Conectar o pino 7 ao GND faz com que ele seja lido como 0, enquanto conect�-lo ao 5V faz com que seja lido como 1. A fun��o `digitalRead()` reflete corretamente o estado l�gico do pino 7 conforme as conex�es estabelecidas.

**7. Sugest�es para Trabalhos Futuros**

Para futuros experimentos, sugere-se integrar diferentes tipos de sensores ao pino 7 para investigar como diferentes dispositivos de entrada afetam a leitura e o comportamento do programa.
