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

#include <iostream>

UltraPythonCli::UltraPythonCli(const std::string &remotePort) {
  yarp::os::Property property;
  property.put("device", "remote_grabber");
  property.put("local", "/xxx");
  property.put("remote", remotePort + "/rpc");

  if (!UltraPythonCli::device_.open(property)) {
    std::cout << "Unable to open device." << std::endl;
    exit(-1);
  }

  UltraPythonCli::device_.view(grabber_);

  if (!UltraPythonCli::grabber_) {
    std::cout << "Unable to view device." << std::endl;
    exit(-1);
  }
};

UltraPythonCli::~UltraPythonCli() {}

bool UltraPythonCli::setGrabberFeature(int feature, double value) {
  grabber_->setFeature(feature, value);
}

bool UltraPythonCli::setGrabberFeature(int feature, double value1,
                                        double value2) {
  grabber_->setFeature(feature, value1, value2);
}

bool UltraPythonCli::getGrabberFeature(int feature, double *value) {
  grabber_->getFeature(feature, value);
}

bool UltraPythonCli::getGrabberFeature(int feature, double *value1,
                                       double *value2) {
  grabber_->getFeature(feature, value1, value2);
}
