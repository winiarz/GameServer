class UserContainer
{
public:
    void addUser (char username[], char password[]);
    void  userRegisterResp(char username[]);
private:
    int static const maxUsersNumber = 100;
    int currentNumberOfUsers = 0;
    char usernames [maxUsersNumber][30];
    char passwords [maxUsersNumber][30];
};
