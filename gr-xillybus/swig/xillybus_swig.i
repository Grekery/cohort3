/* -*- c++ -*- */

#define XILLYBUS_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "xillybus_swig_doc.i"

%{
#include "xillybus/xilly_write_32.h"
#include "xillybus/xilly_read_32.h"
%}


%include "xillybus/xilly_write_32.h"
GR_SWIG_BLOCK_MAGIC2(xillybus, xilly_write_32);
%include "xillybus/xilly_read_32.h"
GR_SWIG_BLOCK_MAGIC2(xillybus, xilly_read_32);
