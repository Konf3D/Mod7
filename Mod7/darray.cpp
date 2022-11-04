#include "darray.h"
#include <exception>
int* IntArray::Init(const unsigned int capacity)
{
	int* ptr = nullptr;
	try
	{
		ptr = new int[capacity];
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
	return ptr;
}

IntArray::IntArray()
	:_Ptr(nullptr),_size(0), _capacity(0)
{
}

IntArray::IntArray(const unsigned int capacity)
	:_Ptr(Init(capacity)),_size(0),_capacity(capacity)
{
		
}

IntArray::IntArray(const unsigned int capacity, const unsigned int size)
{
}
