
#ifndef PREFIX_H_
#define PREFIX_H_

#include "sc_types.h"
		
#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'prefix'.
*/

/*! Enumeration of all states */ 
typedef enum
{
	Prefix_TECX_NO_OPRIMIDO,
	Prefix_TECX_DEBOUNCE,
	Prefix_TECX_VALIDATION,
	Prefix_TECX_OPRIMIDO,
	Prefix_IDLE_ESPERA,
	Prefix_PORTON_CERRADO,
	Prefix_PORTON_CERRANDO,
	Prefix_PORTON_ABRIENDO,
	Prefix_PORTON_ABIERTO,
	Prefix_LED1_REPOSO,
	Prefix_LED1_TITILAR,
	Prefix_LED1_TITILAR_r1_APAGADO,
	Prefix_LED1_TITILAR_r1_ENCENDIDO,
	Prefix_LED2_REPOSO,
	Prefix_LED2_TITILAR,
	Prefix_LED2_TITILAR_r1_APAGADO,
	Prefix_LED2_TITILAR_r1_ENCENDIDO,
	Prefix_last_state
} PrefixStates;

/*! Type definition of the data structure for the PrefixIface interface scope. */
typedef struct
{
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
	sc_boolean evTECXNoOprimido_raised;
} PrefixIface;

/* Declaration of constants for scope PrefixIface. */
extern const sc_integer PREFIX_PREFIXIFACE_LEDB;
extern const sc_integer PREFIX_PREFIXIFACE_LED1;
extern const sc_integer PREFIX_PREFIXIFACE_LED2;
extern const sc_integer PREFIX_PREFIXIFACE_LED3;
extern const sc_boolean PREFIX_PREFIXIFACE_LED_ON;
extern const sc_boolean PREFIX_PREFIXIFACE_LED_OFF;
extern const sc_integer PREFIX_PREFIXIFACE_TEC1;
extern const sc_integer PREFIX_PREFIXIFACE_TEC2;
extern const sc_integer PREFIX_PREFIXIFACE_TEC3;

/*! Type definition of the data structure for the PrefixInternal interface scope. */
typedef struct
{
	sc_boolean siTECXOK_raised;
	sc_boolean siAbrir_raised;
	sc_boolean siCerrar_raised;
	sc_boolean siLED1_raised;
	sc_boolean siNoLED1_raised;
	sc_boolean siLED2_raised;
	sc_boolean siNoLED2_raised;
	sc_integer viTecla;
} PrefixInternal;

/*! Type definition of the data structure for the PrefixTimeEvents interface scope. */
typedef struct
{
	sc_boolean prefix_TECX_DEBOUNCE_tev0_raised;
	sc_boolean prefix_PORTON_CERRANDO_tev0_raised;
	sc_boolean prefix_PORTON_ABRIENDO_tev0_raised;
	sc_boolean prefix_LED1_TITILAR_r1_APAGADO_tev0_raised;
	sc_boolean prefix_LED1_TITILAR_r1_ENCENDIDO_tev0_raised;
	sc_boolean prefix_LED2_TITILAR_r1_APAGADO_tev0_raised;
	sc_boolean prefix_LED2_TITILAR_r1_ENCENDIDO_tev0_raised;
} PrefixTimeEvents;


/*! Define dimension of the state configuration vector for orthogonal states. */
#define PREFIX_MAX_ORTHOGONAL_STATES 5

/*! 
 * Type definition of the data structure for the Prefix state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	PrefixStates stateConfVector[PREFIX_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	PrefixIface iface;
	PrefixInternal internal;
	PrefixTimeEvents timeEvents;
} Prefix;

/*! Initializes the Prefix state machine data structures. Must be called before first usage.*/
extern void prefix_init(Prefix* handle);

/*! Activates the state machine */
extern void prefix_enter(Prefix* handle);

/*! Deactivates the state machine */
extern void prefix_exit(Prefix* handle);

/*! Performs a 'run to completion' step. */
extern void prefix_runCycle(Prefix* handle);

/*! Raises a time event. */
extern void prefix_raiseTimeEvent(const Prefix* handle, sc_eventid evid);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTECXOprimido(Prefix* handle, sc_integer value);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void prefixIface_raise_evTECXNoOprimido(Prefix* handle);

/*! Gets the value of the variable 'LEDB' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lEDB(const Prefix* handle);
/*! Gets the value of the variable 'LED1' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED1(const Prefix* handle);
/*! Gets the value of the variable 'LED2' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED2(const Prefix* handle);
/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_lED3(const Prefix* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_lED_ON(const Prefix* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern const sc_boolean prefixIface_get_lED_OFF(const Prefix* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC1(const Prefix* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC2(const Prefix* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern const sc_integer prefixIface_get_tEC3(const Prefix* handle);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean prefix_isActive(const Prefix* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean prefix_isFinal(const Prefix* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state);

#ifdef __cplusplus
}
#endif 

#endif /* PREFIX_H_ */
