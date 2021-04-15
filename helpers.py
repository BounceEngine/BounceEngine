import sys
import platform

configurations = [
    "debug",
    "release"
]

colors = {
    "red"     : "\033[31m",
    "reset"   : "\033[0m",
    "green"   : "\033[92m",
    "blue"    : "\033[94m",
    "yellow"  : "\033[33m",
    "magenta" : "\033[35m"
}

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