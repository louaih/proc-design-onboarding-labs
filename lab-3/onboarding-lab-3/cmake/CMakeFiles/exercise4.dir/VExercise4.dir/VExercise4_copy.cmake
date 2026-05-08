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
set(VExercise4_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(VExercise4_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(VExercise4_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(VExercise4_COVERAGE 0)
# Timing mode?  0/1
set(VExercise4_TIMING 0)
# Threaded output mode?  1/N threads (from --threads)
set(VExercise4_THREADS 1)
# VCD Tracing output mode?  0/1 (from --trace)
set(VExercise4_TRACE_VCD 0)
# FST Tracing output mode? 0/1 (from --trace-fst)
set(VExercise4_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(VExercise4_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp" "${VERILATOR_ROOT}/include/verilated_threads.cpp" )
# Generated module classes, non-fast-path, compile with low/medium optimization
set(VExercise4_CLASSES_SLOW "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise4.dir/VExercise4.dir/VExercise4___024root__Slow.cpp" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise4.dir/VExercise4.dir/VExercise4___024root__DepSet_hde24e49b__0__Slow.cpp" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise4.dir/VExercise4.dir/VExercise4___024root__DepSet_ha7f20b33__0__Slow.cpp" )
# Generated module classes, fast-path, compile with highest optimization
set(VExercise4_CLASSES_FAST "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise4.dir/VExercise4.dir/VExercise4.cpp" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise4.dir/VExercise4.dir/VExercise4___024root__DepSet_hde24e49b__0.cpp" "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise4.dir/VExercise4.dir/VExercise4___024root__DepSet_ha7f20b33__0.cpp" )
# Generated support classes, non-fast-path, compile with low/medium optimization
set(VExercise4_SUPPORT_SLOW "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/cmake/CMakeFiles/exercise4.dir/VExercise4.dir/VExercise4__Syms.cpp" )
# Generated support classes, fast-path, compile with highest optimization
set(VExercise4_SUPPORT_FAST )
# All dependencies
set(VExercise4_DEPS "/home/louai/proc-design-onboarding-labs/lab-3/onboarding-lab-3/rtl/Exercise4.sv" "/usr/bin/verilator_bin" "/usr/share/verilator/include/verilated_std.sv" )
# User .cpp files (from .cpp's on Verilator command line)
set(VExercise4_USER_CLASSES )
