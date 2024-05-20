
# Relat�rio de Experi�ncias com Componentes Eletr�nicos e Arduino

## Exerc�cio 3

**1. Introdu��o**

Este relat�rio descreve a an�lise de um c�digo para ESP32, explicando o comportamento de cada linha e o resultado esperado ao executar o programa com um ESP32. O circuito descrito possui um fio conectado ao pino T0 sem conex�o ou energia e um LED conectado ao pino 23.

**2. Objetivos**

O objetivo deste relat�rio � entender e explicar o funcionamento de um programa que utiliza a funcionalidade de leitura de toque (touch sensor) do ESP32 e o controle de um LED baseado na leitura do sensor.

**3. Metodologia**

A metodologia adotada consiste na an�lise linha por linha do c�digo fornecido e a descri��o do comportamento do circuito, incluindo a explica��o das portas utilizadas e a raz�o pela qual o LED acende.

**4. Experimentos Realizados**

A an�lise do c�digo � realizada da seguinte maneira:

```arduino
int LED_BUILTIN = 23;
```
Declara-se uma vari�vel do tipo `int` chamada `LED_BUILTIN` e a inicializa com o valor 23. Este valor representa o pino 23 do ESP32, ao qual o LED est� conectado.

```arduino
void setup(){
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(T0, INPUT);
}
```
Na fun��o `setup()`, que � executada uma vez quando o ESP32 � energizado:
- `pinMode(LED_BUILTIN, OUTPUT);`: Configura o pino 23 como sa�da. 
- `pinMode(T0, INPUT);`: Configura o pino T0 como entrada.

```arduino
void loop(){
	if(touchRead(T0) < 20){
		digitalWrite(LED_BUILTIN, HIGH);
	}else{
		digitalWrite(LED_BUILTIN, LOW);
	}
	delay (100);
}
```
Na fun��o `loop()`, que executa continuamente:
- `if(touchRead(T0) < 20)`: L� o valor do sensor de toque no pino T0. Se o valor lido for menor que 20:
  - `digitalWrite(LED_BUILTIN, HIGH);`: Define o pino 23 em n�vel alto (ligado), acendendo o LED.
- `else`: Caso contr�rio:
  - `digitalWrite(LED_BUILTIN, LOW);`: Define o pino 23 em n�vel baixo (desligado), apagando o LED.
- `delay(100);`: Aguarda 100 milissegundos antes de repetir o loop.

**5. Resultados e Discuss�o**

Ao executar o c�digo no ESP32, o seguinte comportamento � observado:

1. O LED conectado ao pino 23 ser� controlado pelo valor lido do sensor de toque no pino T0.
2. A leitura do sensor de toque em T0 ser� baixa se n�o estiver encostando na outra ponta do fio e alta se o pino T0 detectar um toque ou uma varia��o significativa na capacit�ncia, ligando ou apagando a LED dependendo do estado.

**Por que o LED acende?**

O LED acende quando a fun��o `touchRead(T0)` retorna um valor menor que 20. Isso acontece porque a fun��o `touchRead` mede a mudan�a na capacit�ncia no pino T0. Quando o sensor de toque detecta uma capacit�ncia baixa (indicativa de um toque ou proximidade), o valor lido ser� menor, acionando a condi��o do `if` e acendendo o LED.

**6. Conclus�o**

O c�digo e o circuito analisados demonstram o uso do sensor de toque do ESP32 para controlar um LED. O LED acende quando a capacit�ncia medida no pino T0 � baixa, indicando um toque ou proximidade. Sem conex�o ou energia no fio do pino T0, as leituras do sensor de toque podem ser altas, mantendo o LED apagado na maior parte do tempo.

**7. Sugest�es para Trabalhos Futuros**

Para futuros experimentos, sugere-se explorar diferentes valores de limiar para o sensor de toque para ajustar a sensibilidade e integrar mais sensores de toque em diferentes pinos do ESP32 para controlar m�ltiplos LEDs ou outros atuadores.
