#!/usr/bin/env python

# REF [site] >> https://docs.python.org/3/library/profile.html

import re

def main():
	re.compile('foo|bar')

#--------------------------------------------------------------------

# Usage:
#	python -m cProfile profiling_on_existing_application.py

if '__main__' == __name__:
	main()
