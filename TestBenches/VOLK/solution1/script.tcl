############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2013 Xilinx Inc. All rights reserved.
############################################################
open_project VOLK
set_top volk
add_files VOLK/volk.c
add_files VOLK/volk.h
add_files -tb VOLK/main.c
add_files -tb VOLK/volk_in_i.txt
add_files -tb VOLK/volk_in_r.txt
add_files -tb VOLK/volk_out_i.txt
add_files -tb VOLK/volk_out_r.txt
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
source "./VOLK/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level none
export_design -format ip_catalog -description "An IP generated by Vivado HLS" -vendor "xilinx.com" -library "hls" -version "1.0"
