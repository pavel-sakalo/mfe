// Array.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>

template <class T> 
class Array {
public:
	Array(const int len = 10);
	~Array() { 	free(arr); 	mem = 0, size = 0;	}
	void PushBack(const T var);
	int GetSize() { return size; }
	Array& operator = (const Array &x); 
	T& operator [] (const int i) { return arr[i]; }
private:
	T *arr;
	int size;
	int mem;
};

template<class T> Array<T>::Array(const int len = 10) {
		arr = (T*)malloc(size*sizeof(T));
		mem = len*sizeof(T);
		size = 0;
}
template<class T> void Array<T>::PushBack(const T var) {
		size++;
		if( size > mem/sizeof(T)) {
			mem *= 2;
			arr = (T*)realloc(arr,mem);
			if( !arr ) 
				perror("Failed to reallocate memory to Array");
		}
		arr[size-1] = var;
}
template<class T> Array<T>& Array<T>::operator = (const Array &x) {
			size = 0;
			for(int i = 0; i < x.GetSize(); i++) 
				this.PushBack(x[i]);
			return this;
}

int main()
{
	Array<int> arr;
	for(int i = 0; i < 200; i++) {
		arr.PushBack(i);
	}
	for(int i = 0; i < 200; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	Array<int> arr2 = arr;
	for(int i = 0; i < 200; i++) {
		printf("%d ",arr2[i]);
	}
	system("pause");
	return 0;
}

