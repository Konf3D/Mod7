#include "darray.h"
#include <iostream>
int main()
{
	//Создание контейнера				Create container
	IntArray myArray(10, 5);


	//Изменение элементов				Modification of the elements
	std::cout << "Filled array\n";
	for (int i = 0; i < 5; ++i)
	{
		myArray.modify(i, i * 2);
		std::cout << i << "->" << myArray[i] << '\n';
	}
	std::cout << "\nFlushed array\n";

	
	//Удаление элементов				Removal of the elemets
	myArray.remove(1);
	myArray.remove(4);
	for (int i = 0; i < 3; ++i)
	{
		std::cout << i << "->" << myArray[i] << '\n';
	}

	//Копирование экземпляра класса		Copy of the array class
	IntArray copy = myArray;


	//Вставка элементов					Insertion of the elements
	std::cout << "\nRefilled array\n";
	for (int i = 0; i < 5; ++i)
	{
		myArray.insert(i, i * 2);
		std::cout << i << "->" << myArray[i] << '\n';
	}

	// Копия экзепляра класса					Copy of the array
	std::cout << "\nCopy of the array after removal of elements\n";
	for (int i = 0; i < 3; ++i)
	{
		std::cout << i << "->" << copy[i] << '\n';
	}

}