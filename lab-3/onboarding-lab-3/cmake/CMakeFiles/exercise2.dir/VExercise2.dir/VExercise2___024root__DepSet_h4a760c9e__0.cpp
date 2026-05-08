// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VExercise2.h for the primary calling header

#include "VExercise2__pch.h"
#include "VExercise2___024root.h"

void VExercise2___024root___eval_act(VExercise2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise2___024root___eval_act\n"); );
}

VL_INLINE_OPT void VExercise2___024root___nba_sequent__TOP__0(VExercise2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise2___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->out = (0xffffU & ((IData)(vlSelf->reset)
                               ? (~ (IData)(vlSelf->init))
                               : ((0xfffeU & ((IData)(vlSelf->out) 
                                              << 1U)) 
                                  | (1U & VL_REDXOR_16(
                                                       (0x50aU 
                                                        & (IData)(vlSelf->out)))))));
}

void VExercise2___024root___eval_nba(VExercise2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise2___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VExercise2___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VExercise2___024root___eval_triggers__act(VExercise2___024root* vlSelf);

bool VExercise2___024root___eval_phase__act(VExercise2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise2___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VExercise2___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VExercise2___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VExercise2___024root___eval_phase__nba(VExercise2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise2___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VExercise2___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise2___024root___dump_triggers__nba(VExercise2___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise2___024root___dump_triggers__act(VExercise2___024root* vlSelf);
#endif  // VL_DEBUG

void VExercise2___024root___eval(VExercise2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise2___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VExercise2___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/rtl/Exercise2.sv", 9, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VExercise2___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/rtl/Exercise2.sv", 9, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VExercise2___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VExercise2___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VExercise2___024root___eval_debug_assertions(VExercise2___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise2___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
