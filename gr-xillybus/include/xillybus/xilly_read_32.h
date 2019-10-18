/* -*- c++ -*- */
/* 
 * Copyright 1970 <+YOU OR YOUR COMPANY+>.
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


#ifndef INCLUDED_XILLYBUS_XILLY_READ_32_H
#define INCLUDED_XILLYBUS_XILLY_READ_32_H

#include <xillybus/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace xillybus {

    /*!
     * \brief <+description of block+>
     * \ingroup xillybus
     *
     */
    class XILLYBUS_API xilly_read_32 : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<xilly_read_32> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of xillybus::xilly_read_32.
       *
       * To avoid accidental use of raw pointers, xillybus::xilly_read_32's
       * constructor is in a private implementation
       * class. xillybus::xilly_read_32::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace xillybus
} // namespace gr

#endif /* INCLUDED_XILLYBUS_XILLY_READ_32_H */

