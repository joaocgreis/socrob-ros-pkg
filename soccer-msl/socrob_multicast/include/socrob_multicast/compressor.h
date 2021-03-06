/*
 * Copyright 2012, 2013 Instituto de Sistemas e Robotica, Instituto Superior Tecnico
 *
 * This file is part of SocRob Multicast.
 *
 * SocRob Multicast is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SocRob Multicast is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with SocRob Multicast.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SOCROB_MULTICAST_COMPRESSOR_H_
#define _SOCROB_MULTICAST_COMPRESSOR_H_

#include <cstddef>
#include <stdint.h>

#include <vector>



namespace socrob
{
  namespace multicast
  {
    /**
     * @brief Base class to implement a compressor
     *
     * This class is a base class that can be used to implement a compressor
     * that will filter all data to be sent and received from the multicast
     * channel.
     */
    class Compressor
    {
      public:
        /**
         * @brief Compress data
         *
         * This function sould compress a data vector in place.
         * @param vec Vector to be compressed in place.
         */
        virtual void compress (std::vector<uint8_t> & vec) {}
        
        /**
         * @brief Decompress data
         *
         * This function should decompress a data vector in place.
         * @param vec Vector to be decompressed in place.
         */
        virtual void decompress (std::vector<uint8_t> & vec) {}
    };
  }
}

#endif
