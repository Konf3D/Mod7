#include "darray.h"
#include <iostream>

int* IntArray::Init(const unsigned int capacity)
{
	int* ptr = nullptr;
	try
	{
		ptr = new int[capacity]();
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << e.what();
		return nullptr;
	}
	return ptr;
}

void IntArray::voidGuard() const
{
	if (!_Ptr)
		throw VoidException();
	return;
}

void IntArray::borderGuard(const int iterator) const
{
	if (_Ptr + iterator < _Ptr || _Ptr + _size <= _Ptr + iterator)
		throw BoundExpection();
}

int IntArray::generalGuard(const int i)
{
	try
	{
		voidGuard();
		borderGuard(i);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		return 0;
	}
	return 1;
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

}

IntArray::IntArray(const IntArray& rhs)
    :_Ptr(Init(rhs._capacity)),_size(rhs._size),_capacity(rhs._capacity)
{
    //std::memcpy(_Ptr,rhs._Ptr,_size); not working for some reasons

	for (int i = 0; i < _size; ++i)
		_Ptr[i] = rhs._Ptr[i];
}

IntArray::IntArray(IntArray&& rhs) noexcept
	:_Ptr(rhs._Ptr), _size(rhs._size), _capacity(rhs._capacity)
{
	rhs._Ptr = nullptr;
}

IntArray::~IntArray()
{
	delete[] _Ptr;
}

IntArray& IntArray::operator=(const IntArray& rhs)
{

	delete[] _Ptr;
	try
	{
		_Ptr = Init(rhs._capacity);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
		_Ptr = nullptr;
		return *this;
	}
	_size = rhs._size;
	_capacity = rhs._capacity;
	
    //std::memcpy(_Ptr,rhs._Ptr,_size); not working for some reasons
	for (int i = 0; i < _size; ++i)
		_Ptr[i] = rhs._Ptr[i];
	return *this;
}

IntArray& IntArray::operator=(IntArray&& rhs) noexcept
{
	_Ptr = rhs._Ptr;
	_size = rhs._size;
	_capacity = rhs._capacity;

	rhs._Ptr = nullptr;
	return *this;
}

int IntArray::operator[](const int i)
{
	if(generalGuard(i))
		return _Ptr[i];
}

int IntArray::getSize() const
{
	return _size;
}

void IntArray::resize(const int capacity)
{
	int* tmp = Init(capacity);
	if (!tmp)
		return;

	for (int i = 0; i < _size; ++i)
		tmp[i] = _Ptr[i];
	delete[] _Ptr;
	_Ptr = tmp;
	_capacity = capacity;
}

void IntArray::insert(const int position, const int value)
{
	if (_size == _capacity)
		resize(_capacity * 2);
	if (_size < _capacity)
	{
		for (int i = _size; i > position; --i)
		{
			_Ptr[i] = _Ptr[i - 1];
		}
		_Ptr[position] = value;
		++_size;
	}
}

void IntArray::remove(const int position)
{
	if (!generalGuard(position))
		return;
	for (int i = position; i < _size-1; ++i)
	{
		_Ptr[i] = _Ptr[i + 1];
	}
	--_size;
}

void IntArray::modify(const int position, const int value)
{
	if (!generalGuard(position))
		return;
	_Ptr[position] = value;
}

void IntArray::push_back(const int value)
{
	this->insert(_size, value);
}

void IntArray::push_front(const int value)
{
	this->insert(0, value);
}

int IntArray::search(int value) const
{
	for (int i = 0; i < _size; ++i)
	{
		if (_Ptr[i] == value)
			return i;
	}
	return -1;
}
