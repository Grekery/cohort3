# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/Desktop/gr-xillybus/gr-xillybus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/Desktop/gr-xillybus/gr-xillybus/build

# Utility rule file for pygen_swig_2e2bf.

# Include the progress variables for this target.
include swig/CMakeFiles/pygen_swig_2e2bf.dir/progress.make

swig/CMakeFiles/pygen_swig_2e2bf: swig/xillybus_swig.pyc
swig/CMakeFiles/pygen_swig_2e2bf: swig/xillybus_swig.pyo

swig/xillybus_swig.pyc: swig/xillybus_swig.py
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Desktop/gr-xillybus/gr-xillybus/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating xillybus_swig.pyc"
	cd /root/Desktop/gr-xillybus/gr-xillybus/build/swig && /usr/bin/python2 /root/Desktop/gr-xillybus/gr-xillybus/build/python_compile_helper.py /root/Desktop/gr-xillybus/gr-xillybus/build/swig/xillybus_swig.py /root/Desktop/gr-xillybus/gr-xillybus/build/swig/xillybus_swig.pyc

swig/xillybus_swig.pyo: swig/xillybus_swig.py
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Desktop/gr-xillybus/gr-xillybus/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating xillybus_swig.pyo"
	cd /root/Desktop/gr-xillybus/gr-xillybus/build/swig && /usr/bin/python2 -O /root/Desktop/gr-xillybus/gr-xillybus/build/python_compile_helper.py /root/Desktop/gr-xillybus/gr-xillybus/build/swig/xillybus_swig.py /root/Desktop/gr-xillybus/gr-xillybus/build/swig/xillybus_swig.pyo

swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/tagged_stream_block.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/gnuradio.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/realtime.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/block.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/block_detail.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/constants.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/sync_block.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/gr_shared_ptr.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/block_gateway.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/sync_interpolator.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/gr_types.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/basic_block.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/gr_ctrlport.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/io_signature.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/top_block.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/gr_extras.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/message.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/tags.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/msg_handler.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/runtime_swig.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/msg_queue.i
swig/xillybus_swigPYTHON_wrap.cxx: ../swig/xillybus_swig.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/buffer.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/gr_swig_block_magic.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/hier_block2.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/runtime_swig_doc.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/feval.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/sync_decimator.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/gr_logger.i
swig/xillybus_swigPYTHON_wrap.cxx: swig/xillybus_swig_doc.i
swig/xillybus_swigPYTHON_wrap.cxx: /usr/local/include/gnuradio/swig/prefs.i
swig/xillybus_swigPYTHON_wrap.cxx: swig/xillybus_swig.tag
swig/xillybus_swigPYTHON_wrap.cxx: ../swig/xillybus_swig.i
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Desktop/gr-xillybus/gr-xillybus/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Swig source"
	cd /root/Desktop/gr-xillybus/gr-xillybus/build/swig && /usr/local/bin/cmake -E make_directory /root/Desktop/gr-xillybus/gr-xillybus/build/swig
	cd /root/Desktop/gr-xillybus/gr-xillybus/build/swig && /usr/bin/swig2.0 -python -fvirtual -modern -keyword -w511 -module xillybus_swig -DSIZE_T_32 -I/root/Desktop/gr-xillybus/gr-xillybus/build/swig -I/root/Desktop/gr-xillybus/gr-xillybus/swig -I/usr/local/include/gnuradio/swig -I/usr/include/python2.7 -I/usr/include/python2.7 -outdir /root/Desktop/gr-xillybus/gr-xillybus/build/swig -c++ -I/root/Desktop/gr-xillybus/gr-xillybus/lib -I/root/Desktop/gr-xillybus/gr-xillybus/include -I/root/Desktop/gr-xillybus/gr-xillybus/build/lib -I/root/Desktop/gr-xillybus/gr-xillybus/build/include -I/usr/include -I/usr/local/include -I/root/Desktop/gr-xillybus/gr-xillybus/build/swig -I/root/Desktop/gr-xillybus/gr-xillybus/swig -I/usr/local/include/gnuradio/swig -I/usr/include/python2.7 -o /root/Desktop/gr-xillybus/gr-xillybus/build/swig/xillybus_swigPYTHON_wrap.cxx /root/Desktop/gr-xillybus/gr-xillybus/swig/xillybus_swig.i

