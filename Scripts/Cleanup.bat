@echo off
pushd ..

if exist Release (rmdir /Q /S Release)
if exist Debug (rmdir /Q /S Debug)
if exist __pycache__ (rmdir /Q /S __pycache__)
if exist .sconsign.dblite (del .sconsign.dblite)

popd
exit