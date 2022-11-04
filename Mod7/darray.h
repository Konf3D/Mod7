#pragma once

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
public:
	IntArray();
	IntArray(const unsigned int capacity);
	IntArray(const unsigned int capacity, const unsigned int size);

	~IntArray();
};
