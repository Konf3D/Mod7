#include "darray.h"
#include <iostream>
int main()
{
	IntArray myArray(10, 5);


	std::cout << "Filled array\n";

	for (int i = 0; i < myArray.getSize(); ++i)
	{
		myArray.modify(i, i * 2);
		std::cout << i << "->" << myArray[i] << '\n';
	}
	std::cout << "\nFlushed array\n";

	
	myArray.remove(1);
	myArray.remove(3);
	for (int i = 0; i < myArray.getSize(); ++i)
	{
		std::cout << i << "->" << myArray[i] << '\n';
	}

	IntArray copy = myArray;


	std::cout << "\nRefilled array\n";

	const int tmpSize = myArray.getSize();
	for (int i = 0; i < tmpSize; ++i) // getSize evokes infinite loop
	{
		myArray.insert(i, i * 2);
		std::cout << i << "->" << myArray[i] << '\n';
	}

	for (int i = 0; i < copy.getSize(); ++i)
	{
		std::cout << i << "->" << copy[i] << '\n';
	}
	copy.push_back(1337);
	copy.push_front(34);
	
	std::cout << "\nGet index of each elemet\n";
	for (int i = 0; i < copy.getSize(); ++i)
	{
		std::cout << copy[i] << "->" << copy.search(copy[i]) << '\n';
	}
	
}