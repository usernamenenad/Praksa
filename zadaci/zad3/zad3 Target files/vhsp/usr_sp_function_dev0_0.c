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
double _compensator_constant1__out = 12.0;
X_Int32 _compensator_enable_close_loop__out;
double _compensator_sr_flip_flop1__out;
double _compensator_sr_flip_flop1__out_n;
double _compensator_slope_compensation__out;
X_Int32 _compensator_fsw__out;
double _disturbance__out;
X_Int32 _enable_disturbance__out;
double _input_voltage_input_voltage_reference__out = 12.0;
double _input_voltage_no_disturbance__out = 0.0;
double _iout_ia1__out;
double _isw_ia1__out;
double _output_power__out = 50.0;
double _output_voltage__out;
double _vout_va1__out;
double _buck_boost_bus_join1__out[2];
double _input_voltage_signal_switch1__out;
double _resistance_calculation_product1__out;
double _compensator_sum2__out;
double _input_voltage_sum1__out;
double _resistance_calculation_product2__out;
double _compensator_pid__out;
double _compensator_pid__pi_reg_out_int;
double _compensator_sum3__out;
double _compensator_gain1__out;
double _compensator_sum1__out;
double _compensator_comparator1__out;//@cmp.var.end

//@cmp.svar.start
// state variables
double _compensator_sr_flip_flop1__state;
double _compensator_slope_compensation__current_phase;
double _compensator_fsw__current_phase;
double _disturbance__current_phase;
double _compensator_pid__integrator_state;
X_Int32 _compensator_pid__av_active;
double _compensator_pid__filter_state;
double _compensator_comparator1__state;//@cmp.svar.end

