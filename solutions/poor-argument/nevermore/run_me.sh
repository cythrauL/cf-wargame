#!/bin/bash

ln -s /level_up ./d

CWD=$(pwd)

export PATH=$PATH:$CWD

/levels/poor-argument/poor-argument.out < exploit.txt
