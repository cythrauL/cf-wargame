#!/bin/bash

clear

#create user accounts

useradd smash-me
useradd poor-argument
useradd mario
useradd matrix
useradd bolt
useradd ropasaurusrandom
useradd old-school
useradd compound-problem
useradd juxtaposition

#get to src directory

cd ./src

#call make file

make

cp ./keygen/level_up /level_up

cp -R ./levels /levels
