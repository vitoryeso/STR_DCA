# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProjetoSTR_1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProjetoSTR_1_autogen.dir\\ParseCache.txt"
  "ProjetoSTR_1_autogen"
  )
endif()
