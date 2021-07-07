![The Ore SDK wordmark](https://github.com/ore-project/ore-logo/blob/master/sdk/png/ore-sdk-wordmark-1636x512px.png)

-----

The Ore SDK is a C++ library. It provides a simple API to parse, compile and translate Ore source files. There are three components in the Ore SDK: frontend, core and backend.

# Build

Developing of this repository requires a specific docker image. The according image may be downloaded from the Docker Hub with the following command:

```
docker pull oreproject/ore:sdk-build
```

Use the following commands to build the repository:

```
mkdir build
docker run -it --rm -v$(pwd):/oresdk oreproject/ore:sdk-build sh
cd /oresdk/build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --parallel $(nproc)
```

# License

The project licensed under the Apache License, Version 2.0; you may obtain a copy of the License at:

http://www.apache.org/licenses/LICENSE-2.0
