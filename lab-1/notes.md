# Onboarding Lab 1 Notes and Answers

## Make Note: What version of cmake is running in your environment?

```bash
cmake version 4.3.2
```

## Make Note: Run make help and figure out what the valid targets (command arguments) are for this project. For all the targets that start with “hello”, can you figure out what they produce? What about all and clean?

To help answer the question, here's the output of `make help`
```bash
The following are some of the valid targets for this Makefile:
... all (the default if no target is provided)
... clean
... depend
... codegen
... edit_cache
... rebuild_cache
... hello_world
... hello.o
... hello.i
... hello.s
```

Running `make help` lists the valid targets available in the project’s Makefile. 

The targets beginning with `hello` correspond to different stages of the compilation pipeline for the source file. `hello_world` builds the final executable program. `hello.i` produces the preprocessed C source after macros and includes are expanded, `hello.s` produces the generated assembly code, and `hello.o` produces the compiled object file before linking. 

The `all` target is the default build target that typically compiles the entire project, often including the final executable and any required intermediate files. 

The `clean` target removes generated build artifacts such as executables, object files, assembly files, and cache outputs so the project directory returns to a fresh state.

## Answer the following:

### The paths used by target_sources and target_include_directories are relative, not absolute. What file or folder are they relative to?

The paths are relative to the directory that the CML is in. Since the CML is in the project root, the paths are relative to the project root. I think moving the CML to another directory will mess a lot of things up so I'll assume that it's relative to the file and not always the root. I'll also assume that having the CML at the project root is convention so this distinction is semantic in nature.

### What are some differences between cmake and ninja?

CMake is a meta build system and ninja is a build system. CMake orchestrates ninja and ninja is only meant to be used in conjunction with a meta build system.

### Why is it important to run cmake in its own directory?

This is important because otherwise, the project root would be "filled with random crap" a.k.a build-specific files that have no business being at the root.