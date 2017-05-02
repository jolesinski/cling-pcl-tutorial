## How to run Point Cloud Library functions in Cling interpreter?
This example shows how to configure Cling for Point Cloud Library. Using an interpreter significantly boosts development of Point Cloud processing applications. It is particularly useful for quick fine-tuneing of algorithm parameters and output visualization.

# Setting up Cling
For a all-in-one installer (it works at least on Ubuntu 16.04), please see:
	https://github.com/Axel-Naumann/cling-all-in-one

In particular, download and execute the clone.sh script:
	wget https://raw.githubusercontent.com/Axel-Naumann/cling-all-in-one/master/clone.sh && \
	chmod +x clone.sh && ./clone.sh

If successful, cling will be installed under ./inst/bin/cling.

# Interpreting PCL
An example script for running PCLVisualizer is provided in pcl_viewer.C.
Required library for this example is loaded with:
	.L /usr/local/lib/libpcl_visualization.so
Include paths are loaded with:
	.I /usr/local/include/pcl-1.8
	.I /usr/local/include/eigen3
	.I /usr/include/vtk-6.2
The exact paths depend on your PCL istallation. You can check all the library paths that PCL is using by running the provided CMake script with:
	cmake -H. -Btmp
The output will be under pcl_paths.C, it contains all include directories starting with .I and all libraries with .L.

# Troubleshooting
If you run into issues with cxxabi declaration mismatch from _GLIBCXX_NOTHROW, a workaround is to clear it with a define, before including any of pcl headers:
	#define _GLIBCXX_NOTHROW
