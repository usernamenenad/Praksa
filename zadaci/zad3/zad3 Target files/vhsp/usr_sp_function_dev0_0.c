// generated using template: cop_main.template---------------------------------------------
/******************************************************************************************
**
**  Module Name: cop_main.c
**  NOTE: Automatically generated file. DO NOT MODIFY!
**  Description:
**            Main file
**
******************************************************************************************/
// generated using template: arm/custom_include.template-----------------------------------


#ifdef __cplusplus
#include <limits>

extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <complex.h>

// x86 libraries:
#include "../include/sp_functions_dev0.h"


#ifdef __cplusplus
}
#endif


// ----------------------------------------------------------------------------------------                // generated using template:generic_macros.template-----------------------------------------
/*********************** Macros (Inline Functions) Definitions ***************************/

// ----------------------------------------------------------------------------------------

#ifndef MAX
#define MAX(value, limit) (((value) > (limit)) ? (value) : (limit))
#endif
#ifndef MIN
#define MIN(value, limit) (((value) < (limit)) ? (value) : (limit))
#endif

// generated using template: VirtualHIL/custom_defines.template----------------------------

typedef unsigned char X_UnInt8;
typedef char X_Int8;
typedef signed short X_Int16;
typedef unsigned short X_UnInt16;
typedef int X_Int32;
typedef unsigned int X_UnInt32;
typedef unsigned int uint;
typedef double real;

// ----------------------------------------------------------------------------------------
// generated using template: custom_consts.template----------------------------------------

// arithmetic constants
#define C_SQRT_2                    1.4142135623730950488016887242097f
#define C_SQRT_3                    1.7320508075688772935274463415059f
#define C_PI                        3.1415926535897932384626433832795f
#define C_E                         2.7182818284590452353602874713527f
#define C_2PI                       6.283185307179586476925286766559f

//@cmp.def.start
//component defines














//@cmp.def.end


//-----------------------------------------------------------------------------------------
// generated using template: common_variables.template-------------------------------------
// true global variables



// const variables

//@cmp.var.start
// variables
double _buck_boost_constant1__out = 0.0;
double _il_ia1__out;
double _subsystem1_constant1__out = 5.0;
double _subsystem1_sr_flip_flop1__out;
double _subsystem1_sr_flip_flop1__out_n;
double _subsystem1_fsw__out;
double _vout_va1__out;
double _buck_boost_bus_join1__out[2];
double _subsystem1_sum1__out;
double _subsystem1_pid_controller1__out;
double _subsystem1_pid_controller1__pi_reg_out_int;
double _subsystem1_comparator1__out;//@cmp.var.end

//@cmp.svar.start
// state variables
double _subsystem1_sr_flip_flop1__state;
double _subsystem1_fsw__current_phase;
double _subsystem1_pid_controller1__integrator_state;
double _subsystem1_pid_controller1__filter_state;
double _subsystem1_comparator1__state;//@cmp.svar.end

//
// Tunable parameters
//
static struct Tunable_params {
} __attribute__((__packed__)) tunable_params;

void *tunable_params_dev0_cpu0_ptr = &tunable_params;

// Dll function pointers
#if defined(_WIN64)
#else
// Define handles for loading dlls
#endif








// generated using template: virtual_hil/custom_functions.template---------------------------------
void ReInit_user_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rReInitTimer");
#endif
    //@cmp.init.block.start
    _subsystem1_sr_flip_flop1__state =  0;
    _subsystem1_fsw__current_phase = 0.0;
    HIL_OutAO(0x4000, 0.0f);
    HIL_OutInt32(0x810002e, 0x3);
    _subsystem1_pid_controller1__integrator_state =  0.0;
    _subsystem1_pid_controller1__filter_state =  0.0;
    HIL_OutAO(0x4002, 0.0f);
    _subsystem1_comparator1__state = 0.0f;
    HIL_OutAO(0x4001, 0.0f);
    //@cmp.init.block.end
}


// Dll function pointers and dll reload function
#if defined(_WIN64)
// Define method for reloading dll functions
void ReloadDllFunctions_user_sp_cpu0_dev0(void) {
    // Load each library and setup function pointers
}

void FreeDllFunctions_user_sp_cpu0_dev0(void) {
}

#else
// Define method for reloading dll functions
void ReloadDllFunctions_user_sp_cpu0_dev0(void) {
    // Load each library and setup function pointers
}

void FreeDllFunctions_user_sp_cpu0_dev0(void) {
}
#endif

void load_fmi_libraries_user_sp_cpu0_dev0(void) {
#if defined(_WIN64)
#else
#endif
}


void ReInit_sp_scope_user_sp_cpu0_dev0() {
    // initialise SP Scope buffer pointer
}
// generated using template: common_timer_counter_handler.template-------------------------

