#pragma once
#include "excpt.h"
class IntArray
{
private:
	int* _Ptr;
	int _size;
	int _capacity;
	
private:
	int* Init(const unsigned int capacity);
	void InitZero();
	void InitZero(const int border);
	void voidGuard() const;
	void borderGuard(const int i) const;

public:
	IntArray();
	IntArray(const unsigned int capacity);
	IntArray(const unsigned int capacity, const unsigned int size);
	~IntArray();

public:
	IntArray& operator=(const IntArray& rhs);
	IntArray& operator=(IntArray&& rhs) noexcept;
	int operator[](const int i);
	void insert(const int position, const int value);
};
