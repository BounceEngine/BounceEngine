import sys
import platform

configurations = [
    "debug",
    "release"
]

def error_arg(a):
    print("Expected argument '%s' was not specified." % a)
    sys.exit(1)

def is_platform(p):
    if (platform.system()).lower() == p:
        return True
    else:
        return False

def get_platform_bin(e):
    if is_platform("windows"):
        return "%s.exe" % e