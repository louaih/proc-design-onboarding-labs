// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VExercise2__pch.h"

//============================================================
// Constructors

VExercise2::VExercise2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VExercise2__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , init{vlSymsp->TOP.init}
    , out{vlSymsp->TOP.out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VExercise2::VExercise2(const char* _vcname__)
    : VExercise2(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VExercise2::~VExercise2() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VExercise2___024root___eval_debug_assertions(VExercise2___024root* vlSelf);
#endif  // VL_DEBUG
void VExercise2___024root___eval_static(VExercise2___024root* vlSelf);
void VExercise2___024root___eval_initial(VExercise2___024root* vlSelf);
void VExercise2___024root___eval_settle(VExercise2___024root* vlSelf);
void VExercise2___024root___eval(VExercise2___024root* vlSelf);

void VExercise2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VExercise2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VExercise2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VExercise2___024root___eval_static(&(vlSymsp->TOP));
        VExercise2___024root___eval_initial(&(vlSymsp->TOP));
        VExercise2___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VExercise2___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VExercise2::eventsPending() { return false; }

uint64_t VExercise2::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VExercise2::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VExercise2___024root___eval_final(VExercise2___024root* vlSelf);

VL_ATTR_COLD void VExercise2::final() {
    VExercise2___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VExercise2::hierName() const { return vlSymsp->name(); }
const char* VExercise2::modelName() const { return "VExercise2"; }
unsigned VExercise2::threads() const { return 1; }
void VExercise2::prepareClone() const { contextp()->prepareClone(); }
void VExercise2::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void VExercise2::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'VExercise2::trace()' called on model that was Verilated without --trace option");
}
