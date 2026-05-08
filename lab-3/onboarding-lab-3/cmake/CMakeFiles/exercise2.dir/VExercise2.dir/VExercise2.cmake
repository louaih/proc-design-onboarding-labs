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
set(VExercise2_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(VExercise2_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(VExercise2_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(VExercise2_COVERAGE 0)
# Timing mode?  0/1
set(VExercise2_TIMING 0)
# Threaded output mode?  1/N threads (from --threads)
set(VExercise2_THREADS 1)
# VCD Tracing output mode?  0/1 (from --trace)
set(VExercise2_TRACE_VCD 0)
# FST Tracing output mode? 0/1 (from --trace-fst)
set(VExercise2_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(VExercise2_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_threads.cpp" )
# Generated module classes, non-fast-path, compile with low/medium optimization
set(VExercise2_CLASSES_SLOW "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise2.dir/VExercise2.dir/VExercise2___024root__Slow.cpp" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise2.dir/VExercise2.dir/VExercise2___024root__DepSet_h4a760c9e__0__Slow.cpp" )
# Generated module classes, fast-path, compile with highest optimization
set(VExercise2_CLASSES_FAST "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise2.dir/VExercise2.dir/VExercise2.cpp" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise2.dir/VExercise2.dir/VExercise2___024root__DepSet_he719417e__0.cpp" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise2.dir/VExercise2.dir/VExercise2___024root__DepSet_h4a760c9e__0.cpp" )
# Generated support classes, non-fast-path, compile with low/medium optimization
set(VExercise2_SUPPORT_SLOW "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise2.dir/VExercise2.dir/VExercise2__Syms.cpp" )
# Generated support classes, fast-path, compile with highest optimization
set(VExercise2_SUPPORT_FAST )
# All dependencies
set(VExercise2_DEPS "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/rtl/Exercise2.sv" "/usr/bin/verilator_bin" "/usr/share/verilator/include/verilated_std.sv" )
# User .cpp files (from .cpp's on Verilator command line)
set(VExercise2_USER_CLASSES )
