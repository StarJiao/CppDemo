#!/usr/bin/python 
from ctypes import *
import os

libtest = cdll.LoadLibrary('../cppdemo/build/src/libMathFun.so')

print libtest.add(2,7)
