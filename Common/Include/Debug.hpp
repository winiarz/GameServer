#pragma once
#include <fstream>
#include <string.h>

class DebugStream
{
public:
    static DebugStream& getDebugStream()
    {
        static DebugStream theOnlyDebugStream;
        return theOnlyDebugStream;
    }

    std::ostream& getStream(std::string, int);

    ~DebugStream();
private:
    DebugStream();

    std::ofstream debugFile;
};




#define DEBUG_ENABLED 1

#define FILENAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define DEBUG \
    if ( DEBUG_ENABLED ) \
        DebugStream::getDebugStream().getStream(FILENAME, __LINE__)

