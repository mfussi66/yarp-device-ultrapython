# Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

add_subdirectory(devices)
add_subdirectory(common)
add_subdirectory(cli)

if(COMPILE_WITHUI_ULTRAPYTHON)
    add_subdirectory(ui)
endif()


