import os
import glob
from helpers import *
import platform

if is_platform("windows"):
    with open("Engine/Platform.h", "w") as f:
        f.write("#define __PLATFORM_WINDOWS__")

env = Environment(CPPPATH=["Engine", "Engine/Vendor/glfw/include", "Engine/Vendor/glad/include"], CXXFLAGS="/std:c++17", CXXCOMSTR="%sBuilding %s==> %s$SOURCES%s" % (colors["red"], colors["reset"], colors["green"], colors["reset"]),
                                                                    LINKCOMSTR="%sLinking Program%s" % (colors["green"], colors["reset"]))

libs = ["glfw3", "gdi32", "opengl32", "msvcrt", "kernel32", "user32", "shell32", "glad"]

# Build Internal Dependencies
## Glad
env.Object("Binaries/Intermediate/glad.obj", "Engine/Vendor/glad/glad.c")
env.Library("Libraries/glad", "Binaries/Intermediate/glad.obj")

# Compile Core Components
engine_sources = glob.glob("Engine/**/*.cpp", recursive=True)
engine_sources.extend(glob.glob("Engine/**/*.c"))
print(engine_sources)

for file in engine_sources:

    if file.endswith(".cpp"):
        object_name = (os.path.basename(file)).replace(".cpp", ".obj")
    else:
        object_name = (os.path.basename(file)).replace(".c", ".obj")

    env.Object("Binaries/Intermediate/%s" % object_name, file)


objects = Glob("Binaries/Intermediate/*.obj")
env.Program("Binaries/%s" % get_platform_bin("BounceEngine"), objects, LIBPATH="Libraries", LIBS=libs)