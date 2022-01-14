/**
* [Suha Cho]
* [MagicArray.h]
**/

#pragma once
#ifndef MAGICARRAY_H
#define MAGICARRAY_H

#include <iostream>
using namespace std;

template <class T>
class MagicArray
{
public:
	MagicArray();
	//Constructor

	~MagicArray();
	/**
	*Destructor
	*removes all items from the heap.
	*/

	void grow();
	/**
	* grow creates a new fixed-size array on the heap 
	* with two times the current capacity.
	*/

	void grow(int growNum);
	/**
	* grow creates a new fixed-size array on the heap
	* with the given int capacity.
	* @param growNum is the given int capacity.
	*/

	void shrink();
	/**
	* shrink creates a new fixed-size array on the heap
	* with half the current capacity.
	* an odd capacity round down.
	*/

	void shrink(int shrinkNum);
	/**
	* shrink creates a new fixed-size array on the heap
	* with the given int capacity.
	* @param shrinkNum is the given int capacity.
	*/

	T getCapacity();
	//getCapacity returns the current capacity of the array.

	void add(T itemType, int index);
	/**
	* add places the itemType into the int index of the
	* fixed-size array on the heap.
	* @param itemType template parameter used with the class that determines
	* the type of data stored in the MagicArray.
	* @param index Index of the fixed-size array on the heap.
	*/

	T get(int index);
	/**
	* get returns the element at index given.
	* if index is out of bounds display an error message.
	* @param index Index of the fixed-size array on the heap.
	*/

	T find(T itemType);
	/**
	* find searches the array for the given itemType.
	* @param itemType template parameter used with the class that determines
	* the type of data stored in the MagicArray.
	* @return the index of the first occurance of itemType if it's found, -1 otherwise.
	*/

	void clear();
	/**
	* clear deletes te current fixed size array on the heap.
	* resets to a new array of a single element.
	*/

private:
	T *arrayPtr;
	//a pointer to a fixed size array of itemType elements.

	int capacity;
	//number of elements allocated to the fixed size array
	//pointed by arrayPtr.
};

#endif