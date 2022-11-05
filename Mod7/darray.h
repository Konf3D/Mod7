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
	void voidGuard() const;
	void borderGuard(const int i) const;

public:
	IntArray();
	IntArray(const unsigned int capacity);
	IntArray(const unsigned int capacity, const unsigned int size);
	IntArray(const IntArray& rhs);
	IntArray(IntArray&& rhs) noexcept;
	~IntArray();

public:
	IntArray& operator=(const IntArray& rhs);
	IntArray& operator=(IntArray&& rhs) noexcept;
	int operator[](const int i);
	void resize(const int size);
	void insert(const int position, const int value);
	void remove(const int position);
	void modify(const int position, const int value);
	//void push_back(const int value);
	//void push_front(const int value);
};
