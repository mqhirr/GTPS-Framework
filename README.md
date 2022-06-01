# GTPS-Framework
A framework for Growtopia Private Server developers

#### Building
Clone this repo using </br>
`$ git clone --recursive https://github.com/mqhirr/GTPS-Framework.git` (why recursive? because otherwise it wouldn't fetch submodules) </br>
and then make your changes, then build it (using CMake) </br>

# Non-Windows Platforms
Cross-platform support is present in this project, but building it may have a *small* error. </br>
To fix it go to vendor/fmt and open the **CMakeLists.txt** file. </br>
Then, add `set(CMAKE_POSITION_INDEPENDENT_CODE ON)` under `cmake_minimum_required` </br>