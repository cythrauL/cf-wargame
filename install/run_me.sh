#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

for d in ../src/levels/*
do
  cd $d
  make
  cd $DIR
done

gcc ./temporary_level_up.c -o /level_up
