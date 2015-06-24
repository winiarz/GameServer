
const long msgIdServerControlReq = 1;

enum ServerControlCommand
{
    ServerShutdown,
    ServerRestart,
    Start,
    Pause,
    SecondElapsed
};

struct MsgServerControlReq
{
    ServerControlCommand command; 
};