//
// Tunable parameters
//
static struct Tunable_params {
    double _compensator_gain1__gain;
    double _compensator_pid__lower_sat_lim;
    double _compensator_pid__kp;
    double _compensator_pid__upper_sat_lim;
    double _compensator_pid__ki;
    double _compensator_slope_compensation__max_val;
    double _compensator_slope_compensation__phase;
    double _compensator_slope_compensation__duty_cycle;
    double _compensator_slope_compensation__min_val;
    double _compensator_slope_compensation__frequency;
    double _compensator_fsw__phase;
    double _compensator_fsw__duty_cycle;
    X_Int32 _compensator_fsw__hs_output;
    double _compensator_fsw__frequency;
    X_Int32 _compensator_fsw__ls_output;
    double _disturbance__amplitude;
    double _disturbance__phase;
    double _disturbance__frequency;
    double _disturbance__dc_offset;
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
    _compensator_sr_flip_flop1__state =  0;
    _compensator_slope_compensation__current_phase = tunable_params._compensator_slope_compensation__phase;
    _compensator_fsw__current_phase = tunable_params._compensator_fsw__phase;
    _disturbance__current_phase = tunable_params._disturbance__phase / 360.0f;
    HIL_OutAO(0x4000, 0.0f);
    HIL_OutInt32(0x810002e, 0x3);
    _compensator_pid__integrator_state =  0.0;
    _compensator_pid__filter_state =  0.0;
    HIL_OutFloat(137101312, 0.0);
    HIL_OutFloat(137363456, 0.0);
    _compensator_comparator1__state = 0.0f;
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
    // Generated from the component: Compensator.Constant1
    // Generated from the component: Input Voltage.Input voltage reference
    // Generated from the component: Input Voltage.No disturbance
    // Generated from the component: Output power
//////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: Compensator.Enable close loop
    _compensator_enable_close_loop__out = XIo_InInt32(0xfffc0000);
    // Generated from the component: Compensator.SR Flip Flop1
    _compensator_sr_flip_flop1__out = _compensator_sr_flip_flop1__state;
    _compensator_sr_flip_flop1__out_n = _compensator_sr_flip_flop1__state != -1 ? !_compensator_sr_flip_flop1__state : -1;
    // Generated from the component: Compensator.Slope compensation
    if (_compensator_slope_compensation__current_phase < tunable_params._compensator_slope_compensation__duty_cycle) {
        _compensator_slope_compensation__out = tunable_params._compensator_slope_compensation__min_val + (((tunable_params._compensator_slope_compensation__max_val) - (tunable_params._compensator_slope_compensation__min_val)) * (_compensator_slope_compensation__current_phase / tunable_params._compensator_slope_compensation__duty_cycle));
    } else {
        _compensator_slope_compensation__out = tunable_params._compensator_slope_compensation__max_val - (((tunable_params._compensator_slope_compensation__max_val) - (tunable_params._compensator_slope_compensation__min_val)) * ((_compensator_slope_compensation__current_phase - tunable_params._compensator_slope_compensation__duty_cycle) / (1.0f - tunable_params._compensator_slope_compensation__duty_cycle)));
    }
    // Generated from the component: Compensator.fsw
    if (_compensator_fsw__current_phase < tunable_params._compensator_fsw__duty_cycle) {
        _compensator_fsw__out = tunable_params._compensator_fsw__hs_output;
    } else {
        _compensator_fsw__out = tunable_params._compensator_fsw__ls_output;
    }
    // Generated from the component: Disturbance
    _disturbance__out = (tunable_params._disturbance__amplitude * sin(2.0f * M_PI * _disturbance__current_phase) + tunable_params._disturbance__dc_offset);
    // Generated from the component: Enable disturbance
    _enable_disturbance__out = XIo_InInt32(0xfffc0004);
    // Generated from the component: Iout.Ia1
    _iout_ia1__out = (HIL_InFloat(0xc80000 + 0x5));
    // Generated from the component: Isw.Ia1
    _isw_ia1__out = (HIL_InFloat(0xc80000 + 0x6));
    // Generated from the component: Output voltage
    _output_voltage__out = XIo_InFloat(0xfffc0008);
    // Generated from the component: Vout.Va1
    _vout_va1__out = (HIL_InFloat(0xc80000 + 0x4));
    // Generated from the component: Buck-Boost.Bus_Join1
    _buck_boost_bus_join1__out[0] = _compensator_sr_flip_flop1__out;
    _buck_boost_bus_join1__out[1] = _buck_boost_constant1__out;
    // Generated from the component: Compensator.Duty
    HIL_OutAO(0x4000, (float)_compensator_sr_flip_flop1__out);
    // Generated from the component: Input Voltage.Signal switch1
    _input_voltage_signal_switch1__out = (_enable_disturbance__out > 0.5) ? _disturbance__out : _input_voltage_no_disturbance__out;
    // Generated from the component: Resistance calculation.Product1
    _resistance_calculation_product1__out = (_output_voltage__out * _output_voltage__out);
    // Generated from the component: Compensator.Sum2
    _compensator_sum2__out = _output_voltage__out - _vout_va1__out;
    // Generated from the component: Buck-Boost.FSM_Wrapper1
    _buck_boost_bus_join1__out[0] = (_buck_boost_bus_join1__out[0]) ? 1 : 0;
    _buck_boost_bus_join1__out[1] = (_buck_boost_bus_join1__out[1]) ? 1 : 0;
    HIL_OutInt32(0x810002f, 2 * _buck_boost_bus_join1__out[0] + 1 * _buck_boost_bus_join1__out[1]);
    // Generated from the component: Input Voltage.Sum1
    _input_voltage_sum1__out = _input_voltage_signal_switch1__out + _input_voltage_input_voltage_reference__out;
    // Generated from the component: Resistance calculation.Product2
    _resistance_calculation_product2__out = (_resistance_calculation_product1__out) * 1.0 / (_output_power__out);
    // Generated from the component: Compensator.PID
    _compensator_pid__pi_reg_out_int = _compensator_pid__integrator_state + tunable_params._compensator_pid__kp * _compensator_sum2__out;
    if (_compensator_pid__pi_reg_out_int < tunable_params._compensator_pid__lower_sat_lim)
        _compensator_pid__av_active = -1;
    else if (_compensator_pid__pi_reg_out_int > tunable_params._compensator_pid__upper_sat_lim)
        _compensator_pid__av_active = 1;
    else
        _compensator_pid__av_active = 0;
    _compensator_pid__out = MIN(MAX(_compensator_pid__pi_reg_out_int, tunable_params._compensator_pid__lower_sat_lim), tunable_params._compensator_pid__upper_sat_lim);
    // Generated from the component: Compensator.Sum3
    _compensator_sum3__out = _compensator_constant1__out - _input_voltage_sum1__out;
    // Generated from the component: Vin.Vs1
    HIL_OutFloat(137101312, (float) _input_voltage_sum1__out);
    // Generated from the component: RLoad.Vs
    HIL_OutFloat(137363456, (float) _resistance_calculation_product2__out);
    // Generated from the component: Compensator.Gain1
    _compensator_gain1__out = tunable_params._compensator_gain1__gain * _compensator_sum3__out;
    // Generated from the component: Compensator.Sum1
    _compensator_sum1__out = _compensator_pid__out - _compensator_slope_compensation__out + _compensator_gain1__out;
    // Generated from the component: Compensator.Comparator1
    if (_isw_ia1__out < _compensator_sum1__out) {
        _compensator_comparator1__out = 0;
    } else if (_isw_ia1__out > _compensator_sum1__out) {
        _compensator_comparator1__out = 1;
    } else {
        _compensator_comparator1__out = _compensator_comparator1__state;
    }
    // Generated from the component: Compensator.Imax
    HIL_OutAO(0x4001, (float)_compensator_sum1__out);
//@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: Compensator.SR Flip Flop1
    if ((_compensator_fsw__out != 0x0) && (_compensator_comparator1__out == 0x0))
        _compensator_sr_flip_flop1__state = 1;
    else if ((_compensator_fsw__out == 0x0) && (_compensator_comparator1__out != 0x0))
        _compensator_sr_flip_flop1__state = 0;
    else if ((_compensator_fsw__out != 0x0) && (_compensator_comparator1__out != 0x0))
        _compensator_sr_flip_flop1__state = -1;
    // Generated from the component: Compensator.Slope compensation
    _compensator_slope_compensation__current_phase += tunable_params._compensator_slope_compensation__frequency * 5e-06;
    if (_compensator_slope_compensation__current_phase >= 1.0f) {
        _compensator_slope_compensation__current_phase -= 1.0f;
    }
    // Generated from the component: Compensator.fsw
    _compensator_fsw__current_phase += tunable_params._compensator_fsw__frequency * 5e-06;
    if (_compensator_fsw__current_phase >= 1.0f) {
        _compensator_fsw__current_phase -= 1.0f;
    }
    // Generated from the component: Disturbance
    _disturbance__current_phase += tunable_params._disturbance__frequency * 5e-06;
    if (_disturbance__current_phase >= 1.0f) {
        _disturbance__current_phase -= 1.0f;
    }
    // Generated from the component: Compensator.PID
    if (!_compensator_pid__av_active || ((_compensator_pid__av_active < 0 && _compensator_sum2__out > 0 ) || (_compensator_pid__av_active > 0 && _compensator_sum2__out < 0 ))) {
        _compensator_pid__integrator_state += tunable_params._compensator_pid__ki * _compensator_sum2__out * 5e-06;
    }
    // Generated from the component: Compensator.Comparator1
    if (_isw_ia1__out < _compensator_sum1__out) {
        _compensator_comparator1__state = 0;
    } else if (_isw_ia1__out > _compensator_sum1__out) {
        _compensator_comparator1__state = 1;
    }
    //@cmp.update.block.end
}
// ----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------