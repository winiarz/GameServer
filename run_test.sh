#!/bin/bash

msgQueueId=123
msgQueueId2=124

logsDir=logs

mkdir -p $logsDir
Bin/SpaceStrategyServer $msgQueueId $msgQueueId2 2>&1 > $logsDir/server.out &
Bin/FirstTest $msgQueueId2 $msgQueueId           2>&1 > $logsDir/test.out &

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

