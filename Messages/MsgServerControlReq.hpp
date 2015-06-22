
const long MsgIdServerControlReq = 1;

enum ServerControlCommand
{
    ServerShutdown
};

struct MsgServerControlReq
{
    long msgId = MsgIdServerControlReq;
    ServerControlCommand command; 
};

