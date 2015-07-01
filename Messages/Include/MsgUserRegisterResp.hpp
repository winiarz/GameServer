//jakies ID trzeba
enum UserRegisterStatus
{
     RegisterSuccessful,
     UsernameAlreadyUsed,
     TooManyUsers,
     ServerNotRunning

};
struct MsgUserRegisterResp
{
UserRegisterStatus userRegisterStatus;
};
