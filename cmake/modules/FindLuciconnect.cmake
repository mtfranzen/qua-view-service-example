# LUCICONNECT_ROOT: The installation path of Luciconnect

add_library(luciconnect STATIC IMPORTED)
if (WIN32)
  find_path(LUCICONNECT_INCLUDE_DIR NAMES luciconnect/luciconnect.h HINTS "${LUCICONNECT_ROOT}/include")
  find_library(LUCICONNECT_LIBRARY NAMES lib/luciconnect.lib HINTS "${LUCICONNECT_ROOT}")
else (WIN32)
  find_path(LUCICONNECT_INCLUDE_DIR NAMES luciconnect/luciconnect.h HINTS "${LUCICONNECT_ROOT}/include")
  find_library(LUCICONNECT_LIBRARY NAMES lib/libluciconnect.a HINTS "${LUCICONNECT_ROOT}")
endif (WIN32)

set_target_properties(luciconnect PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${LUCICONNECT_INCLUDE_DIR}"
  INTERFACE_LINK_LIBRARY "${LUCICONNECT_LIBRARY}"
  IMPORTED_LOCATION "${LUCICONNECT_LIBRARY}"
)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(luciconnect DEFAULT_MSG LUCICONNECT_LIBRARY LUCICONNECT_INCLUDE_DIR)