swig/xillybus_swig.py: swig/xillybus_swigPYTHON_wrap.cxx
	@$(CMAKE_COMMAND) -E touch_nocreate swig/xillybus_swig.py

swig/xillybus_swig_doc.i: swig/xillybus_swig_doc_swig_docs/xml/index.xml
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Desktop/gr-xillybus/gr-xillybus/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating python docstrings for xillybus_swig_doc"
	cd /root/Desktop/gr-xillybus/gr-xillybus/docs/doxygen && /usr/bin/python2 -B /root/Desktop/gr-xillybus/gr-xillybus/docs/doxygen/swig_doc.py /root/Desktop/gr-xillybus/gr-xillybus/build/swig/xillybus_swig_doc_swig_docs/xml /root/Desktop/gr-xillybus/gr-xillybus/build/swig/xillybus_swig_doc.i

swig/xillybus_swig.tag: swig/_xillybus_swig_swig_tag
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Desktop/gr-xillybus/gr-xillybus/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating xillybus_swig.tag"
	cd /root/Desktop/gr-xillybus/gr-xillybus/build/swig && ./_xillybus_swig_swig_tag
	cd /root/Desktop/gr-xillybus/gr-xillybus/build/swig && /usr/local/bin/cmake -E touch /root/Desktop/gr-xillybus/gr-xillybus/build/swig/xillybus_swig.tag

swig/xillybus_swig_doc_swig_docs/xml/index.xml: swig/_xillybus_swig_doc_tag
	$(CMAKE_COMMAND) -E cmake_progress_report /root/Desktop/gr-xillybus/gr-xillybus/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating doxygen xml for xillybus_swig_doc docs"
	cd /root/Desktop/gr-xillybus/gr-xillybus/build/swig && ./_xillybus_swig_doc_tag
	cd /root/Desktop/gr-xillybus/gr-xillybus/build/swig && /usr/bin/doxygen /root/Desktop/gr-xillybus/gr-xillybus/build/swig/xillybus_swig_doc_swig_docs/Doxyfile

pygen_swig_2e2bf: swig/CMakeFiles/pygen_swig_2e2bf
pygen_swig_2e2bf: swig/xillybus_swig.pyc
pygen_swig_2e2bf: swig/xillybus_swig.pyo
pygen_swig_2e2bf: swig/xillybus_swigPYTHON_wrap.cxx
pygen_swig_2e2bf: swig/xillybus_swig.py
pygen_swig_2e2bf: swig/xillybus_swig_doc.i
pygen_swig_2e2bf: swig/xillybus_swig.tag
pygen_swig_2e2bf: swig/xillybus_swig_doc_swig_docs/xml/index.xml
pygen_swig_2e2bf: swig/CMakeFiles/pygen_swig_2e2bf.dir/build.make
.PHONY : pygen_swig_2e2bf

# Rule to build all files generated by this target.
swig/CMakeFiles/pygen_swig_2e2bf.dir/build: pygen_swig_2e2bf
.PHONY : swig/CMakeFiles/pygen_swig_2e2bf.dir/build

swig/CMakeFiles/pygen_swig_2e2bf.dir/clean:
	cd /root/Desktop/gr-xillybus/gr-xillybus/build/swig && $(CMAKE_COMMAND) -P CMakeFiles/pygen_swig_2e2bf.dir/cmake_clean.cmake
.PHONY : swig/CMakeFiles/pygen_swig_2e2bf.dir/clean

swig/CMakeFiles/pygen_swig_2e2bf.dir/depend:
	cd /root/Desktop/gr-xillybus/gr-xillybus/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/Desktop/gr-xillybus/gr-xillybus /root/Desktop/gr-xillybus/gr-xillybus/swig /root/Desktop/gr-xillybus/gr-xillybus/build /root/Desktop/gr-xillybus/gr-xillybus/build/swig /root/Desktop/gr-xillybus/gr-xillybus/build/swig/CMakeFiles/pygen_swig_2e2bf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : swig/CMakeFiles/pygen_swig_2e2bf.dir/depend

