#pragma once
#include <exception>
class BoundExpection : std::exception
{
public:
    virtual const char* what() const noexcept override;
};

class VoidException : std::exception
{
public:
    virtual const char* what() const noexcept override;
};