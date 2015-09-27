#!/bin/bash

guardTimer=3

testBin=$1
msgQueueId=123
msgQueueId2=124

logsDir=logs

mkdir -p $logsDir
timeout $guardTimer Bin/SpaceStrategyServer $msgQueueId $msgQueueId2 2>&1 > $logsDir/server.out &
timeout $guardTimer Bin/Test/$testBin $msgQueueId2 $msgQueueId           2>&1 > $logsDir/test.out &
testPid=$!

wait $testPid

result=$?

if [ "$result" == "0" ];
then
    echo -e "PASS\t$testBin"
else
    echo -e "FAIL\t$testBin"
fi

ipcrm -q `cat msgqid1` > /dev/null
ipcrm -q `cat msgqid2` > /dev/null
rm msgqid1 msgqid2


mv debug.txt $logsDir

