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

/**
 * @brief Executes the main loop, and parses command line arguments
 * @returns -1 on error, 0 if successful
 */
int main(int argc, char* argv[]) {
  int control_code = 0;
  double value = 0.0;
  std::string port_name = "/grabber";

  if (argc > 5 || argc < 2) {
    std::cout << "Use 'ultrapythoncli --help'" << std::endl;
    return -1;
  }

  if (std::string(argv[1]) == "--help") {
    std::cout << "Usage 'ultrapythoncli [--help] [--remote portname] [--get controlcode] [--set "
                 "controlcode value]'\n"
                 "NOTE: the name is without rpc and "
                 "port name usually is /grabber"
              << std::endl;
    return -1;
  }

  yarp::dev::IFrameGrabberControls* grabber{nullptr};
  UltraPythonCli client(grabber);

  if (argc >= 3 && std::string(argv[1]) == "--remote") {
      port_name = argv[2];
  } else {
       std::cout<< "Please select the remote port before selecting the command."
                << std::endl;
      return -1;     
  }
  
  if (!client.InitYarpCommunication(port_name)) {
    return -1;
  }

  if (std::string(argv[1]) == "--set") {
    std::vector<std::string> set_args = client.splitString(argv[2], "=");

    // Assume control code as first string
    try {
      control_code = std::stoi(set_args[0]);
    } catch (const std::exception& e) {
      std::cout << e.what()
                << "\nControl codes can be expressed only in integer values."
                << std::endl;
      return -1;
    }

    // Assume desired value as second string
    try {
      value = std::stoi(set_args[1]);
    } catch (const std::exception& e) {
      std::cout << e.what() << "\nInvalid set value." << std::endl;
      return -1;
    }

    bool result = grabber->setFeature(control_code, value);

    if (!result) {
      std::cout << "Unable to set control " + std::to_string(control_code) +
                       "=" + std::to_string(value) +
                       ".\nCheck remote yarpdev device."
                << std::endl;
      return -1;
    }
  }

  if (std::string(argv[1]) == "--get") {
    try {
      control_code = std::atoi(argv[2]);
    } catch (const std::exception& e) {
      std::cout << e.what()
                << "\nControl codes can be expressed only in integer values."
                << std::endl;
      return -1;
    }
    bool result = grabber->getFeature(control_code, &value);

    if (!result) {
      std::cout << "Unable to get control " + std::to_string(control_code) +
                       ".\nCheck remote yarpdev device."
                << std::endl;
      return -1;
    }
    std::cout << "Value for control code " << control_code << " is: " << value
              << std::endl;
  }

  return 0;
}
