#include "InitMessageQueue.hpp"
#include "ServerInMessage.hpp"
void sendMessage(const MessageQueuesIds& queuesIds,
                 ServerInMessage& message);
void startServer (const MessageQueuesIds& queuesIds);
void shutdownServer (const MessageQueuesIds& queuesIds);