#!/bin/bash

declare -A HAVEN_RESET=()
HAVEN_RESET["aaa"]="true"
usb="aaa"

echo "${HAVEN_RESET["$usb"]}"

args=()
if [ -n "${HAVEN_RESET["$usb"]}" ]; then
  echo "here"
  args+=(-r)
fi

echo "${args[@]}"
