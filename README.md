# Activador de cargas por I2C/UART

A través de comunicación de 2 pines físicos I2C o UART, se puede activar y desactivar cargas eléctricas en un dispositivo. Este activador puede ser utilizado para controlar salidas digitales por medio del microcontrolador, cuenta con un expansor de salidas que van directamente conectados a las entradas de un driver de potencia para conectar por ejemplo relevadores o motores directamente.

<img src="hardware\schematics\ActivadorCargasI2C-UART_Esquematico.jpeg" alt="Circuito Esquematico" width="100%" height="auto">

<img src="docs\video\SimulacionATtiny85_74HC595.gif" alt="Simulacion" width="100%" height="auto">

## Características

- Programa de ejemplo para utilizarlo directamente con un módulo bluetooth
- Control de 8 salidas digitales activas a bajos
- Manejo de salidas de 3.3V hasta 12V dependiendo del voltaje de potencia suministrado
- Diseño de PCB personalizado para un uso más sencillo
- Respuestas a través del módulo bluetooth para conocer el estado de las salidas

## Estructura del repositorio

**docs**: En esta carpeta se encuentran las imágenes de la vista en 3D de la PCB diseñada especialmente para el proyecto, la vista de PCB terminada en el programa. Y un vídeo de la simulación del programa sin el módulo bluetooth.

**firmware**: En esta carpeta se encuentra un código fuente de Arduino listo para copiar y pegar en el IDE de arduino y probar el circuito, además de un **"README"** con instrucciones para instalar las dependencias necesarias y utilizar el programa de 2 formas distintas.

**hardware**: En esta carpeta se encuentran los archivos gerber, BOM y POS para la producción de la PCB, el esquemático del proyecto para un mejor entendimiento.

## ¿Cómo empezar?

Para programar el ATtiny85 se recomienda cargar un bootloader diferente al que tiene por defecto, en específico uno de 8MHz interno del microcontrolador para que pueda funcionar con la comunicación bluetooth. Una vez cargado el bootloader  se procede a cargar el programa y una vez cargado se procede a colocar en el circuito deseado para su uso.

## Links

[Canal de YouTube](https://www.youtube.com/@mexatronica99)

[Linkedin](https://www.linkedin.com/in/angel-diaz-mexatronica/)