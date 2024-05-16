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
double _constant1__out = 0.037007684712566;
double _constant2__out = 1.0;
double _step1__out;
double _step2__out;
double _vout_va1__out;
double _ss__A_values[4] = {0.9994203957488299, -0.02407015615907818, 0.04814031231815637, 0.9994204596242737};
X_Int32 _ss__A_indices[4] = {0, 1, 0, 1};
double _ss__B_values[2] = {3.382037762993528, -0.33398230717508204};
X_Int32 _ss__B_indices[2] = {0, 0};
;
double _ss__C_values[1] = {1.0};
X_Int32 _ss__C_indices[1] = {1};
double _ss__out;
double _ss__y1[1];
double _ss__y2[1];

double _ss__x1_new[2];
double _ss__x2_new[2];
double _ss__x_new[2];
double _sum1__out;
double _sum4__out;
double _k__out;
double _k1__out;
double _lead__out;
double _lead__pi_reg_out_int;
double _lead__derivative;
double _lead1__out;
double _lead1__pi_reg_out_int;
double _lead1__derivative;
double _lag__out;
double _lag__pi_reg_out_int;
double _lag1__out;
double _lag1__pi_reg_out_int;
double _sum2__out;
X_UnInt32 _flyback1_pwm_modulator__channels[1] = {0};
double _flyback1_pwm_modulator__limited_in[1];
X_UnInt32 _flyback1_pwm_modulator__update_mask;

//@cmp.var.end

//@cmp.svar.start
// state variables
double _step1__state;
double _step2__state;
double _ss__x[2];
double _lead__integrator_state;
double _lead__filter_state;
double _lead1__integrator_state;
double _lead1__filter_state;
double _lag__integrator_state;
X_Int32 _lag__av_active;
double _lag__filter_state;
double _lag1__integrator_state;
X_Int32 _lag1__av_active;
double _lag1__filter_state;//@cmp.svar.end

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
    _step1__state = 0x0;
    _step2__state = 0x0;
    double _ss__initial_conditions[2] = {0.0, 0.0};
    _ss__x[0] = _ss__initial_conditions[0];
    _ss__x[1] = _ss__initial_conditions[1];
    HIL_OutAO(0x4001, 0.0f);
    _lead__integrator_state =  0.0;
    _lead__filter_state =  0.0;
    _lead1__integrator_state =  0.0;
    _lead1__filter_state =  0.0;
    _lag__integrator_state =  0.0;
    _lag__filter_state =  0.0;
    _lag1__integrator_state =  0.0;
    _lag1__filter_state =  0.0;
    _flyback1_pwm_modulator__update_mask = 1;
    HIL_OutInt32(0x2000080 + _flyback1_pwm_modulator__channels[0], 80000); // divide by 2 is already implemented in hw
    HIL_OutInt32(0x20000c0 + _flyback1_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x20001c0 + _flyback1_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000200 + _flyback1_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000240 + _flyback1_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000300 + _flyback1_pwm_modulator__channels[0], 1);
    HIL_OutInt32(0x2000340 + _flyback1_pwm_modulator__channels[0], 0);
    HIL_OutInt32(0x2000140, _flyback1_pwm_modulator__update_mask);
    HIL_OutAO(0x4000, 0.0f);
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
    // Generated from the component: Constant1
    // Generated from the component: Constant2
