
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
static sc_boolean prefix_check_Application_ESPERA_tr3_tr3(const Prefix* handle);
static sc_boolean prefix_check_eForma_senoidal_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eForma_cuadrada_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eForma_triangular_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_FRECUENCIA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_DISMINUYE_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_DELAY_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_AUMENTA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_ESPERA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_TENSION_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_TENSION_r1_TENSION_ACTUAL_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_TENSION_r1_TENSION_ACTUAL_tr1_tr1(const Prefix* handle);
static sc_boolean prefix_check_eMagn_TENSION_r1_DISMINUYE_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_TENSION_r1_DELAY_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_TENSION_r1_AUMENTA_tr0_tr0(const Prefix* handle);
static sc_boolean prefix_check_eMagn_TENSION_r1_ESPERA_tr0_tr0(const Prefix* handle);
static void prefix_effect_TECX_DEBOUNCE_tr0(Prefix* handle);
static void prefix_effect_TECX_NO_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_TECX_OPRIMIDO_tr0(Prefix* handle);
static void prefix_effect_TECX_VALIDACION_tr0(Prefix* handle);
static void prefix_effect_TECX_VALIDACION_tr1(Prefix* handle);
static void prefix_effect_Application_ESPERA_tr0(Prefix* handle);
static void prefix_effect_Application_ESPERA_tr1(Prefix* handle);
static void prefix_effect_Application_ESPERA_tr2(Prefix* handle);
static void prefix_effect_Application_ESPERA_tr3(Prefix* handle);
static void prefix_effect_eForma_senoidal_tr0(Prefix* handle);
static void prefix_effect_eForma_cuadrada_tr0(Prefix* handle);
static void prefix_effect_eForma_triangular_tr0(Prefix* handle);
static void prefix_effect_eMagn_FRECUENCIA_tr0(Prefix* handle);
static void prefix_effect_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr0(Prefix* handle);
static void prefix_effect_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr1(Prefix* handle);
static void prefix_effect_eMagn_FRECUENCIA_r1_DISMINUYE_tr0(Prefix* handle);
static void prefix_effect_eMagn_FRECUENCIA_r1_DELAY_tr0(Prefix* handle);
static void prefix_effect_eMagn_FRECUENCIA_r1_AUMENTA_tr0(Prefix* handle);
static void prefix_effect_eMagn_FRECUENCIA_r1_ESPERA_tr0(Prefix* handle);
static void prefix_effect_eMagn_TENSION_tr0(Prefix* handle);
static void prefix_effect_eMagn_TENSION_r1_TENSION_ACTUAL_tr0(Prefix* handle);
static void prefix_effect_eMagn_TENSION_r1_TENSION_ACTUAL_tr1(Prefix* handle);
static void prefix_effect_eMagn_TENSION_r1_DISMINUYE_tr0(Prefix* handle);
static void prefix_effect_eMagn_TENSION_r1_DELAY_tr0(Prefix* handle);
static void prefix_effect_eMagn_TENSION_r1_AUMENTA_tr0(Prefix* handle);
static void prefix_effect_eMagn_TENSION_r1_ESPERA_tr0(Prefix* handle);
static void prefix_enact_TECX_DEBOUNCE(Prefix* handle);
static void prefix_enact_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle);
static void prefix_enact_TECX_VALIDACION(Prefix* handle);
static void prefix_enact_eForma_senoidal(Prefix* handle);
static void prefix_enact_eForma_cuadrada(Prefix* handle);
static void prefix_enact_eForma_triangular(Prefix* handle);
static void prefix_enact_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(Prefix* handle);
static void prefix_enact_eMagn_FRECUENCIA_r1_DISMINUYE(Prefix* handle);
static void prefix_enact_eMagn_FRECUENCIA_r1_DELAY(Prefix* handle);
static void prefix_enact_eMagn_FRECUENCIA_r1_AUMENTA(Prefix* handle);
static void prefix_enact_eMagn_FRECUENCIA_r1_ESPERA(Prefix* handle);
static void prefix_enact_eMagn_TENSION_r1_TENSION_ACTUAL(Prefix* handle);
static void prefix_enact_eMagn_TENSION_r1_DISMINUYE(Prefix* handle);
static void prefix_enact_eMagn_TENSION_r1_DELAY(Prefix* handle);
static void prefix_enact_eMagn_TENSION_r1_AUMENTA(Prefix* handle);
static void prefix_enact_eMagn_TENSION_r1_ESPERA(Prefix* handle);
static void prefix_exact_TECX_DEBOUNCE(Prefix* handle);
static void prefix_exact_eMagn_FRECUENCIA_r1_DISMINUYE(Prefix* handle);
static void prefix_exact_eMagn_FRECUENCIA_r1_DELAY(Prefix* handle);
static void prefix_exact_eMagn_FRECUENCIA_r1_AUMENTA(Prefix* handle);
static void prefix_exact_eMagn_FRECUENCIA_r1_ESPERA(Prefix* handle);
static void prefix_exact_eMagn_TENSION_r1_DISMINUYE(Prefix* handle);
static void prefix_exact_eMagn_TENSION_r1_DELAY(Prefix* handle);
static void prefix_exact_eMagn_TENSION_r1_AUMENTA(Prefix* handle);
static void prefix_exact_eMagn_TENSION_r1_ESPERA(Prefix* handle);
static void prefix_enseq_TECX_DEBOUNCE_default(Prefix* handle);
static void prefix_enseq_TECX_NO_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_TECX_OPRIMIDO_default(Prefix* handle);
static void prefix_enseq_TECX_VALIDACION_default(Prefix* handle);
static void prefix_enseq_Application_ESPERA_default(Prefix* handle);
static void prefix_enseq_eForma_senoidal_default(Prefix* handle);
static void prefix_enseq_eForma_cuadrada_default(Prefix* handle);
static void prefix_enseq_eForma_triangular_default(Prefix* handle);
static void prefix_enseq_eMagn_FRECUENCIA_default(Prefix* handle);
static void prefix_enseq_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_default(Prefix* handle);
static void prefix_enseq_eMagn_FRECUENCIA_r1_DISMINUYE_default(Prefix* handle);
static void prefix_enseq_eMagn_FRECUENCIA_r1_DELAY_default(Prefix* handle);
static void prefix_enseq_eMagn_FRECUENCIA_r1_AUMENTA_default(Prefix* handle);
static void prefix_enseq_eMagn_FRECUENCIA_r1_ESPERA_default(Prefix* handle);
static void prefix_enseq_eMagn_TENSION_default(Prefix* handle);
static void prefix_enseq_eMagn_TENSION_r1_TENSION_ACTUAL_default(Prefix* handle);
static void prefix_enseq_eMagn_TENSION_r1_DISMINUYE_default(Prefix* handle);
static void prefix_enseq_eMagn_TENSION_r1_DELAY_default(Prefix* handle);
static void prefix_enseq_eMagn_TENSION_r1_AUMENTA_default(Prefix* handle);
static void prefix_enseq_eMagn_TENSION_r1_ESPERA_default(Prefix* handle);
static void prefix_enseq_TECX_default(Prefix* handle);
static void prefix_enseq_Application_default(Prefix* handle);
static void prefix_enseq_eForma_default(Prefix* handle);
static void prefix_enseq_eMagn_default(Prefix* handle);
static void prefix_enseq_eMagn_FRECUENCIA_r1_default(Prefix* handle);
static void prefix_enseq_eMagn_TENSION_r1_default(Prefix* handle);
static void prefix_exseq_TECX_DEBOUNCE(Prefix* handle);
static void prefix_exseq_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_exseq_TECX_OPRIMIDO(Prefix* handle);
static void prefix_exseq_TECX_VALIDACION(Prefix* handle);
static void prefix_exseq_Application_ESPERA(Prefix* handle);
static void prefix_exseq_eForma_senoidal(Prefix* handle);
static void prefix_exseq_eForma_cuadrada(Prefix* handle);
static void prefix_exseq_eForma_triangular(Prefix* handle);
static void prefix_exseq_eMagn_FRECUENCIA(Prefix* handle);
static void prefix_exseq_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(Prefix* handle);
static void prefix_exseq_eMagn_FRECUENCIA_r1_DISMINUYE(Prefix* handle);
static void prefix_exseq_eMagn_FRECUENCIA_r1_DELAY(Prefix* handle);
static void prefix_exseq_eMagn_FRECUENCIA_r1_AUMENTA(Prefix* handle);
static void prefix_exseq_eMagn_FRECUENCIA_r1_ESPERA(Prefix* handle);
static void prefix_exseq_eMagn_TENSION(Prefix* handle);
static void prefix_exseq_eMagn_TENSION_r1_TENSION_ACTUAL(Prefix* handle);
static void prefix_exseq_eMagn_TENSION_r1_DISMINUYE(Prefix* handle);
static void prefix_exseq_eMagn_TENSION_r1_DELAY(Prefix* handle);
static void prefix_exseq_eMagn_TENSION_r1_AUMENTA(Prefix* handle);
static void prefix_exseq_eMagn_TENSION_r1_ESPERA(Prefix* handle);
static void prefix_exseq_TECX(Prefix* handle);
static void prefix_exseq_Application(Prefix* handle);
static void prefix_exseq_eForma(Prefix* handle);
static void prefix_exseq_eMagn(Prefix* handle);
static void prefix_exseq_eMagn_FRECUENCIA_r1(Prefix* handle);
static void prefix_exseq_eMagn_TENSION_r1(Prefix* handle);
static void prefix_react_TECX_DEBOUNCE(Prefix* handle);
static void prefix_react_TECX_NO_OPRIMIDO(Prefix* handle);
static void prefix_react_TECX_OPRIMIDO(Prefix* handle);
static void prefix_react_TECX_VALIDACION(Prefix* handle);
static void prefix_react_Application_ESPERA(Prefix* handle);
static void prefix_react_eForma_senoidal(Prefix* handle);
static void prefix_react_eForma_cuadrada(Prefix* handle);
static void prefix_react_eForma_triangular(Prefix* handle);
static void prefix_react_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(Prefix* handle);
static void prefix_react_eMagn_FRECUENCIA_r1_DISMINUYE(Prefix* handle);
static void prefix_react_eMagn_FRECUENCIA_r1_DELAY(Prefix* handle);
static void prefix_react_eMagn_FRECUENCIA_r1_AUMENTA(Prefix* handle);
static void prefix_react_eMagn_FRECUENCIA_r1_ESPERA(Prefix* handle);
static void prefix_react_eMagn_TENSION_r1_TENSION_ACTUAL(Prefix* handle);
static void prefix_react_eMagn_TENSION_r1_DISMINUYE(Prefix* handle);
static void prefix_react_eMagn_TENSION_r1_DELAY(Prefix* handle);
static void prefix_react_eMagn_TENSION_r1_AUMENTA(Prefix* handle);
static void prefix_react_eMagn_TENSION_r1_ESPERA(Prefix* handle);
static void prefix_react_TECX__entry_Default(Prefix* handle);
static void prefix_react_Application__entry_Default(Prefix* handle);
static void prefix_react_eForma__entry_Default(Prefix* handle);
static void prefix_react_eMagn__entry_Default(Prefix* handle);
static void prefix_react_eMagn_FRECUENCIA_r1__entry_Default(Prefix* handle);
static void prefix_react_eMagn_TENSION_r1__entry_Default(Prefix* handle);
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
	handle->iface.tension = 0;
	handle->iface.frecuencia = 0;
	handle->iface.flag_tecla = bool_false;
	handle->internal.viTecla = 0;

}

