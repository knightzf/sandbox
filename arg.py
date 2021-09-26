#!/usr/bin/env python3

import os
import sys
import argparse

if __name__ == '__main__':
  parser = argparse.ArgumentParser()
  parser.add_argument("-n", "--noformat", dest="FORMAT",
                      action="store_false", required=False,
                      help="Whether or not to run format code")
  args = parser.parse_args(sys.argv[1:])
  if args.FORMAT:
    print('has')
  else:
    print('not')

