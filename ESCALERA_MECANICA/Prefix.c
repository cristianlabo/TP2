
#include <stdlib.h>
#include <string.h>
#include "sc_types.h"
#include "Prefix.h"
#include "PrefixRequired.h"
/*! \file Implementation of the state machine 'prefix'
*/

/* prototypes of all internal functions */
static sc_boolean prefix_check_TECX_DEBOUNCE_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_OPRIMIDO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_VALIDACION_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_TECX_VALIDACION_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_Application_ESPERA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_Application_ESPERA_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_Application_ESPERA_tr2_tr2(const Prefix* handle);
static sc_boolean prefix_check_eForma_velocidad_1_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eForma_velocidad_2_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_INGRESO_EGRESO_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_INGRESO_INGRESO_tr0_tr0(const Prefix* handle);
static void prefix_effect_TECX_DEBOUNCE_tr0(Prefix* handle);
static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_TECX_VALIDACION_tr0(Prefix* handle);
static void prefix_effect_TECX_VALIDACION_tr1(Prefix* handle);
static void prefix_effect_Application_ESPERA_tr0(Prefix* handle);
static void prefix_effect_Application_ESPERA_tr1(Prefix* handle);
static void prefix_effect_Application_ESPERA_tr2(Prefix* handle);
static void prefix_effect_eForma_velocidad_1_tr0(Prefix* handle);
static void prefix_effect_eForma_velocidad_2_tr0(Prefix* handle);
static void prefix_effect_INGRESO_EGRESO_tr0(Prefix* handle);
static void prefix_effect_INGRESO_INGRESO_tr0(Prefix* handle);
static void prefix_enact_TECX_DEBOUNCE(Prefix* handle);
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle);
static void prefix_enact_eForma_velocidad_1(Prefix* handle);
static void prefix_enact_eForma_velocidad_2(Prefix* handle);
static void prefix_enact_INGRESO_EGRESO(Prefix* handle);
static void prefix_enact_INGRESO_INGRESO(Prefix* handle);
static void prefix_exact_TECX_DEBOUNCE(Prefix* handle);
static void prefix_enseq_TECX_DEBOUNCE_default(Prefix* handle);
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_TECX_VALIDACION_default(Prefix* handle);
static void prefix_enseq_Application_ESPERA_default(Prefix* handle);
static void prefix_enseq_eForma_velocidad_1_default(Prefix* handle);
static void prefix_enseq_eForma_velocidad_2_default(Prefix* handle);
static void prefix_enseq_INGRESO_EGRESO_default(Prefix* handle);
static void prefix_enseq_INGRESO_INGRESO_default(Prefix* handle);
static void prefix_enseq_TECX_default(Prefix* handle);
static void prefix_enseq_Application_default(Prefix* handle);
static void prefix_enseq_eForma_default(Prefix* handle);
static void prefix_enseq_INGRESO_default(Prefix* handle);
static void prefix_exseq_TECX_DEBOUNCE(Prefix* handle);
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle);
static void prefix_exseq_TECX_VALIDACION(Prefix* handle);
static void prefix_exseq_Application_ESPERA(Prefix* handle);
static void prefix_exseq_eForma_velocidad_1(Prefix* handle);
static void prefix_exseq_eForma_velocidad_2(Prefix* handle);
static void prefix_exseq_INGRESO_EGRESO(Prefix* handle);
static void prefix_exseq_INGRESO_INGRESO(Prefix* handle);
static void prefix_exseq_TECX(Prefix* handle);
static void prefix_exseq_Application(Prefix* handle);
static void prefix_exseq_eForma(Prefix* handle);
static void prefix_exseq_INGRESO(Prefix* handle);
static void prefix_react_TECX_DEBOUNCE(Prefix* handle);
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_react_TECX_OPRIMIDO(Prefix* handle);
static void prefix_react_TECX_VALIDACION(Prefix* handle);
static void prefix_react_Application_ESPERA(Prefix* handle);
static void prefix_react_eForma_velocidad_1(Prefix* handle);
static void prefix_react_eForma_velocidad_2(Prefix* handle);
static void prefix_react_INGRESO_EGRESO(Prefix* handle);
static void prefix_react_INGRESO_INGRESO(Prefix* handle);
static void prefix_react_TECX__entry_Default(Prefix* handle);
static void prefix_react_Application__entry_Default(Prefix* handle);
static void prefix_react_eForma__entry_Default(Prefix* handle);
static void prefix_react_INGRESO__entry_Default(Prefix* handle);
static void prefix_clearInEvents(Prefix* handle);
static void prefix_clearOutEvents(Prefix* handle);

