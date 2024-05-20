
# Relatório de Experiências com Componentes Eletrônicos e Arduino

## Exercício 3

**1. Introdução**

Este relatório descreve a análise de um código para ESP32, explicando o comportamento de cada linha e o resultado esperado ao executar o programa com um ESP32. O circuito descrito possui um fio conectado ao pino T0 sem conexão ou energia e um LED conectado ao pino 23.

**2. Objetivos**

O objetivo deste relatório é entender e explicar o funcionamento de um programa que utiliza a funcionalidade de leitura de toque (touch sensor) do ESP32 e o controle de um LED baseado na leitura do sensor.

**3. Metodologia**

A metodologia adotada consiste na análise linha por linha do código fornecido e a descrição do comportamento do circuito, incluindo a explicação das portas utilizadas e a razão pela qual o LED acende.

**4. Experimentos Realizados**

A análise do código é realizada da seguinte maneira:

```arduino
int LED_BUILTIN = 23;
```
Declara-se uma variável do tipo `int` chamada `LED_BUILTIN` e a inicializa com o valor 23. Este valor representa o pino 23 do ESP32, ao qual o LED está conectado.

```arduino
void setup(){
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(T0, INPUT);
}
```
Na função `setup()`, que é executada uma vez quando o ESP32 é energizado:
- `pinMode(LED_BUILTIN, OUTPUT);`: Configura o pino 23 como saída. 
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
Na função `loop()`, que executa continuamente:
- `if(touchRead(T0) < 20)`: Lê o valor do sensor de toque no pino T0. Se o valor lido for menor que 20:
  - `digitalWrite(LED_BUILTIN, HIGH);`: Define o pino 23 em nível alto (ligado), acendendo o LED.
- `else`: Caso contrário:
  - `digitalWrite(LED_BUILTIN, LOW);`: Define o pino 23 em nível baixo (desligado), apagando o LED.
- `delay(100);`: Aguarda 100 milissegundos antes de repetir o loop.

**5. Resultados e Discussão**

Ao executar o código no ESP32, o seguinte comportamento é observado:

1. O LED conectado ao pino 23 será controlado pelo valor lido do sensor de toque no pino T0.
2. A leitura do sensor de toque em T0 será baixa se não estiver encostando na outra ponta do fio e alta se o pino T0 detectar um toque ou uma variação significativa na capacitância, ligando ou apagando a LED dependendo do estado.

**Por que o LED acende?**

O LED acende quando a função `touchRead(T0)` retorna um valor menor que 20. Isso acontece porque a função `touchRead` mede a mudança na capacitância no pino T0. Quando o sensor de toque detecta uma capacitância baixa (indicativa de um toque ou proximidade), o valor lido será menor, acionando a condição do `if` e acendendo o LED.

**6. Conclusão**

O código e o circuito analisados demonstram o uso do sensor de toque do ESP32 para controlar um LED. O LED acende quando a capacitância medida no pino T0 é baixa, indicando um toque ou proximidade. Sem conexão ou energia no fio do pino T0, as leituras do sensor de toque podem ser altas, mantendo o LED apagado na maior parte do tempo.

**7. Sugestões para Trabalhos Futuros**

Para futuros experimentos, sugere-se explorar diferentes valores de limiar para o sensor de toque para ajustar a sensibilidade e integrar mais sensores de toque em diferentes pinos do ESP32 para controlar múltiplos LEDs ou outros atuadores.
