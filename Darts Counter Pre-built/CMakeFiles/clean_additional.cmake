# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\darts-counter_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\darts-counter_autogen.dir\\ParseCache.txt"
  "darts-counter_autogen"
  )
endif()
