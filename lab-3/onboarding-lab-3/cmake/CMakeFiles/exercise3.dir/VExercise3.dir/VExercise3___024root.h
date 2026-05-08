// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VExercise3.h for the primary calling header

#ifndef VERILATED_VEXERCISE3___024ROOT_H_
#define VERILATED_VEXERCISE3___024ROOT_H_  // guard

#include "verilated.h"


class VExercise3__Syms;

class alignas(VL_CACHE_LINE_BYTES) VExercise3___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(a,3,0);
    CData/*7:0*/ Exercise3__DOT__a_in;
    CData/*7:0*/ Exercise3__DOT__b_in;
    CData/*2:0*/ Exercise3__DOT__gamma__DOT__count;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(b,15,0);
    VL_IN16(c,15,0);
    VL_OUT16(out,15,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VExercise3__Syms* const vlSymsp;

    // CONSTRUCTORS
    VExercise3___024root(VExercise3__Syms* symsp, const char* v__name);
    ~VExercise3___024root();
    VL_UNCOPYABLE(VExercise3___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
