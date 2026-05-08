// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VExercise4.h for the primary calling header

#include "VExercise4__pch.h"
#include "VExercise4___024root.h"

VL_ATTR_COLD void VExercise4___024root___eval_static(VExercise4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise4___024root___eval_static\n"); );
}

VL_ATTR_COLD void VExercise4___024root___eval_initial(VExercise4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise4___024root___eval_initial\n"); );
}

VL_ATTR_COLD void VExercise4___024root___eval_final(VExercise4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise4___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise4___024root___dump_triggers__stl(VExercise4___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VExercise4___024root___eval_phase__stl(VExercise4___024root* vlSelf);

VL_ATTR_COLD void VExercise4___024root___eval_settle(VExercise4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise4___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VExercise4___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/rtl/Exercise4.sv", 13, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VExercise4___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise4___024root___dump_triggers__stl(VExercise4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise4___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VExercise4___024root___ico_sequent__TOP__0(VExercise4___024root* vlSelf);

VL_ATTR_COLD void VExercise4___024root___eval_stl(VExercise4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise4___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VExercise4___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VExercise4___024root___eval_triggers__stl(VExercise4___024root* vlSelf);

VL_ATTR_COLD bool VExercise4___024root___eval_phase__stl(VExercise4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise4___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VExercise4___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VExercise4___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise4___024root___dump_triggers__ico(VExercise4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise4___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise4___024root___dump_triggers__act(VExercise4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise4___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise4___024root___dump_triggers__nba(VExercise4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise4___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VExercise4___024root___ctor_var_reset(VExercise4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise4___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->sel = VL_RAND_RESET_I(2);
    vlSelf->cs = VL_RAND_RESET_I(1);
    vlSelf->alpha = VL_RAND_RESET_I(8);
    vlSelf->beta = VL_RAND_RESET_I(8);
    vlSelf->gamma = VL_RAND_RESET_I(8);
    vlSelf->out = VL_RAND_RESET_I(8);
}
