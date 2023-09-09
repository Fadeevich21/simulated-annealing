# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SimulatedAnnealing_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SimulatedAnnealing_autogen.dir/ParseCache.txt"
  "SimulatedAnnealing_autogen"
  "libs/QCustomPlot-library-master/lib/CMakeFiles/qcustomplot_autogen.dir/AutogenUsed.txt"
  "libs/QCustomPlot-library-master/lib/CMakeFiles/qcustomplot_autogen.dir/ParseCache.txt"
  "libs/QCustomPlot-library-master/lib/qcustomplot_autogen"
  )
endif()
