
const long msgIdServerControlReq = 1;

enum ServerControlCommand
{
    ServerShutdown,
    ServerRestart,
    Start,
    Pause
};

struct MsgServerControlReq
{
    ServerControlCommand command; 
};





