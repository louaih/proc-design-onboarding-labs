// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VExercise3__pch.h"

//============================================================
// Constructors

VExercise3::VExercise3(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VExercise3__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , a{vlSymsp->TOP.a}
    , b{vlSymsp->TOP.b}
    , c{vlSymsp->TOP.c}
    , out{vlSymsp->TOP.out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VExercise3::VExercise3(const char* _vcname__)
    : VExercise3(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VExercise3::~VExercise3() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VExercise3___024root___eval_debug_assertions(VExercise3___024root* vlSelf);
#endif  // VL_DEBUG
void VExercise3___024root___eval_static(VExercise3___024root* vlSelf);
void VExercise3___024root___eval_initial(VExercise3___024root* vlSelf);
void VExercise3___024root___eval_settle(VExercise3___024root* vlSelf);
void VExercise3___024root___eval(VExercise3___024root* vlSelf);

void VExercise3::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VExercise3::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VExercise3___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VExercise3___024root___eval_static(&(vlSymsp->TOP));
        VExercise3___024root___eval_initial(&(vlSymsp->TOP));
        VExercise3___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VExercise3___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VExercise3::eventsPending() { return false; }

uint64_t VExercise3::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VExercise3::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VExercise3___024root___eval_final(VExercise3___024root* vlSelf);

VL_ATTR_COLD void VExercise3::final() {
    VExercise3___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VExercise3::hierName() const { return vlSymsp->name(); }
const char* VExercise3::modelName() const { return "VExercise3"; }
unsigned VExercise3::threads() const { return 1; }
void VExercise3::prepareClone() const { contextp()->prepareClone(); }
void VExercise3::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void VExercise3::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'VExercise3::trace()' called on model that was Verilated without --trace option");
}
