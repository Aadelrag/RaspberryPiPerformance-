RaspberryPiPerformance-
=======================

All files found within CSCE 498.

The performance counter module file, linux framebuffer file and various 2D blur files are all C++ code.

2DBlur.c is the original 2DBlur file without performance counters.

2DBwPC.c is the 2DBlur file with performance counters included.

2DBwT.c is the 2DBlur with tiling. This file has the row pass done in each tile, and then goes back through and does the column pass in each tile.

2DBwTwPC.c is the 2DBlur with tiling and performance counters. 

Aadeltest.c is the 2DBlur with tiling. This version has the row and column pass done with in the same loop, and then moves to the next tile.

array.h this is the test file for the code. This was used as it would be faster than using the linux frame buffer.

lfb.c is the linux frame buffer. It works for the most part, but the color is grayscale. Will play with to see if I can get it fixed. 
