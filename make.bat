@echo off

cd build
del RayTracer-x64.exe
del output.bmp

cls

echo Building...

g++ -std=c++17 -O2 ^
../src/main.cpp ^
../src/bitmap_io.cpp ^
../src/camera.cpp ^
../src/colour.cpp ^
../src/hittable_object_list.cpp ^
../src/ray.cpp ^
../src/sphere.cpp ^
../src/vec3.cpp ^
-o RayTracer-x64.exe

echo Done
echo.

if exist RayTracer-x64.exe (
	RayTracer-x64.exe
	output.bmp
)

cd ../