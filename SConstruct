import os
import glob
from helpers import *
import platform

target = ARGUMENTS.get("target")
if not target:
    error_arg("target")

if not target in configurations:
    print("Configuration '%s' was not found." % target)
    sys.exit(1)

print("Building Cofiguration: %s" % target.title())

if is_platform("windows"):
    with open("Engine/Platform.h", "w") as f:
        f.write("#define __PLATFORM_WINDOWS__")

env = Environment(CPPPATH="Engine")

# Compile Core Components
engine_sources = glob.glob("Engine/**/*.cpp")
engine_sources.extend(glob.glob("Engine/**/*.c"))

for file in engine_sources:

    f_name = target.title()

    if file.endswith(".cpp"):
        object_name = (os.path.basename(file)).replace(".cpp", ".obj")
    else:
        object_name = (os.path.basename(file)).replace(".c", ".obj")

    env.Object("%s/Intermediate/%s" % (f_name, object_name), file)


objects = Glob("%s/Intermediate/*.obj" % target.title())
env.Program("%s/%s" % (target.title(), get_platform_bin("BounceEngine")), objects)