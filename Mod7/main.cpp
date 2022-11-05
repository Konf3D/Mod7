#include "darray.h"
#include <iostream>
int main()
{
	IntArray myArray(10, 5);

	//Пример работы геттера и сеттера
	//Getter and setter usage example
	std::cout << "Filled array\n";
	for (int i = 0; i < 5; ++i)
	{
		myArray.modify(i, i * 2);
		std::cout << i << "->" << myArray[i] << '\n';
	}
	std::cout << "\nFlushed array\n";
	myArray.remove(1);
	myArray.remove(4);
	for (int i = 0; i < 3; ++i)
	{
		std::cout << i << "->" << myArray[i] << '\n';
	}
	//IntArray copy = myArray;

	std::cout << "\nRefilled array\n";
	for (int i = 0; i < 5; ++i)
	{
		myArray.insert(i, i * 2);
		std::cout << i << "->" << myArray[i] << '\n';
	}

}