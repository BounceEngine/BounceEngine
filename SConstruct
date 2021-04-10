import os
import glob
from helpers import *
import platform

if is_platform("windows"):
    with open("Engine/Platform.h", "w") as f:
        f.write("#define __PLATFORM_WINDOWS__")

env = Environment(CPPPATH="Engine")

# Compile Core Components
engine_sources = glob.glob("Engine/**/*.cpp")
engine_sources.extend(glob.glob("Engine/**/*.c"))

for file in engine_sources:

    if file.endswith(".cpp"):
        object_name = (os.path.basename(file)).replace(".cpp", ".obj")
    else:
        object_name = (os.path.basename(file)).replace(".c", ".obj")

    env.Object("Bin/Intermediate/%s" % object_name, file)


objects = Glob("Bin/Intermediate/*.obj")
env.Program("Bin/%s" % get_platform_bin("BounceEngine"), objects)