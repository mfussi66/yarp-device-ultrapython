/*
 * Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include "UltraPythonCli.h"

int main(int argc, char* argv[]) {
  if (argc > 4 || argc < 2) {
    std::cout << "Use 'ultrapythoncli --help'" << std::endl;
    exit(-1);
  }

  if (std::string(argv[1]) == "--help") {
    std::cout << "Usage 'ultrapythoncli [--help] [--get value] "
                 "[--set ctrlcode value]'  NOTE: the name is without rpc and "
                 "port name usually is /grabber"
              << std::endl;
    exit(-1);
  }

  if (!yarp::os::NetworkBase::checkNetwork(2)) {
    std::cout << "Yarp yarpserver not found.\n "
                 "Please activate yarpserver and retry."
              << std::endl;
    exit(-1);
  }

  UltraPythonCli client("/grabber");
  int controlCode = 0;

  if (std::string(argv[1]) == "--set") {

    try {
      controlCode = std::atoi(argv[2]);
    } catch (const std::exception& e) {
      std::cout << e.what()
                << "\n Control codes can be expressed only in integer values."
                << std::endl;
    }
  }

  return 0;
}