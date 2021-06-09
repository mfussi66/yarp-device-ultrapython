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

#pragma once

#include <yarp/dev/DeviceDriver.h>
#include <yarp/dev/FrameGrabberInterfaces.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/os/Property.h>

#include <iostream>
#include <string>

#include "../common/common.h"

class UltraPythonCli {
 public:
  /**
   * @brief Construct a new Ultra Python Cli object
   *
   * @param grabber Pointer to object representing a camera features controller
   */
  UltraPythonCli(yarp::dev::IFrameGrabberControls* grabber);

  /**
   * @brief Destroy the Ultra Python Cli object
   */
  ~UltraPythonCli();

  /**
   * @brief Verifies the status of the Yarp network and sets the properties
   *        of the frame grabber
   * @param remotePort string containing the port at which the grabber connects
   * to
   * @param grabber pointer to the frame grabber object to be filled
   * @return true if successful, false otherwise.
   */
  bool InitYarpCommunication(const std::string& remotePort,
                             yarp::dev::IFrameGrabberControls* grabber);

  /**
   * @brief Splits a string according to a custom separator
   *
   * @param c string to be split
   * @param separator character delimiter
   * @return a vector containing separated substrings
   */
  std::vector<std::string> splitString(const std::string& c,
                                       const char* separator);
  /*
      bool setGrabberFeature(int feature, double value);

      bool setGrabberFeature(int feature, double value1, double value2);

      bool getGrabberFeature(int feature, double *value);

      bool getGrabberFeature(int feature, double *value1, double *value2);
  */
 private:
  /**
   * @brief Device object containing connection properties needed to instantiate
   *        the frame grabber.
   */
  yarp::dev::PolyDriver device_;

  /**
   * @brief Container of connection properties of the device.
   */
  yarp::os::Property property_;
};
