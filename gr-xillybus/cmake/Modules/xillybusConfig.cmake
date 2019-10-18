INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_XILLYBUS xillybus)

FIND_PATH(
    XILLYBUS_INCLUDE_DIRS
    NAMES xillybus/api.h
    HINTS $ENV{XILLYBUS_DIR}/include
        ${PC_XILLYBUS_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    XILLYBUS_LIBRARIES
    NAMES gnuradio-xillybus
    HINTS $ENV{XILLYBUS_DIR}/lib
        ${PC_XILLYBUS_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(XILLYBUS DEFAULT_MSG XILLYBUS_LIBRARIES XILLYBUS_INCLUDE_DIRS)
MARK_AS_ADVANCED(XILLYBUS_LIBRARIES XILLYBUS_INCLUDE_DIRS)

