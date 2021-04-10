@echo off
pushd ..

if exist Binaries (rmdir /Q /S Binaries)
if exist Libraries (rmdir /Q /S Libraries)
if exist __pycache__ (rmdir /Q /S __pycache__)
if exist .sconsign.dblite (del .sconsign.dblite)

popd
exit