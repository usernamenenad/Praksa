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
double _controller_constant1__out = 0.0;
double _controller_control_mode__out;
double _controller_dc_reference_input_voltage__out = 7.0;
X_Int32 _controller_open_loop_duty_ratio__out;
double _controller_sr_flip_flop1__out;
double _controller_sr_flip_flop1__out_n;
double _controller_slope_compensation__out;
double _controller_triangular_wave_source1__out;
X_Int32 _controller_fsw__out;
double _disturbance__out;
X_Int32 _enable_disturbance__out;
double _input_voltage_input_voltage_reference__out = 7.0;
double _input_voltage_no_disturbance__out = 0.0;
double _isw_ia1__out;
double _load_resistance__out;
double _output_voltage__out;
X_Int32 _turn_on_load__out;
double _vout_va1__out;
double _controller_integrator__out;
double _input_voltage_signal_switch1__out;
double _controller_sum2__out;
double _controller_sum4__out;
double _controller_lead_regulator__out;
double _controller_lead_regulator__b_coeff[2] = {1.0, -0.9999583067878977};
double _controller_lead_regulator__a_coeff[2] = {1.0, -0.990619276102561};
double _controller_lead_regulator__a_sum;
double _controller_lead_regulator__b_sum;
double _controller_lead_regulator__delay_line_in;
double _input_voltage_sum1__out;
double _controller_signal_switch1__out;
double _controller_voltage_mode_controller__out;
double _controller_voltage_mode_controller__pi_reg_out_int;
double _controller_sum3__out;
double _controller_k__out;
double _controller_comparator2__out;
double _controller_gain__out;
double _controller_multiport_signal_switch1__out;
double _controller_sum1__out;
double _buck_boost_bus_join1__out[2];
double _controller_comparator1__out;//@cmp.var.end

//@cmp.svar.start
// state variables
double _controller_open_loop_duty_ratio__current_phase;
double _controller_sr_flip_flop1__state;
double _controller_slope_compensation__current_phase;
double _controller_triangular_wave_source1__current_phase;
double _controller_fsw__current_phase;
double _disturbance__current_phase;
double _controller_integrator__state;
double _controller_integrator__reset_state;
double _controller_lead_regulator__states[1];
double _controller_voltage_mode_controller__integrator_state;
X_Int32 _controller_voltage_mode_controller__av_active;
double _controller_voltage_mode_controller__filter_state;
double _controller_voltage_mode_controller__reset_state;
double _controller_comparator2__state;
double _controller_comparator1__state;//@cmp.svar.end

