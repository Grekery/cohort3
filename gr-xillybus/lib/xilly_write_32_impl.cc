/* -*- c++ -*- */
/* 
 * Copyright 2015 Alireza Khodamoradi.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "xilly_write_32_impl.h"

/* Ali */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int fd;
/* *** */
namespace gr {
  namespace xillybus {

    xilly_write_32::sptr
    xilly_write_32::make()
    {
      fd = open("/dev/xillybus_write_32", O_WRONLY);
  
      if (fd < 0) {
        printf("Failed to open write_32");
      }
      return gnuradio::get_initial_sptr
        (new xilly_write_32_impl());
    }

    /*
     * The private constructor
     */
    xilly_write_32_impl::xilly_write_32_impl()
      : gr::block("xilly_write_32",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(0, 0, 0))
    {}

    /*
     * Our virtual destructor.
     */
    xilly_write_32_impl::~xilly_write_32_impl()
    {
    }

    void
    xilly_write_32_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
        /*ninput_items_required[0] = 2048;//2*1024 floats because it's complex)*/
    }

    int
    xilly_write_32_impl::general_work (int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
        const unsigned char *in = (unsigned char *) input_items[0];
        

	int sent = 0;
  	int rc;
	int len = 8*noutput_items;
//printf("number of bytes(w) = %d\n", len);

  	while (sent < len) {
    	  rc = write(fd, in + sent, len - sent);
	
    	  if ((rc < 0) && (errno == EINTR))
      	    continue;

    	  if (rc < 0) {
      	    printf("allwrite() failed to write\n");
      	  }
	
    	  if (rc == 0) {
      	    printf("Reached write EOF (?!)\n");
      	  }
 
    	  sent += rc;
  	}
        // Do <+signal processing+>
        // Tell runtime system how many input items we consumed on
        // each input stream.
        consume_each (noutput_items);

        // Tell runtime system how many output items we produced.
        return sent/8;
    }

  } /* namespace xillybus */
} /* namespace gr */
