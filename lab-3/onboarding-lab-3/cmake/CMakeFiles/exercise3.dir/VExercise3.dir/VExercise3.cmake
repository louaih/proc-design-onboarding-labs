# Verilated -*- CMake -*-
# DESCRIPTION: Verilator output: CMake include script with class lists
#
# This CMake script lists generated Verilated files, for including in higher level CMake scripts.
# This file is meant to be consumed by the verilate() function,
# which becomes available after executing `find_package(verilator).

### Constants...
set(PERL "perl" CACHE FILEPATH "Perl executable (from $PERL)")
set(VERILATOR_ROOT "/usr/share/verilator" CACHE PATH "Path to Verilator kit (from $VERILATOR_ROOT)")

### Compiler flags...
# User CFLAGS (from -CFLAGS on Verilator command line)
set(VExercise3_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(VExercise3_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(VExercise3_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(VExercise3_COVERAGE 0)
# Timing mode?  0/1
set(VExercise3_TIMING 0)
# Threaded output mode?  1/N threads (from --threads)
set(VExercise3_THREADS 1)
# VCD Tracing output mode?  0/1 (from --trace)
set(VExercise3_TRACE_VCD 0)
# FST Tracing output mode? 0/1 (from --trace-fst)
set(VExercise3_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(VExercise3_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_threads.cpp" )
# Generated module classes, non-fast-path, compile with low/medium optimization
set(VExercise3_CLASSES_SLOW "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise3.dir/VExercise3.dir/VExercise3___024root__Slow.cpp" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise3.dir/VExercise3.dir/VExercise3___024root__DepSet_h677403fd__0__Slow.cpp" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise3.dir/VExercise3.dir/VExercise3___024root__DepSet_h1a3cb337__0__Slow.cpp" )
# Generated module classes, fast-path, compile with highest optimization
set(VExercise3_CLASSES_FAST "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise3.dir/VExercise3.dir/VExercise3.cpp" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise3.dir/VExercise3.dir/VExercise3___024root__DepSet_h677403fd__0.cpp" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise3.dir/VExercise3.dir/VExercise3___024root__DepSet_h1a3cb337__0.cpp" )
# Generated support classes, non-fast-path, compile with low/medium optimization
set(VExercise3_SUPPORT_SLOW "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise3.dir/VExercise3.dir/VExercise3__Syms.cpp" )
# Generated support classes, fast-path, compile with highest optimization
set(VExercise3_SUPPORT_FAST )
# All dependencies
set(VExercise3_DEPS "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/rtl/Exercise3.sv" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/rtl/Mysteries/Mystery1.sv" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/rtl/Mysteries/Mystery2.sv" "/usr/bin/verilator_bin" "/usr/share/verilator/include/verilated_std.sv" )
# User .cpp files (from .cpp's on Verilator command line)
set(VExercise3_USER_CLASSES )