const sc_integer PREFIX_PREFIXIFACE_LEDR = 0;
const sc_integer PREFIX_PREFIXIFACE_LEDG = 1;
const sc_integer PREFIX_PREFIXIFACE_LEDB = 2;
const sc_integer PREFIX_PREFIXIFACE_LED1 = 3;
const sc_integer PREFIX_PREFIXIFACE_LED2 = 4;
const sc_integer PREFIX_PREFIXIFACE_LED3 = 5;
const sc_boolean PREFIX_PREFIXIFACE_LED_ON = bool_true;
const sc_boolean PREFIX_PREFIXIFACE_LED_OFF = bool_false;
const sc_integer PREFIX_PREFIXIFACE_TEC1 = 1 << 0;
const sc_integer PREFIX_PREFIXIFACE_TEC2 = 1 << 1;
const sc_integer PREFIX_PREFIXIFACE_TEC3 = 1 << 2;
const sc_integer PREFIX_PREFIXIFACE_TEC4 = 1 << 3;

void prefix_init(Prefix* handle)
{
	sc_integer i;

	for (i = 0; i < PREFIX_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Prefix_last_state;
	}
	
	
	handle->stateConfVectorPosition = 0;

	prefix_clearInEvents(handle);
	prefix_clearOutEvents(handle);

	/* Default init sequence for statechart prefix */
	handle->internal.viTecla = 0;

}

void prefix_enter(Prefix* handle)
{
	/* Default enter sequence for statechart prefix */
	prefix_enseq_TECX_default(handle);
	prefix_enseq_Application_default(handle);
	prefix_enseq_eForma_default(handle);
	prefix_enseq_INGRESO_default(handle);
}

void prefix_exit(Prefix* handle)
{
	/* Default exit sequence for statechart prefix */
	prefix_exseq_TECX(handle);
	prefix_exseq_Application(handle);
	prefix_exseq_eForma(handle);
	prefix_exseq_INGRESO(handle);
}

sc_boolean prefix_isActive(const Prefix* handle)
{
	sc_boolean result;
	if (handle->stateConfVector[0] != Prefix_last_state || handle->stateConfVector[1] != Prefix_last_state || handle->stateConfVector[2] != Prefix_last_state || handle->stateConfVector[3] != Prefix_last_state)
	{
		result =  bool_true;
	}
	else
	{
		result = bool_false;
	}
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean prefix_isFinal(const Prefix* handle)
{
   return bool_false;
}

static void prefix_clearInEvents(Prefix* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_false;
	handle->iface.evTECXOprimido_raised = bool_false;
	handle->internal.siTECXOK_raised = bool_false;
	handle->internal.eVelocidad_raised = bool_false;
	handle->internal.eIngreso_raised = bool_false;
	handle->internal.eEgreso_raised = bool_false;
	handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised = bool_false;
}

static void prefix_clearOutEvents(Prefix* handle)
{
}

void prefix_runCycle(Prefix* handle)
{
	
	prefix_clearOutEvents(handle);
	
	for (handle->stateConfVectorPosition = 0;
		handle->stateConfVectorPosition < PREFIX_MAX_ORTHOGONAL_STATES;
		handle->stateConfVectorPosition++)
		{
			
		switch (handle->stateConfVector[handle->stateConfVectorPosition])
		{
		case Prefix_TECX_DEBOUNCE :
		{
			prefix_react_TECX_DEBOUNCE(handle);
			break;
		}
		case Prefix_TECX_NO_OPRIMIDO :
		{
			prefix_react_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_OPRIMIDO :
		{
			prefix_react_TECX_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_VALIDACION :
		{
			prefix_react_TECX_VALIDACION(handle);
			break;
		}
		case Prefix_Application_ESPERA :
		{
			prefix_react_Application_ESPERA(handle);
			break;
		}
		case Prefix_eForma_velocidad_1 :
		{
			prefix_react_eForma_velocidad_1(handle);
			break;
		}
		case Prefix_eForma_velocidad_2 :
		{
			prefix_react_eForma_velocidad_2(handle);
			break;
		}
		case Prefix_INGRESO_EGRESO :
		{
			prefix_react_INGRESO_EGRESO(handle);
			break;
		}
		case Prefix_INGRESO_INGRESO :
		{
			prefix_react_INGRESO_INGRESO(handle);
			break;
		}
		default:
			break;
		}
	}
	
	prefix_clearInEvents(handle);
}

void prefix_raiseTimeEvent(const Prefix* handle, sc_eventid evid)
{
	if ( ((sc_intptr_t)evid) >= ((sc_intptr_t)&(handle->timeEvents))
		&&  ((sc_intptr_t)evid) < ((sc_intptr_t)&(handle->timeEvents)) + sizeof(PrefixTimeEvents))
		{
		*(sc_boolean*)evid = bool_true;
	}		
}

sc_boolean prefix_isStateActive(const Prefix* handle, PrefixStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Prefix_TECX_DEBOUNCE :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_DEBOUNCE
			);
			break;
		case Prefix_TECX_NO_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_NO_OPRIMIDO
			);
			break;
		case Prefix_TECX_OPRIMIDO :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_OPRIMIDO
			);
			break;
		case Prefix_TECX_VALIDACION :
			result = (sc_boolean) (handle->stateConfVector[0] == Prefix_TECX_VALIDACION
			);
			break;
		case Prefix_Application_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[1] == Prefix_Application_ESPERA
			);
			break;
		case Prefix_eForma_velocidad_1 :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_eForma_velocidad_1
			);
			break;
		case Prefix_eForma_velocidad_2 :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_eForma_velocidad_2
			);
			break;
		case Prefix_INGRESO_EGRESO :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_INGRESO_EGRESO
			);
			break;
		case Prefix_INGRESO_INGRESO :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_INGRESO_INGRESO
			);
			break;
		default:
			result = bool_false;
			break;
	}
	return result;
}

