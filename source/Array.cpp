// Array.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>

template <class T> 
class Array {
public:
	Array(int len = 10)	{
		arr = (T*)malloc(size*sizeof(T));
		mem = len*sizeof(T);
		size = 0;
	};

	~Array() {
		free(arr);
		mem = 0, size = 0;
	};

	void push_back(T var)	{
		size++;
		if( size > mem/sizeof(T)) {
			arr = (T*)realloc(arr,mem*2);
			if( !arr ) 
				perror("Failed to reallocate memory to Array");
		}
		arr[size-1] = var;
	};

	int getSize() { return size; };

	T at(int i) {
		return arr[i];
	};
	//попали сюда
	Array& operator = (const Array &x) {
			size = 0;
			for(int i = 0; i < x.getSize(); i++) 
				this.push_back(x.at(i));
	};

	T& operator [] (const int i) {
		return arr[i];
	};

private:
	T *arr;
	int size;
	int mem;
};

int main()
{
	Array<int> arr;
	for(int i = 0; i < 200; i++) {
		arr.push_back(i);
	}
	for(int i = 0; i < 200; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	//Array<int> arr2 = arr;
	/*for(int i = 0; i < 200; i++) {
		printf("%d ",arr2[i]);
	}*/
	system("pause");
	return 0;
}

