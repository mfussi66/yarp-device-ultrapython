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

#include "../../../cli/UltraPythonCli.h"
#include "CliMock.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

TEST(UltraPython, setFeature_ok) {
    IFrameGrabberControlsMock *grabber_mock = new IFrameGrabberControlsMock();
    UltraPythonCli mock_client(grabber_mock);

    bool result = grabber_mock->setFeature(YARP_FEATURE_BRIGHTNESS_ABSOLUTE, 10);

    EXPECT_TRUE(result);

    delete grabber_mock;
}

TEST(UltraPython, getFeature_ok) {
    IFrameGrabberControlsMock *grabber_mock = new IFrameGrabberControlsMock();
    UltraPythonCli mock_client(grabber_mock);

    double value = -1.0;

    bool result = grabber_mock->getFeature(YARP_FEATURE_BRIGHTNESS_ABSOLUTE, &value);

    EXPECT_EQ(value, 1);

    delete grabber_mock;
}