//////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: Step1
    if (_step1__state < 0.0) {
        _step1__out = 0.0;
    } else {
        _step1__out = 5.0;
    }
    // Generated from the component: Step2
    if (_step2__state < 0.0) {
        _step2__out = 0.0;
    } else {
        _step2__out = 5.0;
    }
    // Generated from the component: Vout.Va1
    _vout_va1__out = (HIL_InFloat(0xc80000 + 0x4));
    // Generated from the component: ss
    _ss__y1[0] = _ss__C_values[0] * _ss__x[_ss__C_indices[0]];
    _ss__y2[0] = 0;
    _ss__out = _ss__y1[0] +  _ss__y2[0];;
    // Generated from the component: Sum1
    _sum1__out = _step1__out - _vout_va1__out;
    // Generated from the component: Probe2
    HIL_OutAO(0x4001, (float)_ss__out);
    // Generated from the component: Sum4
    _sum4__out = _step2__out - _ss__out;
    // Generated from the component: k
    _k__out = 0.030199450595804 * _sum1__out;
    // Generated from the component: k1
    _k1__out = 0.030199450595804 * _sum4__out;
    // Generated from the component: Lead
    _lead__derivative = (114.57992326153034 * _k__out - _lead__filter_state) * 1799954.3071552312;
    _lead__pi_reg_out_int = 0.008726867790757915 * _k__out + _lead__derivative;
    _lead__out = _lead__pi_reg_out_int;
    // Generated from the component: Lead1
    _lead1__derivative = (114.57992326153034 * _k1__out - _lead1__filter_state) * 1799954.3071552312;
    _lead1__pi_reg_out_int = 0.008726867790757915 * _k1__out + _lead1__derivative;
    _lead1__out = _lead1__pi_reg_out_int;
    // Generated from the component: Lag
    _lag__pi_reg_out_int = _lag__integrator_state + 1.0 * _lead__out;
    if (_lag__pi_reg_out_int < 0.0)
        _lag__av_active = -1;
    else if (_lag__pi_reg_out_int > 1.0)
        _lag__av_active = 1;
    else
        _lag__av_active = 0;
    _lag__out = MIN(MAX(_lag__pi_reg_out_int, 0.0), 1.0);
    // Generated from the component: Lag1
    _lag1__pi_reg_out_int = _lag1__integrator_state + 1.0 * _lead1__out;
    if (_lag1__pi_reg_out_int < 0.0)
        _lag1__av_active = -1;
    else if (_lag1__pi_reg_out_int > 1.0)
        _lag1__av_active = 1;
    else
        _lag1__av_active = 0;
    _lag1__out = MIN(MAX(_lag1__pi_reg_out_int, 0.0), 1.0);
    // Generated from the component: Sum2
    _sum2__out = _lag__out + _constant1__out;
    // Generated from the component: Flyback1.PWM_Modulator
    _flyback1_pwm_modulator__limited_in[0] = MIN(MAX(_sum2__out, 0.0), 1.0);
    HIL_OutInt32(0x2000040 + _flyback1_pwm_modulator__channels[0], ((X_UnInt32)((_flyback1_pwm_modulator__limited_in[0] - (0.0)) * 80000.0)));
    if (_constant2__out == 0x0) {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _flyback1_pwm_modulator__channels[0], 0x0);
    }
    else {
        // pwm_modulator_en
        HIL_OutInt32(0x2000000 + _flyback1_pwm_modulator__channels[0], 0x1);
    }
    HIL_OutInt32(0x2000140, _flyback1_pwm_modulator__update_mask);
    // Generated from the component: Probe1
    HIL_OutAO(0x4000, (float)_sum2__out);
//@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: Step1
    if (_step1__state <= 0.0)
        _step1__state += 0.0001;
    // Generated from the component: Step2
    if (_step2__state <= 0.0)
        _step2__state += 0.0001;
    // Generated from the component: ss
    _ss__x1_new[0] = _ss__A_values[0] * _ss__x[_ss__A_indices[0]];
    _ss__x1_new[0] = _ss__x1_new[0] + _ss__A_values[1] * _ss__x[_ss__A_indices[1]];
    _ss__x1_new[1] = _ss__A_values[2] * _ss__x[_ss__A_indices[2]];
    _ss__x1_new[1] = _ss__x1_new[1] + _ss__A_values[3] * _ss__x[_ss__A_indices[3]];
    _ss__x2_new[0] = _ss__B_values[0] * _lag1__out;
    _ss__x2_new[1] = _ss__B_values[1] * _lag1__out;
    _ss__x_new[0] = _ss__x1_new[0] +  _ss__x2_new[0];
    _ss__x_new[1] = _ss__x1_new[1] +  _ss__x2_new[1];
    _ss__x[0] = _ss__x_new[0];
    _ss__x[1] = _ss__x_new[1];
    // Generated from the component: Lead
    _lead__filter_state += _lead__derivative * 0.0001;
    // Generated from the component: Lead1
    _lead1__filter_state += _lead1__derivative * 0.0001;
    // Generated from the component: Lag
    _lag__integrator_state += 1570.7963267948967 * _lead__out * 0.0001;
    // Generated from the component: Lag1
    _lag1__integrator_state += 1570.7963267948967 * _lead1__out * 0.0001;
    //@cmp.update.block.end
}
// ----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------