void prefixIface_raise_evTECXNoOprimido(Prefix* handle)
{
	handle->iface.evTECXNoOprimido_raised = bool_true;
}
void prefixIface_raise_evTECXOprimido(Prefix* handle, sc_integer value)
{
	handle->iface.evTECXOprimido_value = value;
	handle->iface.evTECXOprimido_raised = bool_true;
}


const sc_integer prefixIface_get_lEDR(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDR;
}
const sc_integer prefixIface_get_lEDG(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDG;
}
const sc_integer prefixIface_get_lEDB(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LEDB;
}
const sc_integer prefixIface_get_lED1(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED1;
}
const sc_integer prefixIface_get_lED2(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED2;
}
const sc_integer prefixIface_get_lED3(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED3;
}
const sc_boolean prefixIface_get_lED_ON(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED_ON;
}
const sc_boolean prefixIface_get_lED_OFF(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_LED_OFF;
}
const sc_integer prefixIface_get_tEC1(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC1;
}
const sc_integer prefixIface_get_tEC2(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC2;
}
const sc_integer prefixIface_get_tEC3(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC3;
}
const sc_integer prefixIface_get_tEC4(const Prefix* handle)
{
	return PREFIX_PREFIXIFACE_TEC4;
}

/* implementations of all internal functions */

static sc_boolean prefix_check_TECX_DEBOUNCE_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised;
}

static sc_boolean prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean prefix_check_TECX_OPRIMIDO_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean prefix_check_TECX_VALIDACION_tr0_tr0(const Prefix* handle)
{
	return handle->iface.evTECXOprimido_raised;
}

static sc_boolean prefix_check_TECX_VALIDACION_tr1_tr1(const Prefix* handle)
{
	return handle->iface.evTECXNoOprimido_raised;
}

static sc_boolean prefix_check_Application_ESPERA_tr0_tr0(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC2)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_Application_ESPERA_tr1_tr1(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC1)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_Application_ESPERA_tr2_tr2(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC3)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_eForma_velocidad_1_tr0_tr0(const Prefix* handle)
{
	return handle->internal.eVelocidad_raised;
}

static sc_boolean prefix_check_eForma_velocidad_2_tr0_tr0(const Prefix* handle)
{
	return handle->internal.eVelocidad_raised;
}

static sc_boolean prefix_check_INGRESO_EGRESO_tr0_tr0(const Prefix* handle)
{
	return handle->internal.eIngreso_raised;
}

static sc_boolean prefix_check_INGRESO_INGRESO_tr0_tr0(const Prefix* handle)
{
	return handle->internal.eEgreso_raised;
}

static void prefix_effect_TECX_DEBOUNCE_tr0(Prefix* handle)
{
	prefix_exseq_TECX_DEBOUNCE(handle);
	prefix_enseq_TECX_VALIDACION_default(handle);
}

