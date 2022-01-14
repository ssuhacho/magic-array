/**
* [Suha Cho]
* [MagicArray.cpp]
**/
#include "MagicArray.h"


// Constructor
template<class T>
MagicArray<T>::MagicArray() : capacity(1), arrayPtr(nullptr) //initialize
{
  arrayPtr = new T [capacity];
}


// Destructor
template<class T>
MagicArray<T>:: ~MagicArray()
{
  delete [] arrayPtr; //removes all items from the heap
}


template<class T>
void MagicArray<T>::grow()
{
	T* temp;

	//creates a new fixed-size array on the heap
	//with two times the current capacity
	temp = new T[capacity * 2]; 

	for (int i = 0; i < capacity; i++)
	{
		//copies over the elements from the existing fixed-size
		//array on the heap.
		temp[i] = arrayPtr[i];
	}

	delete[] arrayPtr; //deleting array from heap
	arrayPtr = temp;
	temp = nullptr;
	capacity = capacity * 2; //double the current capacity
}


template<class T>
void MagicArray<T>::grow(int growNum)
{
	if (growNum > capacity)
	{
		T* temp;

		//creates a new fixed-size array on the heap
		//with the given int growNum
		temp = new T[growNum];

		for (int i = 0; i < capacity; i++)
		{
			//copies over the elements from the existing fixed-size
			//array on the heap.
			temp[i] = arrayPtr[i]; 
		}

		delete[] arrayPtr; //deleting array from heap
		arrayPtr = temp;
		temp = nullptr;
		capacity = growNum;
	}
}

template<class T>
void MagicArray<T>::shrink()
{
	T* temp;

	//creates a new fixed-size array on the heap with half
	//the current capacity
	capacity = capacity / 2;
	temp = new T[capacity];

	for (int i = 0; i < capacity; i++)
	{
		//copies over the elements from the existing fixed-size
		//array on the heap up to the size of the new array.
		temp[i] = arrayPtr[i];
	}

	delete[] arrayPtr; //deleting array from heap

	arrayPtr = temp;
	temp = nullptr;
}


template<class T>
void MagicArray<T>::shrink(int shrinkNum)
{
	if (shrinkNum < capacity)
	{
		T* temp;
		//creates a new fixed-size array on the heap with
		//the given int shrinkNum
		temp = new T[shrinkNum];

		for (int i = 0; i < shrinkNum; i++)
		{
			//copies over the elements from the existing fixed-size
			//array on the heap up to the size of the new array.
			temp[i] = arrayPtr[i];
		}

		delete[] arrayPtr; //deleting array from heap
		capacity = shrinkNum;
		arrayPtr = temp;
		temp = nullptr;
	}
}


template<class T>
T MagicArray<T>::getCapacity() //accessor
{
	return capacity;
}


template<class T>
void MagicArray<T>::add(T itemType, int index)
{
	if (index < 0)
	{
		//displays error message if the index parameter is less than zero
		cout << "Error: the index parameter is less than zero!" << endl;
		return;
	}

	else if (index > capacity - 1)
	{
		grow(index + 1); //calling grow function to increase the size
	}

	//places the itemType into the int index of the
	//fixed-size array on the heap
	arrayPtr[index] = itemType;
}


template<class T>
T MagicArray<T>::get(int index)
{
	if (index < 0 || index > capacity - 1) 
	{
		//display an error message if index is out of bounds
		cout << "Error: index was out of bounds of the array!" << endl;
	}
	else
		return index; //returns the element at index given
}


template<class T>
T MagicArray<T>::find(T itemType)
{
  for (int i=0; i< getCapacity(); i++)
  {
    if (arrayPtr[i] == itemType)
    {
	//returns the index of the first occurrence of itemType
      return i; 
    }
  }
  return -1; //returns -1 if it's not found
}


template<class T>
void MagicArray<T>::clear()
{
	delete[] arrayPtr; //deletes the current fixed-size array on the heap

	//resets to a new array of a single elements
	capacity = 1;
	arrayPtr = new T[capacity]; 
}
