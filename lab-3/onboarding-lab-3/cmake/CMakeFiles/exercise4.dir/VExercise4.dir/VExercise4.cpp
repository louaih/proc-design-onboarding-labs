// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VExercise4__pch.h"

//============================================================
// Constructors

VExercise4::VExercise4(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VExercise4__Syms(contextp(), _vcname__, this)}
    , sel{vlSymsp->TOP.sel}
    , cs{vlSymsp->TOP.cs}
    , alpha{vlSymsp->TOP.alpha}
    , beta{vlSymsp->TOP.beta}
    , gamma{vlSymsp->TOP.gamma}
    , out{vlSymsp->TOP.out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VExercise4::VExercise4(const char* _vcname__)
    : VExercise4(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VExercise4::~VExercise4() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VExercise4___024root___eval_debug_assertions(VExercise4___024root* vlSelf);
#endif  // VL_DEBUG
void VExercise4___024root___eval_static(VExercise4___024root* vlSelf);
void VExercise4___024root___eval_initial(VExercise4___024root* vlSelf);
void VExercise4___024root___eval_settle(VExercise4___024root* vlSelf);
void VExercise4___024root___eval(VExercise4___024root* vlSelf);

void VExercise4::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VExercise4::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VExercise4___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VExercise4___024root___eval_static(&(vlSymsp->TOP));
        VExercise4___024root___eval_initial(&(vlSymsp->TOP));
        VExercise4___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VExercise4___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VExercise4::eventsPending() { return false; }

uint64_t VExercise4::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VExercise4::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VExercise4___024root___eval_final(VExercise4___024root* vlSelf);

VL_ATTR_COLD void VExercise4::final() {
    VExercise4___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VExercise4::hierName() const { return vlSymsp->name(); }
const char* VExercise4::modelName() const { return "VExercise4"; }
unsigned VExercise4::threads() const { return 1; }
void VExercise4::prepareClone() const { contextp()->prepareClone(); }
void VExercise4::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void VExercise4::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'VExercise4::trace()' called on model that was Verilated without --trace option");
}