//
// Tunable parameters
//
static struct Tunable_params {
    double _controller_gain__gain;
    double _controller_open_loop_duty_ratio__frequency;
    double _controller_open_loop_duty_ratio__duty_cycle;
    X_Int32 _controller_open_loop_duty_ratio__ls_output;
    X_Int32 _controller_open_loop_duty_ratio__hs_output;
    double _controller_open_loop_duty_ratio__phase;
    double _controller_slope_compensation__frequency;
    double _controller_slope_compensation__max_val;
    double _controller_slope_compensation__duty_cycle;
    double _controller_slope_compensation__min_val;
    double _controller_slope_compensation__phase;
    double _controller_voltage_mode_controller__ki;
    double _controller_voltage_mode_controller__upper_sat_lim;
    double _controller_voltage_mode_controller__kp;
    double _controller_voltage_mode_controller__lower_sat_lim;
    double _controller_fsw__phase;
    double _controller_fsw__frequency;
    X_Int32 _controller_fsw__hs_output;
    X_Int32 _controller_fsw__ls_output;
    double _controller_fsw__duty_cycle;
    double _disturbance__dc_offset;
    double _disturbance__frequency;
    double _disturbance__amplitude;
    double _disturbance__phase;
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
    _controller_open_loop_duty_ratio__current_phase = tunable_params._controller_open_loop_duty_ratio__phase;
    _controller_sr_flip_flop1__state =  0;
    _controller_slope_compensation__current_phase = tunable_params._controller_slope_compensation__phase;
    _controller_triangular_wave_source1__current_phase = 0.0;
    _controller_fsw__current_phase = tunable_params._controller_fsw__phase;
    _disturbance__current_phase = tunable_params._disturbance__phase / 360.0f;
    _controller_integrator__state = 0.0;
    _controller_integrator__reset_state = 2;
    HIL_OutFloat(137363456, 0.0);
    X_UnInt32 _controller_lead_regulator__i;
    for (_controller_lead_regulator__i = 0; _controller_lead_regulator__i < 1; _controller_lead_regulator__i++) {
        _controller_lead_regulator__states[_controller_lead_regulator__i] = 0;
    }
    _controller_voltage_mode_controller__integrator_state =  0.0;
    _controller_voltage_mode_controller__filter_state =  0.0;
    HIL_OutFloat(137101312, 0.0);
    _controller_comparator2__state = 0.0f;
    _controller_comparator1__state = 0.0f;
    HIL_OutAO(0x4000, 0.0f);
    HIL_OutInt32(0x810002e, 0x3);
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
    // Generated from the component: Controller.Constant1
    // Generated from the component: Controller.DC Reference input voltage
    // Generated from the component: Input Voltage.Input voltage reference
    // Generated from the component: Input Voltage.No disturbance
//////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: Controller.Control mode
    _controller_control_mode__out = XIo_InFloat(0xfffc0000);
    // Generated from the component: Controller.Open loop duty ratio
    if (_controller_open_loop_duty_ratio__current_phase < tunable_params._controller_open_loop_duty_ratio__duty_cycle) {
        _controller_open_loop_duty_ratio__out = tunable_params._controller_open_loop_duty_ratio__hs_output;
    } else {
        _controller_open_loop_duty_ratio__out = tunable_params._controller_open_loop_duty_ratio__ls_output;
    }
    // Generated from the component: Controller.SR Flip Flop1
    _controller_sr_flip_flop1__out = _controller_sr_flip_flop1__state;
    _controller_sr_flip_flop1__out_n = _controller_sr_flip_flop1__state != -1 ? !_controller_sr_flip_flop1__state : -1;
    // Generated from the component: Controller.Slope compensation
    if (_controller_slope_compensation__current_phase < tunable_params._controller_slope_compensation__duty_cycle) {
        _controller_slope_compensation__out = tunable_params._controller_slope_compensation__min_val + (((tunable_params._controller_slope_compensation__max_val) - (tunable_params._controller_slope_compensation__min_val)) * (_controller_slope_compensation__current_phase / tunable_params._controller_slope_compensation__duty_cycle));
    } else {
        _controller_slope_compensation__out = tunable_params._controller_slope_compensation__max_val - (((tunable_params._controller_slope_compensation__max_val) - (tunable_params._controller_slope_compensation__min_val)) * ((_controller_slope_compensation__current_phase - tunable_params._controller_slope_compensation__duty_cycle) / (1.0f - tunable_params._controller_slope_compensation__duty_cycle)));
    }
    // Generated from the component: Controller.Triangular Wave Source1
    if (_controller_triangular_wave_source1__current_phase < 0.999) {
        _controller_triangular_wave_source1__out = 0.0 + (((1.0) - (0.0)) * (_controller_triangular_wave_source1__current_phase / 0.999));
    } else {
        _controller_triangular_wave_source1__out = 1.0 - (((1.0) - (0.0)) * ((_controller_triangular_wave_source1__current_phase - 0.999) / (1.0f - 0.999)));
    }
    // Generated from the component: Controller.fsw
    if (_controller_fsw__current_phase < tunable_params._controller_fsw__duty_cycle) {
        _controller_fsw__out = tunable_params._controller_fsw__hs_output;
    } else {
        _controller_fsw__out = tunable_params._controller_fsw__ls_output;
    }
    // Generated from the component: Disturbance
    _disturbance__out = (tunable_params._disturbance__amplitude * sin(2.0f * M_PI * _disturbance__current_phase) + tunable_params._disturbance__dc_offset);
    // Generated from the component: Enable disturbance
    _enable_disturbance__out = XIo_InInt32(0xfffc0004);
    // Generated from the component: Isw.Ia1
    _isw_ia1__out = (HIL_InFloat(0xc80000 + 0x6));
    // Generated from the component: Load resistance
    _load_resistance__out = XIo_InFloat(0xfffc0008);
    // Generated from the component: Output voltage
    _output_voltage__out = XIo_InFloat(0xfffc000c);
    // Generated from the component: Turn on load
    _turn_on_load__out = XIo_InInt32(0xfffc0010);
    // Generated from the component: Vout.Va1
    _vout_va1__out = (HIL_InFloat(0xc80000 + 0x4));
    // Generated from the component: Controller.Integrator
    if (((_controller_control_mode__out > 0.0) && (_controller_integrator__reset_state <= 0)) || ((_controller_control_mode__out <= 0.0) && (_controller_integrator__reset_state == 1))) {
        _controller_integrator__state = 0.0;
    }
    _controller_integrator__out = _controller_integrator__state;
    // Generated from the component: Controller.Termination1
    // Generated from the component: Input Voltage.Signal switch1
    _input_voltage_signal_switch1__out = (_enable_disturbance__out > 0.5) ? _disturbance__out : _input_voltage_no_disturbance__out;
    // Generated from the component: Rload.Vs
    HIL_OutFloat(137363456, (float) _load_resistance__out);
    // Generated from the component: S.CTC_Wrapper
    if (_turn_on_load__out == 0x0) {
        HIL_OutInt32(0x8240480, 0x0);
    }
    else {
        HIL_OutInt32(0x8240480, 0x1);
    }
    // Generated from the component: Controller.Sum2
    _controller_sum2__out = _output_voltage__out - _vout_va1__out;
    // Generated from the component: Controller.Sum4
    _controller_sum4__out = _output_voltage__out - _vout_va1__out;
    // Generated from the component: Controller.Lead regulator
    X_UnInt32 _controller_lead_regulator__i;
    _controller_lead_regulator__a_sum = 0.0f;
    _controller_lead_regulator__b_sum = 0.0f;
    _controller_lead_regulator__delay_line_in = 0.0f;
    for (_controller_lead_regulator__i = 0; _controller_lead_regulator__i < 1; _controller_lead_regulator__i++) {
        _controller_lead_regulator__b_sum += _controller_lead_regulator__b_coeff[_controller_lead_regulator__i + 1] * _controller_lead_regulator__states[_controller_lead_regulator__i];
    }
    _controller_lead_regulator__a_sum += _controller_lead_regulator__states[0] * _controller_lead_regulator__a_coeff[1];
    _controller_lead_regulator__delay_line_in = _controller_integrator__out - _controller_lead_regulator__a_sum;
    _controller_lead_regulator__b_sum += _controller_lead_regulator__b_coeff[0] * _controller_lead_regulator__delay_line_in;
    _controller_lead_regulator__out = _controller_lead_regulator__b_sum;
    // Generated from the component: Input Voltage.Sum1
    _input_voltage_sum1__out = _input_voltage_signal_switch1__out + _input_voltage_input_voltage_reference__out;
    // Generated from the component: Controller.Signal switch1
    _controller_signal_switch1__out = (_controller_control_mode__out > 2.5f) ? _controller_sum2__out : _controller_constant1__out;
    // Generated from the component: Controller.Voltage mode controller
    _controller_voltage_mode_controller__pi_reg_out_int = _controller_voltage_mode_controller__integrator_state + tunable_params._controller_voltage_mode_controller__kp * _controller_sum4__out;
    if (_controller_voltage_mode_controller__pi_reg_out_int < tunable_params._controller_voltage_mode_controller__lower_sat_lim)
        _controller_voltage_mode_controller__av_active = -1;
    else if (_controller_voltage_mode_controller__pi_reg_out_int > tunable_params._controller_voltage_mode_controller__upper_sat_lim)
        _controller_voltage_mode_controller__av_active = 1;
    else
        _controller_voltage_mode_controller__av_active = 0;
    _controller_voltage_mode_controller__out = MIN(MAX(_controller_voltage_mode_controller__pi_reg_out_int, tunable_params._controller_voltage_mode_controller__lower_sat_lim), tunable_params._controller_voltage_mode_controller__upper_sat_lim);
    // Generated from the component: Controller.Sum3
    _controller_sum3__out = _controller_dc_reference_input_voltage__out - _input_voltage_sum1__out;
    // Generated from the component: Vin.Vs1
    HIL_OutFloat(137101312, (float) _input_voltage_sum1__out);
    // Generated from the component: Controller.K
    _controller_k__out = 365.07 * _controller_signal_switch1__out;
    // Generated from the component: Controller.Comparator2
    if (_controller_triangular_wave_source1__out < _controller_voltage_mode_controller__out) {
        _controller_comparator2__out = 0;
    } else if (_controller_triangular_wave_source1__out > _controller_voltage_mode_controller__out) {
        _controller_comparator2__out = 1;
    } else {
        _controller_comparator2__out = _controller_comparator2__state;
    }
    // Generated from the component: Controller.Gain
    _controller_gain__out = tunable_params._controller_gain__gain * _controller_sum3__out;
    // Generated from the component: Controller.Multiport signal switch1
    switch((X_UnInt32) _controller_control_mode__out) {
    case 1:
        _controller_multiport_signal_switch1__out = _controller_open_loop_duty_ratio__out;
        break;
    case 2:
        _controller_multiport_signal_switch1__out = _controller_comparator2__out;
        break;
    case 3:
        _controller_multiport_signal_switch1__out = _controller_sr_flip_flop1__out;
        break;
    default:
        _controller_multiport_signal_switch1__out = 0x0;
    }
    // Generated from the component: Controller.Sum1
    _controller_sum1__out = _controller_lead_regulator__out - _controller_slope_compensation__out + _controller_gain__out;
    // Generated from the component: Buck-Boost.Bus_Join1
    _buck_boost_bus_join1__out[0] = _controller_multiport_signal_switch1__out;
    _buck_boost_bus_join1__out[1] = _buck_boost_constant1__out;
    // Generated from the component: Controller.Comparator1
    if (_isw_ia1__out < _controller_sum1__out) {
        _controller_comparator1__out = 0;
    } else if (_isw_ia1__out > _controller_sum1__out) {
        _controller_comparator1__out = 1;
    } else {
        _controller_comparator1__out = _controller_comparator1__state;
    }
    // Generated from the component: Controller.Imax
    HIL_OutAO(0x4000, (float)_controller_sum1__out);
    // Generated from the component: Buck-Boost.FSM_Wrapper1
    _buck_boost_bus_join1__out[0] = (_buck_boost_bus_join1__out[0]) ? 1 : 0;
    _buck_boost_bus_join1__out[1] = (_buck_boost_bus_join1__out[1]) ? 1 : 0;
    HIL_OutInt32(0x810002f, 2 * _buck_boost_bus_join1__out[0] + 1 * _buck_boost_bus_join1__out[1]);
//@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: Controller.Open loop duty ratio
    _controller_open_loop_duty_ratio__current_phase += tunable_params._controller_open_loop_duty_ratio__frequency * 5e-06;
    if (_controller_open_loop_duty_ratio__current_phase >= 1.0f) {
        _controller_open_loop_duty_ratio__current_phase -= 1.0f;
    }
    // Generated from the component: Controller.SR Flip Flop1
    if ((_controller_fsw__out != 0x0) && (_controller_comparator1__out == 0x0))
        _controller_sr_flip_flop1__state = 1;
    else if ((_controller_fsw__out == 0x0) && (_controller_comparator1__out != 0x0))
        _controller_sr_flip_flop1__state = 0;
    else if ((_controller_fsw__out != 0x0) && (_controller_comparator1__out != 0x0))
        _controller_sr_flip_flop1__state = -1;
    // Generated from the component: Controller.Slope compensation
    _controller_slope_compensation__current_phase += tunable_params._controller_slope_compensation__frequency * 5e-06;
    if (_controller_slope_compensation__current_phase >= 1.0f) {
        _controller_slope_compensation__current_phase -= 1.0f;
    }
    // Generated from the component: Controller.Triangular Wave Source1
    _controller_triangular_wave_source1__current_phase += 10000.0 * 5e-06;
    if (_controller_triangular_wave_source1__current_phase >= 1.0f) {
        _controller_triangular_wave_source1__current_phase -= 1.0f;
    }
    // Generated from the component: Controller.fsw
    _controller_fsw__current_phase += tunable_params._controller_fsw__frequency * 5e-06;
    if (_controller_fsw__current_phase >= 1.0f) {
        _controller_fsw__current_phase -= 1.0f;
    }
    // Generated from the component: Disturbance
    _disturbance__current_phase += tunable_params._disturbance__frequency * 5e-06;
    if (_disturbance__current_phase >= 1.0f) {
        _disturbance__current_phase -= 1.0f;
    }
    // Generated from the component: Controller.Integrator
    _controller_integrator__state += _controller_k__out * 5e-06;
    if (_controller_control_mode__out > 0)
        _controller_integrator__reset_state = 1;
    else if (_controller_control_mode__out < 0)
        _controller_integrator__reset_state = -1;
    else
        _controller_integrator__reset_state = 0;
    // Generated from the component: Controller.Lead regulator
    _controller_lead_regulator__states[0] = _controller_lead_regulator__delay_line_in;
    // Generated from the component: Controller.Voltage mode controller
    if (((_controller_control_mode__out > 0.0) && (_controller_voltage_mode_controller__reset_state <= 0)) || ((_controller_control_mode__out <= 0.0) && (_controller_voltage_mode_controller__reset_state == 1))) {
        _controller_voltage_mode_controller__integrator_state = 0.0;
        _controller_voltage_mode_controller__filter_state = 0.0;
    }
    if (!_controller_voltage_mode_controller__av_active || ((_controller_voltage_mode_controller__av_active < 0 && _controller_sum4__out > 0 ) || (_controller_voltage_mode_controller__av_active > 0 && _controller_sum4__out < 0 ))) {
        _controller_voltage_mode_controller__integrator_state += tunable_params._controller_voltage_mode_controller__ki * _controller_sum4__out * 5e-06;
    }
    if (_controller_control_mode__out > 0)
        _controller_voltage_mode_controller__reset_state = 1.0;
    else if (_controller_control_mode__out < 0)
        _controller_voltage_mode_controller__reset_state = -1.0;
    else
        _controller_voltage_mode_controller__reset_state = 0.0;
    // Generated from the component: Controller.Comparator2
    if (_controller_triangular_wave_source1__out < _controller_voltage_mode_controller__out) {
        _controller_comparator2__state = 0;
    } else if (_controller_triangular_wave_source1__out > _controller_voltage_mode_controller__out) {
        _controller_comparator2__state = 1;
    }
    // Generated from the component: Controller.Comparator1
    if (_isw_ia1__out < _controller_sum1__out) {
        _controller_comparator1__state = 0;
    } else if (_isw_ia1__out > _controller_sum1__out) {
        _controller_comparator1__state = 1;
    }
    //@cmp.update.block.end
}
// ----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------