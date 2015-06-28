#include"UserContainer.hpp"
#include<string.h>
void UserContainer::addUser (char username[], char password[])
{
strcpy (usernames[currentNumberOfUsers], username);
strcpy (passwords[currentNumberOfUsers], password);
}
