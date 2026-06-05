# J-Tool File Header Templates

This file currently contains two comment headers for files containing J-Tool source
code. The first file header comment is for C++ files. It is expected to be at the top
of each J-TOOL C++ authored file. That's to say, the first template should be found
at the top of each **`.cxx`** file, and each **`.hxx`** file.

---

<br>

## C++ File Header Comment
###### For file extensions: `.cxx` & `.hxx`

```
/**
 *********************************************************************
 *  J-TOOL: JSON Analyzer, Parser & Formatter
 *  COPYRIGHT (C) 2026 ANDREW JAY CHAMBERS
 *
 *     This program is free software: you can redistribute it and/or
 *     modify it under the terms of the GNU General Public License as
 *     published by the Free Software Foundation, either version 3 of
 *     the License, or (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public
 *     License with this program. If you did not recieve a copy,
 *     see <https://www.gnu.org/licenses/>.
 *
 **//*****************************************************************
 *
 *  FILENAME:     "This_Files_Name.(cxx|hxx)"
 *  DIRECTORY:    ""
 *  AUTHOR:       "Andrew Chambers [Ajay.Chambers@outlook.com]"
 *  REPOSITORY:   "https://GitHub.com/GitHub_UID/{Project_Name}
 *  LICENSE:      "GNU General Public License v3.0 (GPL v3.0)"
 *  DESCRIPTION:  "Insert a description for this file here..."
 *
 *********************************************************************/
```

---

<br><br>




### CMAKE: Script & Module File Header
- **File Type:** `.cmake`
- **Line Length:** 65-chars

**! PLEASE NOTE ! --** "This template is **NOT** for using with _`CMakeLists.txt`_  files, it is for CMake modules and scripts whose names are appended with the `.cmake` file extension and not the `.txt` file extension. If your looking for the _'CMakeLists.txt file documentation header'_ see the template below this one."

```
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
# FILE: ""
# LIC:  ""
# AUTH: ""
# REPO: ""
# DESC: ""
# FILE DESCRIPTION:
#   "Long descriptions are formatted like you see here. Make sure
#   the multi-line description indents each line 2-spaces. Short
#   descriptions use the `# DESC:` format instead."
#################################################################
```

---

<br><br>




### CMAKE: CMakeLists.txt
- **File Type:** `CMakeLists.txt`
- **Line Length:** 65-chars


```
##########################################################################
#  PROJECT:
#    * PROJ-NAME: "J-TOOL"
#    * DESCRIPTION: "JSON AST Generator, Schema Validator, and Formatter"
#
#  THIS FILE :
#    * FILE-NAME:   "include_base_dir_name/CMakeLists.txt"
#    * AUTHOR(S):   "Name every programmer who has worked on this file"
#    * DESCRIPTION: "Describe the file's purpose, and the code within it"
#
#  CONTACT INFO:
#    * EMAIL:       "Ajay.Chambers@Outlook.com"
#    * REPOSITORY:  "https://GitHub.com/AjayChambers/J-Tool"
#    * ISSUES/BUGS: "https://GitHub.com/AjayChambers/J-Tool/issues"
#==============================================================================
```

---

<br><br>




### CMAKE: Inline Function Documentation
  - ###### For file extensions: `.cmake`
  - ###### Header Line Length = 65-chars
```
#################################################################
# FUNCTION: ""
# ARGUMENTS:
#   * ""
#   * ""
#   * ""
# DESCRIPTION: ""
#################################################################
```