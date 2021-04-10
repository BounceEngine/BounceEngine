import os
import glob
from helpers import *
import platform

if is_platform("windows"):
    with open("Engine/Platform.h", "w") as f:
        f.write("#define __PLATFORM_WINDOWS__")

env = Environment(CPPPATH=["Engine", "Engine/Vendor/glfw/include"], CXXFLAGS="/std:c++17")

libs = ["glfw3", "gdi32", "opengl32", "msvcrt", "kernel32", "user32", "shell32"]

# Compile Core Components
engine_sources = glob.glob("Engine/**/*.cpp")
engine_sources.extend(glob.glob("Engine/**/*.c"))

for file in engine_sources:

    if file.endswith(".cpp"):
        object_name = (os.path.basename(file)).replace(".cpp", ".obj")
    else:
        object_name = (os.path.basename(file)).replace(".c", ".obj")

    env.Object("Binaries/Intermediate/%s" % object_name, file)


objects = Glob("Binaries/Intermediate/*.obj")
env.Program("Binaries/%s" % get_platform_bin("BounceEngine"), objects, LIBPATH="Libraries", LIBS=libs)