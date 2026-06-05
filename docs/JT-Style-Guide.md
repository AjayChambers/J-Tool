# J-TOOL STYLE GUIDE

This document contains a set of rules that describe how the programming languages, markup languages,
data formats, filetypes, and plain text, that make up the J-TOOL project, should formatted within each
document


### Using the Style Guide
When searching for a rule, or when you are unsure of how to format a bit of code, it's important to know
that the _"J-TOOL Style Guide"_ follows an enumerated and indexed hierarchical-pattern. The **index**
below should be the place you start looking when you need guidance formatting a bit of code. If you can't
find what your looking for using the index, the hierarchy pattern was intended to organize the rules into
groups that make a rules location feel intuitive. If a rule can't be found with the index, look around in
sections that are similar to the rule. If you still cannot find what your looking for, open up an issue
in the J-Tool Repository @("https://GitHub.com/AjayChambers/J-TOOL/issues"), and explain what it is your
looking for, or what knowledge you seek.


<br>




## Style Guide Index

### #01 &nbsp;•&nbsp; INDENTATION
- **1.1** &nbsp;•&nbsp; C++ Indentation\
- **1.2** &nbsp;•&nbsp; CMake Indentation\
- **1.3** &nbsp;•&nbsp; Markdown Indentation

2. ### &nbsp; <u>Column Width</u>


----------------------------------------

<br>
<br>




## #01 • INDENTATION


  - ### 1.1 − C++ Indentation
  - **FILE EXT: `.c`, `.h`, `.cxx`, `.hxx`, `.h`**
    * Standard: 4
    * Continuation: 2
    * Ctor-Initializer: 2
    * Access-Modifier: -2 (negative means offset)

- ### Markdown `.md` = 4 spaces
   - CMake = 2 spaces
   - JSON = 2 spaces
   - YAML = 2 spaces
   - Text = 2 spaces

TAB Character
   The tab character is not allowed. Indentation should be represented using the space char.

---

<br>




3. #### Column Width

   In order for a column width to be set for a language/file-type the column-width's number of chars must be able be divided by **`15`** evenly. In other words, the if statement below must be true in order for the column width to be set as a column width for a language/file-type in the J-TOOL project's style guide _(this document)._

   #### `if(COLUMN_WIDTH % 15 == 0)`

| ##  | LANGUAGE         | FILE EXT                  | LENGTH |
| :-: | :--------------- | :-------------------------| :----: |
| 01  | C++              | **`.cxx`**                |   90   |
| 02  | C++ Comments     | **`.cxx`**                |   60   |
| 03  | CMake            | **`.cmake`**              |   75   |
| 04  | CMake Comments   | **\* `.cmake` / `.txt` ** |   60   |
| 05  | JSON/JSONC       | ** `.json` / `.jsonc` **  |  120   |
| 06  | Powershell (ps1) | **`.`**                   |   75   |
| 07  | BASH (ps1)       | **`.`**                   |   75   |
| 08  | Markdown         | **`.`**                   |  105   |
| 09  | Plain Text       | **`.`**                   |  105   |

###### \* NOTE: The CMake file extension `.txt` () only applies to `CMakeLists.txt` files.

---------------------------------------

<br>




4. ####

### "LINE-BREAKING" / "LINE & SYNTAX WRAPPING"
