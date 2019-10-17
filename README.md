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

## a) migrar proyecto
Para migrar el proyecto a projects/tp2 se copiaron los archivos correspondientes a esta carpeta dentro del proyecto firmware_v2:

## b)generacion de codigos con statecharts

Para cada caso se copio los archivos Blinky.-sct,BlinkyTimeEvent.-sct,Button.-sct,ldelBlinky.-sct, Application.-sct,Porton.-sct y se los renombro como prefix.sct cada uno por separado en las carpetas SCT_1_1,SCT_1_2,SCT_2_1,SCT_2_2,SCT_3_1 y SCT_3_2 correspondientemente.Luego se genero el codigo de cada uno por separado.
Para generar los codigos fuentes correspondientes de cada maquina de estado se usaron los archivos de prefix.sgen -> generate code artifacts.Como se puede visualizar en la siguiente figura:

![2b_codigo_generado.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/2b_codigo_generado.jpg)


![2b_makefile1.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/2b_makefile1.jpg)
![2b_makefile2.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/2b_makefile2.jpg)
![2b_makefile3.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/2b_makefile3.jpg)

### c)prueba de simulaciones

Con los codigos generados en el punto anterior se modifico el #define TEST (SCT_?) con ? ={1,2,3} en el main.c para seleccionar entre los diferentes casos de las maquinas de estado como se puede visualizar en la siguiente figura:

![2c_simulaciones.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/2c_simulaciones.jpg)


## d)casos de prueba con TIME EVENTS

Con los codigos generados en el punto anterior se modifico el #define _USE_TIME_EVENTS (?) con ? ={true,false} en el main.c para seleccionar entre usar time events o no.

![2d_timeevents.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/2d_timeevents.jpg)


## e)compilacion

Se realizaron las acciones clear ->refresh -> build sobre el proyecto para cada caso y luego se ejecutaron los diferentes casos de prueba.

![2e_compilacion.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/2e_compilacion.jpg)

## f)configuracion DEBUG

Se configuro el DEBUG teniendo en cuenta que el proyecto apunte a out/lpc4337_m4/TP2.axf como se puede ver en la figura:

![2f_debug.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/2f_debug.jpg)


## g)prueba DEBUG

Se realizaron las pruebas de DEBUG para los casos SCT_1_1,SCT_1_2,SCT_2_1,SCT_2_2,SCT_3_1 y SCT_3_2 para los diferentes casos con Time Events.

## h)repositorio

Se creó un repositorio en GitHub, y se sincronizó la carpeta *TP2* del proyecto *firmware_v2* utilizando los siguientes comandos
```sh
$ git init
$ git remote add origin https://github.com/cristianlabo/TP2.git
$ git status
$ git add .
$ git commit -m "Primer commit. Archivos .c .h y make"
$ git push -u origin master
```

# 3,4,5,6,7 - Implementacion de maquinas de estado

Para la implementacion de la maquina de estados para cada uno de los casos propuestos se separaron en carpetas,se realizaron los diagramas de estado,se  generaron los codigos fuente(prefix.sgen -> generate code artifacts) en las carpetas correspondientes y se modifico el archivo makefile como se puede ver en la siguiente figura:

![implementacion_maquinas_estados.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/implementacion_maquinas_estados.jpg)

![makefile_implementaciones1.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/makefile_implementaciones1.jpg)
![makefile_implementaciones2.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/makefile_implementaciones2.jpg)

## Panel de control de un generador de señales

Para este caso se puede ver el diagrama de estados  en la siguiente figura:

![generador_frecuencia1.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/generador_frecuencia1.jpg)
![generador_frecuencia3.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/generador_frecuencia3.jpg)
![generador_frecuencia2.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/generador_frecuencia2.jpg)

## Puerta corrediza

Para este caso se puede ver el diagrama de estados  en la siguiente figura:

![puerta_corrediza1.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/puerta_corrediza1.jpg)
![puerta_corrediza2.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/puerta_corrediza2.jpg)


## Portón de cochera

Para este caso se puede ver el diagrama de estados  en la siguiente figura:

![porton_cochera1.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/porton_cochera1.jpg)
![porton_cochera2.jpg](https://github.com/cristianlabo/TP2/blob/master/Imagenes/porton_cochera2.jpg)



## Escalera mecánica 

Para este caso se puede ver el diagrama de estados  en la siguiente figura:

## Horno microondas

Para este caso se puede ver el diagrama de estados  en la siguiente figura:

# 8 Hoja de ruta
