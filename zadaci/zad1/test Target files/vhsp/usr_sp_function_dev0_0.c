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
double _duty_ratio__out;
double _enable__out;
double _set_power__out;
X_UnInt32 _flyback_pwm_modulator__channels[1] = {0};
double _flyback_pwm_modulator__limited_in[1];
X_UnInt32 _flyback_pwm_modulator__update_mask;

//@cmp.var.end

//@cmp.svar.start
// state variables
//@cmp.svar.end

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
    HIL_OutAO(0x4000, 0.0f);
    _flyback_pwm_modulator__update_mask = 1;
    HIL_OutInt32(0x2000080 + _flyback_pwm_modulator__channels[0], 80000); // divide by 2 is already implemented in hw
    HIL_OutInt32(0x20000c0 + _flyback_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x20001c0 + _flyback_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000200 + _flyback_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000240 + _flyback_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000300 + _flyback_pwm_modulator__channels[0], 1);
    HIL_OutInt32(0x2000340 + _flyback_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000140, _flyback_pwm_modulator__update_mask);
    HIL_OutFloat(137363456, 0.0);
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
//////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: duty ratio
    _duty_ratio__out = XIo_InFloat(0x55000100);
    // Generated from the component: enable
    _enable__out = XIo_InFloat(0x55000104);
    // Generated from the component: set power
    _set_power__out = XIo_InFloat(0x55000108);
    // Generated from the component: duty ratio probe
    HIL_OutAO(0x4000, (float)_duty_ratio__out);
    // Generated from the component: Flyback.PWM_Modulator
    _flyback_pwm_modulator__limited_in[0] = MIN(MAX(_duty_ratio__out, 0.0), 1.0);
    HIL_OutInt32(0x2000040 + _flyback_pwm_modulator__channels[0], ((X_UnInt32)((_flyback_pwm_modulator__limited_in[0] - (0.0)) * 80000.0)));
    if (_enable__out == 0x0) {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _flyback_pwm_modulator__channels[0], 0x0);
    }
    else {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _flyback_pwm_modulator__channels[0], 0x1);
    }
    HIL_OutInt32(0x2000140, _flyback_pwm_modulator__update_mask);
    // Generated from the component: RL1.Vs
    HIL_OutFloat(137363456, (float) _set_power__out);
    // Generated from the component: set power probe
    HIL_OutAO(0x4001, (float)_set_power__out);
//@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    //@cmp.update.block.end
}
// ----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------