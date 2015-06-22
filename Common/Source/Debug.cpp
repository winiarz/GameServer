#include "Debug.hpp"

DebugStream::DebugStream() :
    debugFile("debug.txt")
    {}


std::ostream& DebugStream::getStream(std::string fileName, int lineNb)
{
    debugFile << std::endl << fileName << " #" << lineNb << ": ";
    return debugFile;
}

DebugStream::~DebugStream()
{
    debugFile.close();
}

