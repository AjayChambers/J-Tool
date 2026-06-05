#################################################################
# J-TOOL: JSON Analyzer, Parser & Formatter
#
# Copyright (C) 2026 "ANDREW J CHAMBERS JR"
#
# This program is free software: you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation, either version 3 of
# the License, or at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public
# License along with this program. If you did not receive a copy
# visit <"https://www.gnu.org/licenses/">
#
#################################################################
#
# FILE: "log-mod/logger.cmake"
# LIC:  "GPL-3.0"
# AUTH: "Andrew J Chambers Jr"
# REPO: "https://GitHub.com/AjayChambers/J-Tool"
# FILE DESCRIPTION:
#   "logger.cmake provides J-Tool with a logging interface that
#   it is able to use to inject error logging & trace logging
#   throughout the project to help advanced users and developers
#   understand what the program is doing and why it is doing it.
# NOTE: "'logger.cmake' requires the CMake-Globals.cmake config
#   file to work properly."
#################################################################



#################################################################
# FUNCTION: "logger.cmake"
# ARGUMENTS:
#   * TARGET_NAME_ - "The name of the test target to be created."
#   * EXECUTABLE_NAME_ - "The test's executable name used in the
#      terminal/console when executing the test."
#   * FILENAME_ - "The test's source filename."
# DESCRIPTION: ""
#################################################################