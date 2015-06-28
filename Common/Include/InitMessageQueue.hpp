#pragma once

struct MessageQueuesIds
{
    int inputQueue;
    int outputQueue;
};

MessageQueuesIds initMessageQueues(int argc, char* argv[]);

