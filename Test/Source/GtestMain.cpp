#include <GameServerTestSuiteBase.hpp>

MessageQueuesIds queueIds;

int main(int argc, char* argv[])
{
    queueIds = initMessageQueues(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
