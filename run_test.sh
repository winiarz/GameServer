#!/bin/bash

msgQueueId=123
logsDir=logs

mkdir -p $logsDir
Bin/SpaceStrategyServer $msgQueueId 2>&1 > $logsDir/server.out &
Bin/FirstTest $msgQueueId 2>&1 > $logsDir/test.out &

result=$?

if [ "$result" == "0" ];
then
    echo "PASS"
else
    echo "FAIL"
fi

wait
ipcrm -q `cat msgqid` > /dev/null
mv debug.txt $logsDir

