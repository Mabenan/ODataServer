 export(PACKAGE ODataServer)

include(CMakePackageConfigHelpers)
configure_package_config_file( 
  "Config.cmake.in" 
  "ODataServerConfig.cmake"
  INSTALL_DESTINATION ${LIB_FOLDER}
  PATH_VARS
    LIB_FOLDER
  )

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/ODataServerConfigVersion.cmake
  VERSION 1.0.0
  COMPATIBILITY SameMajorVersion
  )
  
  export(EXPORT ODataServer
  FILE "${CMAKE_CURRENT_BINARY_DIR}/ODataServer.cmake"
)
configure_file(${CMAKE_CURRENT_BINARY_DIR}/ODataServerConfig.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/ODataServer.cmake"
)

### Install Config and ConfigVersion files
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/ODataServerConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/ODataServerConfigVersion.cmake"
  DESTINATION "${LIB_FOLDER}"
  )