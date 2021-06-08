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

#include "../common/common.h"

class UltraPythonCli {
 public:
  UltraPythonCli(const std::string &remotePort);
  ~UltraPythonCli();

  bool setGrabberFeature(int feature, double value);

  bool setGrabberFeature(int feature, double value1, double value2);

  bool getGrabberFeature(int feature, double *value);

  bool getGrabberFeature(int feature, double *value1, double *value2);

 private:
  yarp::dev::PolyDriver device_;
  yarp::dev::IFrameGrabberControls *grabber_;
};