// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VEXERCISE4__SYMS_H_
#define VERILATED_VEXERCISE4__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VExercise4.h"

// INCLUDE MODULE CLASSES
#include "VExercise4___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VExercise4__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VExercise4* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VExercise4___024root           TOP;

    // CONSTRUCTORS
    VExercise4__Syms(VerilatedContext* contextp, const char* namep, VExercise4* modelp);
    ~VExercise4__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
