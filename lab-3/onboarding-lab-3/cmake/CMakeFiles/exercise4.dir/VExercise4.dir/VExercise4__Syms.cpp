// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VExercise4__pch.h"
#include "VExercise4.h"
#include "VExercise4___024root.h"

// FUNCTIONS
VExercise4__Syms::~VExercise4__Syms()
{
}

VExercise4__Syms::VExercise4__Syms(VerilatedContext* contextp, const char* namep, VExercise4* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
