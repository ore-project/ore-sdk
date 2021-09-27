![The Ore SDK wordmark](https://github.com/ore-project/ore-logo/blob/master/sdk/png/ore-sdk-wordmark-1636x512px.png)

-----

The Ore SDK is a C++ library. It provides a simple API to parse, compile and translate Ore source files. There are three components in the Ore SDK: frontend, core and backend.

# Setup environment

Building and further development of this repository is easier in a specific docker image. The according image may be downloaded from the Docker Hub with the following command:

```
docker pull oreproject/sdk-dev
```

> Notice: this docker image contains all required dependencies & allows starting build & development out of the box. Also, each release has a specific docker image with the according tag name.

Use the following commands to run the docker container & the project configuration:

```
mkdir build
docker run -it --rm -v$(pwd):/oresdk oreproject/ore:sdk-build sh
```

Execute the following commands inside docker container:

```
cd /oresdk/build
cmake ..
```

> Notice: the default build type is `Release`, use `-DCMAKE_BUILD_TYPE=Debug` for development purposes.

# Build

Use the following commands to build the repository:

```
cmake --build . --parallel $(nproc)
```

> Notice: the project's default build type is "Debug" if it's not set. Another build option is "Release".

# Install

Use the following commands to build the repository:

```
cmake --install .
```

> Notice: the project need to be built before installation.

> Notice: only one project version may be installed on the system at the same time.

# Using

In order to use the Ore SDK library in a project:
 - include header(s) from the `ore/sdk` directory;
 - link the library with an executable.

Usage example in C++ sources:

```c++
#include <iostream>
#include <ore/sdk/version.h>

int main()
{
   std::cout << ore::sdk::name << " - " << ore::sdk::version << std::endl;
   return 0;
}
```

Usage example in CMake sources:

```cmake
cmake_minimum_required(VERSION 3.20)
project("example" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(ore-sdk REQUIRED)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_Libraries(${CMAKE_PROJECT_NAME} ore-sdk)
```

# Development

Use the following keynotes for standardization of all changes.

## Test

When the project is built in the debug session, the unit test may be run via the following command:

```
ctest
```

> Notice: unit tests are available only in the "Debug" session.

## Code style

C++ & CMake source files may be formatted automatically via the following command:

```
cmake --build . --target code_format
```

In case if file changes are unacceptable, only format validation may be done via the following command:

```
cmake --build . --target code_format_check_only
```

## Code analysis

C++ source files may be analyzed by static code analyzer (currently: clang-tidy) via the following command:

```
cmake --build . --target code_analysis
```

> Notice: clang-tidy runs in parallel, job count is defined by the `nproc` command's output.

# Versioning

All Ore projects including this one use one-to-one versioning. This means, that the version number is common for all Ore projects.

The major version always brings incompatibility between projects and defines releases.

The minor version of the project may be skipped if nothing were changed, it increases if the incompatibility between projects is reached.

The patch version never brings incompatibility. It may be skipped as well as the minor version.

# License

The project licensed under the Apache License, Version 2.0; you may obtain a copy of the License at:

http://www.apache.org/licenses/LICENSE-2.0
