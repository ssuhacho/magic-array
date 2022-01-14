/**
* [Suha Cho]
* [main.cpp]
**/
#include <iostream>
#include <cstdlib> // for rand()
#include <time.h> // for time()
#include "MagicArray.h"
#include "MagicArray.cpp"

int main() {
	MagicArray<int> myMagicArray = MagicArray<int>();

	std::cout << "Current capacity of myMagicArray is: " 
		<< myMagicArray.getCapacity() 
		<< " [should be 1]" << std::endl << std::endl;

	// Place 1000 random ints into myMagicArray
	srand(static_cast<int>(time(0)));
	for (int i = 0; i < 1000; i++) {
		int randomNum = rand() % 1000 + 1;
		myMagicArray.add(randomNum, i);
	}
	std::cout << "Current capacity of myMagicArray is: " 
		<< myMagicArray.getCapacity() 
		<< " [should be 1000]" << std::endl << std::endl;

	std::cout << "The value of myMagicArray[500] is: " 
		<< myMagicArray.get(500) 
		<< " [should be a random number]" << std::endl << std::endl;

	myMagicArray.add(2137, 2137);

	std::cout << "Find result is : " << myMagicArray.find(2137) 
		<< " [should be 2137]" << std::endl << std::endl;

	myMagicArray.grow();

	std::cout << "Current capacity of myMagicArray is: " 
		<< myMagicArray.getCapacity() 
		<< " [should be 4276]" << std::endl << std::endl;

	myMagicArray.shrink();

	std::cout << "Current capacity of myMagicArray is: " 
		<< myMagicArray.getCapacity() 
		<< " [should be 2138]" << std::endl << std::endl;

	myMagicArray.shrink(100);

	std::cout << "Current capacity of myMagicArray is: " 
		<< myMagicArray.getCapacity() 
		<< " [should be 100]" << std::endl << std::endl;

	myMagicArray.shrink(200);

	std::cout << "Current capacity of myMagicArray is: "
		<< myMagicArray.getCapacity()
		<< " [should be 100]" << std::endl << std::endl;

	myMagicArray.grow(1234);

	std::cout << "Current capacity of myMagicArray is: "
		<< myMagicArray.getCapacity()
		<< " [should be 1234]" << std::endl << std::endl;

	myMagicArray.grow(100);

	std::cout << "Current capacity of myMagicArray is: "
		<< myMagicArray.getCapacity()
		<< " [should be 1234]" << std::endl << std::endl;

	myMagicArray.clear();

	cout << "Call to add(123, -1) should produce an error message:" << endl;
	myMagicArray.add(123, -1);

	cout << "Call to get(100) should produce an error message:" << endl;
	myMagicArray.get(100);
}