/*****************************************************************************************/
/**
* This function is the handler which performs processing for the timer counter.
* It is called from an interrupt context such that the amount of processing
* performed should be minimized.  It is called when the timer counter expires
* if interrupts are enabled.
*
*
* @param    None
*
* @return   None
*
* @note     None
*
*****************************************************************************************/

void TimerCounterHandler_0_user_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rTimerCounterHandler_0");
#endif
    //////////////////////////////////////////////////////////////////////////
    // Set tunable parameters
    //////////////////////////////////////////////////////////////////////////
    // Generated from the component: Buck-Boost.Constant1
    // Generated from the component: Subsystem1.Constant1
//////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: IL.Ia1
    _il_ia1__out = (HIL_InFloat(0xc80000 + 0x3));
    // Generated from the component: Subsystem1.SR Flip Flop1
    _subsystem1_sr_flip_flop1__out = _subsystem1_sr_flip_flop1__state;
    _subsystem1_sr_flip_flop1__out_n = _subsystem1_sr_flip_flop1__state != -1 ? !_subsystem1_sr_flip_flop1__state : -1;
    // Generated from the component: Subsystem1.fsw
    if (_subsystem1_fsw__current_phase < 0.01) {
        _subsystem1_fsw__out = 1.0;
    } else {
        _subsystem1_fsw__out = 0.0;
    }
    // Generated from the component: Vout.Va1
    _vout_va1__out = (HIL_InFloat(0xc80000 + 0x2));
    // Generated from the component: Buck-Boost.Bus_Join1
    _buck_boost_bus_join1__out[0] = _subsystem1_sr_flip_flop1__out;
    _buck_boost_bus_join1__out[1] = _buck_boost_constant1__out;
    // Generated from the component: Subsystem1.Duty
    HIL_OutAO(0x4000, (float)_subsystem1_sr_flip_flop1__out);
    // Generated from the component: Subsystem1.Sum1
    _subsystem1_sum1__out = _subsystem1_constant1__out - _vout_va1__out;
    // Generated from the component: Buck-Boost.FSM_Wrapper1
    _buck_boost_bus_join1__out[0] = (_buck_boost_bus_join1__out[0]) ? 1 : 0;
    _buck_boost_bus_join1__out[1] = (_buck_boost_bus_join1__out[1]) ? 1 : 0;
    HIL_OutInt32(0x810002f, 2 * _buck_boost_bus_join1__out[0] + 1 * _buck_boost_bus_join1__out[1]);
    // Generated from the component: Subsystem1.PID controller1
    _subsystem1_pid_controller1__pi_reg_out_int = _subsystem1_pid_controller1__integrator_state + 0.0371006381036056 * _subsystem1_sum1__out;
    _subsystem1_pid_controller1__out = _subsystem1_pid_controller1__pi_reg_out_int;
    // Generated from the component: Subsystem1.error
    HIL_OutAO(0x4002, (float)_subsystem1_sum1__out);
    // Generated from the component: Subsystem1.Comparator1
    if (_il_ia1__out < _subsystem1_pid_controller1__out) {
        _subsystem1_comparator1__out = 0;
    } else if (_il_ia1__out > _subsystem1_pid_controller1__out) {
        _subsystem1_comparator1__out = 1;
    } else {
        _subsystem1_comparator1__out = _subsystem1_comparator1__state;
    }
    // Generated from the component: Subsystem1.Imax
    HIL_OutAO(0x4001, (float)_subsystem1_pid_controller1__out);
//@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: Subsystem1.SR Flip Flop1
    if ((_subsystem1_fsw__out != 0x0) && (_subsystem1_comparator1__out == 0x0))
        _subsystem1_sr_flip_flop1__state = 1;
    else if ((_subsystem1_fsw__out == 0x0) && (_subsystem1_comparator1__out != 0x0))
        _subsystem1_sr_flip_flop1__state = 0;
    else if ((_subsystem1_fsw__out != 0x0) && (_subsystem1_comparator1__out != 0x0))
        _subsystem1_sr_flip_flop1__state = -1;
    // Generated from the component: Subsystem1.fsw
    _subsystem1_fsw__current_phase += 10000.0 * 1e-06;
    if (_subsystem1_fsw__current_phase >= 1.0f) {
        _subsystem1_fsw__current_phase -= 1.0f;
    }
    // Generated from the component: Subsystem1.PID controller1
    _subsystem1_pid_controller1__integrator_state += 8.5895228388425 * _subsystem1_sum1__out * 1e-06;
    // Generated from the component: Subsystem1.Comparator1
    if (_il_ia1__out < _subsystem1_pid_controller1__out) {
        _subsystem1_comparator1__state = 0;
    } else if (_il_ia1__out > _subsystem1_pid_controller1__out) {
        _subsystem1_comparator1__state = 1;
    }
    //@cmp.update.block.end
}
// ----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------