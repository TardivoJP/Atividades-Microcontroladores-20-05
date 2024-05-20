
# Relatório de Experiências com Componentes Eletrônicos e Arduino

## Exercício 4

**1. Introdução**

Este relatório descreve a análise de um código para ESP32 que utiliza comunicação Bluetooth para controlar um LED. Através de um aplicativo Android chamado Serial Bluetooth Terminal, o usuário pode ligar ou desligar o LED enviando comandos via Bluetooth.

**2. Objetivos**

O objetivo deste relatório é entender e explicar o funcionamento de um programa que permite o controle de um LED através de comandos enviados por um dispositivo Android via Bluetooth.

**3. Metodologia**

A metodologia adotada consiste na análise linha por linha do código fornecido e na descrição do comportamento do circuito, incluindo a explicação de como o LED muda de estado com base nos comandos recebidos via Bluetooth.

**4. Experimentos Realizados**

A análise do código é realizada da seguinte maneira:

```arduino
#include <BluetoothSerial.h>
```
Inclui a biblioteca BluetoothSerial, que permite a comunicação Bluetooth serial.

```arduino
BluetoothSerial SerialBT;
```
Declara um objeto `SerialBT` da classe `BluetoothSerial` para gerenciar a comunicação Bluetooth.

```arduino
void setup()
{
	SerialBT.begin("ESP32 LED");
	pinMode(2, OUTPUT);
}
```
Na função `setup()`, que é executada uma vez quando o ESP32 é energizado:
- `SerialBT.begin("ESP32 LED");`: Inicializa o Bluetooth com o nome "ESP32 LED".
- `pinMode(2, OUTPUT);`: Configura o pino 2 como saída, ao qual o LED está conectado.

```arduino
void loop(){
	if(SerialBT.available()){
		char c = SerialBT.read();
		if(c == '1'){
			digitalWrite(2, HIGH);
			SerialBT.println("LED on");
		}
		if(c == '0'){
			digitalWrite(2, LOW);
			SerialBT.println("LED off");
		}
	}
	delay(20);
}
```
Na função `loop()`, que executa continuamente:
- `if(SerialBT.available())`: Verifica se há dados disponíveis para leitura via Bluetooth.
  - `char c = SerialBT.read();`: Lê o caractere enviado via Bluetooth e o armazena na variável `c`.
  - `if(c == '1')`: Se o caractere lido for '1':
    - `digitalWrite(2, HIGH);`: Define o pino 2 em nível alto (ligado), acendendo o LED.
    - `SerialBT.println("LED on");`: Envia a mensagem "LED on" de volta ao dispositivo Bluetooth.
  - `if(c == '0')`: Se o caractere lido for '0':
    - `digitalWrite(2, LOW);`: Define o pino 2 em nível baixo (desligado), apagando o LED.
    - `SerialBT.println("LED off");`: Envia a mensagem "LED off" de volta ao dispositivo Bluetooth.
- `delay(20);`: Aguarda 20 milissegundos antes de repetir o loop.

**5. Resultados e Discussão**

Ao executar o código no ESP32 e utilizar o aplicativo Serial Bluetooth Terminal no Android, o seguinte comportamento é observado:

1. O ESP32 se inicializa como um dispositivo Bluetooth com o nome "ESP32 LED".
2. O aplicativo no Android pode se conectar ao ESP32 via Bluetooth.
3. Quando o caractere '1' é enviado pelo aplicativo, o LED conectado ao pino 2 acende, e a mensagem "LED on" é enviada de volta ao aplicativo.
4. Quando o caractere '0' é enviado pelo aplicativo, o LED conectado ao pino 2 apaga, e a mensagem "LED off" é enviada de volta ao aplicativo.

**Por que o LED muda de estado?**

O LED muda de estado com base nos comandos recebidos via Bluetooth. Quando o ESP32 recebe o caractere '1', ele define o pino 2 como HIGH, acendendo o LED. Quando recebe o caractere '0', ele define o pino 2 como LOW, apagando o LED. O feedback enviado ao aplicativo confirma o estado do LED.

**6. Conclusão**

O código e o circuito analisados demonstram como utilizar a comunicação Bluetooth para controlar um LED com o ESP32. Através do envio de comandos simples ('1' para ligar e '0' para desligar), o usuário pode controlar o estado do LED remotamente usando um aplicativo Android.

**7. Sugestões para Trabalhos Futuros**

Para futuros experimentos, sugere-se explorar outras funcionalidades da biblioteca BluetoothSerial, como a leitura de múltiplos caracteres ou comandos complexos.