void prefix_enter(Prefix* handle)
{
	/* Default enter sequence for statechart prefix */
	prefix_enseq_TECX_default(handle);
	prefix_enseq_Application_default(handle);
	prefix_enseq_eForma_default(handle);
	prefix_enseq_eMagn_default(handle);
}

void prefix_exit(Prefix* handle)
{
	/* Default exit sequence for statechart prefix */
	prefix_exseq_TECX(handle);
	prefix_exseq_Application(handle);
	prefix_exseq_eForma(handle);
	prefix_exseq_eMagn(handle);
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
	handle->internal.eForma_raised = bool_false;
	handle->internal.eMagn_raised = bool_false;
	handle->internal.eUp_raised = bool_false;
	handle->internal.eDown_raised = bool_false;
	handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised = bool_false;
	handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_DISMINUYE_tev0_raised = bool_false;
	handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_DELAY_tev0_raised = bool_false;
	handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_AUMENTA_tev0_raised = bool_false;
	handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_ESPERA_tev0_raised = bool_false;
	handle->timeEvents.prefix_eMagn_TENSION_r1_DISMINUYE_tev0_raised = bool_false;
	handle->timeEvents.prefix_eMagn_TENSION_r1_DELAY_tev0_raised = bool_false;
	handle->timeEvents.prefix_eMagn_TENSION_r1_AUMENTA_tev0_raised = bool_false;
	handle->timeEvents.prefix_eMagn_TENSION_r1_ESPERA_tev0_raised = bool_false;
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
		case Prefix_eForma_senoidal :
		{
			prefix_react_eForma_senoidal(handle);
			break;
		}
		case Prefix_eForma_cuadrada :
		{
			prefix_react_eForma_cuadrada(handle);
			break;
		}
		case Prefix_eForma_triangular :
		{
			prefix_react_eForma_triangular(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL :
		{
			prefix_react_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_DISMINUYE :
		{
			prefix_react_eMagn_FRECUENCIA_r1_DISMINUYE(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_DELAY :
		{
			prefix_react_eMagn_FRECUENCIA_r1_DELAY(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_AUMENTA :
		{
			prefix_react_eMagn_FRECUENCIA_r1_AUMENTA(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_ESPERA :
		{
			prefix_react_eMagn_FRECUENCIA_r1_ESPERA(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_TENSION_ACTUAL :
		{
			prefix_react_eMagn_TENSION_r1_TENSION_ACTUAL(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_DISMINUYE :
		{
			prefix_react_eMagn_TENSION_r1_DISMINUYE(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_DELAY :
		{
			prefix_react_eMagn_TENSION_r1_DELAY(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_AUMENTA :
		{
			prefix_react_eMagn_TENSION_r1_AUMENTA(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_ESPERA :
		{
			prefix_react_eMagn_TENSION_r1_ESPERA(handle);
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
		case Prefix_eForma_senoidal :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_eForma_senoidal
			);
			break;
		case Prefix_eForma_cuadrada :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_eForma_cuadrada
			);
			break;
		case Prefix_eForma_triangular :
			result = (sc_boolean) (handle->stateConfVector[2] == Prefix_eForma_triangular
			);
			break;
		case Prefix_eMagn_FRECUENCIA :
			result = (sc_boolean) (handle->stateConfVector[3] >= Prefix_eMagn_FRECUENCIA
				&& handle->stateConfVector[3] <= Prefix_eMagn_FRECUENCIA_r1_ESPERA);
			break;
		case Prefix_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL
			);
			break;
		case Prefix_eMagn_FRECUENCIA_r1_DISMINUYE :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_eMagn_FRECUENCIA_r1_DISMINUYE
			);
			break;
		case Prefix_eMagn_FRECUENCIA_r1_DELAY :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_eMagn_FRECUENCIA_r1_DELAY
			);
			break;
		case Prefix_eMagn_FRECUENCIA_r1_AUMENTA :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_eMagn_FRECUENCIA_r1_AUMENTA
			);
			break;
		case Prefix_eMagn_FRECUENCIA_r1_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_eMagn_FRECUENCIA_r1_ESPERA
			);
			break;
		case Prefix_eMagn_TENSION :
			result = (sc_boolean) (handle->stateConfVector[3] >= Prefix_eMagn_TENSION
				&& handle->stateConfVector[3] <= Prefix_eMagn_TENSION_r1_ESPERA);
			break;
		case Prefix_eMagn_TENSION_r1_TENSION_ACTUAL :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_eMagn_TENSION_r1_TENSION_ACTUAL
			);
			break;
		case Prefix_eMagn_TENSION_r1_DISMINUYE :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_eMagn_TENSION_r1_DISMINUYE
			);
			break;
		case Prefix_eMagn_TENSION_r1_DELAY :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_eMagn_TENSION_r1_DELAY
			);
			break;
		case Prefix_eMagn_TENSION_r1_AUMENTA :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_eMagn_TENSION_r1_AUMENTA
			);
			break;
		case Prefix_eMagn_TENSION_r1_ESPERA :
			result = (sc_boolean) (handle->stateConfVector[3] == Prefix_eMagn_TENSION_r1_ESPERA
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
sc_integer prefixIface_get_tension(const Prefix* handle)
{
	return handle->iface.tension;
}
void prefixIface_set_tension(Prefix* handle, sc_integer value)
{
	handle->iface.tension = value;
}
sc_integer prefixIface_get_frecuencia(const Prefix* handle)
{
	return handle->iface.frecuencia;
}
void prefixIface_set_frecuencia(Prefix* handle, sc_integer value)
{
	handle->iface.frecuencia = value;
}
sc_boolean prefixIface_get_flag_tecla(const Prefix* handle)
{
	return handle->iface.flag_tecla;
}
void prefixIface_set_flag_tecla(Prefix* handle, sc_boolean value)
{
	handle->iface.flag_tecla = value;
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

static sc_boolean prefix_check_Application_ESPERA_tr3_tr3(const Prefix* handle)
{
	return ((handle->internal.siTECXOK_raised) && (handle->internal.viTecla == PREFIX_PREFIXIFACE_TEC4)) ? bool_true : bool_false;
}

static sc_boolean prefix_check_eForma_senoidal_tr0_tr0(const Prefix* handle)
{
	return handle->internal.eForma_raised;
}

static sc_boolean prefix_check_eForma_cuadrada_tr0_tr0(const Prefix* handle)
{
	return handle->internal.eForma_raised;
}

static sc_boolean prefix_check_eForma_triangular_tr0_tr0(const Prefix* handle)
{
	return handle->internal.eForma_raised;
}

static sc_boolean prefix_check_eMagn_FRECUENCIA_tr0_tr0(const Prefix* handle)
{
	return handle->internal.eMagn_raised;
}

static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr0_tr0(const Prefix* handle)
{
	return handle->internal.eDown_raised;
}

static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr1_tr1(const Prefix* handle)
{
	return handle->internal.eUp_raised;
}

static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_DISMINUYE_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_DISMINUYE_tev0_raised;
}

static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_DELAY_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_DELAY_tev0_raised;
}

static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_AUMENTA_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_AUMENTA_tev0_raised;
}

static sc_boolean prefix_check_eMagn_FRECUENCIA_r1_ESPERA_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_ESPERA_tev0_raised;
}

static sc_boolean prefix_check_eMagn_TENSION_tr0_tr0(const Prefix* handle)
{
	return handle->internal.eMagn_raised;
}

static sc_boolean prefix_check_eMagn_TENSION_r1_TENSION_ACTUAL_tr0_tr0(const Prefix* handle)
{
	return handle->internal.eDown_raised;
}

static sc_boolean prefix_check_eMagn_TENSION_r1_TENSION_ACTUAL_tr1_tr1(const Prefix* handle)
{
	return handle->internal.eUp_raised;
}

static sc_boolean prefix_check_eMagn_TENSION_r1_DISMINUYE_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_eMagn_TENSION_r1_DISMINUYE_tev0_raised;
}

static sc_boolean prefix_check_eMagn_TENSION_r1_DELAY_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_eMagn_TENSION_r1_DELAY_tev0_raised;
}

static sc_boolean prefix_check_eMagn_TENSION_r1_AUMENTA_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_eMagn_TENSION_r1_AUMENTA_tev0_raised;
}

static sc_boolean prefix_check_eMagn_TENSION_r1_ESPERA_tr0_tr0(const Prefix* handle)
{
	return handle->timeEvents.prefix_eMagn_TENSION_r1_ESPERA_tev0_raised;
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
	handle->internal.eMagn_raised = bool_true;
	prefix_enseq_Application_ESPERA_default(handle);
}

static void prefix_effect_Application_ESPERA_tr1(Prefix* handle)
{
	prefix_exseq_Application_ESPERA(handle);
	handle->internal.eForma_raised = bool_true;
	prefix_enseq_Application_ESPERA_default(handle);
}

static void prefix_effect_Application_ESPERA_tr2(Prefix* handle)
{
	prefix_exseq_Application_ESPERA(handle);
	handle->internal.eDown_raised = bool_true;
	handle->iface.flag_tecla = bool_true;
	prefix_enseq_Application_ESPERA_default(handle);
}

static void prefix_effect_Application_ESPERA_tr3(Prefix* handle)
{
	prefix_exseq_Application_ESPERA(handle);
	handle->internal.eUp_raised = bool_true;
	handle->iface.flag_tecla = bool_true;
	prefix_enseq_Application_ESPERA_default(handle);
}

static void prefix_effect_eForma_senoidal_tr0(Prefix* handle)
{
	prefix_exseq_eForma_senoidal(handle);
	prefix_enseq_eForma_cuadrada_default(handle);
}

static void prefix_effect_eForma_cuadrada_tr0(Prefix* handle)
{
	prefix_exseq_eForma_cuadrada(handle);
	prefix_enseq_eForma_triangular_default(handle);
}

static void prefix_effect_eForma_triangular_tr0(Prefix* handle)
{
	prefix_exseq_eForma_triangular(handle);
	prefix_enseq_eForma_senoidal_default(handle);
}

static void prefix_effect_eMagn_FRECUENCIA_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_FRECUENCIA(handle);
	prefix_enseq_eMagn_TENSION_default(handle);
}

static void prefix_effect_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(handle);
	prefix_enseq_eMagn_FRECUENCIA_r1_DISMINUYE_default(handle);
}

static void prefix_effect_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr1(Prefix* handle)
{
	prefix_exseq_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(handle);
	prefix_enseq_eMagn_FRECUENCIA_r1_AUMENTA_default(handle);
}

static void prefix_effect_eMagn_FRECUENCIA_r1_DISMINUYE_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_FRECUENCIA_r1_DISMINUYE(handle);
	prefix_enseq_eMagn_FRECUENCIA_r1_DELAY_default(handle);
}

static void prefix_effect_eMagn_FRECUENCIA_r1_DELAY_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_FRECUENCIA_r1_DELAY(handle);
	prefix_enseq_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_default(handle);
}

static void prefix_effect_eMagn_FRECUENCIA_r1_AUMENTA_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_FRECUENCIA_r1_AUMENTA(handle);
	prefix_enseq_eMagn_FRECUENCIA_r1_ESPERA_default(handle);
}

