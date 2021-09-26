#!/bin/bash

a=("aaa" "bbb")
b="aaa"
if [[ " ${a[@]} " =~ " ${b} " ]]; then
  echo "find"
fi
