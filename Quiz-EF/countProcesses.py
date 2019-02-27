#!/usr/bin/python
import sys

unique_pids = set()

for line in sys.stdin.readlines():
	unique_pids.add(line.strip())

print("There are: ", len(unique_pids), " unique PIDs" )
