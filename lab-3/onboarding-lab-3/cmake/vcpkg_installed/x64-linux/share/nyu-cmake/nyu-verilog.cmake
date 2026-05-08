function(nyu_add_sv TARGET)
  foreach(_src IN LISTS ARGN)
    file(REAL_PATH ${_src} _real)
    set_property(TARGET ${TARGET} APPEND
      PROPERTY SV_SOURCES ${_real}
    )
    set_property(TARGET ${TARGET} APPEND
      PROPERTY SV_SRC_PATHS ${_real}
    )
    set_property(TARGET ${TARGET} APPEND
      PROPERTY SV_SOURCES_NOGENEX ${_real}
    )
  endforeach()
endfunction()

function(nyu_sv_include_directories TARGET)
  foreach(_dir IN LISTS ARGN)
    file(REAL_PATH ${_dir} _real)
    set_property(TARGET ${TARGET} APPEND
      PROPERTY SV_INCLUDE_DIRS ${_real}
    )
    set_property(TARGET ${TARGET} APPEND
      PROPERTY SV_INCLUDE_DIRS_NOGENEX ${_real}
    )
  endforeach()
endfunction()

function(nyu_add_sv_library TARGET)
  add_library(${TARGET} INTERFACE)
  nyu_add_sv(${TARGET} ${ARGN})
endfunction()

function(__nyu_link_internal TARGET)
  foreach(_lib IN LISTS ARGN)
    set_property(TARGET ${TARGET} APPEND
      PROPERTY SV_SOURCES $<TARGET_GENEX_EVAL:${_lib},$<TARGET_PROPERTY:${_lib},SV_SOURCES>>
    )
    get_target_property(_srcs ${_lib} SV_SOURCES_NOGENEX)
    set_property(TARGET ${TARGET} APPEND
      PROPERTY SV_SOURCES_NOGENEX ${_srcs}
    )

    set_property(TARGET ${TARGET} APPEND
      PROPERTY SV_INCLUDE_DIRS $<TARGET_GENEX_EVAL:${_lib},$<TARGET_PROPERTY:${_lib},SV_INCLUDE_DIRS>>
    )
    get_target_property(_dirs ${_lib} SV_INCLUDE_DIRS_NOGENEX)
    set_property(TARGET ${TARGET} APPEND
      PROPERTY SV_INCLUDE_DIRS_NOGENEX ${_dirs}
    )
  endforeach()
endfunction()

function(nyu_link_sv TARGET LINKAGE)
  target_link_libraries(${TARGET} ${LINKAGE} ${ARGN})
  __nyu_link_internal(${TARGET} ${ARGN})
endfunction()

function(nyu_include_fixup)
  foreach(_target IN LISTS ARGN)
    get_target_property(_srcs ${_target} SV_SOURCES)

    if(_srcs)
      return()
    endif()

    set_property(TARGET ${_target}
      PROPERTY SV_SOURCES $<TARGET_PROPERTY:${_target},INTF_SV_SOURCES>
    )
    get_target_property(_intf_srcs ${_target} INTF_SV_SOURCES)
    set_property(TARGET ${_target}
      PROPERTY SV_SOURCES_NOGENEX ${_intf_srcs}
    )

    set_property(TARGET ${_target}
      PROPERTY SV_INCLUDE_DIRS $<TARGET_PROPERTY:${_target},INTF_SV_INCLUDE_DIR>
    )
    get_target_property(_intf_dir ${_target} INTF_SV_INCLUDE_DIR)
    set_property(TARGET ${_target}
      PROPERTY SV_INCLUDE_DIRS_NOGENEX ${_intf_dir}
    )

    get_target_property(_libs ${_target} INTERFACE_LINK_LIBRARIES)

    if(_libs)
      __nyu_link_internal(${_target} ${_libs})
    endif()
  endforeach()
endfunction()

function(nyu_install_sv)
  cmake_parse_arguments(PARSE_ARGV 0 ARG
    ""
    "EXPORT;NAMESPACE;SV_DEST;EXPORT_DEST"
    "TARGETS"
  )

  foreach(_target IN LISTS ARG_TARGETS)
    get_target_property(_srcs ${_target} SV_SRC_PATHS)

    if(NOT _srcs)
      continue()
    endif()

    set(_imp [[${_IMPORT_PREFIX}]])

    foreach(_src IN LISTS _srcs)
      cmake_path(GET _src FILENAME _file)
      set_property(TARGET ${_target} APPEND
        PROPERTY INTF_SV_SOURCES ${_imp}/${ARG_SV_DEST}/${_file}
      )
    endforeach()

    set_property(TARGET ${_target}
      PROPERTY INTF_SV_INCLUDE_DIR ${_imp}/${ARG_SV_DEST}
    )

    set_property(TARGET ${_target} APPEND
      PROPERTY EXPORT_PROPERTIES INTF_SV_SOURCES INTF_SV_INCLUDE_DIR
    )
    install(
      FILES $<TARGET_GENEX_EVAL:${_target},$<TARGET_PROPERTY:${_target},SV_SRC_PATHS>>
      DESTINATION ${ARG_SV_DEST}
    )
  endforeach()

  install(
    TARGETS ${ARG_TARGETS}
    EXPORT ${ARG_EXPORT}
  )

  install(
    EXPORT ${ARG_EXPORT}
    NAMESPACE ${ARG_NAMESPACE}
    DESTINATION ${ARG_EXPORT_DEST}
  )
endfunction()

find_package(verilator CONFIG REQUIRED)

function(nyu_verilate TARGET)
  get_target_property(_srcs ${TARGET} SV_SOURCES_NOGENEX)
  get_target_property(_dirs ${TARGET} SV_INCLUDE_DIRS_NOGENEX)

  if(_dirs)
    set(_inc_dirs INCLUDE_DIRS)
  endif()

  verilate(${TARGET}
    SOURCES ${_srcs}
    ${_inc_dirs} ${_dirs}
    ${ARGN}
  )
endfunction()

function(nyu_target_verilate TARGET)
  cmake_parse_arguments(PARSE_ARGV 1 ARG
    ""
    "PREFIX"
    "TOP_MODULES;ARGS"
  )

  if(NOT ARG_PREFIX)
    set(ARG_PREFIX V)
  endif()

  get_target_property(_srcs ${TARGET} SV_SOURCES_NOGENEX)
  get_target_property(_dirs ${TARGET} SV_INCLUDE_DIRS_NOGENEX)

  if(_dirs)
    set(_inc_dirs INCLUDE_DIRS)
  else()
    set(_dirs)
  endif()

  foreach(_mod IN LISTS ARG_TOP_MODULES)
    verilate(${TARGET}
      SOURCES ${_srcs}
      ${_inc_dirs} ${_dirs}
      TOP_MODULE ${_mod}
      PREFIX ${ARG_PREFIX}${_mod}
      ${ARG_ARGS}
    )
  endforeach()
endfunction()
