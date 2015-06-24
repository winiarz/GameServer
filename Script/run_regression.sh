#!/bin/bash

testList=`ls Bin/Test`


for test in $testList 
do
#echo $test
Script/run_test.sh $test
done