static void prefix_effect_eMagn_FRECUENCIA_r1_ESPERA_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_FRECUENCIA_r1_ESPERA(handle);
	prefix_enseq_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_default(handle);
}

static void prefix_effect_eMagn_TENSION_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_TENSION(handle);
	prefix_enseq_eMagn_FRECUENCIA_default(handle);
}

static void prefix_effect_eMagn_TENSION_r1_TENSION_ACTUAL_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_TENSION_r1_TENSION_ACTUAL(handle);
	prefix_enseq_eMagn_TENSION_r1_DISMINUYE_default(handle);
}

static void prefix_effect_eMagn_TENSION_r1_TENSION_ACTUAL_tr1(Prefix* handle)
{
	prefix_exseq_eMagn_TENSION_r1_TENSION_ACTUAL(handle);
	prefix_enseq_eMagn_TENSION_r1_AUMENTA_default(handle);
}

static void prefix_effect_eMagn_TENSION_r1_DISMINUYE_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_TENSION_r1_DISMINUYE(handle);
	prefix_enseq_eMagn_TENSION_r1_DELAY_default(handle);
}

static void prefix_effect_eMagn_TENSION_r1_DELAY_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_TENSION_r1_DELAY(handle);
	prefix_enseq_eMagn_TENSION_r1_TENSION_ACTUAL_default(handle);
}

