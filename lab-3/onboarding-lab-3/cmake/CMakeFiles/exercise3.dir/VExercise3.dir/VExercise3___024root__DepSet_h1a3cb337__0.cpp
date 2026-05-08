// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VExercise3.h for the primary calling header

#include "VExercise3__pch.h"
#include "VExercise3___024root.h"

VL_INLINE_OPT void VExercise3___024root___ico_sequent__TOP__0(VExercise3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise3___024root___ico_sequent__TOP__0\n"); );
    // Body
    if ((0U == (3U & (IData)(vlSelf->a)))) {
        vlSelf->Exercise3__DOT__a_in = ((0xc0U & ((IData)(vlSelf->a) 
                                                  << 6U)) 
                                        | ((0x38U & 
                                            ((IData)(vlSelf->b) 
                                             << 3U)) 
                                           | (7U & (IData)(vlSelf->c))));
    } else if ((1U == (3U & (IData)(vlSelf->a)))) {
        vlSelf->Exercise3__DOT__a_in = ((0xc0U & ((IData)(vlSelf->a) 
                                                  << 6U)) 
                                        | ((0x38U & 
                                            ((IData)(vlSelf->c) 
                                             << 3U)) 
                                           | (7U & (IData)(vlSelf->b))));
    } else if ((2U == (3U & (IData)(vlSelf->a)))) {
        vlSelf->Exercise3__DOT__a_in = (0xffU & (IData)(vlSelf->b));
    } else if ((3U == (3U & (IData)(vlSelf->a)))) {
        vlSelf->Exercise3__DOT__a_in = (0xffU & (IData)(vlSelf->c));
    }
    if ((0U == (3U & ((IData)(vlSelf->a) >> 2U)))) {
        vlSelf->Exercise3__DOT__b_in = ((0xc0U & ((IData)(vlSelf->a) 
                                                  << 4U)) 
                                        | ((0x38U & 
                                            ((IData)(vlSelf->b) 
                                             >> 5U)) 
                                           | (7U & 
                                              ((IData)(vlSelf->c) 
                                               >> 8U))));
    } else if ((1U == (3U & ((IData)(vlSelf->a) >> 2U)))) {
        vlSelf->Exercise3__DOT__b_in = ((0xc0U & ((IData)(vlSelf->a) 
                                                  << 4U)) 
                                        | ((0x38U & 
                                            ((IData)(vlSelf->c) 
                                             >> 5U)) 
                                           | (7U & 
                                              ((IData)(vlSelf->b) 
                                               >> 8U))));
    } else if ((2U == (3U & ((IData)(vlSelf->a) >> 2U)))) {
        vlSelf->Exercise3__DOT__b_in = (0xffU & ((IData)(vlSelf->b) 
                                                 >> 8U));
    } else if ((3U == (3U & ((IData)(vlSelf->a) >> 2U)))) {
        vlSelf->Exercise3__DOT__b_in = (0xffU & ((IData)(vlSelf->c) 
                                                 >> 8U));
    }
}

void VExercise3___024root___eval_ico(VExercise3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise3___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VExercise3___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VExercise3___024root___eval_triggers__ico(VExercise3___024root* vlSelf);

bool VExercise3___024root___eval_phase__ico(VExercise3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise3___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VExercise3___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VExercise3___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VExercise3___024root___eval_act(VExercise3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise3___024root___eval_act\n"); );
}

VL_INLINE_OPT void VExercise3___024root___nba_sequent__TOP__0(VExercise3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise3___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ __Vdly__out;
    __Vdly__out = 0;
    CData/*2:0*/ __Vdly__Exercise3__DOT__gamma__DOT__count;
    __Vdly__Exercise3__DOT__gamma__DOT__count = 0;
    // Body
    __Vdly__Exercise3__DOT__gamma__DOT__count = vlSelf->Exercise3__DOT__gamma__DOT__count;
    __Vdly__out = vlSelf->out;
    if (vlSelf->reset) {
        __Vdly__out = (((IData)(vlSelf->Exercise3__DOT__b_in) 
                        << 8U) | (IData)(vlSelf->Exercise3__DOT__a_in));
        __Vdly__Exercise3__DOT__gamma__DOT__count = 0U;
    } else {
        if ((0U == (IData)(vlSelf->Exercise3__DOT__gamma__DOT__count))) {
            __Vdly__out = (((IData)(vlSelf->Exercise3__DOT__a_in) 
                            << 8U) | (0xffU & (IData)(vlSelf->out)));
        } else if ((1U == (IData)(vlSelf->Exercise3__DOT__gamma__DOT__count))) {
            __Vdly__out = ((0xff00U & (IData)(vlSelf->out)) 
                           | (IData)(vlSelf->Exercise3__DOT__b_in));
        } else if ((2U == (IData)(vlSelf->Exercise3__DOT__gamma__DOT__count))) {
            __Vdly__out = ((0xff00U & ((IData)(vlSelf->out) 
                                       << 8U)) | (0xffU 
                                                  & ((IData)(vlSelf->out) 
                                                     >> 8U)));
        } else if ((3U == (IData)(vlSelf->Exercise3__DOT__gamma__DOT__count))) {
            __Vdly__out = ((0xf000U & ((IData)(vlSelf->out) 
                                       << 0xcU)) | 
                           ((0xf00U & ((IData)(vlSelf->out) 
                                       << 4U)) | ((0xf0U 
                                                   & ((IData)(vlSelf->out) 
                                                      >> 4U)) 
                                                  | (0xfU 
                                                     & ((IData)(vlSelf->out) 
                                                        >> 0xcU)))));
        } else if ((4U == (IData)(vlSelf->Exercise3__DOT__gamma__DOT__count))) {
            __Vdly__out = (1U & VL_REDXOR_16(vlSelf->out));
        }
        __Vdly__Exercise3__DOT__gamma__DOT__count = 
            (7U & VL_MODDIV_III(32, ((IData)(1U) + (IData)(vlSelf->Exercise3__DOT__gamma__DOT__count)), (IData)(5U)));
    }
    vlSelf->out = __Vdly__out;
    vlSelf->Exercise3__DOT__gamma__DOT__count = __Vdly__Exercise3__DOT__gamma__DOT__count;
}

void VExercise3___024root___eval_nba(VExercise3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise3___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VExercise3___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void VExercise3___024root___eval_triggers__act(VExercise3___024root* vlSelf);

bool VExercise3___024root___eval_phase__act(VExercise3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise3___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VExercise3___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VExercise3___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VExercise3___024root___eval_phase__nba(VExercise3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise3___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VExercise3___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise3___024root___dump_triggers__ico(VExercise3___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise3___024root___dump_triggers__nba(VExercise3___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VExercise3___024root___dump_triggers__act(VExercise3___024root* vlSelf);
#endif  // VL_DEBUG

void VExercise3___024root___eval(VExercise3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise3___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VExercise3___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/rtl/Exercise3.sv", 12, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VExercise3___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VExercise3___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/rtl/Exercise3.sv", 12, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VExercise3___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/rtl/Exercise3.sv", 12, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VExercise3___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VExercise3___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VExercise3___024root___eval_debug_assertions(VExercise3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VExercise3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VExercise3___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->a & 0xf0U))) {
        Verilated::overWidthError("a");}
}
#endif  // VL_DEBUG
