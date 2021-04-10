@echo off
pushd ..

if exist Bin (rmdir /Q /S Bin)
if exist __pycache__ (rmdir /Q /S __pycache__)
if exist .sconsign.dblite (del .sconsign.dblite)

popd
exit