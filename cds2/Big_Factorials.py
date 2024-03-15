import builtins
import io
import abc
import _weakrefset
import site
import os
import errno
import stat
import _stat
import posixpath
import genericpath
import sys
import _imp
import _warnings
import _thread
import _weakref
import marshal
import posix
import zipimport
import encodings
import codecs
import _codecs
import encodings.aliases
import encodings.utf_8
import __main__
import encodings.latin_1
import os.path
import _collections_abc
import _sitebuiltins
import sysconfig
import types
import functools
import collections
import operator
import _operator
import keyword
import heapq
import _heapq
import itertools
import reprlib
import weakref
import collections.abc
import importlib
import importlib._bootstrap
import importlib._bootstrap_external
import warnings
import importlib.util
import importlib.abc
import importlib.machinery
import contextlib
def solution():
	n=int(input())
	a=1
	for i in range(n):
		a*=(i+1)
	a=str(a)
	l=len(a)
	if l<5:
		print(a)
		return 0
	print(a[-4:])
testcase = 1
#testcase = int(input())
while testcase>0:
	solution()
	testcase-=1