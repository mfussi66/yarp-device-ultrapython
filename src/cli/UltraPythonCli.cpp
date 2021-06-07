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

UltraPythonTerminalClient::UltraPythonTerminalClient(){};

bool UltraPythonTerminalClient::initYarp(const std::string& remotePort)
{
	if (!yarp::os::NetworkBase::checkNetwork(2))
	{
		std::cout << "Yarp yarpserver not found.\n "
					 "Please activate yarpserver and retry."
				  << std::endl;
		exit(-1);
	}

	yarp::os::Property property;
	property.put("device", "remote_grabber");
	property.put("local", "/xxx");
	property.put("remote", remotePort + "/rpc");

	if (!UltraPythonTerminalClient::device_.open(property))
	{
		std::cout << "Unable to open device." << std::endl;
		exit(-1);
	}
	UltraPythonTerminalClient::device_.view(grabber_);

	if (!UltraPythonTerminalClient::grabber_)
	{
		std::cout << "Unable to view device." << std::endl;
		exit(-1);
		return false;
	}
	return true;
}
