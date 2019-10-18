############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2013 Xilinx Inc. All rights reserved.
############################################################
open_project IIR
set_top IIR_filter
add_files IIR/iir.c
add_files IIR/iir.h
add_files -tb IIR/iir_in.dat
add_files -tb IIR/iir_out.dat
add_files -tb IIR/main.c
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
source "./IIR/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level none
export_design -format ip_catalog -description "An IP generated by Vivado HLS" -vendor "xilinx.com" -library "hls" -version "1.0"