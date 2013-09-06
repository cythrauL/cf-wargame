#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

for d in ../src/*
do
  cd $d
  make
  cd $DIR
done
