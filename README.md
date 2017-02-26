# Compiling

## Linux
1. Install [Luciconnect](https://github.com/mtfranzen/luci-connect) using either one of the Relaease Binaries or by compiling it according to the instructions
2. Install Asio or Boost (*libasio-dev* on Ubuntu)
2. Install [CMake](https://cmake.org/)
3. Run ```cmake . && make``` *(tested with g++)*

## Windows
1. Install [Luciconnect](https://github.com/mtfranzen/luci-connect) using either one of the Relaease Binaries or by compiling it according to the instructions
2. Install [CMake](https://cmake.org/)
3. Run Cmake. Make sure to specify your correct Visual Studio version and Luciconnect Installation-Folder)
````
cmake -G "Visual Studio 14 2015 Win64" -DLUCICONNECT_ROOT="C:\Program Files\Luciconnect 0.1.2"
```
4. Open the project solution with Visual Studio (Tested with Visual Studio 2015 Update 3)
5. Make sure to have the correct version of Luciconnect installed (Release mode requries the static release version of Luciconnect)
