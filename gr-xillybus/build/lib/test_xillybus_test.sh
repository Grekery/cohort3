#!/bin/sh
export GR_DONT_LOAD_PREFS=1
export srcdir=/root/Desktop/gr-xillybus/gr-xillybus/lib
export PATH=/root/Desktop/gr-xillybus/gr-xillybus/build/lib:$PATH
export LD_LIBRARY_PATH=/root/Desktop/gr-xillybus/gr-xillybus/build/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$PYTHONPATH
test-xillybus 
