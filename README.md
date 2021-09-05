![The Ore SDK wordmark](https://github.com/ore-project/ore-logo/blob/master/sdk/png/ore-sdk-wordmark-1636x512px.png)

-----

The Ore SDK is a C++ library. It provides a simple API to parse, compile and translate Ore source files. There are three components in the Ore SDK: frontend, core and backend.

# Development

Developing of this repository requires a specific docker image. The according image may be downloaded from the Docker Hub with the following command:

```
docker pull oreproject/ore:sdk-build
```

This docker image contains all required dependencies & allows starting development out of the box.

## Setup environment

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

## Build

Use the following commands to build the repository:

```
cmake --build . --parallel $(nproc)
```

> Notice: the project's default build type is "Debug" if it's not set. Another build option is "Release".

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

> Notice: clang-tidy runs in parallel, job count is defined by the `nproc`command's output.

# License

The project licensed under the Apache License, Version 2.0; you may obtain a copy of the License at:

http://www.apache.org/licenses/LICENSE-2.0
