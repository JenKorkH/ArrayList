#pragma once

#include <iostream>
template <typename T> class MyArrayList
{
private:
	int length;
	int capacity;
	T* data;

	void Resize();
	bool NeedToResize();

public:
	MyArrayList();
	~MyArrayList();

	void Add(T num);

	bool Update(int index, T num);

	T Get(int index);


	void Del(int index);

	int GetLength();
	int GetCapacity();
};

template<typename T> MyArrayList<T>::MyArrayList()
{
	data = new T[5];
	length = 0;
	capacity = 5;
}

template<typename T> MyArrayList<T>::~MyArrayList()
{
	delete data;
}

template<typename T> bool MyArrayList<T>::NeedToResize()
{
	return capacity == length;
}

template<typename T> void MyArrayList<T>::Resize()
{
	T* temp = new T[capacity * 2];
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = data[i];
	}
	data = temp;
	capacity *= 2;
}

template<typename T> void MyArrayList<T>::Add(T item)
{
	if (NeedToResize())
	{
		Resize();
	}

	data[length] = item;
	length++;
}

template<typename T> bool MyArrayList<T>::Update(int index, T item)
{
	if (index > length || index < 0)
	{
		return false;
	}
	data[index] = item;

	return true;
}

template<typename T> T MyArrayList<T>::Get(int index)
{
	if (index <= length && index >= 0)
	{
		return data[index];
	}
}

template<typename T> void MyArrayList<T>::Del(int index)
{
	for (int i = index; i < length-1; i++)
	{
		data[i] = data[i + 1];
	}
	length--;
}

template<typename T> int MyArrayList<T>::GetCapacity()
{
	return capacity;
}

template<typename T> int MyArrayList<T>::GetLength()
{
	return length;
}