static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_TECX_NO_OPRIMIDO(handle);
	prefix_enseq_TECX_DEBOUNCE_default(handle);
}

static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle)
{
	prefix_exseq_TECX_OPRIMIDO(handle);
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void prefix_effect_TECX_VALIDACION_tr0(Prefix* handle)
{
	prefix_exseq_TECX_VALIDACION(handle);
	prefix_enseq_TECX_OPRIMIDO_default(handle);
}

static void prefix_effect_TECX_VALIDACION_tr1(Prefix* handle)
{
	prefix_exseq_TECX_VALIDACION(handle);
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

static void prefix_effect_Application_ESPERA_tr0(Prefix* handle)
{
	prefix_exseq_Application_ESPERA(handle);
	handle->internal.eIngreso_raised = bool_true;
	prefix_enseq_Application_ESPERA_default(handle);
}

static void prefix_effect_Application_ESPERA_tr1(Prefix* handle)
{
	prefix_exseq_Application_ESPERA(handle);
	handle->internal.eVelocidad_raised = bool_true;
	prefix_enseq_Application_ESPERA_default(handle);
}

static void prefix_effect_Application_ESPERA_tr2(Prefix* handle)
{
	prefix_exseq_Application_ESPERA(handle);
	handle->internal.eEgreso_raised = bool_true;
	prefix_enseq_Application_ESPERA_default(handle);
}

static void prefix_effect_eForma_velocidad_1_tr0(Prefix* handle)
{
	prefix_exseq_eForma_velocidad_1(handle);
	prefix_enseq_eForma_velocidad_2_default(handle);
}

static void prefix_effect_eForma_velocidad_2_tr0(Prefix* handle)
{
	prefix_exseq_eForma_velocidad_2(handle);
	prefix_enseq_eForma_velocidad_1_default(handle);
}

static void prefix_effect_INGRESO_EGRESO_tr0(Prefix* handle)
{
	prefix_exseq_INGRESO_EGRESO(handle);
	prefix_enseq_INGRESO_INGRESO_default(handle);
}

static void prefix_effect_INGRESO_INGRESO_tr0(Prefix* handle)
{
	prefix_exseq_INGRESO_INGRESO(handle);
	prefix_enseq_INGRESO_EGRESO_default(handle);
}

/* Entry action for state 'DEBOUNCE'. */
static void prefix_enact_TECX_DEBOUNCE(Prefix* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised) , 50, bool_false);
}

/* Entry action for state 'OPRIMIDO'. */
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTECXOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTECXOprimido_value;
}

