#!/bin/bash


Bin/SpaceStrategyServer 123&
Bin/FirstTest 12

result=$?

if [ "$result" == "0" ];
then
    echo "PASS"
else
    echo "FAIL"
fi

ipcrm -q `cat msgqid`
