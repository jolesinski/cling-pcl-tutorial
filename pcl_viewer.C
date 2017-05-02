#!/home/oles/src/test-cling/inst/bin/cling -std=c++14

// PCL libraries
.L /usr/local/lib/libpcl_visualization.so

// Uncomment to fix cxxabi declaration mismatch 
// #define _GLIBCXX_NOTHROW

// Include dirs
.I /usr/local/include/pcl-1.8
.I /usr/local/include/eigen3
.I /usr/include/vtk-6.2

#include <pcl/visualization/pcl_visualizer.h>

auto viewer = pcl::visualization::PCLVisualizer("test");

viewer.setBackgroundColor(0,0,0);
viewer.addCoordinateSystem(0.5);
viewer.initCameraParameters();
viewer.addSphere(pcl::PointXYZ{1,1,1}, 0.2, 0.3, 0.3, 0.0, "sphere");
viewer.spin();


