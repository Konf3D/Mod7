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

void IntArray::InitZero()
{
	for (int i = 0; i < _size; ++i)
	{
		_Ptr[i] = 0;
	}
}

void IntArray::InitZero(const int border)
{
	for (int i = 0; i < border; ++i)
	{
		_Ptr[i] = 0;
	}
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
	:_Ptr(Init(capacity)),_size(size),_capacity(capacity)
{
	if(_Ptr)
		InitZero();
}

IntArray::~IntArray()
{
	delete[] _Ptr;
}
