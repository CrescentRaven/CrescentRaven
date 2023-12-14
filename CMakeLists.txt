cmake_minimum_required(VERSION 3.5)
project (CrescentRaven)
#set(CMAKE_C_STANDARD 17) # 90, 99, 11, 17, 23
set(CMAKE_CXX_STANDARD 20) # 98, 11, 14, 17, 20, 23, 26

function(build bit)
  message("Building for ${bit}-bit...")

  add_compile_options(
        -Wall -Wextra -Wpedantic -Wno-char-subscripts -Wno-unused-variable -m${bit} #-Wno-overflow -Wno-unused-but-set-variable
        $<$<CONFIG:RELEASE>:-O3> # Optimize.
        $<$<CONFIG:RELEASE>:-s> # Debug symbol stripping.
        $<$<CONFIG:DEBUG>:-O0> # No optimizations.
        $<$<CONFIG:DEBUG>:-ggdb3> # Set symbol type.
  )
  add_compile_definitions(
         $<$<CONFIG:RELEASE>:RELEASE>
         $<$<CONFIG:DEBUG>:DEBUG>
  )

  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

  ### Library
  #add_library(${PROJECT_NAME}${bit} SHARED src/${PROJECT_NAME}.cpp)
  #add_custom_command(TARGET ${PROJECT_NAME}${bit} POST_BUILD DEPENDS ${PROJECT_NAME} COMMAND $<$<CONFIG:release>:${CMAKE_STRIP}> ARGS --strip-all lib${PROJECT_NAME}${bit}.dll)
  #install(TARGETS ${PROJECT_NAME}${bit} DESTINATION build/lib)
  
  ### Executable
  add_executable(${PROJECT_NAME}${bit} src/${PROJECT_NAME}.cpp)
  add_custom_command(TARGET ${PROJECT_NAME}${bit} POST_BUILD DEPENDS ${PROJECT_NAME} COMMAND $<$<CONFIG:release>:${CMAKE_STRIP}> ARGS --strip-all ${PROJECT_NAME}${bit}.exe)
  install(TARGETS ${PROJECT_NAME}${bit} DESTINATION build/bin)
  
  install(FILES include/${PROJECT_NAME}.h DESTINATION build/include/${PROJECT_NAME}${bit})

  message("Building for ${bit}-bit complete!")
endfunction()

#build(32)
build(64)
