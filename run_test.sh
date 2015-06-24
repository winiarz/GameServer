#!/bin/bash

msgQueueId=123
msgQueueId2=124

logsDir=logs

mkdir -p $logsDir
Bin/SpaceStrategyServer $msgQueueId $msgQueueId2 2>&1 > $logsDir/server.out &
Bin/FirstTest $msgQueueId2 $msgQueueId           2>&1 > $logsDir/test.out &
testPid=$!

wait $testPid

result=$?

if [ "$result" == "0" ];
then
    echo "PASS"
else
    echo "FAIL"
fi

ipcrm -q `cat msgqid1` > /dev/null
ipcrm -q `cat msgqid2` > /dev/null
rm msgqid1 msgqid2


mv debug.txt $logsDir

