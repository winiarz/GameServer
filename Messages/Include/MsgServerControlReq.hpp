
const long msgIdServerControlReq = 1;

enum ServerControlCommand
{
    ServerShutdown,
    ServerRestart
};

struct MsgServerControlReq
{
    ServerControlCommand command; 
};

struct MsgServerStatusResp
{

};



