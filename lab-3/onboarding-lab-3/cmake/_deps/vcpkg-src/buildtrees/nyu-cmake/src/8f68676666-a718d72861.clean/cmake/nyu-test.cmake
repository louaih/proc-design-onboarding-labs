option(NYU_BUILD_TESTS "Build test binaries and add them to CTest" FALSE)

function(nyu_setup_test)
  cmake_parse_arguments(PARSE_ARGV 0 ARG
    ""
    "TEST_NAME;TOP_MODULE"
    "SV_SOURCES;CPP_SOURCES;SV_LIBS;CPP_LIBS"
  )

  if(NOT DEFINED ARG_TEST_NAME)
    set(ARG_TEST_NAME ${ARG_TOP_MODULE})
  endif()

  if(NOT DEFINED ARG_TOP_MODULE)
    set(ARG_TOP_MODULE ${ARG_TEST_NAME})
  endif()

  if(NYU_BUILD_TESTS)
    add_executable(${ARG_TEST_NAME} ${ARG_CPP_SOURCES})
    nyu_add_sv(${ARG_TEST_NAME} ${ARG_SV_SOURCES})

    target_compile_features(${ARG_TEST_NAME} PRIVATE cxx_std_20)

    if(DEFINED ARG_CPP_LIBS)
      target_link_libraries(${ARG_TEST_NAME} PRIVATE ${ARG_CPP_LIBS})
    endif()

    if(DEFINED ARG_SV_LIBS)
      nyu_link_sv(${ARG_TEST_NAME} PRIVATE ${ARG_SV_LIBS})
    endif()

    nyu_verilate(${ARG_TEST_NAME}
      COVERAGE
      PREFIX "V${ARG_TOP_MODULE}"
      TOP_MODULE ${ARG_TOP_MODULE}
    )
    add_test(
      NAME ${ARG_TEST_NAME}
      COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${ARG_TEST_NAME}
    )
  endif()
endfunction()
