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


sleep 1
ipcrm -q `cat msgqid1` > /dev/null
ipcrm -q `cat msgqid2` > /dev/null
wait
mv debug.txt $logsDir

