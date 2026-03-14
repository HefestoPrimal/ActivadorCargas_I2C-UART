# Firmware

El programa se utiliza para pruebas de comunicación serial idealmente pensadas para un módulo Bluetooth en los pines correspondientes, o en caso de no tener uno también cuenta con una sección en dónde se prueban todas las salidas del 74HC595 con LEDS (Tal como se ve en la simulación)

## Instalación

Se debe colocar el siguiente link en el apartado de texto "Preferencias" del IDE de Arduino

***https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json***

Posteriormente buscar la placa de ATtiny85 para instalarla, seleccionarla como el destino de la placa (ATtiny25/ATtiny45/ATtiny85) y finalmente seleccionar el COM en dónde se encuentra el programador.

## Uso

Dependiendo de si se tiene el módulo Bluetooth conectado o no se debe des comentar o comentar las líneas correspondientes dentro del **void loop()** en caso de tenerlo, el microcontrolador estará constantemente esperando un carácter para realizar una acción y en caso de no tenerlo las líneas des comentadas hará una secuencia de luces. (Vídeo de muestra en la carpeta *docs/videos/*)