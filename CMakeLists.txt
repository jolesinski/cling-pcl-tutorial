cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(pcl-config)

find_package(PCL 1.8 REQUIRED)

set(OUT_FILE "pcl_config.C")
file(WRITE ${OUT_FILE} "")
foreach(dir ${PCL_INCLUDE_DIRS})
  file(APPEND ${OUT_FILE} ".I ${dir} \n")
endforeach()

foreach(lib ${PCL_LIBRARIES})
  if(NOT ${lib} MATCHES "(optimized)|(debug)")
    file(APPEND ${OUT_FILE} ".L ${lib} \n")
  endif()
endforeach()
