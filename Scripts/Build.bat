@echo off

title Compiling...
echo Compiling Dependencies

:: Compile GLFW
pushd ..\Engine\Vendor\glfw
cmake .
devenv GLFW.sln /Build
popd

:: Copy Libraries
pushd ..
xcopy Engine\Vendor\glfw\src\Debug\glfw3.lib Libraries\
popd

:: Compile Core Components
pushd ..
scons
popd

PAUSE
exit