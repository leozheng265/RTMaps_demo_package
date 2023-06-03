# RTMaps_demo_package

## How to Build
1. #### Visual Studio
   - Visual Studio 16 2019
2. #### CMAKE
   - modify the path to RTMaps4 folder in the CMakeLists.txt
3. #### Building
   - In the root folder, run: 
   ```bash
     mkdir build && cd build
     cmake .. -G "Visual Studio 16 2019" -A x64
     cmake --build .
4. #### Find the package in build/Debug
