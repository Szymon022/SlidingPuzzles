# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/SlidingPuzzles_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/SlidingPuzzles_autogen.dir/ParseCache.txt"
  "SlidingPuzzles_autogen"
  )
endif()
