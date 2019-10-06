**66.48 SEMINARIO DE SISTEMAS EMBEBIDOS - FIUBA**
- Darío Capucchio 85119
- Cristian García 89040
# TP2

**Objetivo**
- **Uso del IDE** (edición, compilación y depuración de programas) 
- **Uso de GPIO & Diagrama de Estado** (manejo de Salidas y de Entradas Digitales en Aplicaciones) 
- **Documentación**

# Contenidos
- [1 IDE](#1-Uso-del-IDE-(Integrated-Development-Environment)-MCUXpresso-(p/Linux)-o-LPCXpresso-(p/Windows))
- [2 IDE](#2-Uso-del-IDE-(Integrated-Development-Environment)-LPCXpresso-&-plug-in-Yakindu-SCT)
- [3 tickHook](#3-panel-de-control-de-un-generador-de-señales)
- [4 Portabilidad](#4-puerta-corrediza)
- [5 portón de cochera](#5-portón-de-cochera)
- [6 escalera mecánica ](#6-escalera-mecánica)
- [7 horno microondas](#7-horno-microondas)
- [8 Hoja de ruta](#8-hoja-de-ruta)

# 1 Uso del IDE (Integrated Development Environment) MCUXpresso (p/Linux) o LPCXpresso (p/Windows) 

### 1.a.1 Instalacion de software

Se descargó LPCXpreso 8.2.0 y se insatalaron los complementos de OpenOCD, eGit y Yakindu StateChart Tools siguiendo los pasos de la [hoja de ayuda](https://campus.fi.uba.ar/pluginfile.php/307047/mod_resource/content/5/Sistemas_Embebidos-2019_2doC-Instalacion_de_Herramientas-Cruz.pdf) de la materia.

### 1.a.2 Instalacion del plugin  

Dentro de LPCXpresso, se agrego el plug-in Yakindu StateChart Tools Menú Help → Install New Software … Work with: http://updates.yakindu.org/sct/mars/releases/.Se selecciono el plug-in y luego se sigio las instrucciones del asistente (Yakindu SCT)
como se puede ver en la siguiente figura:

### 1.a.3 Debug

En este caso se siguieron los pasos siguientes:

1. Se Selecciono como nombre de Workspace: workspace-SE-2018-TPs (el mismo que utilizó para el TP1)

2. En el archivo project.mk se configuro el proyecto, el procesador y la placa a utilizar:

PROJECT = sapi_examples/edu-ciaa-nxp/statecharts/statecharts_bare_metal
TARGET = lpc4337_m4
BOARD = edu_ciaa_nxp

3. Se copiaron en la carpeta sapi_examples/edu-ciaa-nxp/statcharts/statecharts_bare_metal/gen/ los
archivos:

a. prefix.sct Yakindu SCT Statechart Model file.Se copio y pego Blinky.-sct y  se renombro como: prefix.sct
b. pregix.sgen Yakindu SCT Code Generator Model file

5. Para Simular el modelo: Clic derecho sobre prefix.sct -> Run Us -> 1 Satechart Simulation luego se probo cambiando de estado con el evento etick.

7. Para Generar el código del modelo: se hizo Clic derecho sobre pregix.sgen -> Generate Code Artifacts (Artifacts =>
Prefix.c, Prefix.h, PrefixRequired.h y sc_types.h)

8. Luego se Compilo y debugeo firmware_v2 cambiando la ruta de debug por C:\Users\cmg-8\firmware_v2\out\lpc4337_m4\statecharts_bare_metal.axf

9. Para probar el debug se puso un breakpoint en la funcion que cambia de estado el led para ver el cambio de estado debido a que la frecuencia de interrupcion seteada en el programa es demasiado rapida para ver el cambio a simple vista:




## 1.b funciones 

Se pueden visualizar en la siguiente figura las funciones:

| Nombre | Descripción |
| ------ | ----------- |
|  |  |
||  |
||  |
| |  |

![Imagen Switches_leds_funciones_2_b_1](https://raw.githubusercontent.com/DarioCapu/TP1/master/Imagenes/Switches_leds_funciones_2_b_1.png)

## 1.c constantes,variables.

Se pueden visualizar en la siguiente figura las constantes:

| Nombre | Descripción |
| ------ | ----------- |
| GPIO0 | pin correspondiente a GPIO0 |
| GPIO_INPUT | estado de entrada de un pin GPIO |
| GPIO1 | pin correspondiente a GPIO0 |
| GPIO_OUTPUT | estado de salida de un pin GPIO |
| TEC1 | primer pulsador |
| LEDB | pin correspondiente a LED azul |
| valor | variable booleana que se utiliza para el valor de estado de cada pulsador |
| TEC2 | segundo pulsador |
| LED1 | pin correspondiente a LED amarillo|
| TEC3 | tercer pulsador |
| LED2 | pin correspondiente a LED rojo |
| TEC4 | cuarto pulsador |
| LED3 | pin correspondiente a LED verde |



![Imagen Switches_leds_variables_constantes_2_b_2](https://raw.githubusercontent.com/DarioCapu/TP1/master/Imagenes/Switches_leds_variables_constantes_2_b_2.png)


# 2 Uso del IDE (Integrated Development Environment) LPCXpresso & plug-in Yakindu SCT

# 3 panel de control de un generador de señales

# 4 puerta corrediza

# 5 portón de cochera

# 6 escalera mecánica 

# 7 horno microondas

# 8 Hoja de ruta
