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

![1.a.2.instalacion_yakindu](https://github.com/cristianlabo/TP2/blob/master/Imagenes/1.a.2.instalacion_yakindu.jpg)

### 1.a.3 Debug

En este caso se siguieron los pasos siguientes:

- 1. Se Selecciono como nombre de Workspace: workspace-SE-2018-TPs (el mismo que utilizó para el TP1)

- 2. En el archivo project.mk se configuro el proyecto, el procesador y la placa a utilizar:-

PROJECT = sapi_examples/edu-ciaa-nxp/statecharts/statecharts_bare_metal
TARGET = lpc4337_m4
BOARD = edu_ciaa_nxp

- 3. Se copiaron en la carpeta sapi_examples/edu-ciaa-nxp/statcharts/statecharts_bare_metal/gen/ los
archivos:

- a. prefix.sct Yakindu SCT Statechart Model file.Se copio y pego Blinky.-sct y  se renombro como: prefix.sct
- b. pregix.sgen Yakindu SCT Code Generator Model file

Estos cambios se pueden visualizar en la siguiente figura:


![1.a.4.archivos.gen](https://github.com/cristianlabo/TP2/blob/master/Imagenes/1.a.4.archivos.gen.jpg)


- 4. Para Simular el modelo: Clic derecho sobre prefix.sct -> Run Us -> 1 Satechart Simulation luego se probo cambiando de estado con el evento etick como se puede ver en la siguiente figura:

![1.a.3.evento_etick.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/1.a.3.evento_etick.jpg)

- 5. Para Generar el código del modelo: se hizo Clic derecho sobre pregix.sgen -> Generate Code Artifacts (Artifacts =>
Prefix.c, Prefix.h, PrefixRequired.h y sc_types.h)

- 6. Luego se Compilo y debugeo firmware_v2 cambiando la ruta de debug por C:\Users\cmg-8\firmware_v2\out\lpc4337_m4\statecharts_bare_metal.axf

- 7. Para probar el debug se puso un breakpoint en la funcion que cambia de estado el led para ver el cambio de estado debido a que la frecuencia de interrupcion seteada en el programa es demasiado rapida para ver el cambio a simple vista:

![1.a.7.breackpoint.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/1.a.7.breackpoint.jpg)


## 1.b funciones 

Se pueden visualizar en la siguiente figura las funciones:


| Nombre | Descripción |
| ------ | ----------- |
|  boardConfig(); | configura los pines de entrada y salida    |
|  tickConfig( TICKRATE_MS );  | configurar la frecuencia de la interrupciones    |
|  tickCallbackSet( myTickHook, (void*)NULL );  | configura la funcion que se ejecutara con cada interrupcion    |
|  InitTimerTicks(ticks, NOF_TIMERS); | incializa la frecuencia del timer   |
|  prefix_init(&statechart);  | inicializa la maquina de estados    |
|  prefix_enter(&statechart);   |  cambia el estado de la maquina de estados   |
|  UpdateTimers(ticks, NOF_TIMERS);  | actualiza la frecuencia del timer    |
|  prefixIface_raise_evTick(&statechart);| activa el evento etick |
|  IsPendEvent(ticks, NOF_TIMERS, ticks[i].evid)       | devuelve true si se cumplio el tiempo de eventos dado por NOF_TIMERS|
|  prefix_raiseTimeEvent(&statechart, ticks[i].evid);   |  activa el evento etick   |
|  MarkAsAttEvent(ticks, NOF_TIMERS, ticks[i].evid);   |  setea el evento pendiente en false  |
|  prefix_runCycle(&statechart);   | cambia el estado de la maquina de estados  |


![1.b.funciones.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/1.b.funciones.jpg)

## 1.c constantes,variables.

Se pueden visualizar en la siguiente figura las constantes:

| Nombre | Descripción |
| ------ | ----------- |
|  TICKRATE_MS   |  setea la frecuencia de interrupciones   |
|  USE_TIME_EVENTS  | flag utilizado para decididir si se ejecutan eventos por tiempo o no    |
|  NOF_TIMERS  |  constante utilizada para definir el tiempo de cada evento  |
|  SysTick_Time_Flag  |  flag utilizado para saber si se produjo una interrupcion  |


![1.c.constantes.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/1.c.constantes.jpg)

# 2 Uso del IDE (Integrated Development Environment) LPCXpresso & plug-in Yakindu SCT

Para migrar el proyecto a projects/tp2 se copiaron los archivos correspondientes a esta carpeta dentro del proyecto firmware_v2 como se puede ver en la siguiente figura:

![2b_arbol.png](https://github.com/cristianlabo/TP2/blob/master/Imagenes/2b_arbol.png)

Luego se configuraron el archivo prefix_sgen  de la siguiente forma:

![2a_prefix_sgen.png](https://github.com/cristianlabo/TP2/blob/master/Imagenes/2a_prefix_sgen.png)

# 3 Panel de control de un generador de señales

# 4 Puerta corrediza

# 5 Portón de cochera

# 6 Escalera mecánica 

# 7 Horno microondas

# 8 Hoja de ruta
