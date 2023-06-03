# RTMaps_demo_package

## How to Build
1. #### Visual Studio
   - Visual Studio 16 2019
2. #### Dependencies
   - [Eigen 3.3.9](https://eigen.tuxfamily.org/index.php?title=Main_Page)
3. #### CMAKE
   - modify the path to RTMaps4 folder and eigen3 library in the CMakeLists.txt
4. #### Building
   - In the root folder, run: 
   ```bash
     mkdir build && cd build
     cmake .. -G "Visual Studio 16 2019" -A x64
     cmake --build .
5. #### Find the package in build/Debug