static void prefix_effect_eMagn_TENSION_r1_AUMENTA_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_TENSION_r1_AUMENTA(handle);
	prefix_enseq_eMagn_TENSION_r1_ESPERA_default(handle);
}

static void prefix_effect_eMagn_TENSION_r1_ESPERA_tr0(Prefix* handle)
{
	prefix_exseq_eMagn_TENSION_r1_ESPERA(handle);
	prefix_enseq_eMagn_TENSION_r1_TENSION_ACTUAL_default(handle);
}

/* Entry action for state 'DEBOUNCE'. */
static void prefix_enact_TECX_DEBOUNCE(Prefix* handle)
{
	/* Entry action for state 'DEBOUNCE'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised) , 50, bool_false);
}

/* Entry action for state 'NO_OPRIMIDO'. */
static void prefix_enact_TECX_NO_OPRIMIDO(Prefix* handle)
{
	/* Entry action for state 'NO_OPRIMIDO'. */
	handle->iface.flag_tecla = bool_false;
}

/* Entry action for state 'OPRIMIDO'. */
static void prefix_enact_TECX_OPRIMIDO(Prefix* handle)
{
	/* Entry action for state 'OPRIMIDO'. */
	handle->internal.siTECXOK_raised = bool_true;
	handle->internal.viTecla = handle->iface.evTECXOprimido_value;
}

/* Entry action for state 'VALIDACION'. */
static void prefix_enact_TECX_VALIDACION(Prefix* handle)
{
	/* Entry action for state 'VALIDACION'. */
	handle->iface.flag_tecla = bool_false;
}

/* Entry action for state 'senoidal'. */
static void prefix_enact_eForma_senoidal(Prefix* handle)
{
	/* Entry action for state 'senoidal'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_ON);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'cuadrada'. */
static void prefix_enact_eForma_cuadrada(Prefix* handle)
{
	/* Entry action for state 'cuadrada'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_ON);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'triangular'. */
static void prefix_enact_eForma_triangular(Prefix* handle)
{
	/* Entry action for state 'triangular'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDR, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDG, PREFIX_PREFIXIFACE_LED_OFF);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LEDB, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'FRECUENCIA ACTUAL'. */
static void prefix_enact_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(Prefix* handle)
{
	/* Entry action for state 'FRECUENCIA ACTUAL'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED1, PREFIX_PREFIXIFACE_LED_ON);
}

/* Entry action for state 'DISMINUYE'. */
static void prefix_enact_eMagn_FRECUENCIA_r1_DISMINUYE(Prefix* handle)
{
	/* Entry action for state 'DISMINUYE'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_DISMINUYE_tev0_raised) , 1000, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED2, PREFIX_PREFIXIFACE_LED_ON);
	handle->iface.frecuencia = handle->iface.frecuencia - 10;
}

/* Entry action for state 'DELAY'. */
static void prefix_enact_eMagn_FRECUENCIA_r1_DELAY(Prefix* handle)
{
	/* Entry action for state 'DELAY'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_DELAY_tev0_raised) , 50, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED2, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'AUMENTA'. */
static void prefix_enact_eMagn_FRECUENCIA_r1_AUMENTA(Prefix* handle)
{
	/* Entry action for state 'AUMENTA'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_AUMENTA_tev0_raised) , 1000, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_ON);
	handle->iface.frecuencia = handle->iface.frecuencia + 10;
}

/* Entry action for state 'ESPERA'. */
static void prefix_enact_eMagn_FRECUENCIA_r1_ESPERA(Prefix* handle)
{
	/* Entry action for state 'ESPERA'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_ESPERA_tev0_raised) , 50, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'TENSION ACTUAL'. */
static void prefix_enact_eMagn_TENSION_r1_TENSION_ACTUAL(Prefix* handle)
{
	/* Entry action for state 'TENSION ACTUAL'. */
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED1, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'DISMINUYE'. */
static void prefix_enact_eMagn_TENSION_r1_DISMINUYE(Prefix* handle)
{
	/* Entry action for state 'DISMINUYE'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_TENSION_r1_DISMINUYE_tev0_raised) , 1000, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED2, PREFIX_PREFIXIFACE_LED_ON);
	handle->iface.tension = handle->iface.tension - 1;
}

/* Entry action for state 'DELAY'. */
static void prefix_enact_eMagn_TENSION_r1_DELAY(Prefix* handle)
{
	/* Entry action for state 'DELAY'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_TENSION_r1_DELAY_tev0_raised) , 50, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED2, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Entry action for state 'AUMENTA'. */
static void prefix_enact_eMagn_TENSION_r1_AUMENTA(Prefix* handle)
{
	/* Entry action for state 'AUMENTA'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_TENSION_r1_AUMENTA_tev0_raised) , 1000, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_ON);
	handle->iface.tension = handle->iface.tension + 1;
}

/* Entry action for state 'ESPERA'. */
static void prefix_enact_eMagn_TENSION_r1_ESPERA(Prefix* handle)
{
	/* Entry action for state 'ESPERA'. */
	prefix_setTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_TENSION_r1_ESPERA_tev0_raised) , 50, bool_false);
	prefixIface_opLED(handle, PREFIX_PREFIXIFACE_LED3, PREFIX_PREFIXIFACE_LED_OFF);
}

/* Exit action for state 'DEBOUNCE'. */
static void prefix_exact_TECX_DEBOUNCE(Prefix* handle)
{
	/* Exit action for state 'DEBOUNCE'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_TECX_DEBOUNCE_tev0_raised) );		
}

/* Exit action for state 'DISMINUYE'. */
static void prefix_exact_eMagn_FRECUENCIA_r1_DISMINUYE(Prefix* handle)
{
	/* Exit action for state 'DISMINUYE'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_DISMINUYE_tev0_raised) );		
}

/* Exit action for state 'DELAY'. */
static void prefix_exact_eMagn_FRECUENCIA_r1_DELAY(Prefix* handle)
{
	/* Exit action for state 'DELAY'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_DELAY_tev0_raised) );		
}

/* Exit action for state 'AUMENTA'. */
static void prefix_exact_eMagn_FRECUENCIA_r1_AUMENTA(Prefix* handle)
{
	/* Exit action for state 'AUMENTA'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_AUMENTA_tev0_raised) );		
}

/* Exit action for state 'ESPERA'. */
static void prefix_exact_eMagn_FRECUENCIA_r1_ESPERA(Prefix* handle)
{
	/* Exit action for state 'ESPERA'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_FRECUENCIA_r1_ESPERA_tev0_raised) );		
}

/* Exit action for state 'DISMINUYE'. */
static void prefix_exact_eMagn_TENSION_r1_DISMINUYE(Prefix* handle)
{
	/* Exit action for state 'DISMINUYE'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_TENSION_r1_DISMINUYE_tev0_raised) );		
}

/* Exit action for state 'DELAY'. */
static void prefix_exact_eMagn_TENSION_r1_DELAY(Prefix* handle)
{
	/* Exit action for state 'DELAY'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_TENSION_r1_DELAY_tev0_raised) );		
}

/* Exit action for state 'AUMENTA'. */
static void prefix_exact_eMagn_TENSION_r1_AUMENTA(Prefix* handle)
{
	/* Exit action for state 'AUMENTA'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_TENSION_r1_AUMENTA_tev0_raised) );		
}

/* Exit action for state 'ESPERA'. */
static void prefix_exact_eMagn_TENSION_r1_ESPERA(Prefix* handle)
{
	/* Exit action for state 'ESPERA'. */
	prefix_unsetTimer(handle, (sc_eventid) &(handle->timeEvents.prefix_eMagn_TENSION_r1_ESPERA_tev0_raised) );		
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
	prefix_enact_TECX_NO_OPRIMIDO(handle);
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
	prefix_enact_TECX_VALIDACION(handle);
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

/* 'default' enter sequence for state senoidal */
static void prefix_enseq_eForma_senoidal_default(Prefix* handle)
{
	/* 'default' enter sequence for state senoidal */
	prefix_enact_eForma_senoidal(handle);
	handle->stateConfVector[2] = Prefix_eForma_senoidal;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state cuadrada */
static void prefix_enseq_eForma_cuadrada_default(Prefix* handle)
{
	/* 'default' enter sequence for state cuadrada */
	prefix_enact_eForma_cuadrada(handle);
	handle->stateConfVector[2] = Prefix_eForma_cuadrada;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state triangular */
static void prefix_enseq_eForma_triangular_default(Prefix* handle)
{
	/* 'default' enter sequence for state triangular */
	prefix_enact_eForma_triangular(handle);
	handle->stateConfVector[2] = Prefix_eForma_triangular;
	handle->stateConfVectorPosition = 2;
}

/* 'default' enter sequence for state FRECUENCIA */
static void prefix_enseq_eMagn_FRECUENCIA_default(Prefix* handle)
{
	/* 'default' enter sequence for state FRECUENCIA */
	prefix_enseq_eMagn_FRECUENCIA_r1_default(handle);
}

/* 'default' enter sequence for state FRECUENCIA ACTUAL */
static void prefix_enseq_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_default(Prefix* handle)
{
	/* 'default' enter sequence for state FRECUENCIA ACTUAL */
	prefix_enact_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(handle);
	handle->stateConfVector[3] = Prefix_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state DISMINUYE */
static void prefix_enseq_eMagn_FRECUENCIA_r1_DISMINUYE_default(Prefix* handle)
{
	/* 'default' enter sequence for state DISMINUYE */
	prefix_enact_eMagn_FRECUENCIA_r1_DISMINUYE(handle);
	handle->stateConfVector[3] = Prefix_eMagn_FRECUENCIA_r1_DISMINUYE;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state DELAY */
static void prefix_enseq_eMagn_FRECUENCIA_r1_DELAY_default(Prefix* handle)
{
	/* 'default' enter sequence for state DELAY */
	prefix_enact_eMagn_FRECUENCIA_r1_DELAY(handle);
	handle->stateConfVector[3] = Prefix_eMagn_FRECUENCIA_r1_DELAY;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state AUMENTA */
static void prefix_enseq_eMagn_FRECUENCIA_r1_AUMENTA_default(Prefix* handle)
{
	/* 'default' enter sequence for state AUMENTA */
	prefix_enact_eMagn_FRECUENCIA_r1_AUMENTA(handle);
	handle->stateConfVector[3] = Prefix_eMagn_FRECUENCIA_r1_AUMENTA;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state ESPERA */
static void prefix_enseq_eMagn_FRECUENCIA_r1_ESPERA_default(Prefix* handle)
{
	/* 'default' enter sequence for state ESPERA */
	prefix_enact_eMagn_FRECUENCIA_r1_ESPERA(handle);
	handle->stateConfVector[3] = Prefix_eMagn_FRECUENCIA_r1_ESPERA;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state TENSION */
static void prefix_enseq_eMagn_TENSION_default(Prefix* handle)
{
	/* 'default' enter sequence for state TENSION */
	prefix_enseq_eMagn_TENSION_r1_default(handle);
}

/* 'default' enter sequence for state TENSION ACTUAL */
static void prefix_enseq_eMagn_TENSION_r1_TENSION_ACTUAL_default(Prefix* handle)
{
	/* 'default' enter sequence for state TENSION ACTUAL */
	prefix_enact_eMagn_TENSION_r1_TENSION_ACTUAL(handle);
	handle->stateConfVector[3] = Prefix_eMagn_TENSION_r1_TENSION_ACTUAL;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state DISMINUYE */
static void prefix_enseq_eMagn_TENSION_r1_DISMINUYE_default(Prefix* handle)
{
	/* 'default' enter sequence for state DISMINUYE */
	prefix_enact_eMagn_TENSION_r1_DISMINUYE(handle);
	handle->stateConfVector[3] = Prefix_eMagn_TENSION_r1_DISMINUYE;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state DELAY */
static void prefix_enseq_eMagn_TENSION_r1_DELAY_default(Prefix* handle)
{
	/* 'default' enter sequence for state DELAY */
	prefix_enact_eMagn_TENSION_r1_DELAY(handle);
	handle->stateConfVector[3] = Prefix_eMagn_TENSION_r1_DELAY;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state AUMENTA */
static void prefix_enseq_eMagn_TENSION_r1_AUMENTA_default(Prefix* handle)
{
	/* 'default' enter sequence for state AUMENTA */
	prefix_enact_eMagn_TENSION_r1_AUMENTA(handle);
	handle->stateConfVector[3] = Prefix_eMagn_TENSION_r1_AUMENTA;
	handle->stateConfVectorPosition = 3;
}

/* 'default' enter sequence for state ESPERA */
static void prefix_enseq_eMagn_TENSION_r1_ESPERA_default(Prefix* handle)
{
	/* 'default' enter sequence for state ESPERA */
	prefix_enact_eMagn_TENSION_r1_ESPERA(handle);
	handle->stateConfVector[3] = Prefix_eMagn_TENSION_r1_ESPERA;
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

/* 'default' enter sequence for region eMagn */
static void prefix_enseq_eMagn_default(Prefix* handle)
{
	/* 'default' enter sequence for region eMagn */
	prefix_react_eMagn__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void prefix_enseq_eMagn_FRECUENCIA_r1_default(Prefix* handle)
{
	/* 'default' enter sequence for region r1 */
	prefix_react_eMagn_FRECUENCIA_r1__entry_Default(handle);
}

/* 'default' enter sequence for region r1 */
static void prefix_enseq_eMagn_TENSION_r1_default(Prefix* handle)
{
	/* 'default' enter sequence for region r1 */
	prefix_react_eMagn_TENSION_r1__entry_Default(handle);
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

/* Default exit sequence for state senoidal */
static void prefix_exseq_eForma_senoidal(Prefix* handle)
{
	/* Default exit sequence for state senoidal */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state cuadrada */
static void prefix_exseq_eForma_cuadrada(Prefix* handle)
{
	/* Default exit sequence for state cuadrada */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state triangular */
static void prefix_exseq_eForma_triangular(Prefix* handle)
{
	/* Default exit sequence for state triangular */
	handle->stateConfVector[2] = Prefix_last_state;
	handle->stateConfVectorPosition = 2;
}

/* Default exit sequence for state FRECUENCIA */
static void prefix_exseq_eMagn_FRECUENCIA(Prefix* handle)
{
	/* Default exit sequence for state FRECUENCIA */
	prefix_exseq_eMagn_FRECUENCIA_r1(handle);
}

/* Default exit sequence for state FRECUENCIA ACTUAL */
static void prefix_exseq_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(Prefix* handle)
{
	/* Default exit sequence for state FRECUENCIA ACTUAL */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state DISMINUYE */
static void prefix_exseq_eMagn_FRECUENCIA_r1_DISMINUYE(Prefix* handle)
{
	/* Default exit sequence for state DISMINUYE */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
	prefix_exact_eMagn_FRECUENCIA_r1_DISMINUYE(handle);
}

/* Default exit sequence for state DELAY */
static void prefix_exseq_eMagn_FRECUENCIA_r1_DELAY(Prefix* handle)
{
	/* Default exit sequence for state DELAY */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
	prefix_exact_eMagn_FRECUENCIA_r1_DELAY(handle);
}

/* Default exit sequence for state AUMENTA */
static void prefix_exseq_eMagn_FRECUENCIA_r1_AUMENTA(Prefix* handle)
{
	/* Default exit sequence for state AUMENTA */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
	prefix_exact_eMagn_FRECUENCIA_r1_AUMENTA(handle);
}

/* Default exit sequence for state ESPERA */
static void prefix_exseq_eMagn_FRECUENCIA_r1_ESPERA(Prefix* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
	prefix_exact_eMagn_FRECUENCIA_r1_ESPERA(handle);
}

/* Default exit sequence for state TENSION */
static void prefix_exseq_eMagn_TENSION(Prefix* handle)
{
	/* Default exit sequence for state TENSION */
	prefix_exseq_eMagn_TENSION_r1(handle);
}

/* Default exit sequence for state TENSION ACTUAL */
static void prefix_exseq_eMagn_TENSION_r1_TENSION_ACTUAL(Prefix* handle)
{
	/* Default exit sequence for state TENSION ACTUAL */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
}

/* Default exit sequence for state DISMINUYE */
static void prefix_exseq_eMagn_TENSION_r1_DISMINUYE(Prefix* handle)
{
	/* Default exit sequence for state DISMINUYE */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
	prefix_exact_eMagn_TENSION_r1_DISMINUYE(handle);
}

/* Default exit sequence for state DELAY */
static void prefix_exseq_eMagn_TENSION_r1_DELAY(Prefix* handle)
{
	/* Default exit sequence for state DELAY */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
	prefix_exact_eMagn_TENSION_r1_DELAY(handle);
}

/* Default exit sequence for state AUMENTA */
static void prefix_exseq_eMagn_TENSION_r1_AUMENTA(Prefix* handle)
{
	/* Default exit sequence for state AUMENTA */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
	prefix_exact_eMagn_TENSION_r1_AUMENTA(handle);
}

/* Default exit sequence for state ESPERA */
static void prefix_exseq_eMagn_TENSION_r1_ESPERA(Prefix* handle)
{
	/* Default exit sequence for state ESPERA */
	handle->stateConfVector[3] = Prefix_last_state;
	handle->stateConfVectorPosition = 3;
	prefix_exact_eMagn_TENSION_r1_ESPERA(handle);
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
		case Prefix_eForma_senoidal :
		{
			prefix_exseq_eForma_senoidal(handle);
			break;
		}
		case Prefix_eForma_cuadrada :
		{
			prefix_exseq_eForma_cuadrada(handle);
			break;
		}
		case Prefix_eForma_triangular :
		{
			prefix_exseq_eForma_triangular(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region eMagn */
static void prefix_exseq_eMagn(Prefix* handle)
{
	/* Default exit sequence for region eMagn */
	/* Handle exit of all possible states (of prefix.eMagn) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Prefix_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL :
		{
			prefix_exseq_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_DISMINUYE :
		{
			prefix_exseq_eMagn_FRECUENCIA_r1_DISMINUYE(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_DELAY :
		{
			prefix_exseq_eMagn_FRECUENCIA_r1_DELAY(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_AUMENTA :
		{
			prefix_exseq_eMagn_FRECUENCIA_r1_AUMENTA(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_ESPERA :
		{
			prefix_exseq_eMagn_FRECUENCIA_r1_ESPERA(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_TENSION_ACTUAL :
		{
			prefix_exseq_eMagn_TENSION_r1_TENSION_ACTUAL(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_DISMINUYE :
		{
			prefix_exseq_eMagn_TENSION_r1_DISMINUYE(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_DELAY :
		{
			prefix_exseq_eMagn_TENSION_r1_DELAY(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_AUMENTA :
		{
			prefix_exseq_eMagn_TENSION_r1_AUMENTA(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_ESPERA :
		{
			prefix_exseq_eMagn_TENSION_r1_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void prefix_exseq_eMagn_FRECUENCIA_r1(Prefix* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of prefix.eMagn.FRECUENCIA.r1) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Prefix_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL :
		{
			prefix_exseq_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_DISMINUYE :
		{
			prefix_exseq_eMagn_FRECUENCIA_r1_DISMINUYE(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_DELAY :
		{
			prefix_exseq_eMagn_FRECUENCIA_r1_DELAY(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_AUMENTA :
		{
			prefix_exseq_eMagn_FRECUENCIA_r1_AUMENTA(handle);
			break;
		}
		case Prefix_eMagn_FRECUENCIA_r1_ESPERA :
		{
			prefix_exseq_eMagn_FRECUENCIA_r1_ESPERA(handle);
			break;
		}
		default: break;
	}
}

/* Default exit sequence for region r1 */
static void prefix_exseq_eMagn_TENSION_r1(Prefix* handle)
{
	/* Default exit sequence for region r1 */
	/* Handle exit of all possible states (of prefix.eMagn.TENSION.r1) at position 3... */
	switch(handle->stateConfVector[ 3 ])
	{
		case Prefix_eMagn_TENSION_r1_TENSION_ACTUAL :
		{
			prefix_exseq_eMagn_TENSION_r1_TENSION_ACTUAL(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_DISMINUYE :
		{
			prefix_exseq_eMagn_TENSION_r1_DISMINUYE(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_DELAY :
		{
			prefix_exseq_eMagn_TENSION_r1_DELAY(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_AUMENTA :
		{
			prefix_exseq_eMagn_TENSION_r1_AUMENTA(handle);
			break;
		}
		case Prefix_eMagn_TENSION_r1_ESPERA :
		{
			prefix_exseq_eMagn_TENSION_r1_ESPERA(handle);
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
			}  else
			{
				if (prefix_check_Application_ESPERA_tr3_tr3(handle) == bool_true)
				{ 
					prefix_effect_Application_ESPERA_tr3(handle);
				} 
			}
		}
	}
}

/* The reactions of state senoidal. */
static void prefix_react_eForma_senoidal(Prefix* handle)
{
	/* The reactions of state senoidal. */
	if (prefix_check_eForma_senoidal_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eForma_senoidal_tr0(handle);
	} 
}

/* The reactions of state cuadrada. */
static void prefix_react_eForma_cuadrada(Prefix* handle)
{
	/* The reactions of state cuadrada. */
	if (prefix_check_eForma_cuadrada_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eForma_cuadrada_tr0(handle);
	} 
}

/* The reactions of state triangular. */
static void prefix_react_eForma_triangular(Prefix* handle)
{
	/* The reactions of state triangular. */
	if (prefix_check_eForma_triangular_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eForma_triangular_tr0(handle);
	} 
}

/* The reactions of state FRECUENCIA ACTUAL. */
static void prefix_react_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL(Prefix* handle)
{
	/* The reactions of state FRECUENCIA ACTUAL. */
	if (prefix_check_eMagn_FRECUENCIA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eMagn_FRECUENCIA_tr0(handle);
	}  else
	{
		if (prefix_check_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr0(handle);
		}  else
		{
			if (prefix_check_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr1_tr1(handle) == bool_true)
			{ 
				prefix_effect_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_tr1(handle);
			} 
		}
	}
}

/* The reactions of state DISMINUYE. */
static void prefix_react_eMagn_FRECUENCIA_r1_DISMINUYE(Prefix* handle)
{
	/* The reactions of state DISMINUYE. */
	if (prefix_check_eMagn_FRECUENCIA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eMagn_FRECUENCIA_tr0(handle);
	}  else
	{
		if (prefix_check_eMagn_FRECUENCIA_r1_DISMINUYE_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_eMagn_FRECUENCIA_r1_DISMINUYE_tr0(handle);
		} 
	}
}

/* The reactions of state DELAY. */
static void prefix_react_eMagn_FRECUENCIA_r1_DELAY(Prefix* handle)
{
	/* The reactions of state DELAY. */
	if (prefix_check_eMagn_FRECUENCIA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eMagn_FRECUENCIA_tr0(handle);
	}  else
	{
		if (prefix_check_eMagn_FRECUENCIA_r1_DELAY_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_eMagn_FRECUENCIA_r1_DELAY_tr0(handle);
		} 
	}
}

/* The reactions of state AUMENTA. */
static void prefix_react_eMagn_FRECUENCIA_r1_AUMENTA(Prefix* handle)
{
	/* The reactions of state AUMENTA. */
	if (prefix_check_eMagn_FRECUENCIA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eMagn_FRECUENCIA_tr0(handle);
	}  else
	{
		if (prefix_check_eMagn_FRECUENCIA_r1_AUMENTA_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_eMagn_FRECUENCIA_r1_AUMENTA_tr0(handle);
		} 
	}
}

/* The reactions of state ESPERA. */
static void prefix_react_eMagn_FRECUENCIA_r1_ESPERA(Prefix* handle)
{
	/* The reactions of state ESPERA. */
	if (prefix_check_eMagn_FRECUENCIA_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eMagn_FRECUENCIA_tr0(handle);
	}  else
	{
		if (prefix_check_eMagn_FRECUENCIA_r1_ESPERA_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_eMagn_FRECUENCIA_r1_ESPERA_tr0(handle);
		} 
	}
}

/* The reactions of state TENSION ACTUAL. */
static void prefix_react_eMagn_TENSION_r1_TENSION_ACTUAL(Prefix* handle)
{
	/* The reactions of state TENSION ACTUAL. */
	if (prefix_check_eMagn_TENSION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eMagn_TENSION_tr0(handle);
	}  else
	{
		if (prefix_check_eMagn_TENSION_r1_TENSION_ACTUAL_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_eMagn_TENSION_r1_TENSION_ACTUAL_tr0(handle);
		}  else
		{
			if (prefix_check_eMagn_TENSION_r1_TENSION_ACTUAL_tr1_tr1(handle) == bool_true)
			{ 
				prefix_effect_eMagn_TENSION_r1_TENSION_ACTUAL_tr1(handle);
			} 
		}
	}
}

/* The reactions of state DISMINUYE. */
static void prefix_react_eMagn_TENSION_r1_DISMINUYE(Prefix* handle)
{
	/* The reactions of state DISMINUYE. */
	if (prefix_check_eMagn_TENSION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eMagn_TENSION_tr0(handle);
	}  else
	{
		if (prefix_check_eMagn_TENSION_r1_DISMINUYE_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_eMagn_TENSION_r1_DISMINUYE_tr0(handle);
		} 
	}
}

/* The reactions of state DELAY. */
static void prefix_react_eMagn_TENSION_r1_DELAY(Prefix* handle)
{
	/* The reactions of state DELAY. */
	if (prefix_check_eMagn_TENSION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eMagn_TENSION_tr0(handle);
	}  else
	{
		if (prefix_check_eMagn_TENSION_r1_DELAY_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_eMagn_TENSION_r1_DELAY_tr0(handle);
		} 
	}
}

/* The reactions of state AUMENTA. */
static void prefix_react_eMagn_TENSION_r1_AUMENTA(Prefix* handle)
{
	/* The reactions of state AUMENTA. */
	if (prefix_check_eMagn_TENSION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eMagn_TENSION_tr0(handle);
	}  else
	{
		if (prefix_check_eMagn_TENSION_r1_AUMENTA_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_eMagn_TENSION_r1_AUMENTA_tr0(handle);
		} 
	}
}

/* The reactions of state ESPERA. */
static void prefix_react_eMagn_TENSION_r1_ESPERA(Prefix* handle)
{
	/* The reactions of state ESPERA. */
	if (prefix_check_eMagn_TENSION_tr0_tr0(handle) == bool_true)
	{ 
		prefix_effect_eMagn_TENSION_tr0(handle);
	}  else
	{
		if (prefix_check_eMagn_TENSION_r1_ESPERA_tr0_tr0(handle) == bool_true)
		{ 
			prefix_effect_eMagn_TENSION_r1_ESPERA_tr0(handle);
		} 
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
	prefix_enseq_eForma_senoidal_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_eMagn__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_eMagn_FRECUENCIA_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_eMagn_FRECUENCIA_r1__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_eMagn_FRECUENCIA_r1_FRECUENCIA_ACTUAL_default(handle);
}

/* Default react sequence for initial entry  */
static void prefix_react_eMagn_TENSION_r1__entry_Default(Prefix* handle)
{
	/* Default react sequence for initial entry  */
	prefix_enseq_eMagn_TENSION_r1_TENSION_ACTUAL_default(handle);
}