/* Entry action for state 'velocidad 1'. */
static void prefix_enact_eForma_velocidad_1(Prefix* handle)
{
	/* Entry action for state 'velocidad 1'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_ON);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'velocidad 2'. */
static void prefix_enact_eForma_velocidad_2(Prefix* handle)
{
	/* Entry action for state 'velocidad 2'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'EGRESO'. */
static void prefix_enact_INGRESO_EGRESO(Prefix* handle)
{
	/* Entry action for state 'EGRESO'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED1, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'INGRESO'. */
static void prefix_enact_INGRESO_INGRESO(Prefix* handle)
{
	/* Entry action for state 'INGRESO'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED1, PREFIX_PREFIXIFACE_LED_ON);
}

/* Exit action for state 'DEBOUNCE'. */
static void prefix_exact_TECX_DEBOUNCE(Prefix* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised) );		
}

/* 'default' enter sequence for state DEBOUNCE */
static void prefix_enseq_TECX_DEBOUNCE_default(Prefix* handle)
{
	/* 'default' enter sequence for state DEBOUNCE */
	prefix_enact_TECX_DEBOUNCE(handle);
	handle->stateConfVector[0] = Prefix_TECX_DEBOUNCE;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state NO_OPRIMIDO */
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_TECX_NO_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state OPRIMIDO */
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle)
{
	/* 'default' enter sequence for state OPRIMIDO */
	prefix_enact_TECX_OPRIMIDO(handle);
	handle->stateConfVector[0] = Prefix_TECX_OPRIMIDO;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state VALIDACION */
static void prefix_enseq_TECX_VALIDACION_default(Prefix* handle)
{
	/* 'default' enter sequence for state VALIDACION */
	handle->stateConfVector[0] = Prefix_TECX_VALIDACION;
	handle->stateConfVectorPosition = 0;
}

/* 'default' enter sequence for state ESPERA */
static void prefix_enseq_Application_ESPERA_default(Prefix* handle)
{
	/* 'default' enter sequence for state ESPERA */
	handle->stateConfVector[1] = Prefix_Application_ESPERA;
	handle->stateConfVectorPosition = 1;
}

/* 'default' enter sequence for state velocidad 1 */
static void prefix_enseq_eForma_velocidad_1_default(Prefix* handle)
{
	/* 'default' enter sequence for state velocidad 1 */
	prefix_enact_eForma_velocidad_1(handle);
	handle->stateConfVector[2] = Prefix_eForma_velocidad_1;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state velocidad 2 */
static void prefix_enseq_eForma_velocidad_2_default(Prefix* handle)
{
	/* 'default' enter sequence for state velocidad 2 */
	prefix_enact_eForma_velocidad_2(handle);
	handle->stateConfVector[2] = Prefix_eForma_velocidad_2;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state EGRESO */
static void prefix_enseq_INGRESO_EGRESO_default(Prefix* handle)
{
	/* 'default' enter sequence for state EGRESO */
	prefix_enact_INGRESO_EGRESO(handle);
	handle->stateConfVector[3] = Prefix_INGRESO_EGRESO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state INGRESO */
static void prefix_enseq_INGRESO_INGRESO_default(Prefix* handle)
{
	/* 'default' enter sequence for state INGRESO */
	prefix_enact_INGRESO_INGRESO(handle);
	handle->stateConfVector[3] = Prefix_INGRESO_INGRESO;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for region TECX */
static void prefix_enseq_TECX_default(Prefix* handle)
{
	/* 'default' enter sequence for region TECX */
	prefix_react_TECX__entry_Default(handle);
}

/* 'default' enter sequence for region Application */
static void prefix_enseq_Application_default(Prefix* handle)
{
	/* 'default' enter sequence for region Application */
	prefix_react_Application__entry_Default(handle);
}

/* 'default' enter sequence for region eForma */
static void prefix_enseq_eForma_default(Prefix* handle)
{
	/* 'default' enter sequence for region eForma */
	prefix_react_eForma__entry_Default(handle);
}

/* 'default' enter sequence for region INGRESO */
static void prefix_enseq_INGRESO_default(Prefix* handle)
{
	/* 'default' enter sequence for region INGRESO */
	prefix_react_INGRESO__entry_Default(handle);
}

/* Default exit sequence for state DEBOUNCE */
static void prefix_exseq_TECX_DEBOUNCE(Prefix* handle)
{
	/* Default exit sequence for state DEBOUNCE */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
	prefix_exact_TECX_DEBOUNCE(handle);
}

/* Default exit sequence for state NO_OPRIMIDO */
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state NO_OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state OPRIMIDO */
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle)
{
	/* Default exit sequence for state OPRIMIDO */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state VALIDACION */
static void prefix_exseq_TECX_VALIDACION(Prefix* handle)
{
	/* Default exit sequence for state VALIDACION */
	handle->stateConfVector[0] = Prefix_last_state;
	handle->stateConfVectorPosition = 0;
}

/* Default exit sequence for state ESPERA */
static void prefix_exseq_Application_ESPERA(Prefix* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[1] = Prefix_last_state;
	handle->stateConfVectorPosition = 1;
}

/* Default exit sequence for state velocidad 1 */
static void prefix_exseq_eForma_velocidad_1(Prefix* handle)
{
	/* Default exit sequence for state velocidad 1 */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state velocidad 2 */
static void prefix_exseq_eForma_velocidad_2(Prefix* handle)
{
	/* Default exit sequence for state velocidad 2 */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state EGRESO */
static void prefix_exseq_INGRESO_EGRESO(Prefix* handle)
{
	/* Default exit sequence for state EGRESO */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state INGRESO */
static void prefix_exseq_INGRESO_INGRESO(Prefix* handle)
{
	/* Default exit sequence for state INGRESO */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for region TECX */
static void prefix_exseq_TECX(Prefix* handle)
{
	/* Default exit sequence for region TECX */
	/* Handle exit of all possible states (of prefix.TECX) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Prefix_TECX_DEBOUNCE :
		{
			prefix_exseq_TECX_DEBOUNCE(handle);
			break;
		}
		case Prefix_TECX_NO_OPRIMIDO :
		{
			prefix_exseq_TECX_NO_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_OPRIMIDO :
		{
			prefix_exseq_TECX_OPRIMIDO(handle);
			break;
		}
		case Prefix_TECX_VALIDACION :
		{
			prefix_exseq_TECX_VALIDACION(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region Application */
static void prefix_exseq_Application(Prefix* handle)
{
	/* Default exit sequence for region Application */
	/* Handle exit of all possible states (of prefix.Application) at position 1... */
	switch(handle->stateConfVector[ 1 ])
	{
		case Prefix_Application_ESPERA :
		{
			prefix_exseq_Application_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region eForma */
static void prefix_exseq_eForma(Prefix* handle)
{
	/* Default exit sequence for region eForma */
	/* Handle exit of all possible states (of prefix.eForma) at position 2... */
	switch(handle->stateConfVector[ 2 ])
	{
		case Prefix_eForma_velocidad_1 :
		{
			prefix_exseq_eForma_velocidad_1(handle);
			break;
		}
		case Prefix_eForma_velocidad_2 :
		{
			prefix_exseq_eForma_velocidad_2(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region INGRESO */
static void prefix_exseq_INGRESO(Prefix* handle)
{
	/* Default exit sequence for region INGRESO */
	/* Handle exit of all possible states (of prefix.INGRESO) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Prefix_INGRESO_EGRESO :
		{
			prefix_exseq_INGRESO_EGRESO(handle);
			break;
		}
		case Prefix_INGRESO_INGRESO :
		{
			prefix_exseq_INGRESO_INGRESO(handle);
			break;
		}
		default: break;
	}
}

/* The reactions of state DEBOUNCE. */
static void prefix_react_TECX_DEBOUNCE(Prefix* handle)
{
	/* The reactions of state DEBOUNCE. */
	if (prefix_check_TECX_DEBOUNCE_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_DEBOUNCE_tr0(handle);
	} 
}

/* The reactions of state NO_OPRIMIDO. */
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state NO_OPRIMIDO. */
	if (prefix_check_TECX_NO_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_NO_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state OPRIMIDO. */
static void prefix_react_TECX_OPRIMIDO(Prefix* handle)
{
	/* The reactions of state OPRIMIDO. */
	if (prefix_check_TECX_OPRIMIDO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_OPRIMIDO_tr0(handle);
	} 
}

/* The reactions of state VALIDACION. */
static void prefix_react_TECX_VALIDACION(Prefix* handle)
{
	/* The reactions of state VALIDACION. */
	if (prefix_check_TECX_VALIDACION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_TECX_VALIDACION_tr0(handle);
	}  else
	{
		if (prefix_check_TECX_VALIDACION_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_TECX_VALIDACION_tr1(handle);
		} 
	}
}

/* The reactions of state ESPERA. */
static void prefix_react_Application_ESPERA(Prefix* handle)
{
	/* The reactions of state ESPERA. */
	if (prefix_check_Application_ESPERA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_Application_ESPERA_tr0(handle);
	}  else
	{
		if (prefix_check_Application_ESPERA_tr1_tr1(handle) == bool_true)
		{ 
			prefix_effect_Application_ESPERA_tr1(handle);
		}  else
		{
			if (prefix_check_Application_ESPERA_tr2_tr2(handle) == bool_true)
			{ 
				prefix_effect_Application_ESPERA_tr2(handle);
			} 
		}
	}
}

/* The reactions of state velocidad 1. */
static void prefix_react_eForma_velocidad_1(Prefix* handle)
{
	/* The reactions of state velocidad 1. */
	if (prefix_check_eForma_velocidad_1_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eForma_velocidad_1_tr0(handle);
	} 
}

/* The reactions of state velocidad 2. */
static void prefix_react_eForma_velocidad_2(Prefix* handle)
{
	/* The reactions of state velocidad 2. */
	if (prefix_check_eForma_velocidad_2_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eForma_velocidad_2_tr0(handle);
	} 
}

/* The reactions of state EGRESO. */
static void prefix_react_INGRESO_EGRESO(Prefix* handle)
{
	/* The reactions of state EGRESO. */
	if (prefix_check_INGRESO_EGRESO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_INGRESO_EGRESO_tr0(handle);
	} 
}

/* The reactions of state INGRESO. */
static void prefix_react_INGRESO_INGRESO(Prefix* handle)
{
	/* The reactions of state INGRESO. */
	if (prefix_check_INGRESO_INGRESO_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_INGRESO_INGRESO_tr0(handle);
	} 
}

/* Default react sequence for initial entry  */
static void prefix_react_TECX__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_TECX_NO_OPRIMIDO_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_Application__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_Application_ESPERA_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_eForma__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_eForma_velocidad_1_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_INGRESO__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_INGRESO_EGRESO_default(handle);
}


