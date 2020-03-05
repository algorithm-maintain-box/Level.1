import os
import sys
import pathlib

kMdFlag = ".md"
kCppFlag = ".cpp"

if len(sys.argv) < 2:
    print("Need file name")
    exit()

md_file = str(pathlib.Path().absolute()) + "/" + sys.argv[1] + kMdFlag
if not os.path.exists(md_file):
    print("md file :", md_file)
    with open(md_file, 'w'):
        pass
else:
    print("md file is already exist")

cpp_file = str(pathlib.Path().absolute()) + "/" + sys.argv[1] + kCppFlag
if not os.path.exists(cpp_file):
    print("cpp file :", cpp_file)
    with open(cpp_file, 'w'):
        pass
else:
    print("cpp file is already exist")