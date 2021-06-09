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

UltraPythonCli::UltraPythonCli(yarp::dev::IFrameGrabberControls* grabber) {
  if (!grabber) {
    std::cout << "Unable to view device." << std::endl;
    exit(-1);
  }
};

UltraPythonCli::~UltraPythonCli() {}

bool UltraPythonCli::InitYarpCommunication(
    const std::string& remotePort, yarp::dev::IFrameGrabberControls* grabber) {
  if (!yarp::os::NetworkBase::checkNetwork(2)) {
    std::cout
        << "Yarp yarpserver not found.\nPlease activate yarpserver and retry."
        << std::endl;
    return false;
  }
  
  property_.put("device", "remote_grabber");
  property_.put("local", "/xxx");
  property_.put("remote", remotePort + "/rpc");

  if (!device_.open(property_)) {
    return false;
  }
  device_.view(grabber);

  if (!grabber) {
    std::cout << "Unable to view device." << std::endl;
    return false;
  }

  return true;
}

std::vector<std::string> UltraPythonCli::splitString(const std::string& s,
                                                     const char* separator) {
  std::vector<std::string> output;
  std::string::size_type previous_position = 0;
  std::string::size_type position = 0;

  while ((position = s.find(separator, position)) != std::string::npos) {
    std::string substring(
        s.substr(previous_position, position - previous_position));
    output.push_back(substring);
    previous_position = ++position;
  }
  // Parse last word
  output.push_back(s.substr(previous_position, position - previous_position));
  return output;
}

/*
bool UltraPythonCli::setGrabberFeature(int feature, double value) {
return grabber->setFeature(feature, value);
}

bool UltraPythonCli::setGrabberFeature(int feature, double value1, double
value2) { return grabber->setFeature(feature, value1, value2);
}

bool UltraPythonCli::getGrabberFeature(int feature, double *value) {
return grabber->getFeature(feature, value);
}

bool UltraPythonCli::getGrabberFeature(int feature, double *value1, double
*value2) { return grabber->getFeature(feature, value1, value2);
}
 */