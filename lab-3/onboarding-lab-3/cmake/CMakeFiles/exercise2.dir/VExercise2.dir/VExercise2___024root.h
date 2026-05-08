// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VExercise2.h for the primary calling header

#ifndef VERILATED_VEXERCISE2___024ROOT_H_
#define VERILATED_VEXERCISE2___024ROOT_H_  // guard

#include "verilated.h"


class VExercise2__Syms;

class alignas(VL_CACHE_LINE_BYTES) VExercise2___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(init,15,0);
    VL_OUT16(out,15,0);
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VExercise2__Syms* const vlSymsp;

    // CONSTRUCTORS
    VExercise2___024root(VExercise2__Syms* symsp, const char* v__name);
    ~VExercise2___024root();
    VL_UNCOPYABLE(VExercise2___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
