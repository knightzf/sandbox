#!/bin/bash

a=abc
if [[ $a == "bc" ]]; then
  echo "111"
elif [[ $a == "abc" ]]; then
  echo "222"
fi
