// Array.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>

template <class T> 
class Array {
public:
	Array(const int len = 10);
	~Array(); 
	void PushBack(const T var);
	int GetSize();
	Array& operator = (Array& x); 
	T& operator [] (const int i);
private:
	T *arr;
	int size;
	int mem;
};

template<class T> Array<T>::Array(const int len = 100) {
		arr = new T [len];
		mem = len;
		size = 0;
}
template<class T> Array<T>::~Array() { 	delete [] arr; 	mem = 0, size = 0;	}
template<class T> int Array<T>::GetSize()  { return size; }
template<class T> void Array<T>::PushBack(const T var) {
		size++;
		if( size > mem) {
			//перевыделение памяти
			mem *= 2;
			T *tmp = new T [mem];
			memcpy(tmp,arr,(size-1)*sizeof(T));
			delete [] arr;
			arr = new T [mem];
			memcpy(arr,tmp,(size-1)*sizeof(T));
			delete [] tmp;
			arr[size-1] = var;
		}
		else
			arr[size-1] = var;
}
template<class T> Array<T>& Array<T>::operator = (Array<T>& x) {
	if( this == &x)
		return *this;
	if( size < x.GetSize()) {
		do {
			delete [] arr;	
			mem *= 2;
			arr = new T [mem];
		} while( mem < x.GetSize() );
	}
	memcpy(arr,x.arr,x.GetSize()*sizeof(T));
	size = x.GetSize();
	return *this;
}
template<class T> T& Array<T>::operator [] (const int i) {
	if( i >= size) {
		perror("Out of range");
	}
	else 
		return arr[i];
}



int main()
{
	Array<int> arr;
	for(int i = 0; i < 20; i++) {
		arr.PushBack(i);
	}
	Array<int> tmp;
	tmp = arr;
	for(int i = 0; i < 20; i++) {
		printf("%d ",tmp[i]);
	}
	system("pause");
	return 0;
}