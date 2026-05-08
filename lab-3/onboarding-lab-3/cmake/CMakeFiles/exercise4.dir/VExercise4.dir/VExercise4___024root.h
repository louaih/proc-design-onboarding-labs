// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VExercise4.h for the primary calling header

#ifndef VERILATED_VEXERCISE4___024ROOT_H_
#define VERILATED_VEXERCISE4___024ROOT_H_  // guard

#include "verilated.h"


class VExercise4__Syms;

class alignas(VL_CACHE_LINE_BYTES) VExercise4___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(sel,1,0);
    VL_IN8(cs,0,0);
    VL_IN8(alpha,7,0);
    VL_IN8(beta,7,0);
    VL_IN8(gamma,7,0);
    VL_OUT8(out,7,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    VExercise4__Syms* const vlSymsp;

    // CONSTRUCTORS
    VExercise4___024root(VExercise4__Syms* symsp, const char* v__name);
    ~VExercise4___024root();
    VL_UNCOPYABLE(VExercise4___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
