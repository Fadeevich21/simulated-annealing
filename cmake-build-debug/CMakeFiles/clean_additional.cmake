# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SimulatedAnnealing_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SimulatedAnnealing_autogen.dir/ParseCache.txt"
  "SimulatedAnnealing_autogen"
  )
endif()
