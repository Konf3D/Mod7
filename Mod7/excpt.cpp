#include "excpt.h"

const char* BoundExpection::what() const noexcept
{
    return "Out of range!\n";
}


const char* VoidException::what() const noexcept
{
    return "IntArray allocator missing!\n";
}