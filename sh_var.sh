#!/bin/bash

function a() {
  echo $AAA
  b
}

function b() {
  echo "bb"
}

AAA=1

a
